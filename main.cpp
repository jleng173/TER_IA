#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <cmath>
#include <vector>
#include "ppm.hpp"
#include "Carte.hpp"
#include "InterfaceHUD.hpp"
#include "Joueur.hpp"
#include "Batiment.hpp"
#include "Chateau.hpp"
#include "Caserne.hpp"
#include "Tour.hpp"
#include "Ferme.hpp"
#include "init.hpp"
#include "PositionSouris.hpp"
#include "Personnage.hpp"
#include "Paysan.hpp"
#include "Guerrier.hpp"
#include "Arbaletrier.hpp"
#include "Element.hpp"

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

float timeProjec = 0.0;

Carte carte;

vector<shared_ptr<Element>> toutLesElements;

ppm p;

TEXTURE_STRUCT * initGL::Texture_chateau = p.readPpm ("./texture/castle_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_pierre = p.readPpm ("./texture/castle_walls_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_toit = p.readPpm ("./texture/roof_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_porte = p.readPpm ("./texture/gate_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_paille = p.readPpm ("./texture/straw_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_HUD = p.readPpm ("./texture/HUD_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_HUD2 = p.readPpm ("./texture/HUD2_texture.PPM");

Arbaletrier A1(0,1.5,0,3);

Guerrier Perso2(10,10,0,5);
//Arbaletrier PersoA(initGL::avance,initGL::action,10,10,0,5);

Joueur * Joueur1 = new Joueur();
Chateau ch(0,0,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
Caserne caser(10,10,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
Ferme ferm(Joueur1,-10,-10,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);

int compensationY(int pos){
  if(pos < -20 ) return 0;
  if(pos < -15 ) return 5;
  if(pos < -10 ) return 10;
  if(pos < -5 ) return 15;
  if(pos < 0 ) return 20;
  if(pos < 5 ) return 30;
  if(pos < 10) return 40;
  if(pos < 15) return 45;
  if(pos < 20) return 50;
 return 60;

}

int compensationX(int pos){
  if(pos < 0 ) return 0;
  if(pos < 5 ) return 2;
  if(pos < 10) return 5;
  if(pos < 15) return 7;
  if(pos < 20) return 10;
  if(pos < 25) return 13;
  if(pos < 30) return 16;
  if(pos < 40) return 19;
  if(pos < 50) return 23;
  if(pos < 70) return 28;
 return 35;

}



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

  gluLookAt(initGL::xcam,initGL::ycam-70,100,
                 initGL::xcam,initGL::ycam,0,
                 0,1,0);


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

   //struct cube1 batiment1 =creer_cube1(5);
	  //printf("%f %f %f / %f,%f,%f \n",initGL::xcam,initGL::ycam,initGL::z,SP.positionX,SP.positionY,SP.positionZ);


	  
      float compY = compensationY(SP.positionY-initGL::ycam);

      float compX = 0;
      float absolutXpos = SP.positionX-initGL::xcam;
       if(absolutXpos > 0) {
          compX = compensationX(absolutXpos);
       }
        else {
          compX = -compensationX(-absolutXpos);
        }

      if(SP.positionY >-10){
        compX /= 1;
      }else if(SP.positionY >-20){
        compX /= 2;
      }else if(SP.positionY >-30){
        compX /= 3;
      }else
      {
        compX = 0;
      }
    if (initGL::pose == 1){
      posx = SP.positionX + compX;
      posy = SP.positionY + compY;

		vector<float> add = {SP.positionX + compX,SP.positionY+compY,SP.positionZ};
		cubes_test.push_back(add);
    	initGL::pose = 0;
	  }
	
        glPushMatrix();{   
          carte.solcarte();
        }glPopMatrix();


    if (initGL::pose == 0){
      for( int i = 0 ; i < cubes_test.size() ; i++){
        //printf("%f \n",cubes_test[i][0]);
      glPushMatrix();{   
        //glScalef(0.5,0.5,0.5);
        glRotatef(90,1.0,0.0,0.0);
        Chateau C(cubes_test[i][0],cubes_test[i][1],initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
        C.creerBatiment();
        C.creerPaysan(Joueur1);

        }glPopMatrix();
      }
    }

  //PersoA.creerCarreau();
    
   glPushMatrix();{
      // printf(" thune main %d \n",Joueur1->getOr());
      for(int i = 0 ; i < Joueur1->getUnites().size(); i++){
        Joueur1->getUnites()[i]->creerPersonnage();
        Element * e = new Element(Joueur1->getUnites()[i]->getX(),Joueur1->getUnites()[i]->getY());
        e->setHitbox(Joueur1->getUnites()[i]->getHitbox);
        toutLesElements.push_back(make_shared<Element>(e));
        }

      for(int i = 0 ; i < Joueur1->getUnites().size(); i++)
        Joueur1->getUnites()[i]->deplacementCible(posx,posy,toutLesElements);
      
      
          // A1.creerPersonnage();
          // A1.deplacementCible(posx,posy);
          // A1.tirArbalete(10,10);

     glPushMatrix();{
      for(int i = 0 ; i < Joueur1->listeBatiments.size(); i++){
        Joueur1->listeBatiments[i]->creerBatiment();
      }
   }
  glPopMatrix();

  //Rectangle de sélection click
  glPushMatrix();{
      if (initGL::selection == 1){
          CDposx = SP.positionX + compX;
          CDposy = SP.positionY + compY;
	    }

      if (initGL::selection == 2){
          CDposx2 = SP.positionX + compX;
          CDposy2 = SP.positionY + compY;
          Forme Fselec;
          Fselec.rectangleSelection(CDposx,CDposy,CDposx2,CDposy2);
      }

      if (initGL::selection == 3){
          for(int i = 0 ; i < Joueur1->getUnites().size(); i++){
            float xunit = Joueur1->getUnites()[i]->getX();
            float yunit = Joueur1->getUnites()[i]->getY();
            //printf(" rec[(%f,%f)(%f,%f)]  -  Unit(%f,%f) \n",CDposx,CDposy,CDposx2,CDposy2,xunit,yunit);
            if((xunit >= CDposx) && (xunit <= CDposx2) && (yunit <= CDposy) && (yunit >= CDposy2)){
                Joueur1->getUnites()[i]->setSelected(1);
            }else
              Joueur1->getUnites()[i]->setSelected(0);
          }
      }

    }glPopMatrix();

  //interface
    InterfaceHUD interface(initGL::Texture_HUD, initGL::Texture_HUD2, initGL::Texture_pierre);
    interface.creerInterfaceHUD(Perso2, Joueur1);
	}glPopMatrix();
  
  glutSwapBuffers();
}


int main(int argc, char **argv){

  printf(" TEST \n");
  ch.creerPaysan(Joueur1);
  Paysan * pa = dynamic_cast<Paysan*>(Joueur1->getUnites()[0]);
  pa->construireCaserne(Joueur1,-10,-10,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
  caser.creerGuerrier(Joueur1);
  printf(" taille batiment %d \n",Joueur1->listeBatiments.size());
	
  
  initGL* init = new initGL();

	init->mainInit(argc,argv,&Modelisation);

  
	return 0;
}
