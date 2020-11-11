#include <opencv2/opencv.hpp>
#include <opencv2/flann.hpp>
class FastSearch
{
private:

public:
    FastSearch()
    {
        max_neighbors = 10;
        indices=new cv::Mat(1, max_neighbors, CV_32S);
        distances=new cv::Mat_<float>(1, max_neighbors, CV_32S);
    }

    FastSearch(int max_neighbors)
    {
        this->max_neighbors = max_neighbors;
        indices=new cv::Mat(1, max_neighbors, CV_32S);
        distances=new cv::Mat_<float>(1, max_neighbors, CV_32S);
    }
    cv::Mat *indices;
    cv::Mat *distances;
    int max_neighbors;
};