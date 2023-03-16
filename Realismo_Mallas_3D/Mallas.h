#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include "glm.h"
#include "glsl.h"

class Mallas
{
	GLMmodel* objeto;

	public:
	Mallas();

	void DibujarMallas(float x, float y, float z, float tam);
	void DibujarMallasConTextura(float x, float y, float z, GLuint &texid);
	void AbrirMallas(char* nombre);
};

