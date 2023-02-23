#include "Triangulos.h"

Triangulos::Triangulos(){
}

void Triangulos::DibujarTriangulos(float x, float y, float z){
glPushMatrix();
	glTranslatef(x, y, z);
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5, 0, 0);
		glVertex3f(0, 0.5, 0);
		glVertex3f(0.5, 0, 0);
	glEnd();
glPopMatrix();
}