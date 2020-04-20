#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <cmath>
#include "touches.h"
#include "switch_blend.h"
#include "ppm.hpp"



#ifndef __INIT
#define __INIT

class initGL {
public:
	// Constructor
	initGL();

	//Destructor
	~initGL();

/*
	// Getters
	unsigned int getHeight();
	unsigned int getWidth();

	// Setters
	void setHeight(unsigned int m_height);
	void setWidth(unsigned int m_width);
*/

	//init
	int mainInit(int argc, char** argv, void (*DrawGLScene)());

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
//action.c
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
  static TEXTURE_STRUCT * Texture_chateau;
  static TEXTURE_STRUCT * Texture_pierre;
  static TEXTURE_STRUCT * Texture_toit;
  static TEXTURE_STRUCT * Texture_porte;
  static TEXTURE_STRUCT * Texture_paille;
	
};




#endif













