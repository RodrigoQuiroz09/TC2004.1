#include "facealignmentM2.hpp"
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	Facealignment alignment;
    //nuestros paremetros
	cv::Mat img = cv::imread("/home/emilioag/Documents/TC2004.1/Face_Alignment/Examples/paco1.jpg");
    cv::Rect rect(165, 194, 423, 452); 
    
    //cv::Mat result=alignment.facealignment(img, rect);
       dlib::image_window win(alignment.facealignment(img,rect));
          
    
    std::cout << "Press enter to close" << std::endl;
    std::cin.get();
    return 0;
}

