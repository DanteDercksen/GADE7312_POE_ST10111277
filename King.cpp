#include "King.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>


void King::drawGeometry(float scale, float x, float y, float z)
{
	drawBody(scale, x, y, z);
}

void King::drawBody(float scale, float x, float y, float z)
{
	glTranslatef(x, y, z);
	drawBase(scale);
	//Draw cylinder (2)
	glPushMatrix();
	{
		float height = -30;
		float cylBottom = 0;
		glScalef(scale / 2, scale / 2, scale / 2);
		glTranslatef(0, 12, 34);

		glRotatef(90, 90, 0, 0);

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, cylBottom);
			glVertex3f(1, 3, cylBottom);
			glVertex3f(3, 1, cylBottom);
			glVertex3f(3, -1, cylBottom);
			glVertex3f(1, -3, cylBottom);
			glVertex3f(-1, -3, cylBottom);
			glVertex3f(-3, -1, cylBottom);
			glVertex3f(-3, 1, cylBottom);
			glVertex3f(-1, 3, cylBottom);
		}
		glEnd();

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, height);
			glVertex3f(1, 3, height);
			glVertex3f(3, 1, height);
			glVertex3f(3, -1, height);
			glVertex3f(1, -3, height);
			glVertex3f(-1, -3, height);
			glVertex3f(-3, -1, height);
			glVertex3f(-3, 1, height);
			glVertex3f(-1, 3, height);
		}
		glEnd();

		glBegin(GL_QUAD_STRIP);
		{

			glVertex3f(-1, 3, cylBottom);
			glVertex3f(-1, 3, height);

			glVertex3f(1, 3, cylBottom);
			glVertex3f(1, 3, height);

			glVertex3f(3, 1, cylBottom);
			glVertex3f(3, 1, height);

			glVertex3f(3, -1, cylBottom);
			glVertex3f(3, -1, height);

			glVertex3f(1, -3, cylBottom);
			glVertex3f(1, -3, height);

			glVertex3f(-1, -3, cylBottom);
			glVertex3f(-1, -3, height);

			glVertex3f(-3, -1, cylBottom);
			glVertex3f(-3, -1, height);

			glVertex3f(-3, 1, cylBottom);
			glVertex3f(-3, 1, height);

			glVertex3f(-1, 3, cylBottom);
			glVertex3f(-1, 3, height);
		}
		glEnd();
	}
	glPopMatrix();

	//Draw cylinder (3)
	glPushMatrix();
	{
		float height = -22;
		float cylBottom = -21;
		glScalef(scale / 1.4, scale / 1.4, scale / 1.4);
		glTranslatef(0, 5, 24);

		glRotatef(90, 90, 0, 0);

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, cylBottom);
			glVertex3f(1, 3, cylBottom);
			glVertex3f(3, 1, cylBottom);
			glVertex3f(3, -1, cylBottom);
			glVertex3f(1, -3, cylBottom);
			glVertex3f(-1, -3, cylBottom);
			glVertex3f(-3, -1, cylBottom);
			glVertex3f(-3, 1, cylBottom);
			glVertex3f(-1, 3, cylBottom);
		}
		glEnd();

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, height);
			glVertex3f(1, 3, height);
			glVertex3f(3, 1, height);
			glVertex3f(3, -1, height);
			glVertex3f(1, -3, height);
			glVertex3f(-1, -3, height);
			glVertex3f(-3, -1, height);
			glVertex3f(-3, 1, height);
			glVertex3f(-1, 3, height);
		}
		glEnd();

		glBegin(GL_QUAD_STRIP);
		{

			glVertex3f(-1, 3, cylBottom);
			glVertex3f(-1, 3, height);

			glVertex3f(1, 3, cylBottom);
			glVertex3f(1, 3, height);

			glVertex3f(3, 1, cylBottom);
			glVertex3f(3, 1, height);

			glVertex3f(3, -1, cylBottom);
			glVertex3f(3, -1, height);

			glVertex3f(1, -3, cylBottom);
			glVertex3f(1, -3, height);

			glVertex3f(-1, -3, cylBottom);
			glVertex3f(-1, -3, height);

			glVertex3f(-3, -1, cylBottom);
			glVertex3f(-3, -1, height);

			glVertex3f(-3, 1, cylBottom);
			glVertex3f(-3, 1, height);

			glVertex3f(-1, 3, cylBottom);
			glVertex3f(-1, 3, height);
		}
		glEnd();
	}
	glPopMatrix();

	//Vertical KingTop
	{
		//1
		glPushMatrix();
		{
			glTranslatef(0, 2.5, 2);
			drawCube(0.05);
		}
		glPopMatrix();
		//2
		glPushMatrix();
		{
			glTranslatef(0, 2.6, 2);
			drawCube(0.05);
		}
		glPopMatrix();
		//3
		glPushMatrix();
		{
			glTranslatef(0, 2.7, 2);
			drawCube(0.05);
		}
		glPopMatrix();
		//4
		glPushMatrix();
		{
			glTranslatef(0, 2.8, 2);
			drawCube(0.05);
		}
		glPopMatrix();
	}

	//Horizontal KingTop
	{
		glPushMatrix();
		{
			glTranslatef(0.1, 2.7, 2);
			drawCube(0.05);
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(-0.1, 2.7, 2);
			drawCube(0.05);
		}
		glPopMatrix();
	}

}

void King::drawBase(float scale)
{
	//Draw cylinder


	float y = 1;
	float j = 0;
	glPushMatrix();
	{
		glScalef(scale, scale, scale);
		glTranslatef(0, 7, 17);

		glRotatef(90, 90, 0, 0);

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, j);
			glVertex3f(1, 3, j);
			glVertex3f(3, 1, j);
			glVertex3f(3, -1, j);
			glVertex3f(1, -3, j);
			glVertex3f(-1, -3, j);
			glVertex3f(-3, -1, j);
			glVertex3f(-3, 1, j);
			glVertex3f(-1, 3, j);
		}
		glEnd();

		glBegin(GL_POLYGON);
		{
			glVertex3f(-1, 3, y);
			glVertex3f(1, 3, y);
			glVertex3f(3, 1, y);
			glVertex3f(3, -1, y);
			glVertex3f(1, -3, y);
			glVertex3f(-1, -3, y);
			glVertex3f(-3, -1, y);
			glVertex3f(-3, 1, y);
			glVertex3f(-1, 3, y);
		}
		glEnd();

		glBegin(GL_QUAD_STRIP);
		{

			glVertex3f(-1, 3, j);
			glVertex3f(-1, 3, y);

			glVertex3f(1, 3, j);
			glVertex3f(1, 3, y);

			glVertex3f(3, 1, j);
			glVertex3f(3, 1, y);

			glVertex3f(3, -1, j);
			glVertex3f(3, -1, y);

			glVertex3f(1, -3, j);
			glVertex3f(1, -3, y);

			glVertex3f(-1, -3, j);
			glVertex3f(-1, -3, y);

			glVertex3f(-3, -1, j);
			glVertex3f(-3, -1, y);

			glVertex3f(-3, 1, j);
			glVertex3f(-3, 1, y);

			glVertex3f(-1, 3, j);
			glVertex3f(-1, 3, y);
		}
		glEnd();
	}
	glPopMatrix();
}

void King::drawCube(float scale) {

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