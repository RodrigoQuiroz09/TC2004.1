#ifndef __MODULEFS_HPP__
#define __MODULEFS_HPP__

#include <opencv2/opencv.hpp>
#include <opencv2/flann.hpp>
#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
class FastSearch
{
private:
    cv::Mat *indices;
    cv::Mat *distances;
    int max_neighbors;

public:
    FastSearch();
    FastSearch(int max_neighbors);
    cv::Mat searchIndex(Persistence persistence, cv::Mat query);
    void printResults(Persistence persistance);
};

#endif