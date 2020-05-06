#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h> 

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

struct pyramide1 {
	float sommet5[3];
	float sommet4[3];
	float sommet3[3];
	float sommet2[3];
	float sommet1[3];
};

class Forme {
public:
    // Constructor
    Forme();

    struct cube1 creerCube(float taille);
	GLvoid afficheCube(struct cube1 cube);
	struct pyramide1 creerPyramide(float taille);
	GLvoid affichePyramide(pyramide1 pyramide);
	GLvoid rectangleSelection(float x1, float y1, float x2, float y2);

};



