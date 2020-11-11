#include "moduleFS.hpp"
#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"
#include <opencv2/flann.hpp>
#include <iostream>

void FastSearch::loadUsers(std::map<std::string, Subject> users)
{
    std::map<std::string, Subject>::iterator itr;
    for (itr = users.begin(); itr != users.end(); ++itr)
    {
        cv::hconcat(allFeatures, itr->second.face, allFeatures);
    }
    allFeatures = allFeatures.t();
}
void FastSearch::getIndex(cv::Mat matToIndex)
{
    FastSearch::index(matToIndex, cvflann::KDTreeIndexParams());
}
cv::Mat FastSearch::search(cv::Mat query)
{
    FastSearch::index->knnSearch(query.t(), FastSearch::indices, distances, max_neigh, cvflann::SearchParams());
}

// void FastSearch::getMatches()
// {
//     for (int i = 0; i < indices.size(); i++)
//     {
//         key = "A" + std::to_string(indices.at<int>(i);
//         cout << newClient.users.find(key)->second.name << " " << newClient.users.find(key)->second.id << endl;
//     }
// }