#include "FaceRecognitionSystem.hpp"

int main(){
    FaceRecognitionSystem faceRecognitionSystem = FaceRecognitionSystem();
    cv::Mat image;
    bool flag=true;
    //faceRecognitionSystem.addPerson("A01026744", "Toti", "ITC", "hola3@gmail.com", true, image, "/Users/Hayoung/code/opencv-cpp-template/Faces/ro.jpg");
    cv::VideoCapture cap;
    if (!cap.open(0))
		    std::cout << "WebCam ERROR" << std::endl;
    while (flag)
		{
			cap >> image;
      flag=faceRecognitionSystem.personIdentification(image);
    }
    return 0;
}