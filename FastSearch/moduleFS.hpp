#include <opencv2/opencv.hpp>
#include <opencv2/flann.hpp>
#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
class FastSearch
{
private:

public:
    FastSearch();
    FastSearch(int max_neighbors);
    cv::Mat *indices;
    cv::Mat *distances;
    int max_neighbors;
    cv::Mat searchIndex(Persistence persistence,cv::Mat query);
    void printResults(Persistence persistance);
};