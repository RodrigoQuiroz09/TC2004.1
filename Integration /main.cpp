#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
#include "../Feature_Extraction/source/moduleFE.hpp"
using namespace cv;
using namespace std;
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Run this example by invoking it like this: " << endl;
        cout << "   ./my_prject image_path.jpg image_path2.jpg" << endl;
        cout << endl;
        return 1;
    }
    FeatureExtraction F;
    Mat frame = imread(argv[1]);
    Mat frame2 = imread(argv[2]);
    Mat vector1 = F.getFeatures(frame);
    Mat vector2 = F.getFeatures(frame2);
    int result = F.comparison(vector1, vector2);
    Persistence newClient;
    newClient.registerClient("A1111111", "MAIKOL", "ITI", "a010516f7@itesm.mx", true, vector1);
	//newClient.deleteClient("A5");
	newClient.writeToDisc();

    // cout << vector1.size << endl;
    // cout << vector2.size << endl;

    // printf("The result of the module is: %d\n", result);
    // cout << "M = " << endl
    //      << " " << vector1 << endl;

    return 0;
}