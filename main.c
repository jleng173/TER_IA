// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "./carte.c"
#include "init.h"
#include "axes.h"
#include "VM_init.h"

//CAMERA
float xcam = 0.0;
float ycam = 0.0;

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -15.0f; 

GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

  glPushMatrix();
  {
    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
    gluLookAt(ycam,25,-25+xcam,
					    ycam,2,xcam,
					    0,1,0);
    solcarte();
  }
  glPopMatrix();


  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
