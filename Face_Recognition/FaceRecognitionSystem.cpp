#include "FaceRecognitionSystem.hpp"

	FaceRecognitionSystem::FaceRecognitionSystem(){
		faceDetector=FaceDetector();
        faceAlignment=Facealignment();
        featureExtraction=FeatureExtraction();
		persistence=Persistence("Elpatitofeo.yml");

	}
	FaceRecognitionSystem::~FaceRecognitionSystem(){}

	void FaceRecognitionSystem::addPerson(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat){
		cv::Mat prueba=cv::imread("/Users/Hayoung/code/opencv-cpp-template/Faces/ana4.jpg");
		cv::Mat vectorprueba=featureExtraction.getFeatures(prueba);
		persistence.registerClient(clientId, clientName, clientCareer, clientEmail, clientStudent, vectorprueba);
		std::cout<<persistence.getUserName("A01026744")<<std::endl;
		/* Paso 1: usar el metodo registerClient de la clase Persistence 
		 * * Modificar para que guarde información de 128 características, en vez de la matriz de información de los pixeles 
		 * * Guardar la imagen que se obtenga y almacenar en el path en el .yml 
		 */
	}

	bool FaceRecognitionSystem::personVerification(cv::Mat image2,std::string id){
		cv::Rect rc;
		bool validation;
		rc = faceDetector.detectFace(&image2);
		if(!rc.empty())
		{
			validation = faceDetector.faceValidation(&image2, rc);
			if(validation==false)
			{
				std::cout << "NO hay una cara " << std::endl;
				return true;
			}
		} else {
			return true;
		}

		cv::Mat alignimage=faceAlignment.facealignment(image2, rc);
		cv::Mat vector=featureExtraction.getFeatures(alignimage);
		cv::imshow("chris",alignimage);
		cv::waitKey(0);

		cv::Mat image1=cv::imread("/Users/Hayoung/code/opencv-cpp-template/Faces/ana4.jpg");
		cv::Mat vector1=featureExtraction.getFeatures(image1);

		//int result = featureExtraction.comparison(vector, persistence.getUserFace(id), .15);
		int result = featureExtraction.comparison(vector, vector1, .15);

		if(result==1)
		{
			std::cout<<"WELCOME NOT IMPOSTOR"<<std::endl;
		} else {
			std::cout<<"IMPOSTOR"<<std::endl;
		}

		return false;

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
	