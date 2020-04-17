
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>

#include "init.hpp"

struct cube1 {
	float sommet8[3];
	float sommet7[3];
	float sommet6[3];
	float sommet5[3];
	float sommet4[3];
	float sommet3[3];
	float sommet2[3];
	float sommet1[3];
	float face6[4][3];
	float face5[4][3];
	float face4[4][3];
	float face3[4][3];
	float face2[4][3];
	float face1[4][3];
	float couleur6[3];
	float couleur5[3];
	float couleur4[3];
	float couleur3[3];
	float couleur2[3];
	float couleur1[3];
};

struct cube1 creer_cube1(float taille){
	struct cube1 cube; 
	cube.sommet8[0]=-taille;
	cube.sommet8[1]=-taille;
	cube.sommet8[2]=taille;

	cube.sommet7[0]=taille;
	cube.sommet7[1]=-taille;
	cube.sommet7[2]=taille;

	cube.sommet6[0]=taille;
	cube.sommet6[1]=taille;
	cube.sommet6[2]=taille;

	cube.sommet5[0]=-taille;
	cube.sommet5[1]=taille;
	cube.sommet5[2]=taille;

	cube.sommet4[0]=-taille;
	cube.sommet4[1]=-taille;
	cube.sommet4[2]=-taille;

	cube.sommet3[0]=-taille;
	cube.sommet3[1]=taille;
	cube.sommet3[2]=-taille;

	cube.sommet2[0]=taille;
	cube.sommet2[1]=taille;
	cube.sommet2[2]=-taille;

	cube.sommet1[0]=taille;
	cube.sommet1[1]=-taille;
	cube.sommet1[2]=-taille;

	return cube;
}

GLvoid affiche_cube1(struct cube1 cube){
	glPushMatrix();
		{
			glBegin(GL_QUADS);
			/* 1er face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet8[0],cube.sommet8[1],cube.sommet8[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet7[0],cube.sommet7[1],cube.sommet7[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet6[0],cube.sommet6[1],cube.sommet6[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet5[0],cube.sommet5[1],cube.sommet5[2]);
			}
			glPopMatrix();

			/* 2e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet4[0],cube.sommet4[1],cube.sommet4[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet3[0],cube.sommet3[1],cube.sommet3[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet2[0],cube.sommet2[1],cube.sommet2[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet1[0],cube.sommet1[1],cube.sommet1[2]);
			}
			glPopMatrix();

			/* 3e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet3[0],cube.sommet3[1],cube.sommet3[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet5[0],cube.sommet5[1],cube.sommet5[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet6[0],cube.sommet6[1],cube.sommet6[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet2[0],cube.sommet2[1],cube.sommet2[2]);
			}
			glPopMatrix();

			/* 4e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet4[0],cube.sommet4[1],cube.sommet4[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet1[0],cube.sommet1[1],cube.sommet1[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet7[0],cube.sommet7[1],cube.sommet7[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet8[0],cube.sommet8[1],cube.sommet8[2]);
			}
			glPopMatrix();
		
			/* 5e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet1[0],cube.sommet1[1],cube.sommet1[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet2[0],cube.sommet2[1],cube.sommet2[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet6[0],cube.sommet6[1],cube.sommet6[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet7[0],cube.sommet7[1],cube.sommet7[2]);
			}
			glPopMatrix();
			/* 6e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet4[0],cube.sommet4[1],cube.sommet4[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet8[0],cube.sommet8[1],cube.sommet8[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet5[0],cube.sommet5[1],cube.sommet5[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet3[0],cube.sommet3[1],cube.sommet3[2]);
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();
}


GLvoid Modelisation()
{
	initGL::VM_init();
  struct cube1 batiment1 =creer_cube1(5);
  

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
  glutSwapBuffers();
}

   float initGL::z = 0;
   float initGL::xrot = 0;
   float initGL::yrot = 0;
   int initGL::blend = 1;

int main(int argc, char **argv) {

	initGL* init = new initGL();

	init->mainInit(argc,argv,&Modelisation);




	return 0;
}
