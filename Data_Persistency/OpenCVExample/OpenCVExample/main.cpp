#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"

using namespace cv;
using namespace std;


//PRESENTATION EXAMPLE:
int main(int argv, char **args) {
	//Opens your webcam and stores what it sees in a Mat
	//VideoCapture cap;
	//cap.open(0);
	//Mat frame=imread("../../../../Feature_Extraction/Examples/Maikol3.jpeg");
	Mat frame=imread(args[1]);
	//cap >> frame;
	puts("hola");

	//Creates a persistence object, and registers a new client in memory, or delete a client using its key as parameter, and then you write to disk.
	Persistence newClient;
	newClient.registerClient("A1546546", "MAIKOL", "ALGO	", "a010277fff7@itesm.mx", true, frame);
	//newClient.deleteClient("A5");
	newClient.writeToDisc();
	//cout<< newClient.features_vector.size()<<endl;
	
	return 0;
}