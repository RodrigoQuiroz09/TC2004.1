#include "moduleFS.hpp"
#include <iostream>

FastSearch::FastSearch(){
max_neighbors = 10;
indices=new cv::Mat(1, max_neighbors, CV_32S);
distances=new cv::Mat_<float>(1, max_neighbors, CV_32S);
}

FastSearch::FastSearch(int neighbors){
max_neighbors=neighbors;
indices=new cv::Mat(1, max_neighbors, CV_32S);
distances=new cv::Mat_<float>(1, max_neighbors, CV_32S);
}

void FastSearch::searchIndex(Persistence persistence,cv::Mat query){
    persistence.getGenericIndex().knnSearch(query.t(),*indices,*distances,max_neighbors,cvflann::SearchParams());
    puts("Aqui todo bien");
}

void FastSearch::printResults(Persistence persistence){ 
puts("Los resultados de la busqueda son: "); 
for (int i = 0; i < indices->cols; i++) 
{ 
std::string key = "A" + std::to_string(indices->at<int>(i)); 
std::cout << persistence.getUserName(key) << " " << persistence.getUserStudentID(key)<<" distancia : "<<(distances->at<float>(i))<<std::endl; 

} 
} 