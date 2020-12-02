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
	// 
	fast->crearIndice(features_vector);
}

// Constructor del archivo
Persistence::Persistence(std::string storageFileName, int neighbors) {
	fileName = storageFileName;
	cv::FileStorage fs(fileName, cv::FileStorage::READ);
	fast = new FastSearch(neighbors);
	bool searchClients = true;
	keyCont=0;
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
			users.push_back(tempClient);
			usersKeys.insert(std::pair<std::string,int>(tempMatricula,keyCont));
			if (searchClients) {
				features_vector = tempClient.face.t();
				searchClients = false;
			}
			else {
				cv::vconcat(features_vector, tempClient.face.t(), features_vector);				
			}
			keyCont++;
		}
		else {
			searchClients = false;
		}
		// keyCounter++;
		//print();
	}
	fs.release();
	getGenericIndex();
	//printf("Key counter %d ",keyCont);

}


// Registrar cliente
void Persistence::registerClient(std::string clientId, std::string clientName, std::string clientCareer, std::string clientEmail, bool clientStudent, cv::Mat faceMat, std::string clientPfp) {
	//puts("INICIA register");
	Subject newRegister(clientId, clientName, clientCareer, clientEmail, clientStudent, faceMat, clientPfp);
	usersKeys.insert(std::pair<std::string,int>(clientId,keyCont));
	keyCont++;
	//std::string key= "A"+std::to_string(keyCont);
	users.push_back(newRegister);
	//std::cout<<"vector a aniadir: "<<faceMat.t()<<"\n";
	cv::vconcat(features_vector,newRegister.face.t(),features_vector);
	//std::cout<<"mat despues de aniadir: "<<features_vector<<"\n";
	getGenericIndex();
	//puts("TErmina register");


}

// Eliminar cliente
void Persistence::deleteClient(int position) {
	// users.erase(position)
	// keyCont--;
}

// Copiar a memoria
void Persistence::writeToDisc() {
	//puts("INICIA WRITE");
	cv::FileStorage fs(fileName, cv::FileStorage::WRITE);
	int cont = 0;
	//puts("ANTES DEL FOR");
	for (cont;cont<users.size();++cont) {
		fs << users.at(cont).id << "{";
		fs << "Matricula" << users.at(cont).id;
		fs << "Name" << users.at(cont).name;
		fs << "Career" << users.at(cont).career;
		fs << "Email" << users.at(cont).email;
		fs << "Student" << users.at(cont).currStudent;
		fs << "faceMatrix" << users.at(cont).face;
		fs << "pfp" << users.at(cont).pfp;
		fs << "}";
	}
	// puts("TERMINA WRITE");
	// print();

	fs.release();
}
void Persistence::print() {
	for(int i=0;i<users.size();++i){
		std::cout<<users[i].name<<"\n";
	}
}
void Persistence::printQueryResults(cv::Mat indices){
	for(int i=0;i<indices.cols;++i){
		int key =indices.at<int>(i);
		std::cout << getUserName(key) << " " << getUserStudentID(key) << std::endl;
	}
}
cv::Mat Persistence::searchMat(cv::Mat query){
	getGenericIndex();
	cv::Mat result= fast->searchIndex(query);
	return result;

}

//GETTERS: Get the atribute searching by key
cv::Mat Persistence::getUserFace(int position) {
	return users[position].face;
}

bool Persistence::getUserIsStudent(int position) {
	return users[position].currStudent;
}

std::string Persistence::getUserEmail(int position) {
	return users[position].email;
}

std::string Persistence::getUserCareer(int position) {
	return users[position].career;
}

std::string Persistence::getUserName(int position) {
	return users[position].name;
}

std::string Persistence::getUserStudentID(int position) {
	return users[position].id;
}

std::string Persistence::getUserPfp(int position) {
	return users[position].pfp;
}
Subject Persistence::getUser(int position){
	return users.at(position);
}
int Persistence::getPositionByKey(std::string key){
	return usersKeys[key];
}
#endif

