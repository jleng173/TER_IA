
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ppm.h"
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>
#include <vector>
#include "Carte.hpp"
#include "Batiment.hpp"
#include "Forme.hpp"
#include "init.hpp"
#include "PositionSouris.hpp"

using namespace std;

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

vector< vector<float> > cubes_test;

Carte cforet(true);

 TEXTURE_STRUCT * initGL::Texture_chateau;
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
      initGL::xcam -= 0.1;
    }else if(initGL::xpose > WIDTH -50){
      initGL::xcam += 0.1;
    }

    if(initGL::ypose < 50){
      initGL::ycam += 0.1;
    }else if(initGL::ypose > HEIGHT -50){
      initGL::ycam -= 0.1;
    }    
	  
    //Oriente la camera 
    gluLookAt(initGL::xcam,initGL::ycam,100,
                 initGL::xcam,initGL::ycam,0,
                 0,1,0);

   //struct cube1 batiment1 =creer_cube1(5);
  
	Carte carte;

	// Matrice Vue
    float modelViewMat[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMat);
    // Matrice Projection
    float modelProjetMat[16];
    glGetFloatv(GL_PROJECTION_MATRIX, modelProjetMat);

	PositionSouris SP(modelViewMat,modelProjetMat,initGL::xpose,initGL::ypose,WIDTH,HEIGHT);

	//printf("%f %f %f / %f,%f,%f \n",initGL::xcam,initGL::ycam,initGL::z,SP.positionX,SP.positionY,SP.positionZ);


	

	if (initGL::pose == 1){
      /*posx = SP.positionX;
      posy = SP.positionY;
      posz = SP.positionZ;*/
		vector<float> add = {SP.positionX,SP.positionY,SP.positionZ};
		cubes_test.push_back(add);
    	initGL::pose = 0;
	}
	
	glPushMatrix();{
		carte.solcarte();
    cforet.Foret();
	}glPopMatrix();

  

  glPushMatrix();{
    
   // carte.Decor();
	  glColor3f(1,1,1);
	}glPopMatrix();

    if (initGL::pose == 0){
      for( int i = 0 ; i < cubes_test.size() ; i++){
        //printf("%f \n",cubes_test[i][0]);
      glPushMatrix();{   
        glTranslatef(cubes_test[i][0],cubes_test[i][1],cubes_test[i][2]);
        //glScalef(0.5,0.5,0.5);
        glRotatef(90,1.0,0.0,0.0);
        Batiment B;
        B.creerChateau();
        }glPopMatrix();

      }
    }



	}glPopMatrix();


  glutSwapBuffers();
}


int main(int argc, char **argv) {

	initGL* init = new initGL();

	init->mainInit(argc,argv,&Modelisation);
  //cforet.GenerateForet();



	return 0;
}
