# Final Project: Automatic Face Recognition System
---
## Subject: *TC2004 Analysis and modeling of software systems*
## Instituto Tecnológico y de Estudios Superiores de Monterrey (ITESM)
## Professor: Dr. Leonardo Chang Fernández
## Semester:Aug-Dec 2020

### General Description of the System
A system capable of fulfilling 2 particular cases (to be explained in further detail later on this document) which contemplate an automatic face recognition system was asked by the Head of Security from Tecnológico de Monterrey Santa Fe Campus. The system referenced aforementioned has the intention of automating and improving the security standards in the entry points of the campus. A description of both cases is presented in the following paragraphs. <br />

Case 1: Verification of an ID card holder identity taking as a reference an image retrieved from a Databse in possession of Tecnológico de Monterrey Santa Fe Campus. The system should be able to have as an output whether a confirmation or a denial (yes or no) of the identity of the person. This case is intended to be applied at the diverse entrances of the campus at issue. <br />

Case 2: Identification of any person trying to enter the campus. The developed solution should be able to capture an image from a camera located at whatever entrance point of the property; from this image, the system requires an output that indicates if a person (previously registered in a database from the institution) has been identified or not. The latest case occurs when the person being captured by the camera has not undergone a registration process by the university. As well as with Case 1, this scenario is intended to be put in practice in the coming points of the campus. <br />

### Modules that make up the system (brief and easy to understand overview)
#### Face Detection
Via Haar Cascades, this module is in charge detecting of all faces captured by the camera in which the system is being executed. In case of having multiple matches at a certain instance (more than one), the proposed solution discards all but the one with more proximity and bigger area at that particular moment. <br />
Furthermore, a validation of the detected face described in the previous paragraph is performed. With this, the module assures that the detected object by the camera is in fact the face of a person. <br />

#### Face Alignment
Using shape predictors in order to dectect facial landmarks (68 points thourghout any face being analyzed), this module is in charge of "normalizing" the output from the "Face Detection" module. This normalization contemplates the necessity of rotating, translating and scaling the aforementioned output so the "Features Extraction" module can perform its tasks properly.

#### Features Extraction


#### Redundancy
