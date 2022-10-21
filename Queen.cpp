#include "Queen.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>


void Queen::drawGeometry(float scale, float x, float y, float z)
{
	drawBody(scale, x, y, z);
}

void Queen::drawBody(float scale, float x, float y, float z)
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

	//Draw sphere
	glPushMatrix();
	{
		glTranslatef(0, 21, 17);
		{
			int i, j, lats = 30, longs = 30;
			double r = 2;
			glScalef(scale / 3, scale / 3, scale / 3);
			for (i = 0; i <= lats; i++)
			{
				double lat0 = 3.14159 * (-0.5 + (double)(i - 1) / lats);
				double z0 = sin(lat0);
				double zr0 = cos(lat0);

				double lat1 = 3.14159 * (-0.5 + (double)i / lats);
				double z1 = sin(lat1);
				double zr1 = cos(lat1);

				glBegin(GL_QUAD_STRIP);
				for (j = 0; j <= longs; j++)
				{
					double lng = 2 * 3.14159 * (double)(j - 1) / longs;
					double x = sin(lng);
					double y = cos(lng);

					glNormal3f(x * zr0, y * zr0, z0);
					glVertex3f(r * x * zr0, r * y * zr0, r * z0);
					glNormal3f(x * zr1, y * zr1, z1);
					glVertex3f(r * x * zr1, r * y * zr1, r * z1);
				}
				glEnd();
			}
		}
	}
	glPopMatrix();


	//Draw top cubes
	glPushMatrix();
	{
		glTranslatef(0, 21, 15.6);
		drawCube(0.3);
		glTranslatef(3.8, 0, 3.8);
		drawCube(1);
		glTranslatef(-3.8 * 2, 0, 0);
		drawCube(1);
		glTranslatef(3.8, 0, 3.8);
		drawCube(1);
	}
	glPopMatrix();

}

void Queen::drawBase(float scale)
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

void Queen::drawCube(float scale) {

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