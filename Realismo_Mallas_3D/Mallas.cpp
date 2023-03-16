#include "Mallas.h"

Mallas::Mallas() {
}

void Mallas::AbrirMallas(char* nombre) {
	objeto = NULL;

	if (!objeto)
	{
		objeto = glmReadOBJ(nombre);
		if (!objeto)
			exit(0);

		glmUnitize(objeto);
		glmFacetNormals(objeto);
		glmVertexNormals(objeto, 90.0);
	}
}


void Mallas::DibujarMallas(float x, float y, float z, float tam) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(tam, tam, tam);
	glmDraw(objeto, GLM_SMOOTH | GLM_MATERIAL);
	glPopMatrix();
}

void Mallas::DibujarMallasConTextura(float x, float y, float z, GLuint &texid) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texid);
	glmDraw(objeto, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
	glPopMatrix();
}