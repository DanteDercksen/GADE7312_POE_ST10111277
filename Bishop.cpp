#include "Bishop.h"
#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>

void Bishop::drawGeometry(float scale, float x, float y, float z)
{

}

void Bishop::drawBody(float scale, float x, float y, float z)
{
	glTranslatef(x, y, z);
	drawBase(scale);

	//Draw cylinder (2)
	glPushMatrix();
	{
		float height = -20;
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
		float height = -16;
		float cylBottom = -15;
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
		glTranslatef(0, 16, 17);
		{
			int i, j, lats = 30, longs = 30;
			double r = 2;
			glScalef(scale, scale, scale);
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

	//Draw cone
	glPushMatrix();
	{
		glTranslatef(0, 16, 17);
		{
			glRotatef(90, -90, 0, 0);
			//Draw cone
			glBegin(GL_TRIANGLE_STRIP);
			{
				//1
				glVertex3f(-1, 2, 0);
				glVertex3f(0, 0, 4);
				//2
				glVertex3f(1, 2, 0);
				glVertex3f(0, 0, 4);
				//3
				glVertex3f(2, 1, 0);
				glVertex3f(0, 0, 4);
				//4
				glVertex3f(2, -1, 0);
				glVertex3f(0, 0, 4);
				//5
				glVertex3f(1, -2, 0);
				glVertex3f(0, 0, 4);
				//6
				glVertex3f(-1, -2, 0);
				glVertex3f(0, 0, 4);
				//7
				glVertex3f(-2, -1, 0);
				glVertex3f(0, 0, 4);
				//8
				glVertex3f(-2, 1, 0);
				glVertex3f(0, 0, 4);
				//9
				glVertex3f(-1, 2, 0);
				glVertex3f(0, 0, 4);
			}
			glEnd();
		}
	}
	glPopMatrix();
}

void Bishop::drawBase(float scale)
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