// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "cube.c"

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLvoid Modelisation()
{
  struct cube1 batiment1 =creer_cube1(5);
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
	//Batiment hotel de ville
  glPushMatrix();
  {
    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
		glTranslatef(-10,0,-15);
		//1ere Tour
		glPushMatrix();{
			glDisable(GL_TEXTURE_2D);		
			glPushMatrix();{
			  glColor3f(0.572, 0.545, 0.545);
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(-3,2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//2eme Tour
			glPushMatrix();{
			  glColor3f(0.572, 0.545, 0.545);
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(3,-2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//3eme Tour
			glPushMatrix();{
			  glColor3f(0.572, 0.545, 0.545);
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(3,2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//4eme Tour
			glPushMatrix();{
			  glColor3f(0.572, 0.545, 0.545);
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(3,-2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();

		glScalef(0.6,1,0.6);
		affiche_cube1(batiment1);

		affiche_cube1(batiment1);

  }
  glPopMatrix();

	/*glPushMatrix();
	{
		glPushMatrix();{
		GLUquadric* params = gluNewQuadric();
		glRotatef(90,1,0,0);
		glTranslatef(0,1,-1.1);
		gluCylinder(params,0.5,0.5,0.4,20,1);
		gluDeleteQuadric(params);
		}
		glPopMatrix();		    
	}
	glPopMatrix();*/
  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
