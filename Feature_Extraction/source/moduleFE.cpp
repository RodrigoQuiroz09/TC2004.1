#include <dlib/dnn.h>
#include <dlib/string.h>
#include <dlib/image_processing.h>
#include <opencv2/face.hpp>
#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include "moduleFE.hpp"

FeatureExtraction::FeatureExtraction()
{
    dlib::deserialize("../../Feature_Extraction/source/dlib_face_recognition_resnet_model_v1.dat") >> net;
    // float threshold = .6;
}

/* Mat getFeatures: detects image, divides it and stores it into a Mat. It also asks the DNN to convert each face image in faces into a 128D vector.
* @param Mat frame
* @return Mat with landmark values
*/
cv::Mat FeatureExtraction::getFeatures(cv::Mat frame)
{
    try
    {
        cvtColor(frame, frame, CV_BGR2RGB);

        cv::resize(frame, frame, cv::Size(150, 150), 0, 0, cv::INTER_AREA);

        assign_image(face, dlib::cv_image<dlib::rgb_pixel>(frame));

        faces.push_back(std::move(face));

        dlib_vector = dlib::mean(mat(this->net(faces)));

        featuresVector = dlib::toMat(dlib_vector).clone();

        return featuresVector;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return featuresVector;
}

/* int comparison: gets Euclidean distanceance between the Mat of each image we are comparing 
* @param Mat firstface, secondface
* @return 0 or 1 depending if it's a match or not
*/
int FeatureExtraction::comparison(cv::Mat firstface, cv::Mat secondface)
{
    distance = norm(firstface, secondface, cv::NORM_L2);
    //std::cout << "distance : " << distance << std::endl;
    if (distance <= threshold)
    {
        //puts("Its a match!");
        return 1;
    }
    else
    {
       // puts("Not a match");
        return 0;
    }
}

/* int comparison: gets Euclidean distanceance between the Mat of each image we are comparing (in case of changing the threshold)
* @param Mat firstface, secondface, float threshold
* @return 0 or 1 depending if it's a match or not
*/
int FeatureExtraction::comparison(cv::Mat firstface, cv::Mat secondface, float threshold)
{
    distance = norm(firstface, secondface, cv::NORM_L2);
    //std::cout << "distance : " << distance << std::endl;
    if (distance <= threshold)
    {
        //puts("Its a match!");
        return 1;
    }
    else
    {
        //puts("Not a match");
        return 0;
    }
}
