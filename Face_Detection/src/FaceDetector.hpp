#include <opencv2/opencv.hpp>

class  FaceDetector {
private:
	// Cascade classifiers to use (XMLs)
	//implementar destructores vacios
	cv::CascadeClassifier detector1;//lbpcascade 
	cv::CascadeClassifier aux;//Cargar classifiers del txt
	std::vector<cv::CascadeClassifier> Detectors; //almacenar classifiers cargados
	std::string cascade; //string auxiliar que contiene path de cada classifier 

	/* Method in charge of detecting a certain number of ocurrencies within an image
	 * @param detector: the cascade classifier use to detect/validate
	 * @param image: where the classifier is applied
	 * @param minNeighbors: detected elemtens in a certain area
	 */
	std::vector<cv::Rect> multiScale(cv::CascadeClassifier *detector, cv::Mat *image, int minNeighbors); 
public:
	/*	Default constructor of a Face Detector
	 */
	FaceDetector();

	/* Method that validates the Mat object which contains or not a face
	 * @param image: image to be validated
	 * @param rc: area in which to search for the face
	 */
	bool faceValidation(cv::Mat *image, cv::Rect rc);

	/*	Method that detects a front facing face within a given image and returns the cropped section of the image where the face was found (image returned can be empty if no face was found)
	 *	@param image: image [Mat] in which to search for the face
	 */
	cv::Rect detectFace(cv::Mat *image);

	virtual ~FaceDetector();

};
