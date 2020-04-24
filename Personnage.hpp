#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "Forme.hpp"


class Personnage {

protected:
    int hp;
    int hpMax;
    int dmg;
    float hitbox[2];
    
    float avance;
    float action;
    float mouv;
    
    float position[2];
    float orientation;

    float velocite[2];

    float vitesseMAX;

    bool selected;

public:
    Personnage(float avn,float act,float x, float y,float angle, float vitesseMAX);
    Personnage(float avn,float act,float x, float y,float angle, float vitesseMAX,float mouv);

    GLvoid creerPersonnage();
    virtual GLvoid creerChapeau() const = 0;
    virtual GLvoid creerAccessoire() const = 0;
    GLvoid selectionne();
    GLvoid barreHp();

    void updatePos( float time);

    void deplacementCible(float x, float y);
    
    static GLvoid drawHalfSphere(int scaley, int scalex, GLfloat r);
};