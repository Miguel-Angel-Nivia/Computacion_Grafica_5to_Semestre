//=============================================================================
// Sample Application: Lighting (Per Fragment Phong)
//=============================================================================

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm.h"
#include <FreeImage.h> //*** Para Textura: Incluir librería

// Include de clases
#include "Mallas.h"

//-----------------------------------------------------------------------------


class myWindow : public cwc::glutWindow
{
protected:
   cwc::glShaderManager SM;
   cwc::glShader *shader1;
   cwc::glShader* shader2; //Para Textura: variable para abrir los shader de textura
   GLuint ProgramObject;
   clock_t time0,time1;
   float timer010;  // timer counting 0->1->0
   bool bUp;        // flag if counting up or down.
   GLuint texid; //*** Para Textura: variable que almacena el identificador de textura

   Mallas* miMalla1;
   Mallas* miMalla2;
   Mallas* miMalla3;
   Mallas* miMalla4;
   Mallas* miMalla5;
   Mallas* miMalla6;
   Mallas* miMalla7;
   Mallas* miMalla8;
   Mallas* miMalla9;
   Mallas* miMalla10;
   Mallas* miMalla11;
   Mallas* miMalla12;
   Mallas* miMalla13;
   Mallas* miMalla14;
   Mallas* miMalla15;

public:
	myWindow(){}

	//*** Para Textura: aqui adiciono un método que abre la textura en JPG
	void initialize_textures(void)
	{
		int w, h;
		GLubyte* data = 0;
		//data = glmReadPPM("soccer_ball_diffuse.ppm", &w, &h);
		//std::cout << "Read soccer_ball_diffuse.ppm, width = " << w << ", height = " << h << std::endl;

		//dib1 = loadImage("soccer_ball_diffuse.jpg"); //FreeImage

		glGenTextures(1, &texid);
		glBindTexture(GL_TEXTURE_2D, texid);
		glTexEnvi(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		// Loading JPG file
		FIBITMAP* bitmap = FreeImage_Load(
			FreeImage_GetFileType("./Mallas/bola.jpg", 0),
			"./Mallas/bola.jpg");  //*** Para Textura: esta es la ruta en donde se encuentra la textura

		FIBITMAP* pImage = FreeImage_ConvertTo32Bits(bitmap);
		int nWidth = FreeImage_GetWidth(pImage);
		int nHeight = FreeImage_GetHeight(pImage);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, nWidth, nHeight,
			0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(pImage));

		FreeImage_Unload(pImage);
		//
		glEnable(GL_TEXTURE_2D);
	}


	virtual void OnRender(void)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
      //timer010 = 0.09; //for screenshot!

      glPushMatrix();
	  glRotatef(timer010 * 360, 0.5, 1.0f, 0.1f);   // Rotacion del mundo

	  // ***************************** Dibujar Malla *********************************

      if (shader1) shader1->begin();
		  
		miMalla1->DibujarMallas(0, -1.4, 0);	  // Suelo
		miMalla2->DibujarMallas(-1.5, 0, 0);  // Silla
		miMalla3->DibujarMallas(3, 0, 0.5);   // Mini Silla
		miMalla4->DibujarMallas(-3, 0, 0);  // Mesa Comun
		miMalla5->DibujarMallas(3, 0, 0);   // Mesa Con Cajones
		miMalla6->DibujarMallas(0, 0, 0);  // Mesa Octogonal
		miMalla7->DibujarMallas(2, 0, -2);   // Estanteria
		miMalla8->DibujarMallas(2, 0, 2);  // Armario 2 Puertas
		miMalla9->DibujarMallas(-2, 0, 2);   // Armario 3 Puertas
		miMalla10->DibujarMallas(1.5, 0, -0.8);  // Persona observadora
		miMalla11->DibujarMallas(-1, 0, -3);  // Perosna Agachada
		miMalla12->DibujarMallas(-1.8, 0, -3); // Persona Tropezando
		miMalla13->DibujarMallas(0, 0, -3); // Personaje Principal Sentado
		miMalla14->DibujarMallas(1, 0, -1.5); // Persona Sentado
		miMalla15->DibujarMallas(3, 0, -4);  // Casa

      if (shader1) shader1->end();

	  //*** Para Textura: llamado al shader para objetos texturizados
	  /*if (shader2) shader2->begin();

		  glPushMatrix();
		  glTranslatef(1.5f, 0.0f, 0.0f);
		  glBindTexture(GL_TEXTURE_2D, texid);
		  glmDraw(objeto2, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
		  glPopMatrix();
	  if (shader2) shader2->end();*/

      glutSwapBuffers();
      glPopMatrix();

      UpdateTimer();

		Repaint();
	}

	virtual void OnIdle() {}

	// When OnInit is called, a render context (in this case GLUT-Window) 
	// is already available!
	virtual void OnInit()
	{
		// Creamos las nuevas mallas
		miMalla1 = new Mallas();
		miMalla2 = new Mallas();
		miMalla3 = new Mallas();
		miMalla4 = new Mallas();
		miMalla5 = new Mallas();
		miMalla6 = new Mallas();
		miMalla7 = new Mallas();
		miMalla8 = new Mallas();
		miMalla9 = new Mallas();
		miMalla10 = new Mallas();
		miMalla11 = new Mallas();
		miMalla12 = new Mallas();
		miMalla13 = new Mallas();
		miMalla14 = new Mallas();
		miMalla15 = new Mallas();

		glTranslatef(0.0f, 0.0f, -5.0f);		// Espacio en el mundo
		glClearColor(0.5f, 0.5f, 1.0f, 0.0f);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);

		shader1 = SM.loadfromFile("vertexshader.txt","fragmentshader.txt"); // load (and compile, link) from file
		if (shader1==0) 
         std::cout << "Error Loading, compiling or linking shader\n";
		else
		{
			ProgramObject = shader1->GetProgramObject();
		}

	 //*** Para Textura: abre los shaders para texturas
		shader2 = SM.loadfromFile("vertexshaderT.txt", "fragmentshaderT.txt"); // load (and compile, link) from file
		if (shader2 == 0)
			std::cout << "Error Loading, compiling or linking shader\n";
		else
		{
			ProgramObject = shader2->GetProgramObject();
		}

      time0 = clock();
      timer010 = 0.0f;
      bUp = true;

	  // **************************** Abrir mallas *************************************

	  miMalla1->AbrirMallas("./Mallas/Suelo.obj");
	  miMalla2->AbrirMallas("./Mallas/silla.obj");
	  miMalla3->AbrirMallas("./Mallas/mini_Silla.obj");
	  miMalla4->AbrirMallas("./Mallas/mesa_Comun.obj");
	  miMalla5->AbrirMallas("./Mallas/mesa_con_Cajones.obj");
	  miMalla6->AbrirMallas("./Mallas/mesa_Octogonal.obj");
	  miMalla7->AbrirMallas("./Mallas/estanteria.obj");
	  miMalla8->AbrirMallas("./Mallas/armario_2_puertas.obj");
	  miMalla9->AbrirMallas("./Mallas/armario_3_puertas.obj");
	  miMalla10->AbrirMallas("./Mallas/persona_observadora.obj");
	  miMalla11->AbrirMallas("./Mallas/persona_agachada.obj");
	  miMalla12->AbrirMallas("./Mallas/persona_tropezando.obj");
	  miMalla13->AbrirMallas("./Mallas/Personaje_principal_Sentado.obj");
	  miMalla14->AbrirMallas("./Mallas/Personaje_Sentado.obj");
	  miMalla15->AbrirMallas("./Mallas/casa.obj");
 
	  //*** Para Textura: abrir archivo de textura
	  initialize_textures();
      DemoLight();

	}

	virtual void OnResize(int w, int h)
   {
      if(h == 0) h = 1;
	   float ratio = 1.0f * (float)w / (float)h;

      glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	
	   glViewport(0, 0, w, h);

      gluPerspective(45,ratio,1,100);
	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity();
	   gluLookAt(0.0f,0.0f,4.0f, 
		          0.0,0.0,-1.0,
			       0.0f,1.0f,0.0f);
   }
	virtual void OnClose(void){}
	virtual void OnMouseDown(int button, int x, int y) {}    
	virtual void OnMouseUp(int button, int x, int y) {}
	virtual void OnMouseWheel(int nWheelNumber, int nDirection, int x, int y){}

	virtual void OnKeyDown(int nKey, char cAscii)
	{       
		if (cAscii == 27) // 0x1b = ESC
		{
			this->Close(); // Close Window!
		} 
	};

	virtual void OnKeyUp(int nKey, char cAscii)
	{
      if (cAscii == 's')      // s: Shader
         shader1->enable();
      else if (cAscii == 'f') // f: Fixed Function
         shader1->disable();
	}

   void UpdateTimer()
   {
      time1 = clock();
      float delta = static_cast<float>(static_cast<double>(time1-time0)/static_cast<double>(CLOCKS_PER_SEC));
      delta = delta / 4;
      if (delta > 0.00005f)
      {
         time0 = clock();
         if (bUp)
         {
            timer010 += delta;
            if (timer010>=1.0f) { timer010 = 1.0f; bUp = false;}
         }
         else
         {
            timer010 -= delta;
            if (timer010<=0.0f) { timer010 = 0.0f; bUp = true;}
         }
      }
   }

   void DemoLight(void)
   {
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_NORMALIZE);
   }
};

//-----------------------------------------------------------------------------

class myApplication : public cwc::glApplication
{
public:
	virtual void OnInit() {std::cout << "Hello World!\n"; }
};

//-----------------------------------------------------------------------------

int main(void)
{
	myApplication*  pApp = new myApplication;
	myWindow* myWin = new myWindow();

	pApp->run();
	delete pApp;
	return 0;
}

//-----------------------------------------------------------------------------

