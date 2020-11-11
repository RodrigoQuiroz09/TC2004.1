#include "moduleFS.hpp"
#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"
#include <opencv2/flann.hpp>
cv::flann::GenericIndex<cvflann::L2<float>> inde(cv::Mat allFeatures,cvflann::KDTreeIndexParams());

void FastSearch::loadUsers(std::map<std::string, Subject> users){
    std::map<std::string, Subject>::iterator itr;
    for (itr = users.begin(); itr != users.end(); ++itr){
        cv::hconcat(allFeatures,itr->second.face,allFeatures);
    }
    allFeatures=allFeatures.t();
}
// void FastSearch::getIndex(cv::Mat matToIndex){

// }
// cv::Mat FastSearch::search(cv::Mat query){
//     inde.k

    
// }