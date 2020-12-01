#include "moduleFS.hpp"
#include <iostream>

/* FastSearch: constructor, it inizializes the indices and set a default int max_neighbors
*@param none
*@return nothing*/
FastSearch::FastSearch()
{
    FastSearch(10);
}

/*FastSearch: constructor, it initializes the indices and set a int max_neighbors
*@param int neighbors 
*@return nothing*/
FastSearch::FastSearch(int neighbors)
{
    max_neighbors = neighbors;
    indices = new cv::Mat(1, max_neighbors, CV_32S);
    distances = new cv::Mat_<float>(1, max_neighbors, CV_32S);
}


cv::Mat FastSearch::searchIndex(cv::Mat query)
{
    matIndex->knnSearch(query.t(), *indices, *distances, max_neighbors, cvflann::SearchParams());
    return *indices;
}

