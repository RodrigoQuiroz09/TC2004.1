#include <opencv2/opencv.hpp>
#include <opencv2/flann.hpp>
    class FastSearch{
        public:
            FastSearch(){
                max_neighbors=10;
                cv::Mat indices(1,max_neighbors,CV_32S);
                cv::Mat_<float> distances(1,max_neighbors,CV_32S);
            }
            FastSearch(int max_neighbors){
                this->max_neighbors=max_neighbors;
                cv::Mat indices(1,max_neighbors,CV_32S);
                cv::Mat_<float> distances(1,max_neighbors,CV_32S);
            }
            int max_neighbors;
            void loadUsers(std::map<std::string, Subject> users);
            void getIndex(cv::Mat matToIndex);
            cv::Mat search(cv::Mat query);
            cv::Mat allFeatures;
            // cv::flann::GenericIndex<cvflann::L2<float>> index(cv::Mat allFeatures,cvflann::KDTreeIndexParams());
            
    };