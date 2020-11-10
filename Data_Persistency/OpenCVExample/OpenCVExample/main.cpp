#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"

using namespace cv;
using namespace std;


//PRESENTATION EXAMPLE:
int main() {

	float data[2] = { 1,2 };
	Mat frame = Mat(1, 2, CV_32F, data);

	//Creates a persistence object, and registers a new client in memory, or delete a client using its key as parameter, and then you write to disk.
	Persistence newClient("clientsInfo.yml");
	newClient.registerClient("A0102777", "Leo", "IMI", "a0102777@itesm.mx", true, frame);
	//newClient.deleteClient("A0");
	
	newClient.writeToDisc();
	
	return 0;
} 