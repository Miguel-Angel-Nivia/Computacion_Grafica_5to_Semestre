#include "Cubos.h"

Cubos::Cubos(){
}

void Cubos::DibujarCubos(float x, float y, float z, float prof, float tam){
	glPushMatrix();
		// glRotatef(30, 0, 0, 1);
		glTranslatef(x, y, z);
		glRotatef(prof, 0, 0, 1);
		glutSolidCube(tam);
	glPopMatrix();
}
