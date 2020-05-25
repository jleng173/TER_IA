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
#include "Element.hpp"
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
#include "astar.hpp"

using namespace std;

//Taille Fenetre
 int WIDTH = 1600;
 int HEIGHT = 900;

std::array<float,3> rouge={1,0,0};
std::array<float,3> bleu ={0,0,1};


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
int initGL::construction = 0;
int initGL::modeAction = 0;

float posx, posy, posz = 0.0;
float lastposx, lastposy = 0.0;
float CDposx, CDposy = 0.0;
float clickX, clickY = 0.0;
float CDposx2, CDposy2 = 0.0;
vector< vector<float> > cubes_test;
std::vector <Personnage *> listePersoInterface;
std::vector <Batiment *> listeBatimentInterface;
bool astar::obstacle[500][500];

float timeProjec = 0.0;

Carte carte;

vector<Element *> toutLesElements;


ppm p;

TEXTURE_STRUCT * initGL::Texture_chateau = p.readPpm ("./texture/castle_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_pierre = p.readPpm ("./texture/castle_walls_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_toit = p.readPpm ("./texture/roof_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_porte = p.readPpm ("./texture/gate_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_paille = p.readPpm ("./texture/straw_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_HUD = p.readPpm ("./texture/HUD_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_HUD2 = p.readPpm ("./texture/HUD2_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Guerrier = p.readPpm ("./texture/warrior.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Arbaletrier = p.readPpm ("./texture/rafter.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Paysan = p.readPpm ("./texture/peasant.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Or = p.readPpm ("./texture/coin.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Pierre = p.readPpm ("./texture/stone.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Nourriture = p.readPpm ("./texture/food.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Bois = p.readPpm ("./texture/wood.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Mouvement = p.readPpm ("./texture/move_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Stop = p.readPpm ("./texture/defend_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Attaquer = p.readPpm ("./texture/battle_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Construire = p.readPpm ("./texture/build_texture.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Caserne = p.readPpm ("./texture/barrack.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Ferme = p.readPpm ("./texture/farm.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Tour = p.readPpm ("./texture/tower.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Cancel = p.readPpm ("./texture/cancel.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Hache = p.readPpm ("./texture/hache.PPM");
TEXTURE_STRUCT * initGL::Texture_Img_Pioche = p.readPpm ("./texture/pioche.PPM");

//Arbaletrier A1(15,15,0,3);

//Guerrier Perso2(10,10,0,5);
//Arbaletrier PersoA(initGL::avance,initGL::action,10,10,0,5);

Joueur * Joueur1 = new Joueur(bleu);
Joueur * Joueur2 = new Joueur(rouge);
//Chateau ch(0,0,carte.decors,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
//Ferme ferm(Joueur1,-10,-10,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);

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

void hitboxToObstacle(Hitbox h){
  for(int i= h.x1; i <= h.x2; i++){
    for(int j= h.y1; j<= h.y2;j++){
      astar::obstacle[i+250][j+250]=true;
    }
  }
}


GLvoid Modelisation()
{
	initGL::VM_init();
	Forme f;
  //Element::current_id = 0;
  
  glPushMatrix();
  {
	 if(initGL::xpose < 50){
      initGL::xcam -= 0.2;
    }else if(initGL::xpose > WIDTH -50){
      initGL::xcam += 0.2;
    }

    if(initGL::ypose < 50){
      initGL::ycam += 0.2;
    }else if(initGL::ypose > HEIGHT -50){
      initGL::ycam -= 0.2;
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
      //std::cout << initGL::xpose << " " << initGL::ypose << std::endl;  
      if(initGL::ypose<676 && initGL::ypose>49){
        int limiteC = sqrt((carte.getTailleCarte()*2)*(carte.getTailleCarte()*2)/2);
        if( (SP.positionX + compX <= limiteC -(SP.positionY + compY)) && (SP.positionY + compY <= limiteC -(SP.positionX + compX)) && (SP.positionX + compX >= -1*limiteC +(SP.positionY + compY)) && (SP.positionY + compY >= -1*limiteC +(SP.positionX + compX))){
        //if( (SP.positionX <= limiteC -(SP.positionY )) && (SP.positionY  <= limiteC -(SP.positionX)) && (SP.positionX >= -1*limiteC +(SP.positionY )) && (SP.positionY  >= -1*limiteC +(SP.positionX ))){

            posx = SP.positionX + compX;
            posy = SP.positionY + compY;
        }
      }
      clickX = initGL::xpose;
      clickY = initGL::ypose;
    	// initGL::pose = 0;
      initGL::pose = 2;

	  }

    //Construction par un paysan en appuyant sur x
    // if(Joueur1->getUnites().size()==1 && Joueur1->getUnites()[0]->getNom()=="Paysan")
    // {
    //   // std::cout << "Construction "<< Joueur1->getUnites()[0]->getNom()<<std::endl;
    //   if(initGL::construction==1){
    //     std::cout << "Construction "<< Joueur1->getUnites()[0]->getX() << "  " << Joueur1->getUnites()[0]->getY() <<std::endl;
    //     glPushMatrix();{
    //       glEnable(GL_BLEND);
    //       glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    //       dynamic_cast<Paysan*>(Joueur1->getUnites()[0])->construireTour(Joueur1,Joueur1->getUnites()[0]->getX(),Joueur1->getUnites()[0]->getY());
    //       glDisable(GL_BLEND);
    //     }
    //     glPopMatrix();
    //     initGL::construction=0;
    //   }
    // }
	
        glPushMatrix();{   
          carte.solcarte();
        }glPopMatrix();

    
   glPushMatrix();{
      

  //reset des obstacles car hitbox peut changer à chaque tour
      for(int i = 0 ; i < 500; i++){
        for(int j = 0 ; j < 500; j++){
          astar::obstacle[i][j] = false;
        }}



  // Affichage des Unités
    // Joueur 1
      for(int i = 0 ; i < Joueur1->getUnites().size(); i++){
        Joueur1->getUnites()[i]->creerPersonnage();
        //printf(" hitbox e (%f,%f) et (%f,%f)  \n",e->getHitbox().x1,e->getHitbox().y1,e->getHitbox().x2,e->getHitbox().y2);
        toutLesElements.push_back(dynamic_cast<Element*>(Joueur1->getUnites()[i]));
        }
        Joueur1->removeElements();

    //Joueur 2
      for(int i = 0 ; i < Joueur2->getUnites().size(); i++){
        Joueur2->getUnites()[i]->creerPersonnage();
        Joueur2->getUnites()[i]->comportement(Joueur1->getUnites(),Joueur1->getBatiments(), toutLesElements);
        Joueur2->getUnites()[i]->deplacementCible(Joueur2->getUnites()[i]->lastPosition[0],Joueur2->getUnites()[i]->lastPosition[1], toutLesElements);
        toutLesElements.push_back(dynamic_cast<Element*>(Joueur2->getUnites()[i]));
      }
       Joueur2->removeElements();

  
  // Affichage des Batiments
    // Batiments Joueur 1
    glPushMatrix();{
      for(int i = 0 ; i < Joueur1->getBatiments().size(); i++){
       Joueur1->getBatiments()[i]->creerBatiment();
         if(Joueur1->getBatiments()[i]->getNom()=="Tour"){
            dynamic_cast<Tour *>(Joueur1->getBatiments()[i])->comportement(Joueur2->getUnites(),Joueur2->getBatiments(),toutLesElements);
          }
        hitboxToObstacle(Joueur1->getBatiments()[i]->getHitbox());
        //Hitbox pour le pathfinding
        //Délai de construction
        if(Joueur1->getBatiments()[i]->getEnConstruction()==true){
            if(Joueur1->getBatiments()[i]->getHp() < Joueur1->getBatiments()[i]->getHpMax())
                Joueur1->getBatiments()[i]->setHp(Joueur1->getBatiments()[i]->getHp()+1);
            if(Joueur1->getBatiments()[i]->getHp() == Joueur1->getBatiments()[i]->getHpMax())
                Joueur1->getBatiments()[i]->setEnConstruction(false);
        }
        toutLesElements.push_back(dynamic_cast<Element*>(Joueur1->getBatiments()[i]));
      }
   }glPopMatrix();

    // Batiments Joueur 2
    glPushMatrix();{
      for(int i = 0 ; i < Joueur2->getBatiments().size(); i++){
        Joueur2->getBatiments()[i]->creerBatiment();
         if(Joueur2->getBatiments()[i]->getNom()=="Tour"){
            dynamic_cast<Tour *>(Joueur2->getBatiments()[i])->comportement(Joueur1->getUnites(),Joueur1->getBatiments(),toutLesElements);
          }
                //Hitbox pour le pathfinding
        hitboxToObstacle(Joueur2->getBatiments()[i]->getHitbox());
        toutLesElements.push_back(dynamic_cast<Element*>(Joueur2->getBatiments()[i]));
      }
   }glPopMatrix();


  // Gestion déplacement des unités
      //printf("%d \n",toutLesElements.size());


      for(int i = 0 ; i < Joueur1->getUnites().size(); i++){
                            Node unite;
            unite.x = Joueur1->getUnites()[i]->getX()+250;
            unite.y = Joueur1->getUnites()[i]->getY()+250;//+15;
                  std::vector<Node> path;

            Node destination;
            destination.x = posx+250;
            destination.y = posy+250;


              //Joueur1->getUnites()[i]->tpCible(100,100);

        if(Joueur1->getUnites()[i]->isSelected() && !(unite.x-3 <= destination.x && destination.x<= unite.x+3 && unite.y-3 <= destination.y &&  destination.y<= unite.y+3)){


//A faire : deplacement de groupe, formations, autre hitbox, deplacement naturel

             for (Node node : astar::aStar(unite, destination)) {
               //Joueur1->getUnites()[i]->deplacementCible(node.x-250,node.y-250,toutLesElements);
               //Joueur1->getUnites()[i]->tpCible(node.x-250,node.y-250);
               //sleep(1);
               std::cout <<destination.x<<destination.y<< "ASTAR :" << node.x << node.y << std::endl;
                //std::cout <<destination.x<<destination.y<< " ASTARRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR : " << nodoo.x << nodoo.y << std::endl;
               if(node.x <10000 && node.y <10000){
               
                 //Joueur1->getUnites()[i]->deplacementCible(node.x-250,node.y-250,toutLesElements);
                                 //sleep(1);

Joueur1->getUnites()[i]->deplacementCible(node.x-250,node.y-250,toutLesElements);


               }
               //std::cout <<Joueur1->getUnites()[i]->getX() << "OUI OKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK" << Joueur1->getUnites()[i]->getY() << std::endl;

            }

            //test basé sur la boucle de modelisation 
            //    std::vector<Node>::iterator it;
            // if(path.empty()){
            //                  std::cout << destination.x << destination.y << "ASTAR DEBUT :"<< unite.x << unite.y << std::endl;

            //   path = astar::aStar(unite, destination);
            //   it = path.begin();
            // }

            //        it = next(it);
            //         Node node = *it;
            //   //sleep(1);
            //    Joueur1->getUnites()[i]->deplacementCible(node.x,node.y,toutLesElements);
            //    std::cout << "ASTAR :" << node.x << node.y << std::endl;

            // it = next(it);
            // if(it == path.end()){
            //   path.clear();
            // }
          }
          
        // else{

        //     Node destination;
        //     destination.x = Joueur1->getUnites()[i]->lastPosition[0]+250;
        //     destination.y = Joueur1->getUnites()[i]->lastPosition[1]+250;

        //     for (Node node : astar::aStar(player, destination)) {
        //        Joueur1->getUnites()[i]->deplacementCible(node.x,node.y,toutLesElements);
        //     }
        // }
        if(Joueur1->getUnites()[i]->isSelected()){
          Joueur1->getUnites()[i]->deplacementCible(posx,posy,toutLesElements);
        }else{
          Joueur1->getUnites()[i]->deplacementCible(Joueur1->getUnites()[i]->lastPosition[0],Joueur1->getUnites()[i]->lastPosition[1],toutLesElements);
          Joueur1->getUnites()[i]->comportement(Joueur2->getUnites(),Joueur2->getBatiments(),toutLesElements);
        }
      }

      for(int i = 0 ; i < 500; i++){
        for(int j = 0 ; j < 500; j++){
          if(astar::obstacle[i][j] == true){
            	glPushMatrix();
  	{
      	glTranslatef(i-250,j-250,4.5);
	glColor3f(0.5,0.3,0.2);
	GLUquadric* qobj;
	qobj = gluNewQuadric();
	gluCylinder(qobj, 0.3, 0.3, 3.2, 10, 16);
	}
  	glPopMatrix();
          }
        }}

  // //Gestion des tours
  //     for(int i = 0 ; i < Joueur2->getBatiments().size(); i++){
  //         if(Joueur2->getBatiments()[i]->getNom()=="Tour"){
  //           dynamic_cast<Tour *>(Joueur2->getBatiments()[i])->comportement(Joueur1->getUnites(),Joueur1->getBatiments(),toutLesElements);
  //         }
  //     }
      //printf(" coord elem %f %f \n",toutLesElements[0]->getPositionX(), toutLesElements[0]->getPositionY());
      lastposx = posx;
      lastposy = posy;

      //printf("%d \n",toutLesElements.size());

   }glPopMatrix();


    toutLesElements.clear();

  //Rectangle de sélection clique droit
  glPushMatrix();{
      if (initGL::selection == 1){
          CDposx = SP.positionX + compX;
          CDposy = SP.positionY + compY;
	    }

      if (initGL::selection == 2){
          CDposx2 = SP.positionX + compX;
          CDposy2 = SP.positionY + compY;
          lastposx = posx;
          lastposy = posy;
          Forme Fselec;
          Fselec.rectangleSelection(CDposx,CDposy,CDposx2,CDposy2);
      }

      if (initGL::selection == 3){
          listePersoInterface.clear();
          listeBatimentInterface.clear();
          for(int i = 0 ; i < Joueur1->getUnites().size(); i++){
            float xunit = Joueur1->getUnites()[i]->getX();
            float yunit = Joueur1->getUnites()[i]->getY();
            posx = 0.0;
            posy = 0.0;
            if((xunit >= CDposx) && (xunit <= CDposx2) && (yunit <= CDposy) && (yunit >= CDposy2)){
              Joueur1->getUnites()[i]->setSelected(1);
              listePersoInterface.push_back(Joueur1->getUnites()[i]);
            }else
              Joueur1->getUnites()[i]->setSelected(0);
          }

          for(int i = 0 ; i < Joueur1->getBatiments().size(); i++){
            float xunit = Joueur1->getBatiments()[i]->getX();
            float yunit = Joueur1->getBatiments()[i]->getY();
            posx = 0.0;
            posy = 0.0;
            if((xunit >= CDposx) && (xunit <= CDposx2) && (yunit <= CDposy) && (yunit >= CDposy2)){
              Joueur1->getBatiments()[i]->setSelected(1);
              listeBatimentInterface.push_back(Joueur1->getBatiments()[i]);
            }else
              Joueur1->getBatiments()[i]->setSelected(0);
          }

          
      }
    //std::cout << "END Modelisation" << std::endl;
  }glPopMatrix();


  glPushMatrix();{
  //interface
    InterfaceHUD interface(clickX, clickY, initGL::modeAction, initGL::Texture_HUD, initGL::Texture_HUD2, initGL::Texture_pierre,initGL::Texture_Img_Guerrier,initGL::Texture_Img_Paysan,initGL::Texture_Img_Arbaletrier,initGL::Texture_Img_Or,initGL::Texture_Img_Pierre,initGL::Texture_Img_Nourriture,initGL::Texture_Img_Bois, initGL::Texture_Img_Mouvement, initGL::Texture_Img_Stop, initGL::Texture_Img_Attaquer, initGL::Texture_Img_Construire, initGL::Texture_Img_Caserne, initGL::Texture_Img_Ferme, initGL::Texture_Img_Tour, initGL::Texture_Img_Cancel, initGL::Texture_Img_Hache, initGL::Texture_Img_Pioche);
    interface.creerInterfaceHUD(listePersoInterface, listeBatimentInterface, Joueur1);
    //check l'action des clicks
    initGL::modeAction=interface.ActionClick(listePersoInterface, listeBatimentInterface, Joueur1);
    // std::cout << "click " << clickX << " " << clickY << std::endl;
    clickX=0;
    clickY=0;
	}glPopMatrix();
  

  }glPopMatrix();
  glutSwapBuffers();
}


int main(int argc, char **argv){

  printf(" TEST \n");
  Batiment * castle = new Chateau(0,0,carte.decors,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
  Batiment * caserne = new Caserne(10,10,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
  Joueur1->addBatiment(castle);
  Joueur1->addBatiment(caserne);
  // Joueur1->addBatiment(tower);
  dynamic_cast<Chateau*>(castle)->creerPaysan(Joueur1);
  //dynamic_cast<Paysan*>(Joueur1->getUnites()[0])->construireTour(Joueur1,-10,-10,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
  dynamic_cast<Paysan*>(Joueur1->getUnites()[0])->construireCaserne(Joueur1,-10,-10);
  //dynamic_cast<Caserne*>(Joueur1->getBatiments()[1])->creerArbaletrier(Joueur1);
  //caser.creerGuerrier(Joueur1);

   Caserne * caser = new Caserne(40,40,initGL::Texture_chateau,initGL::Texture_pierre,initGL::Texture_toit,initGL::Texture_porte,initGL::Texture_paille);
   Joueur2->addBatiment(caser);
   caser->creerGuerrier(Joueur2);
  //dynamic_cast<Chateau*>(castle)->creerPaysan(Joueur2);

  // printf(" taille batiment %d \n",Joueur1->getBatiments().size());
  
  initGL* init = new initGL();

	init->mainInit(argc,argv,&Modelisation);

	return 0;
}
