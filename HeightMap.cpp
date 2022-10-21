#include "HeightMap.h"
#include "Texture.h"
#include <iostream>
#include <GL/glut.h>
#include <random>
#include "Texture.h"

void HeightMap::DrawMap(float maxHeight, float size, Texture* texture) {

	glPushMatrix();
	glTranslatef(-size / 2.0, 0, -size / 2.0);

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{

			Pixel p0 = texture->getPixelAt(1, 1);
			Pixel p1 = texture->getPixelAt(x, y);
			Pixel p2 = texture->getPixelAt(x, y + 1);
			Pixel p3 = texture->getPixelAt(x + 1, y);
			Pixel p4 = texture->getPixelAt(x + 1, y + 1);

			float vy1 = p1.r * maxHeight;
			float vx1 = (float)x / (float)width * size;
			float vz1 = (float)y / (float)height * size;

			float vy2 = p2.r * maxHeight;
			float vx2 = (float)x / (float)width * size;
			float vz2 = (float)(y + 1) / (float)height * size;

			float vy3 = p3.r * maxHeight;
			float vx3 = (float)(x + 1) / (float)width * size;
			float vz3 = (float)y / (float)height * size;

			float vy4 = p4.r * maxHeight;
			float vx4 = (float)(x + 1) / (float)width * size;
			float vz4 = (float)(y + 1) / (float)height * size;


			glBegin(GL_TRIANGLE_STRIP);
			{
				glColor3f(p1.r, p1.r, p1.r);
				glVertex3f(vx1, vy1, vz1);

				glColor3f(p2.r, p2.r, p2.r);
				glVertex3f(vx2, vy2, vz2);

				glColor3f(p3.r, p3.r, p3.r);
				glVertex3f(vx3, vy3, vz3);

				glColor3f(p4.r, p4.r, p4.r);
				glVertex3f(vx4, vy4, vz4);
			}
			glEnd();
		}
	}

	glPopMatrix();
}