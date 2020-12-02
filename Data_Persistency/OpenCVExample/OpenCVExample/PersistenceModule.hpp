#include <opencv2/opencv.hpp>
//#pragma once
#include "../../../FastSearch/moduleFS.hpp"
class Subject {
public:
	std::string id;
	std::string name;
	std::string career;
	std::string email;
	bool currStudent;
	cv::Mat face;
	std::string pfp;

	Subject();

	Subject(std::string matriculaPar, std::string namePar, std::string careerPar, std::string emailPar, bool studentPar, cv::Mat facePar, std::string pfpPar);
};

class Persistence {
	std::string fileName = "";
	std::vector<Subject> users;
	std::string clientKey = "";
	std::map<std::string, int> usersKeys;
	int keyCont;

private:
	
	std::string generateKey();
	// cv::flann::GenericIndex<cvflann::L2<float>>* matIndex;
	cv::Mat features_vector;
	FastSearch *fast;
	Persistence();


public:
	
	Persistence(std::string storageFileName, int neighbors=10);
	void registerClient(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat, std::string clientPfp);

	void deleteClient(int position);

	void writeToDisc();
	void print();
	cv::Mat searchMat(cv::Mat query);
	void getGenericIndex();
	void printQueryResults(cv::Mat indices);

	//GETTERS: Get the atribute searching by key
	cv::Mat getUserFace(int position);

	bool getUserIsStudent(int position);

	std::string getUserEmail(int position);

	std::string getUserCareer(int position);

	std::string getUserName(int position);

	std::string getUserStudentID(int position);

	std::string getUserPfp(int position);
	
	Subject getUser(int position);
	
	int getPositionByKey(std::string key);
};