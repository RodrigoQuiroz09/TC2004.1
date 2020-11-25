#include "FaceRecognitionSystem.hpp"

int main(){
    FaceRecognitionSystem faceRecognitionSystem = FaceRecognitionSystem();
    cv::Mat image;
    bool flag=true;
    cv::VideoCapture cap;
    if (!cap.open(0))
		    std::cout << "WebCam ERROR" << std::endl;
    while (flag)
		{
			cap >> image;
      //faceRecognitionSystem.addPerson("A01026744", "Toti", "ITC", "hola3@gmail.com", true, image, "/Users/Hayoung/code/opencv-cpp-template/Faces/ro.jpg");
      std::tuple<Subject,bool> personVer = faceRecognitionSystem.personVerification(image, "A13");
      std::vector<std::tuple<std::string,std::string>> personData = faceRecognitionSystem.personIdentification(image);
      for(int i = 0; i<personData.size();i++){
        std::cout<<std::get<0>(personData.at(i))<<" "<<std::get<1>(personData.at(i))<< std::endl;
      }
      break;
    }
    return 0;
}