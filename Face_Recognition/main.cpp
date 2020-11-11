#include "FaceRecognitionSystem.hpp"

int main(){
    FaceRecognitionSystem faceRecognitionSystem = FaceRecognitionSystem();
    cv::Mat image;
    bool flag=true;
    faceRecognitionSystem.addPerson("A01026744", "Ana Paola", "ITC", "hola@gmail.com", true, image);
    cv::VideoCapture cap;
    if (!cap.open(0))
		    std::cout << "WebCam ERROR" << std::endl;
    while (flag)
		{
			cap >> image;
      flag=faceRecognitionSystem.personVerification(image,"A01026744");
    }
    return 0;
}