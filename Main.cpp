#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "GameObject.h"
#include "Pixel.h"
#include "Texture.h"
#include "TexturedCube.h"
#include "ChessBoard.h"
#include "HeightMap.h"
#include <Windows.h>
#include "ChessPiece.h"
#include <time.h>   
#include <stdio.h>  
#include <chrono>
#include <thread>
#include <string.h>
#include <string>
//STB
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define LEFT_ARROW 75
#define RIGHT_ARROW 77

using namespace std;

static const int WIDTH = 800;
static const int HEIGHT = 600;

GameObject gameObject;
Texture* texture;
TexturedCube gObject;
ChessBoard chessBoard;
HeightMap heightMap;
ChessPiece chessPiece;

void infiniteLoop();
void input(int key, int x, int y);
void init();
void display();
void timer(int);
void updateCamera();

int cameraPos;
bool isPressed = false;
unsigned int iMemClock, iCurClock, iLoops;
char aFPS[12];

//Initial Calls + Window Setup
int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);// (GL_RGB | GLUT_DOUBLE | GLUT_DEPTH); 

	//Window initialising
	{
		int windowX = (int)(glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
		int windowY = (int)(glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;
		glutInitWindowPosition(windowX, windowY);
		glutInitWindowSize(WIDTH, HEIGHT);
		glutCreateWindow("My First Window");
	}

	chessBoard.SetRandom(); //Sets the offset for each chess tile
	
	glutDisplayFunc(display);
	glutSpecialFunc(input);
	glutTimerFunc(0, timer, 0);
	init();
	glutMainLoop();
	
	delete texture;

	return 0;
}

using namespace std::chrono;

steady_clock::time_point initialFPS;
unsigned long fpsCount = 0;

/// -----------
/// FPS Counter
/// -----------

duration<double> uptime() //duration of the FPS counter running is the duration of the program being up and running
{
	if (initialFPS == steady_clock::time_point{})
		return duration<double>{ 0 };

	return steady_clock::now() - initialFPS;
}

double fps() //calculating fps
{
	const double uptime_sec = uptime().count();

	if (uptime_sec == 0)
		return 0;

	return fpsCount / uptime_sec;
}

void threadSpeed() //how frequently fps, in milliseconds, will be recalculated
{
	std::this_thread::sleep_for(milliseconds{ 1000 });
}

void infiniteLoop() //infinitely looping the fps counter as long as the program is running
{
	std::cout << "fps: " << fps() << '\n';
	std::string str = "fps: " + std::to_string(fps());
	const char* c = str.c_str();
	glutSetWindowTitle(c);
	initialFPS = std::chrono::steady_clock::now();

		threadSpeed();
		fpsCount++;
}

/// ---------------
/// end FPS Counter
/// ---------------

//Change Initial Camera View + Texture
void init() {
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (double)WIDTH / (double)HEIGHT, 1.0, 1000.0);
	gluLookAt(
		0, 30 / 4, 50 / 4,
		0, 0, 0,
		0, 1, 0
	);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	texture = new Texture("Textures/cloudimage.png");
}

void display() {

	updateCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(1, 0, 1, 0);

	//Display HeightMap
	{
		glPushMatrix();
		heightMap.DrawMap(15, 100, texture);
		glPopMatrix();
	}

	//Display ChessBoard
	{
		glPushMatrix();
		glTranslatef(0, 0.5f, 0);
		glRotatef(90, 1, 0, 0);
		chessBoard.draw();
		glPopMatrix();
	}

	//Display Chess Pieces
	{
		glPushMatrix();
		chessPiece.placePieces();
		glPopMatrix();
	}

	glutSwapBuffers();
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);		//	Comment this if you want to pause
}

void updateCamera() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double eyeX = 0;

	if (!isPressed)
	{
		if (GetKeyState(GLUT_KEY_RIGHT) & 0x8000)
		{
			cout << "D" << endl;
			isPressed = true;
			cameraPos--;
		}
		else if (GetKeyState(GLUT_KEY_LEFT) & 0x8000)
		{

			cout << "A" << endl;
			isPressed = true;
			cameraPos++;
		}
	}
	else
	{
		Sleep(500);
		isPressed = false;
	}

	//Check cameraPos
	{
		if (cameraPos > 2) cameraPos = 0;
		if (cameraPos < 0) cameraPos = 2;
		if (cameraPos == 0)
		{
			eyeX = -5;
		}
		if (cameraPos == 2)
		{
			eyeX = 5;
		}
	}

	gluLookAt(
		0, 0, 5,
		eyeX, 0, 0,
		0, 1, 0
	);

	infiniteLoop();
}

void input(int key, int x, int y) {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	double eyeX = 0;

	if (key == (GLUT_KEY_RIGHT))
	{
		cout << "D" << endl;
		isPressed = true;
		cameraPos--;
	}
	else if (key == (GLUT_KEY_LEFT))
	{
		cout << "A" << endl;
		isPressed = true;
		cameraPos++;
	}

	//Check cameraPos
	{
		if (cameraPos > 2) cameraPos = 0;
		if (cameraPos < 0) cameraPos = 2;
		if (cameraPos == 0)
		{
			eyeX = -5;
		}
		if (cameraPos == 2)
		{
			eyeX = 5;
		}
	}

	gluLookAt(
		0, 0, 5,
		eyeX, 0, 0,
		0, 1, 0
	);
}