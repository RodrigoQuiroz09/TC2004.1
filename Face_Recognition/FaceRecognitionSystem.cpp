#include "FaceRecognitionSystem.hpp"

	FaceRecognitionSystem::FaceRecognitionSystem(){
		faceDetector=FaceDetector();
        faceAlignment=Facealignment();
        featureExtraction=FeatureExtraction();
		persistence=Persistence();

	}
	FaceRecognitionSystem::~FaceRecognitionSystem(){}

	void FaceRecognitionSystem::addPerson(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat){
		/* Paso 1: usar el metodo registerClient de la clase Persistence 
		 * * Modificar para que guarde información de 128 características, en vez de la matriz de información de los pixeles 
		 * * Guardar la imagen que se obtenga y almacenar en el path en el .yml 
		 */
	}

	bool FaceRecognitionSystem::personVerification(cv::Mat image,std::string id){
		/* Paso 1: el image se obtiene de un capture en el main de la GUI y este
		 * Paso 2: envio de la imagen a FaceDetector 
		 * Paso 3: envio del rectangulo a FaceAllignment 
		 * Paso 4: envio de la matriz resultante de FaceAllignment a FastSearch(modulo Rojo)
		 * Paso 5: envio del resultado de FastSearch a Verification (1 contra 1, modulo Sibaja)
		 * Paso 6: se regresa resultado del paso 5
		 * * El resultado de Paso 6 debe ajustarse a la interfaz de personVerification
		 */
	}

	std::vector<std::tuple<cv::Mat,std::string>> FaceRecognitionSystem::personIdentification(cv::Mat mat){
		/* Paso 1: el image se obtiene de un capture en el main de la GUI y este
		 * Paso 2: envio de la imagen a FaceDetector 
		 * Paso 3: envio del rectangulo a FaceAllignment 
		 * Paso 4: envio de la matriz resultante de FaceAllignment a FastSearch(modulo Rojo)
		 * Paso 5: envio del resultado de FastSearch a Verification (1 contra varios, modulo Sibaja)
		 * Paso 6: se regresa resultado del paso 5
		 * * El resultado de Paso 6 debe ajustarse a la interfaz de personIdentification
		 */
	}

	cv::Rect FaceRecognitionSystem::faceRect(cv::Mat mat){
		/* Paso 1: enviar la imagen a FaceDetector::multiScale
		 * Paso 2: regresar el resultado de Paso 1 a GUI para la muestra de caras en pantalla
		 */
	}
