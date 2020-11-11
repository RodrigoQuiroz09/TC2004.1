#include <opencv2/opencv.hpp>
#include <opencv2/flann.hpp>
#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
#include <string>
class FastSearch
{
private:
    

public:
    FastSearch()
    {
        Persistence newClient;
        max_neighbors = 10;
        cv::Mat indices(1, max_neighbors, CV_32S);
        cv::Mat_<float> distances(1, max_neighbors, CV_32S);
    }

    FastSearch(int max_neighbors)
    {
        cv::flann::GenericIndex<cvflann::L2<float>> index(cv::Mat &matToIndex, const::cvflann::IndexParams &params );
        Persistence newClient;
        this->max_neighbors = max_neighbors;
        cv::Mat indices(1, max_neighbors, CV_32S);
        cv::Mat_<float> distances(1, max_neighbors, CV_32S);

    }
    int max_neighbors;
    std::string key;
    void loadUsers(std::map<std::string, Subject> users);
    void getIndex(cv::Mat matToIndex);
    void getMatches();
    cv::Mat search(cv::Mat query);
    cv::Mat allFeatures;
};