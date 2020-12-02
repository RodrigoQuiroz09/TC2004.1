#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"
#include "../../../Feature_Extraction/source/moduleFE.hpp"

using namespace cv;
using namespace std;


//PRESENTATION EXAMPLE:
int main(int args, char **argv) {

	// float data[2] = { 1,2 };
	Mat frame = imread(argv[1]);
	FeatureExtraction Fe;
	frame=Fe.getFeatures(frame);

	//Creates a persistence object, and registers a new client in memory, or delete a client using its key as parameter, and then you write to disk.
	Persistence newClient("clientsInfo.yml");
	// newClient.print();
	// puts("Antes de ");
	newClient.registerClient(argv[3], argv[2], "IMI", "a0102777@itesm.mx", true, frame,"sample.txt");
	//newClient.deleteClient("A0");
	// newClient.print();
	// sleep(5);
	// puts("ya termine de imprimir... ahora a escribir");
	newClient.writeToDisc();
	
	return 0;
} 