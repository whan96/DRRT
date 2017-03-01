#include <DRRT/drrt.h>
#include <DRRT/visualizer.h>

using namespace std;

/// VISUALIZER FUNCTION
void visualizer(shared_ptr<KDTree> Tree,
                shared_ptr<RobotData> Robot)
{
    int resX = 800, resY = 600, ticks = 100;
    double spacing = 1.0; // straighttest:1.0 smalltest:1.0 largetest:5.0
    double dist = 10; // straighttest:10 smalltest:10 largetest:20
    double fov = 420;

    /// Build display
    // Create OpenGL window
    pangolin::CreateWindowAndBind("RRTx",resX,resY);
    SceneGraph::GLSceneGraph::ApplyPreferredGlSettings();

    // Scenegraph to hold GLObjects and relative transformations
    SceneGraph::GLSceneGraph glGraph;

    // Define grid object
    SceneGraph::GLGrid glGrid(ticks,spacing,true);
    glGraph.AddChild(&glGrid);

    // Define axis object
    SceneGraph::GLAxis glAxis;
    glAxis.SetPose(0,0,0,0,0,0);
    glGraph.AddChild(&glAxis);

    // Draw any-angle best path
    SceneGraph::GLLineStrip path;
    path.SetReference(0,0,0);
    for( int i = 0; i < Robot->best_any_angle_path.size(); i++) {
        path.SetPoint(Robot->best_any_angle_path.at(i)(0),
                      Robot->best_any_angle_path.at(i)(1),
                      0);
    }
    glGraph.AddChild(&path);

    // Define camera render object
    pangolin::OpenGlRenderState stacks3d(
                pangolin::ProjectionMatrix(resX,resY,fov,fov,resX/2,resY/2,
                                           0.1,1000),
                pangolin::ModelViewLookAt(-dist,-dist,-dist, 0,0,0,
                                          pangolin::AxisNegZ));

    // Define view for base container
    pangolin::View view3d;

    // Set view location on screen and add handler for updating of model view
    // matrix (stacks3d)
    view3d.SetBounds(0.0,1.0,0.0,1.0,(float)resX/(float)resY)
            .SetHandler(new SceneGraph::HandlerSceneGraph(
                            glGraph,stacks3d,pangolin::AxisNegZ))
            .SetDrawFunction(SceneGraph::ActivateDrawFunctor(
                                 glGraph,stacks3d));

    // Add view to base container as child
    pangolin::DisplayBase().AddDisplay(view3d);

    // For the K-D Tree nodes
    vector<shared_ptr<KDTreeNode>> nodes;
    Eigen::VectorXd kdnode;
    SceneGraph::GLBox* box;
    SceneGraph::GLAxis* axis;

    // For robot poses
    vector<Eigen::VectorXd> poses;
    SceneGraph::GLAxis* pose;
    Eigen::VectorXd current_pose;

    // Default hook for exiting: Esc
    // Default hook for fullscreen: tab
    while( !pangolin::ShouldQuit() ) {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor4f(1.0f,1.0f,1.0f,1.0f);

        // Add K-D Tree nodes to the frame
        {
            lock_guard<mutex> lock(Tree->treeMutex_);
            nodes = Tree->nodes;
        }
        for( int k = 0; k < nodes.size(); k++ ) {
            box = new SceneGraph::GLBox();
            box->SetScale(0.15);
            box->SetCheckerboard(4);
            axis = new SceneGraph::GLAxis();
            axis->SetAxisSize(0.15);
            axis->AddChild(box);

            kdnode = nodes.at(k)->position;
            axis->SetPose(kdnode(1),kdnode(0),0.0,
                             0.0,0.0,PI/2 - kdnode(2));
            glGraph.AddChild(axis);
            Tree->removeVizNode(nodes.at(k));
        }

        // Update robot pose (x,y,z, r,p,y)
        {
            lock_guard<mutex> lock(Robot->robotMutex_);
            current_pose = Robot->robotPose;
        }
        if( poses.size() == 0 || current_pose != poses.back() ) {
            poses.push_back(current_pose);
            pose = new SceneGraph::GLAxis();
            pose->SetPose(current_pose(1),current_pose(0),0.0,
                          0.0,0.0,PI/2 - current_pose(2));
            glGraph.AddChild(pose);
        }

        // Swap frames and process events
        pangolin::FinishFrame();
    }
    delete(box);
    delete(axis);
    delete(pose);
}
