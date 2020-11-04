# TC2004.1
Team 4: DATA PERSISTENCE  
Authors:  
Lorenzo Jácome / A01026759 / Lorenzo-Jacome  
Marcela Fuentes / A01748161 / marcefuentesl  
Rodrigo Ponce de León / A01364720/ RodrigoPonceLS  
Fernando Garrote De La Macorra / A01027503 / FernandoGarrote  
Vicente Santamaría / A01421801 / Vicentesve  
  
About our module:  
The purpose of this module is to store the data required for the Face Recognition System to work. In order to do that, several functionalities were added:  
Register a client  
Remove a client  
Update a client  
Retrieve a client’s image  
Find a client (check if they’re registered in the system)  
Create a YAML file that displays all registered clients  
Load all registered clients to memory  
Generate a unique key (identifier) for each client  
The module was developed using the programming language C++.  
  
About the demo (main):  
■ If you run “main.cpp” to test our module you’ll find that it opens your camera and stores what it saw in a cv::Mat.  
■ Then it creates an object of type “Persistence” called “newClient”.   
■ newClient uses the function “registerClient” to add a new client to the database, with all its respective attributes.  
■ Then we use the function “deleteClient”, that it uses the key of one of our clients to delete it from the database.  
■ The function “writeToDisc” is called when you want all the information in memory written to disk.   
