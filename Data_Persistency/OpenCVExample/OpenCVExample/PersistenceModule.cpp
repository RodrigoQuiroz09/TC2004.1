#ifndef __PERSISTENCEMODULE__HPP
#define __PERSISTENCEMODULE__HPP
#define _CRT_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

// Constructor para nuevo cliente, para hacer interfaz
Subject::Subject(std::string matriculaPar, std::string namePar, std::string careerPar, std::string emailPar, bool studentPar, cv::Mat facePar, std::string pfpPar) {
	id = matriculaPar;
	name = namePar;
	career = careerPar;
	email = emailPar;
	currStudent = studentPar;
	face = facePar;
	pfp = pfpPar;
}

// Constructor base
Subject::Subject() {

}

//Metodo que genera la nueva key, comprobando que no exista:
std::string Persistence::generateKey() {
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
void Persistence::getGenericIndex() {
	matIndex = new cv::flann::GenericIndex<cvflann::L2<float>>(features_vector, cvflann::KDTreeIndexParams());
}

// Constructor del archivo
Persistence::Persistence(std::string storageFileName, int neighbors) {
	fileName = storageFileName;
	cv::FileStorage fs(fileName, cv::FileStorage::READ);
	fast = new FastSearch(neighbors);
	bool searchClients = true;
	int keyCounter = 0;
	std::string trykey = "";
	std::string tempMatricula = "";
	std::string tempName = "";
	std::string tempCareer;
	std::string tempEmail = "";
	bool tempStudent = "";
	std::string tempPfp = "";

	cv::FileNode fn = fs.root();

	for (cv::FileNodeIterator fit = fn.begin(); fit != fn.end(); ++fit) {
		//trykey = "A" + std::to_string(keyCounter);
		cv::Mat tempFace;

		cv::FileNode item = *fit;
		trykey = item.name();

		cv::FileNode fn = fs[trykey];
		fn["Matricula"] >> tempMatricula;
		fn["Name"] >> tempName;
		fn["Career"] >> tempCareer;
		fn["Email"] >> tempEmail;
		fn["Student"] >> tempStudent;
		fn["faceMatrix"] >> tempFace;
		fn["pfp"] >> tempPfp;

		Subject tempClient(tempMatricula, tempName, tempCareer, tempEmail, tempStudent, tempFace, tempPfp);

		if (tempMatricula.compare("") != 0) {
			users.insert(std::pair<std::string, Subject>(trykey, tempClient));
			if (searchClients) {
				features_vector = tempClient.face;
				searchClients = false;
			}
			else {
				cv::hconcat(features_vector, tempClient.face, features_vector);
			}
		}
		else {
			searchClients = false;
		}
		keyCounter++;
		//print();
	}
	fs.release();
	features_vector = features_vector.t();
	getGenericIndex();

}


// Registrar cliente
void Persistence::registerClient(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat, std::string clientPfp) {
	Subject newRegister(clientId, clientName, clientCareer, clientEmail, clientStudent, faceMat, clientPfp);
	users.insert(std::pair<std::string, Subject>(generateKey(), newRegister));
}

// Eliminar cliente
void Persistence::deleteClient(std::string key) {
	users.erase(key);
}

// Copiar a memoria
void Persistence::writeToDisc() {
	cv::FileStorage fs(fileName, cv::FileStorage::WRITE);
	int cont = 0;
	for (itr = users.begin(); itr != users.end(); ++itr) {
		fs << itr->first << "{";
		fs << "Matricula" << itr->second.id;
		fs << "Name" << itr->second.name;
		fs << "Career" << itr->second.career;
		fs << "Email" << itr->second.email;
		fs << "Student" << itr->second.currStudent;
		fs << "faceMatrix" << itr->second.face;
		fs << "pfp" << itr->second.pfp;
		fs << "}";
	}

	fs.release();
}
void Persistence::print() {
	for (std::map<std::string, Subject>::const_iterator cont = users.begin(); cont != users.end(); ++cont) {
		//std::cout << "\n" << cont->first << " " << cont->second.face << "\n";
	}
}
void Persistence::printQueryResults(cv::Mat indices){
	for(int i=0;i<indices.cols;++i){
		std::string key = "A" + std::to_string(indices.at<int>(i));
		std::cout << getUserName(key) << " " << getUserStudentID(key) << std::endl;
	}
}
cv::Mat Persistence::searchMat(cv::Mat query){
	return fast->searchIndex(matIndex,query);
}

//GETTERS: Get the atribute searching by key
cv::Mat Persistence::getUserFace(std::string userID) {
	return users[userID].face;
}

bool Persistence::getUserIsStudent(std::string userID) {
	return users[userID].currStudent;
}

std::string Persistence::getUserEmail(std::string userID) {
	return users[userID].email;
}

std::string Persistence::getUserCareer(std::string userID) {
	return users[userID].career;
}

std::string Persistence::getUserName(std::string userID) {
	return users[userID].name;
}

std::string Persistence::getUserStudentID(std::string userID) {
	return users[userID].id;
}

std::string Persistence::getUserPfp(std::string userID) {
	return users[userID].pfp;
}
#endif

