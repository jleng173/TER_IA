// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "cube.c"
#include "pyramide.c"
#include "ppm.h"
#include "batiment.c"

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

TEXTURE_STRUCT * Texture_chateau;
TEXTURE_STRUCT * Texture_pierre;
TEXTURE_STRUCT * Texture_toit;
TEXTURE_STRUCT * Texture_porte;
TEXTURE_STRUCT * Texture_paille;

GLvoid Modelisation()
{

  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
  glPushMatrix();
  {
    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
		// glTranslatef(-10,0,-15);
    // creer_chateau();
    // creer_tour();
		creer_caserne();
		// creer_ferme();
  }
  glPopMatrix();

  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
