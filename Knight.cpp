#include "Knight.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>



void Knight::drawBody(float scale, float x, float y, float z)
{
	glTranslatef(x, y, z);
	drawBase(scale);

	glPushMatrix();
	{
		glTranslatef(0, 8, 17);
		drawCube(1);

		glTranslatef(0, 2, 0.8);
		drawCube(1);


		glTranslatef(0, 2, 0.8);
		drawCube(1);

		glTranslatef(0, 2, -0.5);
		drawCube(1);

		glTranslatef(0, 0, -2);
		drawCube(1);

		glScalef(0.6, 0.6, 0.6);
		glTranslatef(0, -1, -4);
		drawCube(1);

		glScalef(0.8, 0.8, 0.8);
		glTranslatef(0, 0, -2);
		drawCube(1);

	}
	glPopMatrix();
}

void Knight::drawBase(float scale)
{
	//Draw cylinder

	glPushMatrix();
	{
		glScalef(scale, scale, scale);
		glTranslatef(0, 7, 17);

		glRotatef(90, 90, 0, 0);

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, 0);
			glVertex3f(1, 3, 0);
			glVertex3f(3, 1, 0);
			glVertex3f(3, -1, 0);
			glVertex3f(1, -3, 0);
			glVertex3f(-1, -3, 0);
			glVertex3f(-3, -1, 0);
			glVertex3f(-3, 1, 0);
			glVertex3f(-1, 3, 0);
		}
		glEnd();

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, 1);
			glVertex3f(1, 3, 1);
			glVertex3f(3, 1, 1);
			glVertex3f(3, -1, 1);
			glVertex3f(1, -3, 1);
			glVertex3f(-1, -3, 1);
			glVertex3f(-3, -1, 1);
			glVertex3f(-3, 1, 1);
			glVertex3f(-1, 3, 1);
		}
		glEnd();

		glBegin(GL_QUAD_STRIP);
		{

			glVertex3f(-1, 3, 0);
			glVertex3f(-1, 3, 1);

			glVertex3f(1, 3, 0);
			glVertex3f(1, 3, 1);

			glVertex3f(3, 1, 0);
			glVertex3f(3, 1, 1);

			glVertex3f(3, -1, 0);
			glVertex3f(3, -1, 1);

			glVertex3f(1, -3, 0);
			glVertex3f(1, -3, 1);

			glVertex3f(-1, -3, 0);
			glVertex3f(-1, -3, 1);

			glVertex3f(-3, -1, 0);
			glVertex3f(-3, -1, 1);

			glVertex3f(-3, 1, 0);
			glVertex3f(-3, 1, 1);

			glVertex3f(-1, 3, 0);
			glVertex3f(-1, 3, 1);
		}
		glEnd();
	}
	glPopMatrix();
}

void Knight::drawCube(float scale) {

	glScalef(scale, scale, scale);
	GLfloat vertices[] =
	{
		-1, -1, -1,
		1, -1, -1,
		1, 1, -1,
		-1, 1, -1,
		-1, -1, 1,
		1, -1, 1,
		1, 1, 1,
		-1, 1, 1
	};

	GLfloat verticeA[] = { -1, -1, -1 };
	GLfloat verticeB[] = { 1, -1, -1, };
	GLfloat verticeC[] = { 1, 1, -1 };
	GLfloat verticeD[] = { -1, 1, -1 };
	GLfloat verticeE[] = { -1, -1, 1 };
	GLfloat verticeF[] = { 1, -1, 1, };
	GLfloat verticeG[] = { 1, 1, 1 };
	GLfloat verticeH[] = { -1, 1, 1 };

	GLfloat colours[] =
	{
		// -1 is now 0
		0, 0, 0,
		255, 0, 0,
		255, 255, 0,
		0, 255, 0,
		0, 0, 255,
		1, 0, 255,
		255, 255, 255,
		0, 255, 255
	};



	glBegin(GL_QUADS);
	{
		glPushMatrix();

		int i = 0;

		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeB[i], verticeB[i + 1], verticeB[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeA[i], verticeA[i + 1], verticeA[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeD[i], verticeD[i + 1], verticeD[i + 2]);
		glVertex3f(verticeC[i], verticeC[i + 1], verticeC[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);
		glVertex3f(verticeE[i], verticeE[i + 1], verticeE[i + 2]);
		glVertex3f(verticeF[i], verticeF[i + 1], verticeF[i + 2]);
		glVertex3f(verticeG[i], verticeG[i + 1], verticeG[i + 2]);
		glVertex3f(verticeH[i], verticeH[i + 1], verticeH[i + 2]);

		glPopMatrix();
	}
	glEnd();
}