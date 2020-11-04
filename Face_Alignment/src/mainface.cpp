#include "facealignmentM2.hpp"


int main(int argc, char** argv)
{
	Facealignment alignment;
	cv::Mat img = cv::imread("C:/Users/malte/Desktop/Faces/paco1.jpg");
    cv::Rect rect(165, 194, 423, 452);
    dlib::image_window win(alignment.facealignment(img, rect));
    std::cout << "Press enter to close" << std::endl;
    std::cin.get();
    return 0;
}

