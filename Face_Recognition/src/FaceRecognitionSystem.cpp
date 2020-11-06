#include "../../Face_Alignment/src/facealignmentM2.hpp"
#include "../../Face_Detection/src/FaceDetector.hpp"
#include <opencv2/opencv.hpp>
class FaceRecognitionmSystem{
    private:
    FaceDetector facedetector;
    Facealignment facealignment;
    public:
    //add_Person();
    void personVerification(std::string id)
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
                cv::imshow("ventana",result);
                cv::waitKey(0);
			}
			else
			{
				std::cout << "NO hay una cara " << std::endl;
			}
		}
    }

    }
    //void personIdentification(cv::Mat mat);

};
 int main()
 {
	 FaceRecognitionmSystem frs;
	 frs.personVerification("hola");
	 
	 return 0;
 }