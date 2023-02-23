#include "Cola.h"

Cola::Cola(){
}

void Cola::DibujarCola(int n, float angulo, float x, float y, float z){
	glPushMatrix();
		glTranslatef(x, y, z);

		// Aqui se reutilizo y modifico codigo de http://www.glprogramming.com/red/chapter03.html

		// Creacion del brazo de robot con pivote en la conexion entre los dos rectangulos.
		glPushMatrix();
			glTranslatef(-0.25, 0.0, 0.0);
			glRotatef(angulo, 0.0, 0.0, 1.0);
			glTranslatef(0.25, 0.0, 0.0);
			glPushMatrix();
				glScalef(0.75, 0.2, 1.0);
				glutSolidCube(1.0);
			glPopMatrix();

			for (int i = 0; i < n; i++){
				glTranslatef(0.25, 0.0, 0.0);
				glRotatef(angulo + (2*i), 0.0, 0.0, 1.0);
				glTranslatef(0.25, 0.0, 0.0);
				glPushMatrix();
					glScalef(0.75, 0.2, 1.0);
					glutSolidCube(1.0);
				glPopMatrix();
			}

		glPopMatrix();

	glPopMatrix();
}
