#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

//using namespace cv;
//using namespace std;

//std::string fileName = "clientsInfo.yml";
std::string fileName = "algo.yml";

class Subject {


public:

	std::string id;
	std::string name;
	std::string career;
	std::string email;
	bool currStudent;
	cv::Mat face;
	
	//Para hacer interfaz:
	Subject(std::string matriculaPar, std::string namePar, std::string careerPar, std::string emailPar, bool studentPar, cv::Mat facePar) {
		id = matriculaPar;
		name = namePar;
		career = careerPar;
		email = emailPar;
		currStudent = studentPar;
		face = facePar;
	}
};

//Para cargar en memoria:
class Persistence {
	std::string clientKey = "";
	std::map<std::string, Subject>::iterator itr;


private:
	//Metodo que genera la nueva key, comprobando que no exista:
	std::string generateKey() {
		cv::FileStorage savedCounter(fileName, cv::FileStorage::READ);
		int counter = 0;
		bool search = true;
		std::string saveKey;



		while (search)
		{
			std::string tryKey = "A" + std::to_string(counter);
			cv::FileNode lastKey = savedCounter[tryKey];
			lastKey["Matricula"] >> saveKey;

			if (saveKey.compare("") == 0) {
				search = false;
				clientKey = tryKey;
			}
			counter++;
		}
		return clientKey;
	}

public:
	std::map<std::string, Subject> users;
	cv::Mat features_vector;
	void loadToMemory(){
		cv::FileStorage fs(fileName, cv::FileStorage::READ);
		bool searchClients = true;
		int keyCounter = 0;
		std::string trykey = "";
		std::string tempMatricula = "";
		std::string tempName = "";
		std::string tempCareer;
		std::string tempEmail = "";
		bool tempStudent = "";
		cv::Mat tempFace;
		while (searchClients) {
				trykey = "A" + std::to_string(keyCounter);

				cv::FileNode fn = fs[trykey];
				fn["Matricula"] >> tempMatricula;
				fn["Name"] >> tempName;
				fn["Career"] >> tempCareer;
				fn["Email"] >> tempEmail;
				fn["Student"] >> tempStudent;
				fn["faceMatrix"] >> tempFace;

				Subject tempClient(tempMatricula, tempName, tempCareer, tempEmail, tempStudent, tempFace);

				if (tempMatricula.compare("") != 0) {
					users.insert(std::pair<std::string, Subject>(trykey, tempClient));
					//Mi cosecha
					if(keyCounter==0){
						features_vector=tempClient.face;
					}
					else{
						cv::hconcat(features_vector,tempClient.face, features_vector);
					}
					
				}
				else {
					searchClients = false;
				}
				keyCounter++;
			}
		features_vector=features_vector.t();


	}

	Persistence() {
		loadToMemory();
		//De nuestra cosecha
		//
	}

	void registerClient(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat) {
		Subject newRegister(clientId, clientName, clientCareer, clientEmail, clientStudent, faceMat);
		users.insert(std::pair<std::string, Subject>(generateKey(), newRegister));
		cv::vconcat(features_vector,faceMat.t(),features_vector);
		writeToDisc();
		loadToMemory();
	}

	void deleteClient(std::string key) {
		users.erase(key);
		writeToDisc();
		loadToMemory();
	}

	void writeToDisc() {
		cv::FileStorage fs(fileName, cv::FileStorage::WRITE);

		for (itr = users.begin(); itr != users.end(); ++itr) {
			fs << itr->first << "{";
			fs << "Matricula" << itr->second.id;
			fs << "Name" << itr->second.name;
			fs << "Career" << itr->second.career;
			fs << "Email" << itr->second.email;
			fs << "Student" << itr->second.currStudent;
			fs << "faceMatrix" << itr->second.face;
			fs << "}";
		}

		fs.release();
	}
	void getIndex(){
		cv::flann::GenericIndex<cvflann::L2<float>> index(features_vector,cvflann::KDTreeIndexParams());
	}
};