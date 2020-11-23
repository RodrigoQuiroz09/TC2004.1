#include <opencv2/opencv.hpp>

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
	std::map<std::string, Subject> users;
	std::string clientKey = "";
	std::map<std::string, Subject>::iterator itr;

private:
	std::string generateKey();
	cv::flann::GenericIndex<cvflann::L2<float>>* matIndex;
	cv::Mat features_vector;


public:
	Persistence(std::string storageFileName);

	void registerClient(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat, std::string clientPfp);

	void deleteClient(std::string key);

	void writeToDisc();
	void print();

	//GETTERS: Get the atribute searching by key
	cv::Mat getUserFace(std::string userID);

	bool getUserIsStudent(std::string userID);

	std::string getUserEmail(std::string userID);

	std::string getUserCareer(std::string userID);

	std::string getUserName(std::string userID);

	std::string getUserStudentID(std::string userID);

	std::string getUserPfp(std::string userID);

	cv::flann::GenericIndex<cvflann::L2<float>> getGenericIndex();

};