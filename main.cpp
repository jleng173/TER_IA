
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ppm.h"
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>
#include "Carte.hpp"
#include "Batiment.hpp"
#include "Forme.hpp"
#include "init.hpp"
#include "PositionSouris.hpp"

//Taille Fenetre
 int WIDTH = 1600;
 int HEIGHT = 900;

float initGL::z = 0;
float initGL::xrot = 0;
float initGL::yrot = 0;
int initGL::blend = 1;
float initGL::xcam = 0.0;
float initGL::ycam = 0.0;
int initGL::pose = 0;
float initGL::xpose = 100.0;
float initGL::ypose = 100.0;

float posx, posy, posz = 0.0;

// TEXTURE_STRUCT * initGL::Texture_chateau;
// TEXTURE_STRUCT * initGL::Texture_pierre;
// TEXTURE_STRUCT * initGL::Texture_toit;
// TEXTURE_STRUCT * initGL::Texture_porte;
// TEXTURE_STRUCT * initGL::Texture_paille;

GLvoid Modelisation()
{
	initGL::VM_init();
	Forme f;
  glPushMatrix();
  {
	 if(initGL::xpose < 50){
      initGL::xcam -= 0.02;
    }else if(initGL::xpose > WIDTH -50){
      initGL::xcam += 0.02;
    }

    if(initGL::ypose < 50){
      initGL::ycam += 0.02;
    }else if(initGL::ypose > HEIGHT -50){
      initGL::ycam -= 0.02;
    }      
    //Oriente la camera 
    gluLookAt(initGL::xcam,initGL::ycam,85,
                 initGL::xcam,initGL::ycam,0,
                 0,1,0);

  struct cube1 batiment1 =f.creerCube(5);
  
	Carte carte;
	carte.solcarte();
  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
	//Batiment hotel de ville

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

      Batiment b;
      b.creerTour();

		glScalef(0.6,1,0.6);
		f.afficheCube(batiment1);

		f.afficheCube(batiment1);

		// Matrice Vue
    	float modelViewMat[16];
    	glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMat);
    	// Matrice Projection
    	float modelProjetMat[16];
    	glGetFloatv(GL_PROJECTION_MATRIX, modelProjetMat);

		PositionSouris SP(modelViewMat,modelProjetMat,initGL::xpose,initGL::ypose,WIDTH,HEIGHT);

		printf("%f %f %f / %f,%f,%f \n",initGL::xcam,initGL::ycam,initGL::z,SP.positionX,SP.positionY,SP.positionZ);

	if (initGL::pose == 1){
      posx = SP.positionX;
      posy = SP.positionY;
      posz = SP.positionZ;
      initGL::pose = 0;
    }
    if (initGL::pose == 0 && posx != 0){
       glPushMatrix();{
        
        glTranslatef(posx,posy,posz);
        glScalef(0.5,0.5,0.5);
        glRotatef(90,1.0,0.0,0.0);
        glutSolidCube(50);
      }glPopMatrix();
    }	

		glPushMatrix();{
			carte.solcarte();
		}glPopMatrix();
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


int main(int argc, char **argv) {

	initGL* init = new initGL();

	init->mainInit(argc,argv,&Modelisation);




	return 0;
}
