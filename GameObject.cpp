#include "GameObject.h"
#include <iostream>
#include <GL/glut.h>




/// rgb
/// xyz

void GameObject::drawOrigin() {

	glBegin(GL_LINES);
	{
		//draw x-axis
		//glRotatef(45,1, 1, 1);
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);

		//draw y-axis
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);

		//draw z-axis
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);


	}
	glEnd();

	glPushMatrix();
	{

		glColor3f(1, 0, 0);
		glTranslatef(1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glutSolidCone(0.1, 0.15, 6, 1);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glColor3f(0, 1, 0);
		glTranslatef(0, 1, 0);
		glRotatef(-90, 1, 0, 0);
		glutSolidCone(0.1, 0.15, 6, 1);
	}
	glPopMatrix();


	glPushMatrix();
	{
		glColor3f(0, 0, 1);
		//glRotatef(45,1,0,0);
		glTranslatef(0, 0, 1);
		glutSolidCone(0.1, 0.15, 6, 1);
	}
	glPopMatrix();



}

void GameObject::drawGeometry() {

	glColor3f(1, 1, 1);
	glutSolidCube(1);
}

void GameObject::draw() {
	drawGeometry();
	glDisable(GL_DEPTH_TEST);
	drawOrigin();
	glEnable(GL_DEPTH_TEST);
}