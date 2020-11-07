#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"

using namespace cv;
using namespace std;


//PRESENTATION EXAMPLE:
int main() {
	//Opens your webcam and stores what it sees in a Mat
	VideoCapture cap(0);
	Mat frame;
	cap >> frame;

	//Creates a persistence object, and registers a new client in memory, or delete a client using its key as parameter, and then you write to disk.
	Persistence newClient;
	newClient.registerClient("A0102777", "Leo", "IMI", "a0102777@itesm.mx", true, frame);
	//newClient.deleteClient("A5");
	newClient.writeToDisc();
	
	return 0;
}