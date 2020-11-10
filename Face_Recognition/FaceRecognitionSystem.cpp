#include "../Face_Alignment/src/facealignmentM2.hpp"
#include "../Face_Detection/src/FaceDetector.hpp"
#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
#include "../Feature_Extraction/source/moduleFE.hpp"
#include <opencv2/opencv.hpp>
#include <
class FaceRecognitionmSystem{
    private:
    FaceDetector faceDetector;
    Facealignment faceAlignment;
	FeatureExtraction featureExtraction;
	FaceRecognitionmSystem faceRecognitionSystem;
    public:
    //add_Person(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat);
	//void registerClient() ---guardar la imagen y el path
    cv::Mat personVerification(cv::Mat image,std::string id)
    {
	cv::VideoCapture cap;
	cv::Mat image;
	cv::Rect rc;
	bool validation;
	if (!cap.open(0))
		std::cout << "WebCam ERROR" << std::endl;

	while (true)
	{
		cap >> image;
		rc = facedetector.detectFace(&image);
        if(!rc.empty())
		{
			validation = facedetector.faceValidation(&image, rc);
			if (validation)
			{
				cv::Mat result=facealignment.facealignment(image, rc);
				cv::imshow("chris",result);
				cv::waitKey(0);
				return result;
			}
			else
			{
				std::cout << "NO hay una cara " << std::endl;
			}
		}
    }

    }
    //std::vector<std::tuple<cv::Mat,std::string>> personIdentification(cv::Mat mat);
	//cv::Rect faceRect(cv::Mat mat)

};
 int main(int argc, char **argv)
 {
	 if (argc != 2)
    {
        std::cout << "Run this example by invoking it like this: " << std::endl;
        std::cout << "   ./my_project image_path.jpg image_path2.jpg" <<std:: endl;
        std::cout << std::endl;
        return 1;
    }
    
	cv::Mat resultt= frs.personVerification("hola");
	cv::Mat result2= frs.personVerification("hola");
    cv::Mat frame2 = cv::imread(argv[1]);//path
	//cv::resize(frame2, frame2, cv::Size(150, 150), 0, 0, cv::INTER_AREA);
    cv::Mat vector1 = F.getFeatures(resultt);
    cv::Mat vector2 = F.getFeatures(result2);
    int result = F.comparison(vector1, vector2,.15);
    Persistence newClient;
	if(result==1)
	{
	newClient.registerClient("A01010101", "Chris", "ITI", "a010516f7@itesm.mx", true, vector1);
	//newClient.deleteClient("A5");
	newClient.writeToDisc();
	}
   

    // cout << vector1.size << endl;
    // cout << vector2.size << endl;

    // printf("The result of the module is: %d\n", result);
    // cout << "M = " << endl
    //      << " " << vector1 << endl;

    return 0;
 }