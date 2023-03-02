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


void Mallas::DibujarMallas(float x, float y, float z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glmDraw(objeto, GLM_SMOOTH | GLM_MATERIAL);
	glPopMatrix();
}