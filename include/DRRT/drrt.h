#include <DRRT/data_structures.h>
#include <DRRT/kdtree.h>
#include <DRRT/sampling.h>


typedef struct Problem{
public:
    CSpace_ptr cspace;
    double planning_time;
    double slice_time;
    double saturation_dist;
    double ball_constant;
    double obs_change_thresh;
    double goal_thresh;
    bool drive;
    Eigen::VectorXi wraps;
    Eigen::VectorXd wrap_points;
    int threads;

    Problem(CSpace_ptr cspace_, double planning_time_, double slice_time_,
            double saturation_dist_, double ball_constant_,
            double obs_change_thresh_, double goal_thresh_, bool drive_,
            Eigen::VectorXi wraps_, Eigen::VectorXd wrap_points_,
            int threads_)
        : cspace(cspace_), planning_time(planning_time_),
          slice_time(slice_time_), saturation_dist(saturation_dist_),
          ball_constant(ball_constant_), obs_change_thresh(obs_change_thresh_),
          goal_thresh(goal_thresh_), drive(drive_), wraps(wraps_),
          wrap_points(wrap_points_), threads(threads_)
    {}
} Problem;

// Priority Queue //
void GetHeapNodeFor(Heap_ptr &heap, Kdnode_ptr node, HeapNode_ptr &heap_node_for_kdnode);
void AddToPriorityQueue(CSpace_ptr &cspace, Kdnode_ptr &node);
void AddToOSQueue(CSpace_ptr &cspace, Kdnode_ptr &node);
void UpdateQueue(CSpace_ptr &cspace, Kdnode_ptr &node,
                 Kdnode_ptr &root, double hyper_ball_rad);

// RRTx //
void MakeOutNeighbor(Kdnode_ptr &new_neighbor, Kdnode_ptr &node, Edge_ptr &edge);
void MakeInNeighbor(Kdnode_ptr &new_neighbor, Kdnode_ptr &node, Edge_ptr &edge);
void MakeInitialOutNeighbor(Kdnode_ptr &node, Edge_ptr &edge);
void MakeInitialInNeighbor(Kdnode_ptr &node, Edge_ptr &edge);
void MakeParent(Kdnode_ptr &new_parent, Kdnode_ptr &node, Edge_ptr &edge);

// Initially sets LMC of new_node
void FindBestParent(CSpace_ptr &cspace, KdTree_ptr &tree, Kdnode_ptr &new_node,
                    RangeList_ptr &range_list, Kdnode_ptr &closest_node);

// Sets a new move_target in cspace->robot_ within radius
void FindNewTarget(CSpace_ptr &cspace, KdTree_ptr &tree, double radius);

bool Extend(CSpace_ptr &cspace, KdTree_ptr &tree, Kdnode_ptr &new_node,
            Kdnode_ptr &closest_node, double delta, double hyper_ball_rad);

// Removes members of node's current neighbor list that are > radius
void CullCurrentOutNeighbors(Kdnode_ptr &node, double radius);

// Recalculates LMC of node based on neighbors
void RecalculateLmc(CSpace_ptr &cspace, Kdnode_ptr &node, Kdnode_ptr &root, double radius);

// Propogates changes through the graph
void Rewire(CSpace_ptr &cspace, Kdnode_ptr &node, Kdnode_ptr &root, double radius);

// Propogates cost information through the k-d tree
void ReduceInconsistency(CSpace_ptr &cspace, Kdnode_ptr goal, Kdnode_ptr &root,
                         double robot_rad, double radius);

// Propogates orphan status to all nodes in the basin of attraction of nodes
// in the cspace->obstacle_successors_ stack
void PropogateDescendents(CSpace_ptr &cspace, KdTree_ptr &tree);
