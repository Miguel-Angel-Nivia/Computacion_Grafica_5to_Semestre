#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include "glsl.h"

class Cola{
public:
	Cola();

	void DibujarCola(int n, float angulo, float x, float y, float z);
};

