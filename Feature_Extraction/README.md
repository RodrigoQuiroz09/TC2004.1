# TC2004.1
Team 3: Face features extraction and comparison.

Este es el módulo encargado de Feature Extraction para el proyecto de reconocimiento facial y verificacion.

Recuerden que para poder compilar y correr el programa deben de seguir los siguientes pasos:

1. mkdir build (En caso de que no exista)
2. cd build
3. cmake ..
4. make
5. ./my_project

En el archivo moduleFE.hpp, el cuál es nuestro header, se declaran las variables template que servirán para la extracción de rasgos, por lo que esas variables no se deberan de mover.

También se declara un objeto del tipo anet_type llamado net, el cuál no se deberá de cambiar debido a que en este mismo se usa para el archivo dlib_face_recognition_resnet_model_v1.dat, que debera estar siempre incluido en la misma carpeta del módulo.

El valor de threshold no se debe de modificar debido a que es el umbral que se incluye por default. En caso de querer cambiar el valor, existe una sobrecarga de métodos en el cuál se puede cambiar, a través de la inclusión dentro de los parametros (debe de ser float).

Se incluyen los métodos y constructor de la clase FeatureExtraction.

En el moduleFE.cpp, se explica cada método a detalle, incluyendo los parametros que se deben de usar.

Para poder hacer pruebas con dos imágenes, se deben de poner correctamente su ruta a la hora de ejecutar el main.cpp:

EJEMPLO:
./my_project ../Examples/Maikol1.jpeg ../Examples/Maikol2.jpeg

IMPORTANTE:

Se debe de descargar la librería DLib, para poderse compilar y ejecutar.
