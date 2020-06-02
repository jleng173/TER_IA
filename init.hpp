#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>
#include "touches.h"
#include "ppm.hpp"



#ifndef __INIT
#define __INIT

class initGL {
public:
	// Constructor
	initGL();

	//Destructor
	~initGL();

	//init
	int mainInit(int argc, char** argv, void (*DrawGLScene)(),int WIDTH, int HEIGHT);

	static void VM_init();


private: 
	// init
	void generalInit(unsigned int width,unsigned int height);
	static void touche_pressee(unsigned char key, int x, int y) ;
	static void specialKeyPressed(int key, int x, int y);
	static GLvoid ReSizeGLScene(int m_width,int m_height);
	static void mouseClicks(int button, int state, int x, int y);
	static void mouseMove(int x, int y);

protected:

	unsigned int m_width;
	unsigned int m_height;

	/* The number of our GLUT window */
	int window; 



//VM_init
 float hauteur;
 float avs;
 float av;
 int lightswap;

 public:
	//Main
 static float z;
 static float xrot;   
 static float yrot; 
 static int  blend;
 static float xcam;
 static float ycam;
 static int pose;
 static float xpose;
 static float ypose;
 static float avance;
 static float action;
 static float mouv;
 static int selection;
 static int construction;
 static int modeAction;		    //Sert a changer le menu du Paysan
 static TEXTURE_STRUCT * Texture_chateau;
 static TEXTURE_STRUCT * Texture_pierre;
 static TEXTURE_STRUCT * Texture_toit;
 static TEXTURE_STRUCT * Texture_porte;
 static TEXTURE_STRUCT * Texture_paille;
 static TEXTURE_STRUCT * Texture_HUD;
 static TEXTURE_STRUCT * Texture_HUD2;
 static TEXTURE_STRUCT * Texture_Img_Guerrier;
 static TEXTURE_STRUCT * Texture_Img_Arbaletrier;
 static TEXTURE_STRUCT * Texture_Img_Paysan;
 static TEXTURE_STRUCT * Texture_Img_Or;
 static TEXTURE_STRUCT * Texture_Img_Pierre;
 static TEXTURE_STRUCT * Texture_Img_Nourriture;
 static TEXTURE_STRUCT * Texture_Img_Bois;
 static TEXTURE_STRUCT * Texture_Img_Mouvement;
 static TEXTURE_STRUCT * Texture_Img_Stop;
 static TEXTURE_STRUCT * Texture_Img_Attaquer;
 static TEXTURE_STRUCT * Texture_Img_Construire;
 static TEXTURE_STRUCT * Texture_Img_Hache;
 static TEXTURE_STRUCT * Texture_Img_Pioche;
 static TEXTURE_STRUCT * Texture_Img_Caserne;
 static TEXTURE_STRUCT * Texture_Img_Ferme;
 static TEXTURE_STRUCT * Texture_Img_Tour;
 static TEXTURE_STRUCT * Texture_Img_Cancel;
};




#endif