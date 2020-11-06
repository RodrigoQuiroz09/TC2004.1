#include <opencv2/opencv.hpp>
#include "./FaceDetector.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

FaceDetector::FaceDetector() {
	// All classifiers are to be loaded beforehand to avoid delays and performance flaws
	detector1.load("../../Face_Detection/cascades/lbpcascade_frontalface.xml");
	
	ifstream readcascades ("../../Face_Detection/cascades/cascades.txt"); //.txt tiene que estar en build o en donde están tus cascades
	if(readcascades.is_open())  
	{
		while(getline(readcascades,cascade)){ //lee líneas del txt 
			aux.load(cascade); //carga el classifier
			Detectors.push_back(aux); //agrega classifier al vector 
		}
	}
	readcascades.close(); //cierra la lectura 
}
FaceDetector:: ~FaceDetector() {} //destructor 


vector<Rect> FaceDetector::multiScale(CascadeClassifier *detector, Mat *image, int minNeighbors)
{

	Mat dest;
	Mat gray;
	vector<Rect> rect;
	if((*image).channels() == 1)
	{
		equalizeHist((*image), dest);//lleva contraste a todo el rango, normalización fotométrica
		(*detector).detectMultiScale(dest, rect, 1.1, minNeighbors, 0, Size(60, 60));
	}
	else if((*image).channels() == 4)//Si la imagen es de 4 canales, se convierte a escala de grises
	{
		cvtColor((*image), gray, COLOR_RGBA2GRAY);
		equalizeHist(gray, dest);
		(*detector).detectMultiScale(dest, rect, 1.1, minNeighbors, 0, Size(60, 60));
	}
	else
	{
		cvtColor((*image), gray, COLOR_BGR2GRAY); 
		equalizeHist(gray, dest);
		(*detector).detectMultiScale(dest, rect, 1.1, minNeighbors, 0, Size(60, 60));
		//Neighbors=elementos detectados dentro de una área
	}
	return rect;
}

bool FaceDetector::faceValidation(Mat *image, Rect rc)
{
	int verify=0;
	Rect croppedRegion(rc.x, rc.y, rc.width, rc.height);//la seccion que va a recortar
	Mat croppedImage = (*image)(croppedRegion); //de la imagen, corta la region

	for(int i=0;i<Detectors.size();i++)// itera todo los classifiers 
	{
		vector<Rect> rect = multiScale(&Detectors.at(i), &croppedImage,5); //verifica coincidencias con cada uno de los classifiers
		//cuando lo detecta es 3 y validado es 5. El cinco representa el número de rectángulos entre lazados.
		if (rect.size() == 1)
		{
			verify++;
		}
	}
	if(verify==Detectors.size())//es true cuando encuentre las coincidencias en todos los cascades 
	{
		return true;
	}
	else
	{
		return false;
	}	
}

Rect FaceDetector::detectFace(Mat *image)
{
	int aux = 0;
	int aux2 = 0;
	Rect area;
	vector<Rect> rect=multiScale(&detector1,image,3);
	for (Rect rc : rect)
	{
		if (rc.width > aux && rc.height > aux2)
		{
			aux = rc.width;
			aux2 = rc.height;

			area=rc;
		}
	}
	return area;
}

//Guardar método para la verificación de la efectividad
/*	Mat detectFace(VideoCapture cap)
	{
		Mat croppedImage;
		while (true)
		{
			Mat image;
			cap >> image;
			croppedImage=detectFace(image);
			if (waitKey(37) >= 0) break; // cerrar programa
		}
		return croppedImage;
	}*/
