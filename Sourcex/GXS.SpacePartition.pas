//
// The graphics engine GLXEngine. The unit of GXScene for Delphi
//
unit GXS.SpacePartition;
(*
  Space Partition speeds up geometrical queries, like what objects does A
  overlap.

  Nota that the class TOctreeSpacePartition is optimized for dynamic scenes with
  objects that are small in relation to the size of the Octree space. This from
  Eric;

  The non-duplicating octree shouldn't really be used if  you have big objects,
  and this especially if you have lots of big objects (the more objects you have
  the less efficient the partitionning, due to the "magnifying glass" effect of
  the non-discriminating volume).
*)
interface

{$I Stage.Defines.inc}

uses
  System.Classes,
  System.SysUtils,
  System.Math,

  Stage.VectorTypes,
  Stage.VectorGeometry,

  GXS.GeometryBB,
  GXS.PersistentClasses;

const
  COctree_LEAF_TRHESHOLD = 30;
  COctree_MAX_TREE_DEPTH = 8;
  COctree_GROW_GRAVY = 0.1;

type
  TBaseSpacePartition = class;

  // Describes a cone, and is used for cone collision
  TSPCone = record
    // The base of the cone
    Base: TAffineVector;
    // The axis of the cone
    Axis: TAffineVector;
    // Angle of the cone
    Angle: Single;
    // Length of the cone
    Length: Single;
  end;

  // Extended frustum, used for fast intersection testing
  TExtendedFrustum = record
    Frustum: TFrustum;
    BSphere: TBSphere;
    // SPCone : TSPCone;
  end;

  // Used to store the actual objects in the SpacePartition
  TSpacePartitionLeaf = class(TgxPersistentObject)
  private
    FSpacePartition: TBaseSpacePartition;
    procedure SetSpacePartition(const Value: TBaseSpacePartition);
  public
    // This can be used by the space partitioner as it sees fit
    FPartitionTag: Pointer;
    // Leaves cache their AABBs so they can easily be accessed when needed by the space partitioner
    FCachedAABB: TAABB;
    (* Leaves cache their BoundingSpheres so they can easily be accessed when
      needed by the space partitioner *)
    FCachedBSphere: TBSphere;
    (* Whenever the size or location of the leaf changes, the space partitioner
      should be notified through a call to Changed. In the basic version, all it
      does is update the cached AABB and BSphere. You do not need to override this
      method. *)
    procedure Changed; virtual;
    // *** Override this!
    (* AABBs and BSpheres are cached for leafs, and this function should be
      overriden to update the cache from the structure that the leaf stores. This
      is the only function you MUST override to use space partitions. *)
    procedure UpdateCachedAABBAndBSphere; virtual;
    // The TBaseSpacePartition that owns this leaf
    property SpacePartition: TBaseSpacePartition read FSpacePartition
      write SetSpacePartition;
    // This tag can be used by the space partition to store vital information in the leaf
    property PartitionTag: Pointer read FPartitionTag;
    constructor CreateOwned(SpacePartition: TBaseSpacePartition);
    destructor Destroy; override;
  end;

  // List for storing space partition leaves
  TSpacePartitionLeafList = class(TgxPersistentObjectList)
  private
    function GetItems(I: Integer): TSpacePartitionLeaf;
    procedure SetItems(I: Integer; const Value: TSpacePartitionLeaf);
  public
    property Items[I: Integer]: TSpacePartitionLeaf read GetItems
      write SetItems; default;
    constructor Create; override;
  end;

  TCullingMode = (CmFineCulling, CmGrossCulling);

  // Basic space partition, does not implement any actual space partitioning
  TBaseSpacePartition = class(TgxPersistentObject)
  private
    FCullingMode: TCullingMode;
    // Query space for Leaves that intersect a cone, result is returned in QueryResult
    function QueryCone(const ACone: TSPCone): Integer; virtual;
  protected
    FQueryResult: TSpacePartitionLeafList;
    FQueryInterObjectTests: Integer;
    // Empties the search result and resetting all search statistics
    procedure FlushQueryResult; virtual;
  public
    // The results from the last query
    property QueryResult: TSpacePartitionLeafList read FQueryResult;
    // Clear all internal storage Leaves
    procedure Clear; virtual;
    // ** Update space partition
    (* Add a leaf *)
    procedure AddLeaf(ALeaf: TSpacePartitionLeaf); virtual;
    // Remove a leaf
    procedure RemoveLeaf(ALeaf: TSpacePartitionLeaf); virtual;
    // Called by leaf when it has changed
    procedure LeafChanged(ALeaf: TSpacePartitionLeaf); virtual;
    // ** Query space partition
    (* Query space for Leaves that intersect the axis aligned bounding box,
      result is returned through QueryResult *)
    function QueryAABB(const AAABB: TAABB): Integer; virtual;
    (* Query space for Leaves that intersect the bounding sphere, result is
      returned through QueryResult *)
    function QueryBSphere(const ABSphere: TBSphere): Integer; virtual;
    (* Query space for Leaves that intersect the bounding sphere or box
      of a leaf. Result is returned through QueryResult *)
    function QueryLeaf(const ALeaf: TSpacePartitionLeaf): Integer; virtual;
    (* Query space for Leaves that intersect a plane. Result is returned through
      QueryResult *)
    function QueryPlane(const Location, Normal: TAffineVector)
      : Integer; virtual;
    (* Query space for Leaves that intersect a Frustum. Result is returned through
      QueryResult *)
    function QueryFrustum(const Frustum: TFrustum): Integer; virtual;
    (* Query space for Leaves that intersect an extended frustum. Result is
      returned through QueryResult. Extended frustum is slightly faster than the
      regular frustum because it uses a bounding sphere for the frustum *)
    function QueryFrustumEx(const ExtendedFrustum: TExtendedFrustum)
      : Integer; virtual;
    (* Once a query has been run, this number tells of how many inter object
      tests that were run. This value must be set by all that override the
      queries. *)
    property QueryInterObjectTests: Integer read FQueryInterObjectTests;
    (* Some space partitioners delay processing changes until all changes have
      been made. ProcessUpdated should be called when all changes have been
      performed. *)
    procedure ProcessUpdated; virtual;
    (* Determines if the spatial structure should do very simple preliminary
      culling (gross culling) or a more detailed form of culling (fine culling) *)
    property CullingMode: TCullingMode read FCullingMode write FCullingMode;
    constructor Create; override;
    destructor Destroy; override;
  end;

  (* Implements a list of all leaves added to the space partition, _not_ a
    good solution, but it can be used as a benchmark against more complex methods *)
  TLeavedSpacePartition = class(TBaseSpacePartition)
  private
    FLeaves: TSpacePartitionLeafList;
    (* Query space for Leaves that intersect a cone, result is returned through
      QueryResult *)
    function QueryCone(const ACone: TSPCone): Integer; override;
  public
    // Clear all internal storage Leaves
    procedure Clear; override;
    // ** Update space partition
    (* Add a leaf *)
    procedure AddLeaf(ALeaf: TSpacePartitionLeaf); override;
    // Remove a leaf
    procedure RemoveLeaf(ALeaf: TSpacePartitionLeaf); override;

    // ** Query space partition
    (* Query space for Leaves that intersect the axis aligned bounding box,
      result is returned through QueryResult. This override scans _all_ leaves
      in the list, so it's far from optimal. *)
    function QueryAABB(const AAABB: TAABB): Integer; override;
    (* Query space for Leaves that intersect the bounding sphere, result is
      returned through QueryResult. This override scans _all_ leaves
      in the list, so it's far from optimal. *)
    function QueryBSphere(const ABSphere: TBSphere): Integer; override;
    (* Query space for Leaves that intersect a plane. Result is returned through
      QueryResult *)
    function QueryPlane(const FLocation, FNormal: TAffineVector)
      : Integer; override;

    constructor Create; override;
    destructor Destroy; override;
  published
    property Leaves: TSpacePartitionLeafList read FLeaves;
  end;

  TSectoredSpacePartition = class;
  TSectorNode = class;
  TSectorNodeArray = array [0 .. 7] of TSectorNode;

  (* Implements a SectorNode node. Each node can have 0 or 8 children, each child
    being a portion of the size of the parent. For quadtrees, that's 1/4, for
    octrees, it's 1/8 *)
  TSectorNode = class
  private
    FLeaves: TSpacePartitionLeafList;
    FAABB: TAABB;
    FSectoredSpacePartition: TSectoredSpacePartition;
    FRecursiveLeafCount: Integer;
    FParent: TSectorNode;
    FNodeDepth: Integer;
    FChildCount: Integer;
    FChildren: TSectorNodeArray;
    FBSphere: TBSphere;
    function GetNoChildren: Boolean;
    procedure SetAABB(const Value: TAABB);
    function GetCenter: TAffineVector;
  protected
    (* Recursively counts the RecursiveLeafCount, this should only be used in
      debugging purposes, because the proprtyu RecursiveLeafCount is always up to
      date. *)
    function CalcRecursiveLeafCount: Integer;
    (* Places a leaf in one of the children of this node, or in the node itself
      if it doesn't fit in any of the children *)
    function PlaceLeafInChild(ALeaf: TSpacePartitionLeaf): TSectorNode;
    (* Debug method that checks that FRecursiveLeafCount and
      CalcRecursiveLeafCount actually agree *)
    function VerifyRecursiveLeafCount: string;
    // Executed whenever the children of the node has changed
    procedure ChildrenChanged; virtual;
  public
    (* Clear deletes all children and empties the leaves. It doesn't destroy
      the leaves, as they belong to the SpacePartition *)
    procedure Clear;
    (* The Axis Aligned Bounding Box for this node. All leaves MUST fit inside
      this box. *)
    property AABB: TAABB read FAABB write SetAABB;
    // BSphere for this node
    property BSphere: TBSphere read FBSphere;
    // Center of the AABB for this node.
    property Center: TAffineVector read GetCenter;
    // NoChildren is true if the node has no children.
    property NoChildren: Boolean read GetNoChildren;
    // A list of the children for this node, only ChildCount children are none nil
    property Children: TSectorNodeArray read FChildren;
    // The number of child sectors that have been created
    property ChildCount: Integer read FChildCount;
    // Computes which child the AABB should go in. Returns nil if no such child exists
    function GetChildForAABB(AABB: TAABB): TSectorNode; virtual;
    // The leaves that are stored in this node
    property Leaves: TSpacePartitionLeafList read FLeaves;
    // The Structure that owns this node
    property SectoredSpacePartition: TSectoredSpacePartition
      read FSectoredSpacePartition;
    (* The parent node of this node. If parent is nil, that means that this
      node is the root node *)
    property Parent: TSectorNode read FParent;
    // The number of leaves stored in this node and all it's children.
    property RecursiveLeafCount: Integer read FRecursiveLeafCount;
    (* The tree depth at which this node is located. For the root, this value
      is 0, for the roots children, it is 1 and so on *)
    property NodeDepth: Integer read FNodeDepth;
    // Checks if an AABB fits completely inside this node
    function AABBFitsInNode(const AAABB: TAABB): Boolean; virtual;
    // Checks if an AABB intersects this node
    function AABBIntersectsNode(const AAABB: TAABB): Boolean; virtual;
    // Checks if a BSphere fits completely inside this node
    function BSphereFitsInNode(const BSphere: TBSphere): Boolean; virtual;
    // Checks if a BSphere intersects this node
    function BSphereIntersectsNode(const BSphere: TBSphere): Boolean; virtual;
    // Checks if a AABB partially or completely contains this sector
    function AABBContainsSector(const AABB: TAABB): TSpaceContains; virtual;
    // Checks if a BSphere partially or completely contains this sector
    function BSphereContainsSector(const BSphere: TBSphere)
      : TSpaceContains; virtual;
    // Checks if this node partially or completely contains a BSphere
    function ContainsBSphere(const ABSphere: TBSphere): TSpaceContains; virtual;
    // Checks if this node partially or completely contains an AABB
    function ContainsAABB(const AAABB: TAABB): TSpaceContains; virtual;
    (* Adds leaf to this node - or one of it's children. If the node has enough
      leaves and has no children, children will be created and all leaves will be
      spread among the children. *)
    function AddLeaf(ALeaf: TSpacePartitionLeaf): TSectorNode;
    (* Remove leaf will remove a leaf from this node. If it is determined that
      this node has too few leaves after the delete, it may be collapsed. Returns
      true if the node was actually collapsed *)
    function RemoveLeaf(ALeaf: TSpacePartitionLeaf;
      OwnerByThis: Boolean): Boolean;
    // Query the node and its children for leaves that match the AABB
    procedure QueryAABB(const AAABB: TAABB;
      const QueryResult: TSpacePartitionLeafList);
    // Query the node and its children for leaves that match the BSphere
    procedure QueryBSphere(const ABSphere: TBSphere;
      const QueryResult: TSpacePartitionLeafList);
    // Query the node and its children for leaves that match the plane
    procedure QueryPlane(const Location, Normal: TAffineVector;
      const QueryResult: TSpacePartitionLeafList);
    // Query the node and its children for leaves that match the frustum.
    procedure QueryFrustum(const Frustum: TFrustum;
      const QueryResult: TSpacePartitionLeafList);
    // Query the node and its children for leaves that match the extended frustum.
    procedure QueryFrustumEx(const ExtendedFrustum: TExtendedFrustum;
      const QueryResult: TSpacePartitionLeafList);
    (* Adds all leaves to query result without testing if they intersect, and
      then do the same for all children. This is used when QueryAABB or
      QueryBSphere determines that a node fits completely in the searched space *)
    procedure AddAllLeavesRecursive(const QueryResult: TSpacePartitionLeafList);
    // Add children to this node and spread the leaves among it's children
    procedure ExpandNode;
    // Create the number of children this node type needs
    procedure CreateChildren; virtual;
    // Delete all children for this node, adding their leaves to this node
    procedure CollapseNode;
    // Returns the number of nodes in the Octree
    function GetNodeCount: Integer;
    constructor Create(ASectoredSpacePartition: TSectoredSpacePartition;
      AParent: TSectorNode);
    destructor Destroy; override;
  end;

  (* Implements sectored space partitioning, sectored space partitions include
    Octrees, Quadtrees and  BSP-trees *)
  TGrowMethod = (gmNever, gmBestFit, gmIncreaseToFitAll);

  TSectoredSpacePartition = class(TLeavedSpacePartition)
  private
    FRootNode: TSectorNode;
    FLeafThreshold: Integer;
    FMaxTreeDepth: Integer;
    FGrowGravy: Single;
    FGrowMethod: TGrowMethod;
    procedure SetLeafThreshold(const Value: Integer);
    procedure SetMaxTreeDepth(const Value: Integer);
  protected
    FQueryNodeTests: Integer;
    // Empties the search result and resetting all search statistics
    procedure FlushQueryResult; override;
  public
    // ** Update space partition
    (* Add a leaf to the structure. If the leaf doesn't fit in the structure, the
      structure is either grown or an exception is raised. If GrowMethod is set to
      gmBestFit or gmIncreaseToFitAll, the octree will be grown. *)
    procedure AddLeaf(ALeaf: TSpacePartitionLeaf); override;
    // Remove a leaf from the structure.
    procedure RemoveLeaf(ALeaf: TSpacePartitionLeaf); override;
    // Called by leaf when it has changed, the leaf will be moved to an apropriate node
    procedure LeafChanged(ALeaf: TSpacePartitionLeaf); override;
    // ** Query space partition
    (* Query space for Leaves that intersect the axis aligned bounding box,
      result is returned through QueryResult. This method simply defers to the
      QueryAABB method of the root node. *)
    function QueryAABB(const AAABB: TAABB): Integer; override;
    (* Query space for Leaves that intersect the bounding sphere, result is
      returned through QueryResult. This method simply defers to the
      QueryBSphere method of the root node. *)
    function QueryBSphere(const ABSphere: TBSphere): Integer; override;
    (* Query space for Leaves that intersect the bounding sphere or box
      of a leaf. Result is returned through QueryResult *)
    function QueryLeaf(const ALeaf: TSpacePartitionLeaf): Integer; override;
    (* Query space for Leaves that intersect a plane. Result is returned through
      QueryResult *)
    function QueryPlane(const Location, Normal: TAffineVector)
      : Integer; override;
    (* Query space for Leaves that intersect a Frustum. Result is returned through
      QueryResult *)
    function QueryFrustum(const Frustum: TFrustum): Integer; override;
    (* Query space for Leaves that intersect an extended frustum. Result is
      returned through QueryResult *)
    function QueryFrustumEx(const ExtendedFrustum: TExtendedFrustum)
      : Integer; override;
    (* After a query has been run, this value will contain the number of nodes
      that were checked during the query *)
    property QueryNodeTests: Integer read FQueryNodeTests;
    // Returns the number of nodes in the structure
    function GetNodeCount: Integer;
    (* UpdateOctreeSize will grow and / or shrink the structure to fit the
      current leaves +-gravy *)
    procedure UpdateStructureSize(Gravy: Single);
    (* Rebuild tree will change the tree to the newAABB size, and completely
      rebuild it *)
    procedure RebuildTree(const NewAABB: TAABB);
    // Returns the _total_ AABB in structure
    function GetAABB: TAABB;
    (* CreateNewNode creates a new node of the TSectorNode subclass that this
      structure requires *)
    function CreateNewNode(AParent: TSectorNode): TSectorNode; virtual;
    procedure Clear; override;
    constructor Create; override;
    destructor Destroy; override;
  published
    // Root TSectorNode that all others stem from
    property RootNode: TSectorNode read FRootNode;
    // Determines how deep a tree should be allowed to grow.
    property MaxTreeDepth: Integer read FMaxTreeDepth write SetMaxTreeDepth;
    // Determines when a node should be split up to form children.
    property LeafThreshold: Integer read FLeafThreshold write SetLeafThreshold;
    (* Determines if the structure should grow with new leaves, or if an exception
      should be raised *)
    property GrowMethod: TGrowMethod read FGrowMethod write FGrowMethod;
    (* When the structure is recreated because it's no longer large enough to fit
      all leafs, it will become large enough to safely fit all leafs, plus
      GrowGravy. This is to prevent too many grows *)
    property GrowGravy: Single read FGrowGravy write FGrowGravy;
  end;

  // ** OCTTREE
  { Implements sector node that handles octrees }
  TSPOctreeNode = class(TSectorNode)
  public
    { Create 8 TSPOctreeNode children }
    procedure CreateChildren; override;

    { Checks if an AABB fits completely inside this node }
    function AABBFitsInNode(const AAABB: TAABB): Boolean; override;

    { Checks if an AABB intersects this node }
    function AABBIntersectsNode(const AAABB: TAABB): Boolean; override;

    { Checks if a BSphere fits completely inside this node }
    function BSphereFitsInNode(const BSphere: TBSphere): Boolean; override;

    { Checks if a BSphere intersects this node }
    function BSphereIntersectsNode(const BSphere: TBSphere): Boolean; override;
  end;

  { Implements octrees }
  TOctreeSpacePartition = class(TSectoredSpacePartition)
  public
    { Set size updates the size of the Octree }
    procedure SetSize(const Min, Max: TAffineVector);

    { CreateNewNode creates a new TSPOctreeNode }
    function CreateNewNode(AParent: TSectorNode): TSectorNode; override;
  end;

  // ** QUADTREE
  (* Implements sector node that handles quadtrees. *)
  TSPQuadtreeNode = class(TSPOctreeNode)
  protected
    (* Executed whenever the children of the node has changed. In the quadtree,
      we want to make sure the Y value of the AABB is correct up and down and that
      the bounding sphere is correct *)
    procedure ChildrenChanged; override;
  public
    // Create 4 TSPQuadtreeNode children
    procedure CreateChildren; override;
    // Checks if an AABB fits completely inside this node
    function AABBFitsInNode(const AAABB: TAABB): Boolean; override;
    // Checks if an AABB intersects this node
    function AABBIntersectsNode(const AAABB: TAABB): Boolean; override;
    // Checks if a BSphere fits completely inside this node
    function BSphereFitsInNode(const BSphere: TBSphere): Boolean; override;
    // Checks if a BSphere intersects this node
    function BSphereIntersectsNode(const BSphere: TBSphere): Boolean; override;
    // Computes which child the AABB should go in. Returns nil if no such child exists
    function GetChildForAABB(AABB: TAABB): TSectorNode; override;
  end;

  (* Implements quadtrees.
    Quadtrees are hardcoded to completely ignore the Y axis, only using X and Z
    to determine positioning.
    This means that they're well suited for 2d-ish situations (landscapes with
    trees for instance) but not for fully 3d situations (space fighting). *)
  TQuadtreeSpacePartition = class(TSectoredSpacePartition)
  public
    // Set size updates the size of the Octree
    procedure SetSize(const Min, Max: TAffineVector);
    // CreateNewNode creates a new TSPOctreeNode
    function CreateNewNode(AParent: TSectorNode): TSectorNode; override;
  end;

// Determines to which extent one Cone contains an BSphere
function ConeContainsBSphere(const Cone: TSPCone; BSphere: TBSphere)
  : TSpaceContains;

// Determines if a extended frustum intersects an BSphere
function ExtendedFrustumIntersectsBSphere(const AExtendedFrustum
  : TExtendedFrustum; ABSphere: TBSphere): Boolean;

// Create an extended frustum from a number of values
function ExtendedFrustumMake(const AFrustum: TFrustum;
  const ANearDist, AFarDist, AFieldOfViewRadians: Single;
  const ACameraPosition, ALookVector: TAffineVector (* ;
    const AScreenWidth, AScreenHeight : integer (* *) ): TExtendedFrustum;

//-------------------------------------------------
implementation
//-------------------------------------------------

(* This was copied from Octree.pas!

 Theory on FlagMax and FlagMin:
 When a node is subdivided, each of the 8 children assumes 1/8th ownership of its
 parent's bounding box (defined by parent extents).  Calculating a child's min/max
 extent only requires 3 values: the parent's min extent, the parent's max extent
 and the midpoint of the parent's extents (since the cube is divided in half twice).
 The following arrays assume that the children are numbered from 0 to 7, named Upper
 and Lower (Upper = top 4 cubes on Y axis, Bottom = lower 4 cubes), Left and Right, and
 Fore and Back (Fore facing furthest away from you the viewer).
 Each node can use its corresponding element in the array to flag the operation needed
 to find its new min/max extent.  Note that min, mid and max refer to an array of
 3 coordinates (x,y,z); each of which are flagged separately. Also note that these
 flags are based on the Y vector being the up vector. *)

const
  CMIN = 0;
  CMID = 1;
  CMAX = 2;

  COctFlagMIN: array [0 .. 7] of array [0 .. 2] of Byte = ((CMIN, CMID, CMID),
    // Upper Fore Left
    (CMID, CMID, CMID), // Upper Fore Right
    (CMIN, CMID, CMIN), // Upper Back Left
    (CMID, CMID, CMIN), // Upper Back Right

    (CMIN, CMIN, CMID), // Lower Fore Left  (similar to above except height/2)
    (CMID, CMIN, CMID), // Lower Fore Right
    (CMIN, CMIN, CMIN), // Lower Back Left
    (CMID, CMIN, CMIN) // Lower Back Right
    );

  COctFlagMax: array [0 .. 7] of array [0 .. 2] of Byte = ((CMID, CMAX, CMAX),
    // Upper Fore Left
    (CMAX, CMAX, CMAX), // Upper Fore Right
    (CMID, CMAX, CMID), // Upper Back Left
    (CMAX, CMAX, CMID), // Upper Back Right

    (CMID, CMID, CMAX), // Lower Fore Left   (similar to above except height/2)
    (CMAX, CMID, CMAX), // Lower Fore Right
    (CMID, CMID, CMID), // Lower Back Left
    (CMAX, CMID, CMID) // Lower Back Right
    );

function ConeContainsBSphere(const Cone: TSPCone; BSphere: TBSphere)
  : TSpaceContains;
var
  U, D: TAffineVector;
  E, Dsqr: Single;
begin
  // NOTE: This code hasn't been verified

  // U = K.vertex - (Sphere.radius/K.sin)*K.axis;
  U := VectorSubtract(Cone.Base, VectorScale(Cone.Axis,
    BSphere.Radius / Sin(Cone.Angle)));

  // D = S.center - U;
  D := VectorSubtract(BSphere.Center, U);

  // dsqr = Dot(D,D)
  Dsqr := VectorDotProduct(D, D);

  // e = Dot(K.axis,D);
  E := VectorDotProduct(Cone.Axis, D);

  if (E > 0) and (E * E >= Dsqr * Sqr(Cos(Cone.Angle))) then
  begin
    // D = S.center - K.vertex;
    D := VectorSubtract(BSphere.Center, Cone.Base);

    // dsqr = Dot(D,D);
    Dsqr := VectorDotProduct(D, D);

    // e = -Dot(K.axis,D);
    E := -VectorDotProduct(Cone.Axis, D);

    if (E > 0) and (E * E >= Dsqr * (Sqr(Sin(Cone.Angle)))) then
    begin
      if Dsqr <= BSphere.Radius * BSphere.Radius then
        Result := ScContainsPartially
      else
        Result := ScNoOverlap;
    end
    else
      Result := ScContainsPartially;
  end
  else
    Result := ScNoOverlap;
end; // }

function ExtendedFrustumIntersectsBSphere(const AExtendedFrustum
  : TExtendedFrustum; ABSphere: TBSphere): Boolean;
begin
  // Test if the bounding sphere of the node intersect the bounding sphere of the
  // frustum? This test is exremely fast
  if not BSphereIntersectsBSphere(ABSphere, AExtendedFrustum.BSphere) then
    Result := False

    // Test if the bsphere of the node intersects the frustum
  else if IsVolumeClipped(ABSphere.Center, ABSphere.Radius,
    AExtendedFrustum.Frustum) then
    Result := False

  else
    Result := True;
end;

function ExtendedFrustumMake(const AFrustum: TFrustum;
  const ANearDist, AFarDist, AFieldOfViewRadians: Single;
  const ACameraPosition, ALookVector: TAffineVector { ;
    const AScreenWidth, AScreenHeight : integer{ } ): TExtendedFrustum;
var
  ViewLen: Single;
  Height, Width: Single;
  // Depth, Corner, NewFov : single;
  P, Q, VDiff: TAffineVector; // }
begin
  // See http://www.flipcode.com/articles/article_frustumculling.shtml for
  // details calculate the radius of the frustum sphere

  Result.Frustum := AFrustum;

  // ************
  // Create a bounding sphere for the entire frustum - only bspheres that
  // intersect this bounding sphere can in turn intersect the frustum
  ViewLen := AFarDist - ANearDist;

  // use some trig to find the height of the frustum at the far plane
  Height := ViewLen * Sin(AFieldOfViewRadians / 2); // was tan( !?

  // with an aspect ratio of 1, the width will be the same
  Width := Height;

  // halfway point between near/far planes starting at the origin and extending along the z axis
  P := AffineVectorMake(0, 0, ANearDist + ViewLen / 2);

  // the calculate far corner of the frustum
  Q := AffineVectorMake(Width, Height, ViewLen);

  // the vector between P and Q
  VDiff := VectorSubtract(P, Q);

  // the radius becomes the length of this vector
  Result.BSphere.Radius := VectorLength(VDiff);

  // calculate the center of the sphere
  Result.BSphere.Center := VectorAdd(ACameraPosition,
    VectorScale(ALookVector, ViewLen / 2 + ANearDist));

  // ************
  // Create a cone
  // calculate the length of the fov triangle
  { Depth  := AScreenHeight / tan(AFieldOfViewRadians / 2);

    // calculate the corner of the screen
    Corner := sqrt(AScreenHeight * AScreenHeight + AScreenWidth * AScreenWidth);

    // now calculate the new fov
    NewFov := ArcTan2(Corner, Depth);

    // apply to the cone
    result.SPCone.Axis := ALookVector;
    result.SPCone.Base := ACameraPosition;
    result.SPCone.Angle := NewFov; // }
end;

{ TSpacePartitionLeaf }

procedure TSpacePartitionLeaf.UpdateCachedAABBAndBSphere;
begin
  // You MUST override TSpacePartitionLeaf.UpdateCachedAABBAndBSphere, if you
  // only have easy access to a bounding sphere, or only an axis aligned
  // bounding box, you can easily convert from one to the other by using
  // AABBToBSphere and BSphereToAABB.
  //
  // You MUST set both FCachedAABB AND FCachedBSphere
  Assert(False,
    'You MUST override TSpacePartitionLeaf.UpdateCachedAABBAndBSphere!');
end;

procedure TSpacePartitionLeaf.Changed;
begin
  UpdateCachedAABBAndBSphere;
  SpacePartition.LeafChanged(Self);
end;

constructor TSpacePartitionLeaf.CreateOwned(SpacePartition
  : TBaseSpacePartition);
begin
  inherited Create;

  FSpacePartition := SpacePartition;

  if SpacePartition <> nil then
    SpacePartition.AddLeaf(Self);
end;

destructor TSpacePartitionLeaf.Destroy;
begin
  if Assigned(FSpacePartition) then
    FSpacePartition.RemoveLeaf(Self);

  inherited;
end;

procedure TSpacePartitionLeaf.SetSpacePartition(const Value
  : TBaseSpacePartition);
begin
  if Assigned(FSpacePartition) then
    FSpacePartition.RemoveLeaf(Self);

  FSpacePartition := Value;

  if Assigned(FSpacePartition) then
    FSpacePartition.AddLeaf(Self);
end;

{ TSpacePartitionLeafList }

constructor TSpacePartitionLeafList.Create;
begin
  inherited;
  GrowthDelta := 128;
end;

function TSpacePartitionLeafList.GetItems(I: Integer): TSpacePartitionLeaf;
begin
  Result := TSpacePartitionLeaf(Get(I));
end;

procedure TSpacePartitionLeafList.SetItems(I: Integer;
  const Value: TSpacePartitionLeaf);
begin
  Put(I, Value);
end;

{ TBaseSpacePartition }

procedure TBaseSpacePartition.AddLeaf(ALeaf: TSpacePartitionLeaf);
begin
  // Virtual
  ALeaf.UpdateCachedAABBAndBSphere;
end;

procedure TBaseSpacePartition.Clear;
begin
  // Virtual
end;

constructor TBaseSpacePartition.Create;
begin
  inherited;

  FQueryResult := TSpacePartitionLeafList.Create
end;

destructor TBaseSpacePartition.Destroy;
begin
  FreeAndNil(FQueryResult);
  inherited;
end;

procedure TBaseSpacePartition.FlushQueryResult;
begin
  FQueryResult.Count := 0;
  FQueryInterObjectTests := 0;
end;

procedure TBaseSpacePartition.LeafChanged(ALeaf: TSpacePartitionLeaf);
begin
  // Virtual
end;

procedure TBaseSpacePartition.ProcessUpdated;
begin
  // Virtual
end;

function TBaseSpacePartition.QueryAABB(const AAABB: TAABB): Integer;
begin
  // Virtual
  Result := 0;
end;

function TBaseSpacePartition.QueryBSphere(const ABSphere: TBSphere): Integer;
begin
  // Virtual
  Result := 0;
end;

function TBaseSpacePartition.QueryCone(const ACone: TSPCone): Integer;
begin
  // Virtual
  Result := 0;
end;

function TBaseSpacePartition.QueryPlane(const Location,
  Normal: TAffineVector): Integer;
begin
  // Virtual
  Result := 0;
end;

function TBaseSpacePartition.QueryLeaf(const ALeaf
  : TSpacePartitionLeaf): Integer;
begin
  QueryBSphere(ALeaf.FCachedBSphere);
  // Remove self if it was included (it should have been)
  FQueryResult.Remove(ALeaf);
  Result := FQueryResult.Count;
end;

procedure TBaseSpacePartition.RemoveLeaf(ALeaf: TSpacePartitionLeaf);
begin
  // Virtual
end;

function TBaseSpacePartition.QueryFrustum(const Frustum: TFrustum): Integer;
begin
  // Virtual
  Result := 0;
end;

function TBaseSpacePartition.QueryFrustumEx(const ExtendedFrustum
  : TExtendedFrustum): Integer;
begin
  // Virtual
  Result := 0;
end;

{ TLeavedSpacePartition }

procedure TLeavedSpacePartition.AddLeaf(ALeaf: TSpacePartitionLeaf);
begin
  FLeaves.Add(ALeaf);
  ALeaf.UpdateCachedAABBAndBSphere;
end;

procedure TLeavedSpacePartition.Clear;
var
  I: Integer;
begin
  inherited;

  for I := 0 to FLeaves.Count - 1 do
  begin
    FLeaves[I].FSpacePartition := nil;
    FLeaves[I].Free;
  end;

  FLeaves.Clear;
end;

constructor TLeavedSpacePartition.Create;
begin
  inherited;

  FLeaves := TSpacePartitionLeafList.Create;
end;

destructor TLeavedSpacePartition.Destroy;
begin
  Clear;
  FreeAndNil(FLeaves);

  inherited;
end;

procedure TLeavedSpacePartition.RemoveLeaf(ALeaf: TSpacePartitionLeaf);
begin
  FLeaves.Remove(ALeaf);
end;

function TLeavedSpacePartition.QueryAABB(const AAABB: TAABB): Integer;
var
  I: Integer;
begin
  // Very brute force!
  FlushQueryResult;

  for I := 0 to Leaves.Count - 1 do
  begin
    Inc(FQueryInterObjectTests);

    if IntersectAABBsAbsolute(AAABB, Leaves[I].FCachedAABB) then
      FQueryResult.Add(Leaves[I]);
  end;

  Result := FQueryResult.Count;
end;

function TLeavedSpacePartition.QueryBSphere(const ABSphere: TBSphere): Integer;
var
  I: Integer;
  Distance2: Single;

  Leaf: TSpacePartitionLeaf;
begin
  // Very brute force!
  FlushQueryResult;

  for I := 0 to Leaves.Count - 1 do
  begin
    Leaf := Leaves[I];
    Distance2 := VectorDistance2(Leaf.FCachedBSphere.Center, ABSphere.Center);

    Inc(FQueryInterObjectTests);

    if Distance2 < Sqr(Leaf.FCachedBSphere.Radius + ABSphere.Radius) then
      FQueryResult.Add(Leaf);
  end;

  Result := FQueryResult.Count;
end;

function TLeavedSpacePartition.QueryCone(const ACone: TSPCone): Integer;
var
  I: Integer;
begin
  // Very brute force!
  FlushQueryResult;

  for I := 0 to Leaves.Count - 1 do
  begin
    Inc(FQueryInterObjectTests);

    if ConeContainsBSphere(ACone, Leaves[I].FCachedBSphere) <> ScNoOverlap then
      FQueryResult.Add(Leaves[I]);
  end;

  Result := FQueryResult.Count;
end;

function TLeavedSpacePartition.QueryPlane(const FLocation,
  FNormal: TAffineVector): Integer;
var
  I: Integer;
  CurrentPenetrationDepth: Single;
  Leaf: TSpacePartitionLeaf;
begin
  // Very brute force!
  FlushQueryResult;

  for I := 0 to Leaves.Count - 1 do
  begin
    Inc(FQueryInterObjectTests);

    Leaf := Leaves[I];

    CurrentPenetrationDepth := -(PointPlaneDistance(Leaf.FCachedBSphere.Center,
      FLocation, FNormal) - Leaf.FCachedBSphere.Radius);

    // Correct the node location
    if CurrentPenetrationDepth > 0 then
      FQueryResult.Add(Leaves[I]);
  end; // }

  Result := FQueryResult.Count;
end;

{ TSectorNode }

function TSectorNode.AABBFitsInNode(const AAABB: TAABB): Boolean;
begin
  Result := ContainsAABB(AAABB) in [ScContainsFully];
end;

function TSectorNode.AABBIntersectsNode(const AAABB: TAABB): Boolean;
begin
  Result := ContainsAABB(AAABB) in [ScContainsPartially, ScContainsFully];
end;

procedure TSectorNode.AddAllLeavesRecursive(const QueryResult
  : TSpacePartitionLeafList);
var
  I: Integer;
begin
  for I := 0 to FLeaves.Count - 1 do
    QueryResult.Add(FLEaves[I]);

  for I := 0 to FChildCount - 1 do
    FChildren[I].AddAllLeavesRecursive(QueryResult);
end;

function TSectorNode.AddLeaf(ALeaf: TSpacePartitionLeaf): TSectorNode;
begin
  // Time to grow the node?
  if NoChildren and (FLeaves.Count >= FSectoredSpacePartition.FLeafThreshold)
    and (FNodeDepth < FSectoredSpacePartition.FMaxTreeDepth) then
  begin
    ExpandNode;
  end;

  Inc(FRecursiveLeafCount);

  if NoChildren then
  begin
    FLeaves.Add(ALeaf);
    ChildrenChanged;
    ALeaf.FPartitionTag := Self;
    Result := Self;
  end
  else
  begin
    // Does it fit completely in any of the children?
    Result := PlaceLeafInChild(ALeaf);
  end;
end;

function TSectorNode.BSphereFitsInNode(const BSphere: TBSphere): Boolean;
begin
  Result := ContainsBSphere(BSphere) in [ScContainsFully];
end;

function TSectorNode.BSphereIntersectsNode(const BSphere: TBSphere): Boolean;
begin
  Result := ContainsBSphere(BSphere) in [ScContainsPartially, ScContainsFully];
end;

function TSectorNode.CalcRecursiveLeafCount: Integer;
var
  I: Integer;
begin
  Result := FLeaves.Count;

  for I := 0 to FChildCount - 1 do
    Result := Result + FChildren[I].CalcRecursiveLeafCount;
end;

procedure TSectorNode.Clear;
var
  I: Integer;
begin
  for I := 0 to FChildCount - 1 do
    FreeAndNil(FChildren[I]);

  FChildCount := 0;

  FLeaves.Clear;
end;

constructor TSectorNode.Create(ASectoredSpacePartition: TSectoredSpacePartition;
  AParent: TSectorNode);
begin
  FLeaves := TSpacePartitionLeafList.Create;
  FChildCount := 0;
  FParent := AParent;
  FSectoredSpacePartition := ASectoredSpacePartition;

  if AParent = nil then
    FNodeDepth := 0
  else
    FNodeDepth := AParent.FNodeDepth + 1;
end;

procedure TSectorNode.ExpandNode;
var
  I: Integer;
  OldLeaves: TSpacePartitionLeafList;

begin
  CreateChildren;

  // The children have been added, now move all leaves to the children - if
  // we can
  OldLeaves := FLeaves;
  try
    FLeaves := TSpacePartitionLeafList.Create;
    for I := 0 to OldLeaves.Count - 1 do
      PlaceLeafInChild(OldLeaves[I]);
  finally
    OldLeaves.Free;
  end;
end;

procedure TSectorNode.CollapseNode;
var
  I, J: Integer;
begin
  for I := 0 to FChildCount - 1 do
  begin
    FChildren[I].CollapseNode;

    for J := 0 to FChildren[I].FLeaves.Count - 1 do
    begin
      FChildren[I].FLeaves[J].FPartitionTag := Self;
      FLeaves.Add(FChildren[I].FLeaves[J]);
    end;

    FChildren[I].FLeaves.Clear;

    FreeAndNil(FChildren[I]);
  end;

  FChildCount := 0;
end;

destructor TSectorNode.Destroy;
begin
  Clear;
  FreeAndNil(FLeaves);
  inherited;
end;

function TSectorNode.GetNoChildren: Boolean;
begin
  Result := FChildCount = 0;
end;

function TSectorNode.GetNodeCount: Integer;
var
  I: Integer;
begin
  Result := 1;

  for I := 0 to FChildCount - 1 do
    Result := Result + FChildren[I].GetNodeCount;
end;

function TSectorNode.PlaceLeafInChild(ALeaf: TSpacePartitionLeaf): TSectorNode;
var
  ChildNode: TSectorNode;
begin
  // Which child does it fit in?
  ChildNode := GetChildForAABB(ALeaf.FCachedAABB);

  if ChildNode <> nil then
  begin
    Result := ChildNode.AddLeaf(ALeaf);
    Exit;
  end; // }

  // Doesn't fit the any child
  ALeaf.FPartitionTag := Self;
  FLeaves.Add(ALeaf);
  ChildrenChanged;
  Result := Self;
end;

procedure TSectorNode.QueryAABB(const AAABB: TAABB;
  const QueryResult: TSpacePartitionLeafList);
var
  I: Integer;
  SpaceContains: TSpaceContains;
begin
  Inc(FSectoredSpacePartition.FQueryNodeTests);

  SpaceContains := AABBContainsSector(AAABB);

  if SpaceContains = ScContainsFully then
  begin
    AddAllLeavesRecursive(QueryResult);
  end
  else if SpaceContains = ScContainsPartially then
  begin
    // Add all leaves that overlap
    if FSectoredSpacePartition.CullingMode = CmFineCulling then
    begin
      for I := 0 to FLeaves.Count - 1 do
      begin
        Inc(FSectoredSpacePartition.FQueryInterObjectTests);

        if IntersectAABBsAbsolute(FLeaves[I].FCachedAABB, AAABB) then
          QueryResult.Add(FLeaves[I]);
      end;
    end
    else
    begin
      for I := 0 to FLeaves.Count - 1 do
        QueryResult.Add(FLeaves[I]);
    end;

    // Recursively let the children add their leaves
    for I := 0 to FChildCount - 1 do
      FChildren[I].QueryAABB(AAABB, QueryResult);
  end;
end;

procedure TSectorNode.QueryBSphere(const ABSphere: TBSphere;
  const QueryResult: TSpacePartitionLeafList);
var
  I: Integer;
  SpaceContains: TSpaceContains;
begin
  Inc(FSectoredSpacePartition.FQueryNodeTests);

  SpaceContains := BSphereContainsSector(ABSphere);

  if SpaceContains = ScContainsFully then
  begin
    AddAllLeavesRecursive(QueryResult);
  end
  else if SpaceContains = ScContainsPartially then
  begin
    // Add all leaves that overlap
    if FSectoredSpacePartition.CullingMode = CmFineCulling then
    begin
      for I := 0 to FLeaves.Count - 1 do
      begin
        Inc(FSectoredSpacePartition.FQueryInterObjectTests);
        if BSphereContainsAABB(ABSphere, FLeaves[I].FCachedAABB) <> ScNoOverlap
        then
          QueryResult.Add(FLeaves[I]);
      end;
    end
    else
      for I := 0 to FLeaves.Count - 1 do
        QueryResult.Add(FLeaves[I]);

    // Recursively let the children add their leaves
    for I := 0 to FChildCount - 1 do
      FChildren[I].QueryBSphere(ABSphere, QueryResult);
  end;
end;

procedure TSectorNode.QueryPlane(const Location, Normal: TAffineVector;
  const QueryResult: TSpacePartitionLeafList);
var
  I: Integer;
  SpaceContains: TSpaceContains;
begin
  Inc(FSectoredSpacePartition.FQueryNodeTests);

  SpaceContains := PlaneContainsBSphere(Location, Normal, FBSphere);

  if SpaceContains = ScContainsFully then
  begin
    AddAllLeavesRecursive(QueryResult);
  end
  else if SpaceContains = ScContainsPartially then
  begin
    // Add all leaves that overlap
    if FSectoredSpacePartition.CullingMode = CmFineCulling then
    begin
      for I := 0 to FLeaves.Count - 1 do
        if PlaneContainsBSphere(Location, Normal, FLeaves[I].FCachedBSphere) <> ScNoOverlap
        then
          QueryResult.Add(FLeaves[I]);
    end
    else
      for I := 0 to FLeaves.Count - 1 do
        QueryResult.Add(FLeaves[I]);

    // Recursively let the children add their leaves
    for I := 0 to FChildCount - 1 do
    begin
      Inc(FSectoredSpacePartition.FQueryInterObjectTests);

      FChildren[I].QueryPlane(Location, Normal, QueryResult);
    end;
  end; // }
end;

function TSectorNode.RemoveLeaf(ALeaf: TSpacePartitionLeaf;
  OwnerByThis: Boolean): Boolean;
begin
  Result := False;
  Dec(FRecursiveLeafCount);

  if OwnerByThis then
  begin
    ALeaf.FPartitionTag := nil;
    FLeaves.Remove(ALeaf);
    ChildrenChanged;
  end;

  // If there aren't enough leaves anymore, it's time to remove the node!
  if not NoChildren and
    (FRecursiveLeafCount + 1 < FSectoredSpacePartition.FLeafThreshold) then
  begin
    CollapseNode;
    Result := True;
  end;

  if Parent <> nil then
    Parent.RemoveLeaf(ALeaf, False);
end;

function TSectorNode.VerifyRecursiveLeafCount: string;
var
  I: Integer;
begin
  if FRecursiveLeafCount <> CalcRecursiveLeafCount then
  begin
    Result := Format('Node at depth %d mismatches, %d<>%d!',
      [FNodeDepth, FRecursiveLeafCount, CalcRecursiveLeafCount]);
    Exit;
  end;

  for I := 0 to FChildCount - 1 do
  begin
    Result := FChildren[I].VerifyRecursiveLeafCount;
    if Result <> '' then
      Exit;
  end;
end;

procedure TSectorNode.CreateChildren;
begin
  Assert(False, 'You must override CreateChildren!');
end;

function TSectorNode.AABBContainsSector(const AABB: TAABB): TSpaceContains;
begin
  Result := AABBContainsAABB(AABB, FAABB);
end;

function TSectorNode.BSphereContainsSector(const BSphere: TBSphere)
  : TSpaceContains;
begin
  Result := BSphereContainsAABB(BSphere, FAABB);
end;

function TSectorNode.ContainsAABB(const AAABB: TAABB): TSpaceContains;
begin
  Result := AABBContainsAABB(FAABB, AAABB);
end;

function TSectorNode.ContainsBSphere(const ABSphere: TBSphere): TSpaceContains;
begin
  Result := AABBContainsBSphere(FAABB, ABSphere);
end;

procedure TSectorNode.SetAABB(const Value: TAABB);
begin
  FAABB := Value;

  AABBToBSphere(FAABB, FBSphere);
end;

function TSectorNode.GetChildForAABB(AABB: TAABB): TSectorNode;
var
  Location: TAffineVector;
  ChildNode: TSectorNode;
  ChildNodeIndex: Integer;
begin
  Assert(FChildCount > 0, 'There are no children in this node!');
  // Instead of looping through all children, we simply determine on which
  // side of the center node the child is located
  ChildNodeIndex := 0;

  Location := AABB.Min;

  // Upper / Lower
  if Location.Y < FBSphere.Center.Y then
    ChildNodeIndex := 4;

  // Left / Right
  if Location.Z < FBSphere.Center.Z then
    ChildNodeIndex := ChildNodeIndex or 2;

  // Fore / Back
  if Location.X > FBSphere.Center.X then
    ChildNodeIndex := ChildNodeIndex or 1;

  Assert((ChildNodeIndex >= 0) and (ChildNodeIndex <= 8),
    Format('ChildNodeIndex is out of range (%d)!', [ChildNodeIndex]));

  ChildNode := FChildren[ChildNodeIndex];

  Assert(Assigned(ChildNode), 'ChildNode not assigned');

  if ChildNode.AABBFitsInNode(AABB) then
    Result := ChildNode
  else
    Result := nil;
end;

function TSectorNode.GetCenter: TAffineVector;
begin
  Result := FBSphere.Center;
end;

procedure TSectorNode.QueryFrustum(const Frustum: TFrustum;
  const QueryResult: TSpacePartitionLeafList);
var
  SpaceContains: TSpaceContains;
  I: Integer;
begin
  Inc(FSectoredSpacePartition.FQueryNodeTests);

  // Check if the frustum contains the bsphere of the node
  if not IsVolumeClipped(BSphere.Center, BSphere.Radius, Frustum) then
    SpaceContains := FrustumContainsAABB(Frustum, AABB)
  else
    SpaceContains := ScNoOverlap;

  // If the frustum fully contains the leaf, then we need not check every piece,
  // just add them all
  if SpaceContains = ScContainsFully then
  begin
    AddAllLeavesRecursive(QueryResult);
  end
  else

    // If the frustum partiall contains the leaf, then we should add the leaves
    // that intersect the frustum and recurse for all children
    if SpaceContains = ScContainsPartially then
    begin
      for I := 0 to FLeaves.Count - 1 do
      begin
        Inc(FSectoredSpacePartition.FQueryInterObjectTests);

        if not IsVolumeClipped(FLeaves[I].FCachedBSphere.Center,
          FLeaves[I].FCachedBSphere.Radius, Frustum) then
          QueryResult.Add(FLeaves[I]);
      end;

      // Recursively let the children add their leaves
      for I := 0 to FChildCount - 1 do
        FChildren[I].QueryFrustum(Frustum, QueryResult);
    end;
end;

procedure TSectorNode.ChildrenChanged;
begin
  // Do nothing in the basic case
end;

procedure TSectorNode.QueryFrustumEx(const ExtendedFrustum: TExtendedFrustum;
  const QueryResult: TSpacePartitionLeafList);
var
  SpaceContains: TSpaceContains;
  I: Integer;
begin
  Inc(FSectoredSpacePartition.FQueryNodeTests);

  // Does the extended frustum intersect the bsphere at all?
  if not ExtendedFrustumIntersectsBSphere(ExtendedFrustum, BSphere) then
    SpaceContains := ScNoOverlap

  else
    // Test if the bounding frustum intersects the AABB of the node
    SpaceContains := FrustumContainsAABB(ExtendedFrustum.Frustum, AABB); // }

  // If the frustum fully contains the leaf, then we need not check every piece,
  // just add them all
  if SpaceContains = ScContainsFully then
  begin
    AddAllLeavesRecursive(QueryResult);
  end
  else

    // If the frustum partially contains the leaf, then we should add the leaves
    // that intersect the frustum and recurse for all children
    if SpaceContains = ScContainsPartially then
    begin
      for I := 0 to FLeaves.Count - 1 do
      begin
        // Early out 1
        if not BSphereIntersectsBSphere(FLeaves[I].FCachedBSphere,
          ExtendedFrustum.BSphere) then
          Continue;

        Inc(FSectoredSpacePartition.FQueryInterObjectTests);

        if not IsVolumeClipped(FLeaves[I].FCachedBSphere.Center,
          FLeaves[I].FCachedBSphere.Radius, ExtendedFrustum.Frustum) then
          QueryResult.Add(FLeaves[I]);
      end;

      // Recursively let the children add their leaves
      for I := 0 to FChildCount - 1 do
        FChildren[I].QueryFrustumEx(ExtendedFrustum, QueryResult);
    end;
end;

{ TSectoredSpacePartition }

procedure TSectoredSpacePartition.AddLeaf(ALeaf: TSpacePartitionLeaf);
begin
  inherited;
  FRootNode.AddLeaf(ALeaf);

  if not FRootNode.AABBFitsInNode(ALeaf.FCachedAABB) then
  begin
    if FGrowMethod in [gmBestFit, gmIncreaseToFitAll] then
      UpdateStructureSize(GrowGravy)
    else
      Assert(False, 'Node is outside Octree!');
  end;
end;

procedure TSectoredSpacePartition.Clear;
begin
  inherited Clear;
  if Assigned(FRootNode) then
    FRootNode.Clear;
end;

constructor TSectoredSpacePartition.Create;
begin
  FLeafThreshold := COctree_LEAF_TRHESHOLD;
  FMaxTreeDepth := COctree_MAX_TREE_DEPTH;

  FRootNode := CreateNewNode(nil);
  FGrowMethod := gmIncreaseToFitAll;

  FGrowGravy := COctree_GROW_GRAVY;

  inherited Create;
end;

function TSectoredSpacePartition.CreateNewNode(AParent: TSectorNode)
  : TSectorNode;
begin
  Result := TSectorNode.Create(Self, AParent);
end;

destructor TSectoredSpacePartition.Destroy;
begin
  inherited Destroy;
  FRootNode.Free;
end;

function TSectoredSpacePartition.GetAABB: TAABB;
var
  I: Integer;
begin
  if FLeaves.Count = 0 then
  begin
    MakeVector(Result.Min, 0, 0, 0);
    MakeVector(Result.Max, 0, 0, 0);
  end
  else
  begin
    Result := FLeaves[0].FCachedAABB;

    for I := 1 to FLeaves.Count - 1 do
      AddAABB(Result, FLeaves[I].FCachedAABB);
  end;
end;

function TSectoredSpacePartition.GetNodeCount: Integer;
begin
  Result := FRootNode.GetNodeCount;
end;

procedure TSectoredSpacePartition.LeafChanged(ALeaf: TSpacePartitionLeaf);
var
  Node: TSectorNode;
begin
  // If the leaf still fits in the old node, leave it there - or in one of the
  // children
  Node := TSectorNode(ALeaf.FPartitionTag);

  Assert(Node <> nil, 'No leaf node could be found!');

  if Node.AABBFitsInNode(ALeaf.FCachedAABB) then
  begin
    // If the node has children, try to add the leaf to them - otherwise just
    // leave it!
    if Node.FChildCount > 0 then
    begin
      Node.FLeaves.Remove(ALeaf);
      Node.PlaceLeafInChild(ALeaf);
      Node.ChildrenChanged;
    end;
  end
  else
  begin
    Node.RemoveLeaf(ALeaf, True);

    // Does this leaf still fit in the Octree?
    if not FRootNode.AABBFitsInNode(ALeaf.FCachedAABB) then
    begin
      if FGrowMethod in [gmBestFit, gmIncreaseToFitAll] then
        UpdateStructureSize(COctree_GROW_GRAVY)
      else
        Assert(False, 'Node is outside Octree!');
    end
    else
      FRootNode.AddLeaf(ALeaf);
  end;
end;

function TSectoredSpacePartition.QueryAABB(const AAABB: TAABB): Integer;
begin
  FlushQueryResult;
  FRootNode.QueryAABB(AAABB, FQueryResult);
  Result := FQueryResult.Count;
end;

function TSectoredSpacePartition.QueryBSphere(const ABSphere: TBSphere)
  : Integer;
begin
  FlushQueryResult;
  FRootNode.QueryBSphere(ABSphere, FQueryResult);
  Result := FQueryResult.Count;
end;

function TSectoredSpacePartition.QueryPlane(const Location,
  Normal: TAffineVector): Integer;
begin
  FlushQueryResult;
  FRootNode.QueryPlane(Location, Normal, FQueryResult);
  Result := FQueryResult.Count;
end;

function TSectoredSpacePartition.QueryLeaf(const ALeaf
  : TSpacePartitionLeaf): Integer;
var
  I: Integer;
  Node: TSectorNode;
  TestLeaf: TSpacePartitionLeaf;
begin
  // Query current node and all nodes upwards until we find the root, no need
  // to check intersections, because we know that the leaf partially intersects
  // all it's parents.

  Node := TSectorNode(ALeaf.FPartitionTag);
  FlushQueryResult;

  // First, query downwards!
  Node.QueryAABB(ALeaf.FCachedAABB, QueryResult);

  // Now, query parents and upwards!
  Node := Node.Parent;

  while Node <> nil do
  begin
    Inc(FQueryNodeTests);

    // Add all leaves that overlap
    for I := 0 to Node.FLeaves.Count - 1 do
    begin
      TestLeaf := Node.FLeaves[I];
      Inc(FQueryInterObjectTests);
      if IntersectAABBsAbsolute(TestLeaf.FCachedAABB, ALeaf.FCachedAABB) then
        QueryResult.Add(TestLeaf);
    end;

    // Try the parent
    Node := Node.Parent;
  end;

  QueryResult.Remove(ALeaf);

  Result := QueryResult.Count;
end;

procedure TSectoredSpacePartition.RemoveLeaf(ALeaf: TSpacePartitionLeaf);
begin
  inherited;
  TSectorNode(ALeaf.FPartitionTag).RemoveLeaf(ALeaf, True);
end;

procedure TSectoredSpacePartition.SetLeafThreshold(const Value: Integer);
begin
  FLeafThreshold := Value;
end;

procedure TSectoredSpacePartition.SetMaxTreeDepth(const Value: Integer);
begin
  FMaxTreeDepth := Value;
end;

procedure TSectoredSpacePartition.RebuildTree(const NewAABB: TAABB);
var
  I: Integer;
  OldLeaves: TSpacePartitionLeafList;
  TempGrowMethod: TGrowMethod;
begin
  // Delete ALL nodes in the tree
  FRootNode.Free;

  FRootNode := CreateNewNode(nil);
  FRootNode.AABB := NewAABB;

  // Insert all nodes again
  OldLeaves := FLeaves;
  FLeaves := TSpacePartitionLeafList.Create;

  // This will cause an except if the build goes badly, which is better than
  // an infinite loop
  TempGrowMethod := FGrowMethod;

  for I := 0 to OldLeaves.Count - 1 do
    AddLeaf(OldLeaves[I]);

  OldLeaves.Free;
  FGrowMethod := TempGrowMethod;
end;

procedure TSectoredSpacePartition.UpdateStructureSize(Gravy: Single);
var
  MaxAABB, NewAABB: TAABB;
  AABBSize: TAffineVector;
begin
  // Create the new extents for the Octree
  MaxAABB := GetAABB;
  AABBSize := VectorSubtract(MaxAABB.Max, MaxAABB.Min);

  if FGrowMethod = gmBestFit then
  begin
    NewAABB.Min := VectorSubtract(MaxAABB.Min, VectorScale(AABBSize, Gravy));
    NewAABB.Max := VectorAdd(MaxAABB.Max, VectorScale(AABBSize, Gravy)); // }
  end
  else if FGrowMethod = gmIncreaseToFitAll then
  begin
    NewAABB.Min := VectorSubtract(MaxAABB.Min, VectorScale(AABBSize, Gravy));
    NewAABB.Max := VectorAdd(MaxAABB.Max, VectorScale(AABBSize, Gravy)); // }

    AddAABB(NewAABB, FRootNode.AABB);
  end;

  RebuildTree(NewAABB);
end;

procedure TSectoredSpacePartition.FlushQueryResult;
begin
  inherited;

  FQueryNodeTests := 0;
end;

function TSectoredSpacePartition.QueryFrustum(const Frustum: TFrustum): Integer;
begin
  FlushQueryResult;
  FRootNode.QueryFrustum(Frustum, FQueryResult);
  Result := FQueryResult.Count;
end;

function TSectoredSpacePartition.QueryFrustumEx(const ExtendedFrustum
  : TExtendedFrustum): Integer;
begin
  FlushQueryResult;
  FRootNode.QueryFrustumEx(ExtendedFrustum, FQueryResult);
  Result := FQueryResult.Count;
end;

{ TSPOctreeNode }

function TSPOctreeNode.AABBFitsInNode(const AAABB: TAABB): Boolean;
begin
  // Faster than inherited method
  Result := AABBFitsInAABBAbsolute(AAABB, FAABB);
end;

function TSPOctreeNode.AABBIntersectsNode(const AAABB: TAABB): Boolean;
begin
  // Faster than inherited method
  Result := IntersectAABBsAbsolute(FAABB, AAABB);
end;

function TSPOctreeNode.BSphereFitsInNode(const BSphere: TBSphere): Boolean;
var
  AABB: TAABB;
begin
  // Faster than inherited method
  BSphereToAABB(BSphere, AABB);
  Result := AABBFitsInAABBAbsolute(AABB, FAABB); // }
end;

function TSPOctreeNode.BSphereIntersectsNode(const BSphere: TBSphere): Boolean;
var
  AABB: TAABB;
begin
  // Faster than inherited method
  BSphereToAABB(BSphere, AABB);
  Result := IntersectAABBsAbsolute(AABB, FAABB); // }
end;

procedure TSPOctreeNode.CreateChildren;
var
  I: Integer;
  AABB: TAABB;
  function GetExtent(const Flags: array of Byte): TAffineVector;
  var
    N: Integer;
  begin
    for N := 0 to 2 do
    begin
      case Flags[N] of
        CMIN:
          Result.V[N] := FAABB.Min.V[N];
        CMID:
          Result.V[N] := (FAABB.Max.V[N] + FAABB.Min.V[N]) / 2;
        CMAX:
          Result.V[N] := FAABB.Max.V[N];
      end;
    end;
  end;

begin
  Assert(FChildCount = 0, 'Children allready exist!');

  for I := 0 to 7 do
  begin
    FChildren[I] := FSectoredSpacePartition.CreateNewNode(Self);

    // Generate new extents based on parent's extents
    AABB.Min := GetExtent(COctFlagMIN[I]);
    AABB.Max := GetExtent(COctFlagMax[I]);
    FChildren[I].AABB := AABB;
  end;

  FChildCount := 8;
end;

{ TOctreeSpacePartition }

function TOctreeSpacePartition.CreateNewNode(AParent: TSectorNode): TSectorNode;
begin
  Result := TSPOctreeNode.Create(Self, AParent);
end;

procedure TOctreeSpacePartition.SetSize(const Min, Max: TAffineVector);
var
  AABB: TAABB;
begin
  AABB.Min := Min;
  AABB.Max := Max;

  RebuildTree(AABB);
end;

{ TSPQuadtreeNode }

function TSPQuadtreeNode.AABBFitsInNode(const AAABB: TAABB): Boolean;
begin
  Result := (AAABB.Min.X >= FAABB.Min.X) and
    (AAABB.Min.Z >= FAABB.Min.Z) and
    (AAABB.Max.X <= FAABB.Max.X) and
    (AAABB.Max.Z <= FAABB.Max.Z);
end;

function TSPQuadtreeNode.AABBIntersectsNode(const AAABB: TAABB): Boolean;
begin
  Assert(False, Format('AABBIntersectsNode not implemented on %s',
    [ClassName]));
  Result := False;
end;

function TSPQuadtreeNode.BSphereFitsInNode(const BSphere: TBSphere): Boolean;
begin
  Assert(False, Format('BSphereFitsInNode not implemented on %s', [ClassName]));
  Result := False;
end;

function TSPQuadtreeNode.BSphereIntersectsNode(const BSphere: TBSphere)
  : Boolean;
begin
  Assert(False, Format('BSphereIntersectsNode not implemented on %s',
    [ClassName]));
  Result := False;
end;

procedure TSPQuadtreeNode.ChildrenChanged;
var
  I: Integer;
  NewMin, NewMax: Single;
begin
  inherited;

  // Establish a baseline
  if Leaves.Count > 0 then
  begin
    NewMin := Leaves[0].FCachedAABB.Min.Y;
    NewMax := Leaves[0].FCachedAABB.Max.Y;
  end
  else

    if FChildCount > 0 then
  begin
    NewMin := FChildren[0].AABB.Min.Y;
    NewMax := FChildren[0].AABB.Max.Y;
  end
  else
  begin
    // This should never happen!
    NewMin := 1E9;
    NewMax := -1E9;
  end;

  for I := 0 to Leaves.Count - 1 do
  begin
    NewMin := Min(NewMin, Leaves[I].FCachedAABB.Min.Y);
    NewMax := Max(NewMax, Leaves[I].FCachedAABB.Max.Y);
  end;

  for I := 0 to FChildCount - 1 do
  begin
    NewMin := Min(NewMin, FChildren[I].AABB.Min.Y);
    NewMax := Max(NewMax, FChildren[I].AABB.Max.Y);
  end;

  if (AABB.Max.Y <> NewMax) and (AABB.Min.Y <> NewMin) then
  begin
    FAABB.Max.Y := NewMax;
    FAABB.Min.Y := NewMin;

    // Make sure the parent updates it's bounds as well
    if Assigned(Parent) then
      Parent.ChildrenChanged; // }
  end;
end;

procedure TSPQuadtreeNode.CreateChildren;
var
  ChildNodeIndex: Integer;
  AABB: TAABB;
  X, Z: Integer;
begin
  for ChildNodeIndex := 0 to 3 do
  begin
    FChildren[ChildNodeIndex] := FSectoredSpacePartition.CreateNewNode(Self);

    // Y is ignored so it's set to a very large number
    AABB.Min.Y := FAABB.Min.Y;
    AABB.Max.Y := FAABB.Max.Y;

    // Generate new extents based on parent's extents
    if ((ChildNodeIndex and 1) > 0) then
      X := 1
    else
      X := 0;
    if ((ChildNodeIndex and 2) > 0) then
      Z := 1
    else
      Z := 0;

    if X = 0 then
    begin
      AABB.Min.X := FAABB.Min.X + (FAABB.Max.X + FAABB.Min.X) / 2 * X;
      AABB.Max.X := (FAABB.Max.X + FAABB.Min.X) / 2 * (1 + X);
    end
    else
    begin
      AABB.Min.X := (FAABB.Max.X + FAABB.Min.X) / 2;
      AABB.Max.X := FAABB.Max.X;
    end;

    if Z = 0 then
    begin
      AABB.Min.Z := FAABB.Min.Z;
      AABB.Max.Z := (FAABB.Max.Z + FAABB.Min.Z) / 2;
    end
    else
    begin
      AABB.Min.Z := (FAABB.Max.Z + FAABB.Min.Z) / 2;
      AABB.Max.Z := FAABB.Max.Z;
    end;

    FChildren[ChildNodeIndex].AABB := AABB;
  end;

  FChildCount := 4;
end;

function TSPQuadtreeNode.GetChildForAABB(AABB: TAABB): TSectorNode;
var
  Location: TAffineVector;
  ChildNode: TSectorNode;
  ChildNodeIndex: Integer;
begin
  // Instead of looping through all children, we simply determine on which
  // side of the center node the child is located
  ChildNodeIndex := 0;

  Location := AABB.Min;

  // Fore / Back
  if Location.X > FBSphere.Center.X then
    ChildNodeIndex := ChildNodeIndex or 1;

  // Left / Right
  if Location.Z > FBSphere.Center.Z then
    ChildNodeIndex := ChildNodeIndex or 2;

  Assert(ChildNodeIndex < ChildCount, 'Bad ChildNodeIndex!');
  ChildNode := FChildren[ChildNodeIndex];

  if ChildNode.AABBFitsInNode(AABB) then
  begin
    Result := ChildNode;
    Exit;
  end;

  Result := nil;
end;

{ TQuadtreeSpacePartition }

function TQuadtreeSpacePartition.CreateNewNode(AParent: TSectorNode)
  : TSectorNode;
begin
  Result := TSPQuadtreeNode.Create(Self, AParent);
end;

procedure TQuadtreeSpacePartition.SetSize(const Min, Max: TAffineVector);
var
  AABB: TAABB;
begin
  AABB.Min := Min;
  AABB.Max := Max;

  RebuildTree(AABB);
end;

end.
