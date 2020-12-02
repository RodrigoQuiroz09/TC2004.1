# Integration and Design TC2004.1

The aim of this particular module was to perform a joint among all the pieces of code elaborated by the different programming teams. Also, the design and error handling of the final applicattion were performed by this team. <br />

The actual executable for this solution is in the GUIElements directory of this repsitory (the CMake file for the entire project was built upon this module as a reference for the paths in it). In it, the FaceDetectorSystem and GUI classes are joint into one for the actual display of the p`rogram with all its functionalities. <br />

In terms of the CMakeList.txt file, please keep in mind that line 17 should be modified with the path in which you have installed your OpenCV and specially the subdirectory "build". Line 9 from this document should also be modified; the path in it should be the one in which the user has the dlib/cmake subdirectory. <br />

OpenCV and Dlib should be installed in the device for this project to work. Additionally, the "cvui.h" file is to be found in the GUIElements directory for the program t work properly. <br />

 In order to correctly compile this module, perform the following commands: <br />

- 1. mkdir build -> Only to be used if the build subdirectory does not exist
- 2. cd build
- 3. cmake ..
- 4. make
- 5. /my_project
