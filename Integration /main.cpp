#include "../Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"
#include "../Feature_Extraction/source/moduleFE.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Run this example by invoking it like this: " << std::endl;
        std::cout << "   ./my_prject image_path.jpg image_path2.jpg" << std::endl;
        std::cout << std::endl;
        return 1;
    }
    FeatureExtraction F;
    cv::Mat frame = imread(argv[1]);//toti
    cv::Mat frame2 = imread(argv[2]);//path
    cv::Mat vector1 = F.getFeatures(frame);
    cv::Mat vector2 = F.getFeatures(frame2);
    int result = F.comparison(vector1, vector2);
    Persistence newClient;
    if(result==1)
    {
        newClient.registerClient("A1111111", "MAIKOL", "ITI", "a010516f7@itesm.mx", true, vector1);
	    //newClient.deleteClient("A5");
	    newClient.writeToDisc();
    }
    // cout << vector1.size << endl;
    // cout << vector2.size << endl;

    // printf("The result of the module is: %d\n", result);
    // cout << "M = " << endl
    //      << " " << vector1 << endl;

    return 0;
}