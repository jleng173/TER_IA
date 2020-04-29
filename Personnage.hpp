#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "Forme.hpp"
#include "Batiment.hpp"

class Personnage {

protected:
    int hp;
    int hpMax;
    int dmg;
    //hitbox représenté par 2 cordonnées formant un rectangle
    //point en bas à gauche (hitbox.x1,hitbox.y1)
    //point en haut à droite (hitbox.x2,hitbox.y2)
    Hitbox hitbox;
    
    float avance;
    float action;
    float mouv;
    
    float position[2];
    float orientation;

    //acceleration
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

    Hitbox getHitbox();
    
    static GLvoid drawHalfSphere(int scaley, int scalex, GLfloat r);

    int getHp();
    int getHpMax();
    int getDmg();
};