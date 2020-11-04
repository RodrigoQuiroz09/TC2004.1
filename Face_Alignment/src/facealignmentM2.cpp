/*
Module: Face alignment
Authors: Ana Paola Minchaca, Rodrigo Sibaja, Francisco Acuña & Karen Morgado
This module recieves a an opencv mat and an opencv rect and uses de clases
extrac_image_chip to align the image
*/
#include <dlib/dnn.h>
#include <dlib/gui_widgets.h>
#include <dlib/clustering.h>
#include <dlib/string.h>
#include <dlib/image_io.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include "facealignmentM2.hpp"

Facealignment::Facealignment()
{
    dlib::deserialize("shape_predictor_5_face_landmarks.dat") >> sp;
}

dlib::matrix<dlib::rgb_pixel> Facealignment::facealignment(cv::Mat img, cv::Rect face){
    std::cout<<img.channels()<<std::endl;
    dlib::cv_image<dlib::bgr_pixel> image(img);
    dlib::matrix<dlib::rgb_pixel> matriz;
    assign_image(matriz, image);
    dlib::rectangle rect((long)face.tl().x, (long)face.tl().y, (long)face.br().x - 1, (long)face.br().y - 1);
    dlib::matrix<dlib::rgb_pixel> face_chip;
    dlib::full_object_detection shape = sp(matriz, rect);
    extract_image_chip(matriz, get_face_chip_details(shape,150,0.25), face_chip);
    return(face_chip);
};