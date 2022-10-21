#include "ChessBoard.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>


void ChessBoard::drawGeometry()
{
	//	Separated for simplicity

	glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);
	drawTiles();
	drawBorder();
	glPopMatrix();
}

void ChessBoard::drawTiles() {

	bool colourCheck = false;
	float offset;

	//	draws tiles 0-7
	//	starts from -4 to center the board
	for (int x = -4; x < 3; x++)
	{
		for (int y = -4; y < 3; y++)
		{
			offset = nrandom[x + 4][y + 4];
			//offset = 0;
			drawCube(colourCheck, x * 2, y * 2, offset);
			colourCheck = !colourCheck;
		}
	}

	//	draws 8th row 
	for (int x = -4; x < 3; x++)
	{
		for (int y = 4; y < 5; y++)
		{
			offset = nrandom[x + 4][y + 4];
			drawCube(colourCheck, (x * 2), (y * 2) - 2, offset);
			colourCheck = !colourCheck;
		}
	}

	//	draws 8th column 
	for (int x = 4; x < 5; x++)
	{
		for (int y = -5; y < 3; y++)
		{
			offset = nrandom[x + 4][y + 4];
			colourCheck = !colourCheck;
			drawCube(colourCheck, (x * 2) - 2, (y * 2) + 2, offset);
		}
	}
}

void ChessBoard::drawSide() {

	glBegin(GL_QUADS);
	{
		glPushMatrix();
		glColor3f(0.3f, 0.3f, 0.3f);

		//back face
		glVertex3f(-4, 1, -9);
		glVertex3f(-4, 0, -9);
		glVertex3f(-3, 0, -9);
		glVertex3f(-3, 1, -9);

		//front face
		glVertex3f(-3, 0, 9);
		glVertex3f(-3, 1, 9);
		glVertex3f(-4, 1, 9);
		glVertex3f(-4, 0, 9);

		//left face 
		glVertex3f(-4, 1, 9);
		glVertex3f(-4, 1, -9);
		glVertex3f(-4, 0, -9);
		glVertex3f(-4, 0, 9);

		//right face
		glVertex3f(-3, 1, 9);
		glVertex3f(-3, 1, -9);
		glVertex3f(-3, 0, -9);
		glVertex3f(-3, 0, 9);

		//top face
		glVertex3f(-4, 1, 9);
		glVertex3f(-4, 1, -9);
		glVertex3f(-3, 1, -9);
		glVertex3f(-3, 1, 9);

		//bottom face
		glVertex3f(-4, 0, 9);
		glVertex3f(-4, 0, -9);
		glVertex3f(-3, 0, -9);
		glVertex3f(-3, 0, 9);
		glPopMatrix();
	}
	glEnd();


}

void ChessBoard::drawBorder() {

	//side 1
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-6, 0, 1);
	drawSide();
	glPopMatrix();

	//side 2
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(11, 0, 1);
	drawSide();
	glPopMatrix();

	//side 3
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(3, 7, -1);
	drawSide();
	glPopMatrix();

	//side 4
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(3, -10, -1);
	drawSide();
	glPopMatrix();
}

void ChessBoard::drawCube(bool isBlack, int x, int y, float offset) {

	//original cube vertices

	GLfloat verticeA[] = { -1, -1, -1 };
	GLfloat verticeB[] = { 1, -1, -1, };
	GLfloat verticeC[] = { 1, 1, -1 };
	GLfloat verticeD[] = { -1, 1, -1 };
	GLfloat verticeE[] = { -1, -1, 1 };
	GLfloat verticeF[] = { 1, -1, 1, };
	GLfloat verticeG[] = { 1, 1, 1 };
	GLfloat verticeH[] = { -1, 1, 1 };

	offset /= 2; //this is for it to be between 0 and 0.5 instead of 1


	//drawing the cube
	glBegin(GL_QUADS);
	{
		glPushMatrix();
		int i = 0;


		if (isBlack)
			glColor3f(0, 0, 0);
		else
			glColor3f(1, 1, 1);


		//vertices altered to create a cube in a new position

		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeB[i] + x, verticeB[i + 1] + y, verticeB[i + 2] + offset);
		glVertex3f(verticeC[i] + x, verticeC[i + 1] + y, verticeC[i + 2] + offset);
		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);

		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);
		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);

		glVertex3f(verticeB[i] + x, verticeB[i + 1] + y, verticeB[i + 2] + offset);
		glVertex3f(verticeC[i] + x, verticeC[i + 1] + y, verticeC[i + 2] + offset);
		glVertex3f(verticeG[i] + x, verticeG[i + 1] + y, verticeG[i + 2] + offset);
		glVertex3f(verticeF[i] + x, verticeF[i + 1] + y, verticeF[i + 2] + offset);

		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeB[i] + x, verticeB[i + 1] + y, verticeB[i + 2] + offset);
		glVertex3f(verticeF[i] + x, verticeF[i + 1] + y, verticeF[i + 2] + offset);
		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);

		glVertex3f(verticeA[i] + x, verticeA[i + 1] + y, verticeA[i + 2] + offset);
		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);
		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);

		glVertex3f(verticeD[i] + x, verticeD[i + 1] + y, verticeD[i + 2] + offset);
		glVertex3f(verticeC[i] + x, verticeC[i + 1] + y, verticeC[i + 2] + offset);
		glVertex3f(verticeG[i] + x, verticeG[i + 1] + y, verticeG[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);

		glVertex3f(verticeE[i] + x, verticeE[i + 1] + y, verticeE[i + 2] + offset);
		glVertex3f(verticeF[i] + x, verticeF[i + 1] + y, verticeF[i + 2] + offset);
		glVertex3f(verticeG[i] + x, verticeG[i + 1] + y, verticeG[i + 2] + offset);
		glVertex3f(verticeH[i] + x, verticeH[i + 1] + y, verticeH[i + 2] + offset);

		glPopMatrix();
	}
	glEnd();
}

void ChessBoard::drawBoard() {
	drawGeometry();
	glDisable(GL_DEPTH_TEST);
}

void ChessBoard::SetRandom() {
	//	Sets the random values of each tile
	//	Avoids the tiles changing constantly and being funky

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			float ran = (rand() % 20 + 1);
			nrandom[x][y] = (ran / 10);
		}
	}
}


