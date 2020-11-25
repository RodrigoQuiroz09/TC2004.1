#include "FaceRecognitionSystem.hpp"


	FaceRecognitionSystem::FaceRecognitionSystem(){
		faceDetector=FaceDetector();
        faceAlignment=Facealignment();
        featureExtraction=FeatureExtraction();
		persistence=new Persistence("algo.yml");

	}
	
	FaceRecognitionSystem::~FaceRecognitionSystem(){}

	void FaceRecognitionSystem::addPerson(std::string clientId, std::string clientName, std::string clientCareer, 
	std::string clientEmail, bool clientStudent, cv::Mat faceMat, std::string pfp){
		cv::Rect rcprueba;
		rcprueba = faceDetector.detectFace(&faceMat);	
		cv::Mat prueba=faceMat;
		cv::Mat alignprueba=faceAlignment.facealignment(prueba, rcprueba);
		cv::Mat vectorprueba=featureExtraction.getFeatures(alignprueba);
		persistence->registerClient(clientId, clientName, clientCareer, clientEmail, clientStudent, vectorprueba, pfp);
		persistence->writeToDisc();
	}

	std::tuple<Subject,bool> FaceRecognitionSystem::personVerification(cv::Mat image2,std::string id){
		cv::Rect rc;
		bool validation;
		rc = faceDetector.detectFace(&image2);
		if(!rc.empty())
		{
			validation = faceDetector.faceValidation(&image2, rc);
			if(validation==false)
			{
				std::cout << "NO hay una cara " << std::endl;
				//return true;
			}
		} else {
			//return true;
		}

		cv::Mat alignimage=faceAlignment.facealignment(image2, rc);
		cv::Mat vector=featureExtraction.getFeatures(alignimage);
		cv::imshow("hello",alignimage);
		cv::waitKey(0);
			
		int result = featureExtraction.comparison(vector, persistence->getUserFace(id), .6);

		Subject datos(persistence->getUserStudentID(id), persistence->getUserName(id), persistence->getUserCareer(id), 
		persistence->getUserEmail(id), persistence->getUserIsStudent(id), persistence->getUserFace(id), persistence->getUserPfp(id));
		std::tuple<Subject,bool> tupla;

		if(result==1)
		{
			validation = true;
			std::cout<<"WELCOME"<<persistence->getUserName(id)<<std::endl;
			tupla = std::make_tuple(datos, validation);
			return tupla;
		} else {
			validation = false;
			std::cout<<"IMPOSTOR"<<std::endl;
			tupla = std::make_tuple(datos, validation);
			return tupla;
		}

	}

	std::vector<std::tuple<std::string,std::string>> FaceRecognitionSystem::personIdentification(cv::Mat mat){
		FastSearch fast;
		cv::Rect rc;

		rc = faceDetector.detectFace(&mat);
		cv::Mat alignimage=faceAlignment.facealignment(mat, rc);
		cv::Mat vector=featureExtraction.getFeatures(alignimage);	

		cv::Mat resultados=fast.searchIndex(*persistence,vector);

		std::vector<std::tuple<std::string,std::string>> data;
		std::tuple<std::string,std::string> info;

		for(int i=0; i<resultados.cols;i++){
			std::string key = "A" + std::to_string(resultados.at<int>(i)); 
			std::string id = persistence->getUserStudentID(key);
			std::string photo = persistence->getUserPfp(key);
			info = std::make_tuple(id, photo);
			data.push_back(info);
		}

		return data;

	}

	cv::Rect FaceRecognitionSystem::faceRect(cv::Mat mat){
		/* Paso 1: enviar la imagen a FaceDetector::multiScale
		 * Paso 2: regresar el resultado de Paso 1 a GUI para la muestra de caras en pantalla
		 */
	}
	