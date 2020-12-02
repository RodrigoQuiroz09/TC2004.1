# Fast Search TC2004.1

This is the module in charge of Fast Search that works hand in hand with Feature Extraction and Comparison for the facial recognition and verification project.

The FastSearch construct initializes the matrix of indexes and distances that works for the search method that is implemented in the GUIelements module in the Identification part that serves to search for a person in the database and find the 10 people who are most alike.

SearchIndex has as a parameter a matrix that works hand in hand with the knnSearch method of the Flan library that, by means of indexes and distances, compares the matrix of the image taken with the images from the database and gives us 10 neighbors, which means the 10 people most similar to our user in question.

IMPORTANT*

You must download the DLib library, to be able to compile and run *

You must modify the CMakeLists.txt with the correct Dlib and OpenCV path of the one that compiles this module

In order to correctly compile this module, perform the following commands:

- 1. mkdir build -> Only to be used if the build subdirectory does not exist
- 2. cd build
- 3. cmake ..
- 4. make
- 5. /my_project
