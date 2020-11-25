#include "FaceRecognitionSystem.hpp"
using namespace cv;
using namespace std;

int main(){
    FaceRecognitionSystem faceRecognitionSystem = FaceRecognitionSystem();
    VideoCapture cap;
	Mat image;
	Rect rc;
	bool validation;

	if (!cap.open(0))
		cout << "WebCam ERROR" << endl;

	while (true)
	{
		cap >> image;
		rc = faceRecognitionSystem.faceRect(&image);
		
		rectangle(image, Point(rc.x, rc.y), Point(rc.x + rc.width, rc.y + rc.height), CV_RGB(0, 255, 0), 2); //verde grande
		imshow("Face Detected", image);

		if(!rc.empty())
		{
			validation = faceRecognitionSystem.faceDetector.faceValidation(&image, rc);
			if (validation)
			{
				cout << "Hay una cara" << endl;
			}
			else
			{
				cout << "NO hay una cara " << endl;
			}
		}
			
		if (waitKey(37) >= 0) break;
	}

	//croppedImage = faceDetector.detectFace(cap);
	cap.release();
	//destroyWindow("Face Detected");
	//rectangle(croppedImage, Point(rc.x, rc.y), Point(rc.x + rc.width, rc.y + rc.height), CV_RGB(51, 0, 102), 2);

  return 0;
}