#include "../Face_Alignment/src/facealignmentM2.hpp"
#include "../Face_Detection/src/FaceDetector.hpp"
#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
#include "../Feature_Extraction/source/moduleFE.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
#include <tuple>


class FaceRecognitionSystem{
    private:
        FaceDetector faceDetector;
        Facealignment faceAlignment;
        FeatureExtraction featureExtraction;
        Persistence persistence;
        
    public:
        /* Constructor y Destructor */
        FaceRecognitionSystem();
        ~FaceRecognitionSystem();

        /* Method that registers a person in the database and prepares values for their identification
        * @param clientId: id that belongs to the person
        * @param clientName: the name of the person
        * @param clientCareer: the career of the person
        * @param clientEmail: the email of the person
        * @param clientStudent: if the person is a student or not
        * @param faceMat: image of the person 
        */
        void addPerson(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat);

        /* Method that verifies if the ID holder is present in the image
        * @param image:image to be verified 
        * @param id: the id that belongs to the person in the image
        * @return: the person in the image is indeed the id holder or not 
        */
        bool personVerification(cv::Mat image,std::string id);

        /* Method that looks for a number of 10 people with similar characteristics to the one in the image.
        * @param mat: image that contains the person to be identied
        * @return:vector of a maximum number of 10 people with similar characteristics to the one in the image and their ID
        */
        std::vector<std::tuple<cv::Mat,std::string>> personIdentification(cv::Mat mat);

        /* Method that identifies rectangle within an image in which a face is detected
        * @param image: image to be analyzed
        * @return: rectangle where the face was identified 
        */
        cv::Rect faceRect(cv::Mat image)


}