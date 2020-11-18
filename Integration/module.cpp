#include "moduleFS.hpp"
#include <iostream>
#include <string>
//#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
// void FastSearch::print(Persistence P){
//         for (int i = 0; i < indices->cols; i++)
//     {
//         std::string key = "A" + std::to_string(indices->at<int>(i));
//         std::cout << P.users.find(key)->second.name << " " << P.users.find(key)->second.id <<std::endl;
//     }
// }
// void FastSearch::loadUsers(std::map<std::string, Subject> users)
// {
//     std::map<std::string, Subject>::iterator itr;
//     for (itr = users.begin(); itr != users.end(); ++itr)
//     {
//         cv::hconcat(allFeatures, itr->second.face, allFeatures);
//     }
//     allFeatures = allFeatures.t();
// }
// void FastSearch::getIndex(cv::Mat matToIndex)
// {
//     FastSearch::index(matToIndex, cvflann::KDTreeIndexParams());
// 

// cv::Mat FastSearch::search(cv::Mat query)
// {
//     FastSearch::index->knnSearch(query.t(), FastSearch::indices, distances, max_neigh, cvflann::SearchParams());
// }


// void FastSearch::search(cv::Mat query){
//     P->searchIndex(query,*distances,*indices,max_neighbors);
//     std::cout<<distances->size<<std::endl;
// }




// cv::Mat FastSearch::getdistances(int max_neighbors=10){
//     cv::Mat_<float> distances(1,max_neighbors,CV_32S);
//     return distances;
// }

// void FastSearch::getMatches()
// {
//     for (int i = 0; i < indices.size(); i++)
//     {
//         key = "A" + std::to_string(indices.at<int>(i);
//         cout << newClient.users.find(key)->second.name << " " << newClient.users.find(key)->second.id << endl;
//     }
// }
FastSearch::FastSearch(){
    max_neighbors = 10;
    indices=new cv::Mat(1, max_neighbors, CV_32S);
    distances=new cv::Mat_<float>(1, max_neighbors, CV_32S);
}

FastSearch::FastSearch(int neighbors=10){
    neighbors = max_neighbors;
    indices=new cv::Mat(1, max_neighbors, CV_32S);
    distances=new cv::Mat_<float>(1, max_neighbors, CV_32S);
}