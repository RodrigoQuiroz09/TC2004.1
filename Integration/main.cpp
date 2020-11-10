#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
#include "../Feature_Extraction/source/moduleFE.hpp"

#include <opencv2/flann.hpp>


using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Run this example by invoking it like this: " << endl;
        cout << "   ./my_prject image_path.jpg image_path2.jpg" << endl;
        cout << endl;
        return 1;
    }
    FeatureExtraction F;
    Mat frame = imread(argv[1]);
    Mat frame2 = imread(argv[2]);
    Mat vector1 = F.getFeatures(frame);
    Mat vector2 = F.getFeatures(frame2);
   // int result = F.comparison(vector1, vector2);
    Persistence newClient;
    //newClient.registerClient("A6666666", "MAIKOLKORS", "ITC", "a010516f7@itesm.mx", true, vector1);
	//newClient.deleteClient("A1");
	//newClient.writeToDisc();
    //Mat fin=vector1;
    //hconcat(vector1, vector2, fin);
    //fin.push_back(vector2);


     cout << newClient.features_vector.size << endl;
     //cout << vector1 << endl;

    // printf("The result of the module is: %d\n", result);
    // cout << "M = " << endl
    //      << " " << vector1 << endl;
    cv::Mat query;
    //newClient.features_vector.convertTo(query,CV_8U);
    cv::flann::GenericIndex<cvflann::L2<float>> index(newClient.features_vector,cvflann::KDTreeIndexParams());
    int max_neigh=4;
    Mat indices(1,max_neigh,CV_32S);
    // cout<<"hasta aqui todo bien :) "<<indices.size<<endl;
    //Mat indices, distances;
    Mat_<float> distances(1,max_neigh);

    index.knnSearch(vector1.t(),indices,distances,max_neigh,cvflann::SearchParams());
    cout<<indices.size<<endl;
    cout<<indices<<endl;
    cout<<distances<<endl;
    cout<<indices.at<int>(0)<<endl;
    string key="A"+to_string(indices.at<int>(0));
    cout<<newClient.users.find(key)->second.name<<" "<<newClient.users.find(key)->second.id<<endl;


}