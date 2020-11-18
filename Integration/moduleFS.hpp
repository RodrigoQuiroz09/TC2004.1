#include <opencv2/opencv.hpp>
#include <opencv2/flann.hpp>
class FastSearch
{
private:

public:
    FastSearch();
    FastSearch(int max_neighbors);
    cv::Mat *indices;
    cv::Mat *distances;
    int max_neighbors;
};