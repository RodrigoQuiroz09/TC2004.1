# TC2004.1
Team 3: Face features extraction and comparison.

This module is in charge of Feature Extraction for the Fatial recognition and verification project.

Keep in mind, in order to compile and run the program it is important to follow next steps:

*IMPORTANT:

The library DLIB must be downloadees in order to compile and execute.*

* CMakeLists.txt must be modified with correct DLIB and OpenCV paths for this module to compile *

1. mkdir build (In case it doesn't exist)
2. cd build
3. cmake ..
4. make
5. ./my_project

The file moduleFE.hpp, which is the header, there are some template variables declared that will help in the feature Extration. Because of this, they can't be removed.

Also, theres declaration of a type anet_type object called net, which must not be modified because this object is used for thee file dlib_face_recognition_resnet_model_v1.dat, which must be included in the same module folder.

The threshold value must not be modified because its the default value. In case of wanting to change the value, there is a overwrite in a method this value needs to be a float.

Methods and constructors of FeatureExtraction class are included.

In the moduleFE.cpp it is explained with detailed every method, including the parameters that must be used.

In order to make tests with 2 images, their correct path must be set at the time to execute the main.cpp:

EXAMPLE:
./my_project ../Examples/Maikol1.jpeg ../Examples/Maikol2.jpeg

IMPORTANT:

The library DLIB must be downloadees in order to compile and execute.
