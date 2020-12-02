#include "FaceRecognitionSystem.hpp"


	FaceRecognitionSystem::FaceRecognitionSystem(){
		faceDetector=FaceDetector();
        faceAlignment=Facealignment();
        featureExtraction=FeatureExtraction();
		persistence=new Persistence("prueba.yml");
	}
	
	FaceRecognitionSystem::~FaceRecognitionSystem(){}

	void FaceRecognitionSystem::addPerson(std::string clientId, std::string clientName, std::string clientCareer, 
	std::string clientEmail, bool clientStudent, cv::Mat faceMat, std::string pfp){
		cv::Rect facerc;
		facerc = faceDetector.detectFace(&faceMat);	
		cv::Mat face=faceMat;
		cv::Mat alignface=faceAlignment.facealignment(face, facerc);
		cv::Mat vectorface=featureExtraction.getFeatures(alignface);
		persistence->registerClient(clientId, clientName, clientCareer, clientEmail, clientStudent, vectorface, pfp);
		persistence->writeToDisc();
	}

	std::tuple<Subject,bool> FaceRecognitionSystem::personVerification(cv::Mat image2,std::string ids){
		cv::Rect rc;
		bool validation;
		rc = faceDetector.detectFace(&image2);
		int id=persistence->getPositionByKey(ids);
		cv::Mat alignimage=faceAlignment.facealignment(image2, rc);
		cv::Mat vector=featureExtraction.getFeatures(alignimage);
		
		
		int result = featureExtraction.comparison(vector, persistence->getUserFace(id), .45);

		Subject datos(persistence->getUserStudentID(id), persistence->getUserName(id), persistence->getUserCareer(id), 
		persistence->getUserEmail(id), persistence->getUserIsStudent(id), persistence->getUserFace(id), persistence->getUserPfp(id));
		std::tuple<Subject,bool> tupla;

		if(result==1)
		{
			validation = true;
			tupla = std::make_tuple(datos, validation);
			return tupla;
		} else {
			validation = false;
			tupla = std::make_tuple(datos, validation);
			return tupla;
		}

	}

	std::vector<Subject> FaceRecognitionSystem::personIdentification(cv::Mat mat){
		cv::Rect rc;
		int key;
		rc = faceDetector.detectFace(&mat);
		cv::Mat alignimage=faceAlignment.facealignment(mat, rc);
		cv::Mat vector=featureExtraction.getFeatures(alignimage);	
		cv::Mat resultados=persistence->searchMat(vector);
		std::vector<Subject> data;
		for(int i=0; i<resultados.cols;i++){
			key = resultados.at<int>(i);
			data.push_back(persistence->getUser(key));
		}
		return data;
	}

	bool FaceRecognitionSystem::faceRect(cv::Mat mat){
		/* Paso 1: enviar la imagen a FaceDetector::multiScale
		 * Paso 2: regresar el resultado de Paso 1 a GUI para la muestra de caras en pantalla
		 */
		cv::Rect rc;
		rc = faceDetector.detectFace(&mat);
		if(!rc.empty())
		{
			return faceDetector.faceValidation(&mat, rc);
		
		}
		return false;
	}
	