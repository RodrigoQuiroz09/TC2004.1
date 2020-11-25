#include "../Feature_Extraction/source/moduleFE.hpp"
#include "moduleFS.hpp"
#include "/home/rojo/Documentos/Git/TC2004.1/Data_Persistency/OpenCVExample/OpenCVExample/PersistenceModule.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Run this example by invoking it like this: " << endl;
        cout << "   ./my_project image_path.jpg" << endl;
        cout << endl;
        return 1;
    }
    FeatureExtraction F;
    Mat frame = imread(argv[1]);
    Mat vector1 = F.getFeatures(frame);
    Persistence Pers("algo.yml");
    Pers.printQueryResults(Pers.searchMat(vector1));
    return 0;
}
