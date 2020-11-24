#include "moduleFS.hpp"
#include <iostream>

FastSearch::FastSearch()
{
    FastSearch(10);
}

FastSearch::FastSearch(int neighbors)
{
    max_neighbors = neighbors;
    indices = new cv::Mat(1, max_neighbors, CV_32S);
    distances = new cv::Mat_<float>(1, max_neighbors, CV_32S);
}

cv::Mat FastSearch::searchIndex(cv::flann::GenericIndex<cvflann::L2<float>>* matIndex, cv::Mat query)
{
    matIndex->knnSearch(query.t(), *indices, *distances, max_neighbors, cvflann::SearchParams());
    // puts("Aqui todo bien");
    return *indices;
}

