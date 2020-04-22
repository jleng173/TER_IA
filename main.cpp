#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>
#include <vector>
#include "ppm.hpp"
#include "Carte.hpp"
#include "Batiment.hpp"
#include "init.hpp"
#include "PositionSouris.hpp"
#include "Personnage.hpp"
#include "Paysan.hpp"
#include "Guerrier.hpp"

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
float initGL::avance = 0.0;
float initGL::action = 0.0;
float initGL::mouv = 0.0;
int initGL::selection = 0;

float posx, posy, posz = 0.0;
float CDposx, CDposy = 0.0;
float CDposx2, CDposy2 = 0.0;
vector< vector<float> > cubes_test;

  	Carte carte;

ppm p;

TEXTURE_STRUCT * initGL::Texture_chateau = p.readPpm ("./texture/castle_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_pierre = p.readPpm ("./texture/castle_walls_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_toit = p.readPpm ("./texture/roof_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_porte = p.readPpm ("./texture/gate_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_paille = p.readPpm ("./texture/straw_texture.PPM");

Paysan Perso1(initGL::avance,initGL::action,0,0,0,3);

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
  glViewport(0, 0, WIDTH, HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)WIDTH/(GLfloat)HEIGHT,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);

	// Matrice Vue
    float modelViewMat[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMat);
    // Matrice Projection
    float modelProjetMat[16];
    glGetFloatv(GL_PROJECTION_MATRIX, modelProjetMat);

	PositionSouris SP(modelViewMat,modelProjetMat,initGL::xpose,initGL::ypose,WIDTH,HEIGHT);

  glViewport(0, 0, WIDTH, HEIGHT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)WIDTH/(GLfloat)HEIGHT,0.1f,1000.0f);
  glMatrixMode(GL_MODELVIEW);

	//printf("%f %f %f / %f,%f,%f \n",initGL::xcam,initGL::ycam,initGL::z,SP.positionX,SP.positionY,SP.positionZ);


	if (initGL::pose == 1){
      posx = SP.positionX;
      posy = SP.positionY;
      posz = SP.positionZ;
		vector<float> add = {SP.positionX,SP.positionY,0};
		cubes_test.push_back(add);
    	initGL::pose = 0;
	}
	
  

        glPushMatrix();{   
          carte.solcarte();
        }glPopMatrix();


    if (initGL::pose == 0){
      // for( int i = 0 ; i < cubes_test.size() ; i++){
      //   //printf("%f \n",cubes_test[i][0]);
      // glPushMatrix();{   
      //   glTranslatef(cubes_test[i][0],cubes_test[i][1],cubes_test[i][2]);
      //   //glScalef(0.5,0.5,0.5);
      //   glRotatef(90,1.0,0.0,0.0);
      //   Batiment B(initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
      //   B.creerChateau();
      //   }glPopMatrix();
      // }
    }
    
   glPushMatrix();{
          
          Perso1.creerPersonnage();
          Perso1.deplacementCible(posx,posy);
          //printf(" %f , %f \n",Perso1.orientation, Perso1.velocite[1]);
   }
  glPopMatrix();

  //  glPushMatrix();{
  //         Personnage Perso2(initGL::avance,initGL::action,5,5,0,3,initGL::mouv);
  //         Perso2.creerPersonnage();
  // }glPopMatrix();


  glPushMatrix();{
      if (initGL::selection == 1){
          CDposx = SP.positionX;
          CDposy = SP.positionY;
	    }

      if (initGL::selection == 2){
          CDposx2 = SP.positionX;
          CDposy2 = SP.positionY;
          Forme Fselec;
          Fselec.rectangleSelection(CDposx,CDposy,CDposx2,CDposy2);
          //initGL::selection = 2;
      }


  }glPopMatrix();




	}glPopMatrix();

  glutSwapBuffers();
}


int main(int argc, char **argv) {


	initGL* init = new initGL();


	init->mainInit(argc,argv,&Modelisation);


	return 0;
}
