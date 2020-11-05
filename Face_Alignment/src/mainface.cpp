#include "facealignmentM2.hpp"


int main(int argc, char** argv)
{
	Facealignment alignment;
	cv::Mat img = cv::imread("C:/Users/malte/Desktop/Faces/paco1.jpg");
    cv::Rect rect(165, 194, 423, 452);
    cv::Mat result=alignment.facealignment(img, rect);
    cv::imshow("Hemllo", result);
    //dlib::image_window win();
    std::cout << "Press enter to close" << std::endl;
    std::cin.get();
    return 0;
}

