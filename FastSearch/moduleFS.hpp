#ifndef __MODULEFS_HPP__
#define __MODULEFS_HPP__

#include <opencv2/opencv.hpp>
#include <opencv2/flann.hpp>
class FastSearch
{
private:
    cv::Mat *indices;
    cv::Mat *distances;
    int max_neighbors;

public:
    /*FastSearch: constructor, it inizializes the indices and set a default int max_neighbors
    *@param none
    *@return nothing
    */
    FastSearch();

    /*FastSearch: constructor, it initializes the indices and set a int max_neighbors
    *@param int neighbors 
    *@return nothing
    */
    FastSearch(int max_neighbors);

    /* Mat searchIndex: Creates an index out of the data base searching for the mats that are similar to the query
    *@param matIndex, flann index of a mat
    *@param Mat query, mat to search in the index above
    *@return mat *indices (close)
    */
    cv::Mat searchIndex(cv::flann::GenericIndex<cvflann::L2<float>>* matIndex, cv::Mat query);
};

#endif