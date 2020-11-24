#include "../Feature_Extraction/source/moduleFE.hpp"
#include "moduleFS.hpp"

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
    //cout <<vector1<<endl;
    Persistence Pers("algo.yml");
    FastSearch fast;
    fast.searchIndex(Pers,vector1);
    fast.printResults(Pers);
    // Pers.getIndex();
    // Pers.searchIndex(vector1,*fast.indices,*fast.distances,fast.max_neighbors);
    return 0;

}