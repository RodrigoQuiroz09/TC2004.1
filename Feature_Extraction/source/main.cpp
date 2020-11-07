#include "moduleFE.hpp"
#include <chrono>
#include <time.h>
using namespace std;
using namespace cv;
using namespace std::chrono;
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
    auto inicio = high_resolution_clock::now();
    Mat vector1 = F.getFeatures(frame);
    auto fin = high_resolution_clock::now();
    auto duracion = fin - inicio;
    cout << "tiempo de feature extraction: " << duration_cast<milliseconds>(duracion).count() << "Milisegundos" << endl;
    Mat vector2 = F.getFeatures(frame2);
    inicio = high_resolution_clock::now();
    int result = F.comparison(vector1, vector2,.15);//.6 es un tamal mike 
    fin = high_resolution_clock::now();
    duracion = fin - inicio;
    cout << "tiempo de comparacion: " << duration_cast<microseconds>(duracion).count() << " Microsegundos" << endl;

    // cout << vector1.size << endl;
    // cout << vector2.size << endl;

    // printf("The result of the module is: %d\n", result);
    // cout << "M = " << endl
    //      << " " << vector1 << endl;

    return 0;
}