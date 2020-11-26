#include <opencv2/opencv.hpp>
#include "PersistenceModule.hpp"
#define CVUI_IMPLEMENTATION
#include "cvui.h"

#define WINDOW_NAME "Face Recognition System"

int main() {
	//Open Camera:
	cv::VideoCapture cap(0);
	cv::Size cameraSize(500, 350); //Tamaño de la imagen cuando se abre la camara
	cv::Mat camera, cameraShow;
	//To start window:
	cv::Mat frame = cv::Mat(500, 900, CV_8UC3);
	cv::namedWindow(WINDOW_NAME);
	cvui::init(WINDOW_NAME, 20);

	//Read and resize image:
	cv::Mat imagen = cv::imread("lena.jpg");
	cv::Mat cross = cv::imread("cross.png");
	cv::Mat IMG1, crossImage, imgCloseMatch;
	cv::Mat userCapture, userCapShow;
	cv::Size size(175, 150); //Tamaño de la imagen cuando se verifica
	cv::Size smallSize(100, 75); //Tamaño de las imagenes cuando se identifica
	cv::Size bigSize(450, 300); //Tamaño de la imagen cuando se quiere agregar un nuevo usuario
	cv::resize(imagen, IMG1, size);
	cv::resize(cross, crossImage, size);
	cv::resize(imagen, imgCloseMatch, smallSize);

	std::string keyboard = "A";

	//Variables for presentation:
	bool clientFound = true;

	bool showHomeScreen = true;
	bool detect121 = false;
	bool detect12N = false;
	bool newUserScreen = false;

	while (true)
	{
		cap >> camera;
		cv::resize(camera, cameraShow, cameraSize);
		frame = cv::Scalar(35, 31, 20); // Color de fondo

		// ----------------------HomeScreen----------------------------------------------------------------
		if (showHomeScreen) {
			if ((cvui::button(frame, 400, 425, "Verificar")) || cv::waitKey(1) == 118) { //Tecla "v"
				showHomeScreen = false;
				detect121 = true;
				cap >> userCapture;
			}
			else if ((cvui::button(frame, 600, 425, "Identificar")) || cv::waitKey(1) == 105) { //Tecla "i"
				showHomeScreen = false;
				detect12N = true;
				cap >> userCapture;
			}
			else if (cvui::button(frame, 10, 20, "Registrar Usuario")) {
				showHomeScreen = false;
				newUserScreen = true;
				cap >> userCapture;
			}

			//Keyboard: (para ingresar llave):
			if (cvui::button(frame, 10, 100, "1")) {
				keyboard += "1";
			}
			else if (cvui::button(frame, 60, 100, "2")) {
				keyboard += "2";
			}
			else if (cvui::button(frame, 110, 100, "3")) {
				keyboard += "3";
			}
			else if (cvui::button(frame, 10, 150, "4")) {
				keyboard += "4";
			}
			else if (cvui::button(frame, 60, 150, "5")) {
				keyboard += "5";
			}
			else if (cvui::button(frame, 110, 150, "6")) {
				keyboard += "6";
			}
			else if (cvui::button(frame, 10, 200, "7")) {
				keyboard += "7";
			}
			else if (cvui::button(frame, 60, 200, "8")) {
				keyboard += "8";
			}
			else if (cvui::button(frame, 110, 200, "9")) {
				keyboard += "9";
			}
			else if (cvui::button(frame, 60, 250, "0")) {
				keyboard += "0";
			}
			else if (cvui::button(frame, 45, 300, "DELETE")) {
				keyboard = "A";
			}

			cvui::rect(frame, 0, 0, 200, 900, 0xF2F7FB);
			cvui::image(frame, 300, 50, cameraShow);

			cvui::text(frame, 60, 425, keyboard);
		}
		//-----------------------Screen agregar nuevo usuario ---------------------------------------------
		if (newUserScreen) {
			bool consoleOpen = false;
			std::string matricula = "";
			std::string nombre = "";
			std::string carrera = "";
			std::string mail = "";
			bool student = true;
			cv::Mat procFace;
			std::string pathFoto = "";

			cv::resize(userCapture, userCapShow, bigSize);
			cvui::image(frame, 50, 50, userCapShow);
			cvui::printf(frame, 550, 75, 0.6, 0xF2F7FB, "Quiere agregar a este usuario?");
			cvui::printf(frame, 550, 100, 0.4, 0xF2F7FB, "Llene el formulario en consola");
			cvui::printf(frame, 550, 175, 0.4, 0xFF0000, "LA INTERFAZ SE DETIENE HASTA QUE TERMINE");
			cvui::printf(frame, 550, 200, 0.4, 0xFF0000, "EL REGISTRO EN CONSOLA");
			if (cvui::button(frame, 550, 125, "Empezar")) {
				consoleOpen = true;
			}

			//Formulario en consola:
			if (consoleOpen) {
				std::cout << "Matricula del usuario:" << std::endl;
				std::cin >> matricula;

				std::cout << "Nombre del usuario:" << std::endl;				std::cin >> nombre;				std::cout << "Carrera del usuario:" << std::endl;				std::cin >> carrera;				std::cout << "Correo del usuario:" << std::endl;				std::cin >> mail;				//std::cout << "Inserta true si el usuario es estudiante o false si es docente:" << std::endl;				//std::cin >> student;				//std::cout << "Matriz del usuario:" << std::endl;				//std::cin >> procFace;				std::cout << "Path de la foto: " << std::endl;
				std::cin >> pathFoto;

				cv::imwrite(pathFoto, userCapture);
				consoleOpen = false;

				std::cout << "PROCESO COMPLETADO, REGRESE A LA INTERFAZ" << std::endl;
			}

			if (cvui::button(frame, 10, 425, "Regresar")) {
				showHomeScreen = true;
				newUserScreen = false;
			}
		}
		// ----------------------Screen para usuario aceptado 1:N------------------------------------------
		if (detect12N) {
			cv::resize(userCapture, userCapShow, size);
			cvui::image(frame, 50, 100, userCapShow);

			if (cvui::button(frame, 10, 425, "Regresar")) {
				showHomeScreen = true;
				detect12N = false;
			}
			cvui::rect(frame, 0, 0, 265, 900, 0xF2F7FB);

			cvui::printf(frame, 50, 75, 0.4, 0xF2F7FB, "Captura del usuario:");
			cvui::printf(frame, 520, 65, 0.4, 0xF2F7FB, "Posibles coincidencias:");

			//Mostrar posibles coincidencias:
			cvui::image(frame, 300, 100, imgCloseMatch);
			cvui::printf(frame, 300, 180, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 300, 200, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 540, 100, imgCloseMatch);
			cvui::printf(frame, 540, 180, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 540, 200, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 780, 100, imgCloseMatch);
			cvui::printf(frame, 780, 180, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 780, 200, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 300, 230, imgCloseMatch);
			cvui::printf(frame, 300, 310, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 300, 330, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 540, 230, imgCloseMatch);
			cvui::printf(frame, 540, 310, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 540, 330, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 780, 230, imgCloseMatch);
			cvui::printf(frame, 780, 310, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 780, 330, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 300, 360, imgCloseMatch);
			cvui::printf(frame, 300, 440, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 300, 460, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 540, 360, imgCloseMatch);
			cvui::printf(frame, 540, 440, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 540, 460, 0.4, 0xF2F7FB, "Matricula");

			cvui::image(frame, 780, 360, imgCloseMatch);
			cvui::printf(frame, 780, 440, 0.4, 0xF2F7FB, "Nombre");
			cvui::printf(frame, 780, 460, 0.4, 0xF2F7FB, "Matricula");
		}
		
		// ----------------------Screen para usuario aceptado 1:1------------------------------------------

		//Constantes (Están independientemente de si el usuario es aceptado o rechazado):
		if (detect121) {
			cvui::printf(frame, 50, 75, 0.4, 0xF2F7FB, "Captura del usuario:");
			cvui::printf(frame, 600, 75, 0.4, 0xF2F7FB, "Foto del Usuario:");
			cv::resize(userCapture, userCapShow, size);
			cvui::image(frame, 50, 100, userCapShow);
			if (cvui::button(frame, 10, 425, "Regresar")) {
				showHomeScreen = true;
				detect121 = false;
			}
			cvui::image(frame, 600, 100, IMG1);
		}

		//Cuando el usuario es aceptado:
		if (clientFound && !showHomeScreen && detect121) {
			cvui::printf(frame, 300, 75, 0.4, 0xF2F7FB, "Datos del Usuario:");
			cvui::printf(frame, 300, 100, 0.4, 0xF2F7FB, "Nombre:");
			cvui::printf(frame, 300, 125, 0.4, 0xF2F7FB, "Matricula:");
			cvui::printf(frame, 300, 150, 0.4, 0xF2F7FB, "Carrera:");
			cvui::printf(frame, 300, 175, 0.4, 0xF2F7FB, "Email:");
			cvui::printf(frame, 300, 200, 0.4, 0xF2F7FB, "Estudiante:");
			cvui::image(frame, 600, 100, IMG1);
			cvui::printf(frame, 50, 275, 0.8, 0x27EF57, "Aceptado");
		}

		//Cuando el usuario es rechazado:
		if (!clientFound && !showHomeScreen && detect121) {
			cvui::printf(frame, 50, 275, 0.8, 0xef3c27, "Rechazado");
			cvui::printf(frame, 300, 180, 0.6, 0xF2F7FB, "USUARIO NO ENCONTRADO");
			cvui::image(frame, 600, 100, crossImage);
		}

		//Controles para aceptado o rechazo (presentacion):
		if (cv::waitKey(1) == 97) {
			cvui::update();
			clientFound = true;
		}
		else if (cv::waitKey(1) == 114) {
			cvui::update();
			clientFound = false;
		}

		cvui::update();
		cv::imshow(WINDOW_NAME, frame);

		if (cv::waitKey(1) == 27) {
			break;
		}
	}

	return 0;
} 