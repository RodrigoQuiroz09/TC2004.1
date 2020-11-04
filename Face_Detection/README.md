# Team 1: Face detection and validation. TC2004.1

The purpose of this particular module is to detect and validate any face that comes into the range of sight of any camera running this system. It serves the purpose of being the first step into the facial recognition process to be achieved by this solution. <br />

In the FaceDetector.hpp, it is possible to find the declaration of the class "FaceDetector"; in it the different methods (and their function prototypes) are included. Furthermore, a small description for each of the previously mentioned methods can alo be found. Furthermore, some private variables used to load the Cascades (files used to detect the faces) are also present in this hpp. <br />

On the other hand, the FaceDetector.cpp file contains the actual code that allows the module to detect and validate faces. Every method coded in this file has comment within it that explain the purpose and functioning of certain lines that could be confussing at first sight. In case there is a doubt on the use of a function or the reasoning behind some parameters used fot this methods, do not hesitate to ask for help! <br />

The xml files that serve the purpose of the cascades to be used to identify faces are to be located in a separate file called "cascades" (please visualize the way in which the FaceDetection subdirectory is organized, as it SHOULD be replicated by anyone working with the code of this module). This structure is MANDATORY as the FaceDetector.cpp uses relative paths to load and used these files. Failure in following this file organization will result in a non-working piece of code. <br />

In terms of the CMakeList.txt file, please keep in mind that line 17 should be modified with the path in which you have installed your OpenCV and specially the subdirectory "build". <br />

No extra libraries (other than OpenCV) or dependencies are needed for the correct implementation of this module's code. <br />

In order to correctly compile this module, perform the following commands: <br />

- 1. mkdir build -> Only to be used if the build subdirectory does not exist
- 2. cd build
- 3. cmake ..
- 4. make
- 5. /my_project
 
The following image shows the capabilities of this module to detect, validate and show the user of the system the faces being detected in real time. <br />

![Photographic Proof 1](https://github.com/RodrigoQuiroz09/TC2004.1/blob/main/Face_Detection/ReadMe_Images/FaceDetectio_ReadMe_Image1.jpeg)
