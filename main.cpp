
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>
#include "Carte.hpp"
#include "init.hpp"
#include "PositionSouris.hpp"


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

GLvoid Modelisation()
{
	initGL::VM_init();

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
    gluLookAt(initGL::xcam,initGL::ycam,100,
                 initGL::xcam,initGL::ycam,0,
                 0,1,0);

   //struct cube1 batiment1 =creer_cube1(5);
  
	Carte carte;
	//carte.solcarte();
  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
	//Batiment hotel de ville

    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
		/*glTranslatef(-10,0,-15);
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

		affiche_cube1(batiment1);*/

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
	glPushMatrix();{
		carte.solcarte();
	}glPopMatrix();

    if (initGL::pose == 0 && posx != 0){
       glPushMatrix();{
        
        glTranslatef(posx,posy,posz);
        glScalef(0.5,0.5,0.5);
        glRotatef(90,1.0,0.0,0.0);
        glutSolidCube(10);
      }glPopMatrix();
    }	


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
