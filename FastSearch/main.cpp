#include "../Feature_Extraction/source/moduleFE.hpp"
#include "moduleFS.hpp"
//#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Run this example by invoking it like this: " << endl;
        cout << "   ./my_project image_path.jpg" << endl;
        cout << endl;
        return 1;
    }
    FeatureExtraction F;
    Mat frame = imread(argv[1]);
    Mat vector1 = F.getFeatures(frame);
    //cout <<vector1<<endl;
    Persistence Pers("algo.yml");
    FastSearch fast;
    fast.searchIndex(Pers,vector1);
    fast.printResults(Pers);
    // Pers.getIndex();
    // Pers.searchIndex(vector1,*fast.indices,*fast.distances,fast.max_neighbors);
    return 0;

}











    //printf("%d",fast.distances->at<int>(0));
    //fast.search(vector1);


     //cout << newClient.features_vector.size << endl;

    // cv::flann::GenericIndex<cvflann::L2<float>> index(newClient.features_vector,cvflann::KDTreeIndexParams());
    // Mat indices(1,fast.max_neighbors,CV_32S);
    // // cout<<"hasta aqui todo bien :) "<<indices.size<<endl;
    // //Mat indices, distances;
    // Mat_<float> distances(1,fast.max_neighbors);

    // index.knnSearch(vector1.t(),indices,distances,fast.max_neighbors,cvflann::SearchParams());
    // cout<<indices.size<<endl;
    // cout<<indices<<endl;
    // cout<<distances<<endl;
    // cout<<indices.at<int>(0)<<endl;
    // puts("La imagen ingresada coincide con: ");
    // for (int i = 0; i < indices.cols; i++)
    // {
    //     string key = "A" + std::to_string(indices.at<int>(i));
    //     cout << newClient.users.find(key)->second.name << " " << newClient.users.find(key)->second.id << endl;
    // }
