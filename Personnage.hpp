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
    int dmg;
    float hitbox[2];
    
    float avance;
    float action;
    float mouv;
    
    float position[2];
    float orientation;

    float velocite[2];
    float rotation;

    float vitesseMAX;

public:
    Personnage(float avn,float act,float x, float y,float angle, float vitesseMAX);
    Personnage(float avn,float act,float x, float y,float angle, float vitesseMAX,float mouv);

    GLvoid creerPersonnage();
    virtual GLvoid creerChapeau() const = 0;

    void updatePos( float time);

    void deplacementCible(float x, float y);

    GLvoid drawHalfSphere(int scaley, int scalex, GLfloat r);
};

//Classe Paysan
class Paysan:public Personnage{
protected:

public:
    Paysan(float avn,float act,float x, float y,float angle, float vitesseMAX);
    GLvoid creerBatiment();
    GLvoid creerChapeau() const override;

};

//Classe Guerrier
class Guerrier : public Personnage{
    protected:

    public:
        Guerrier(float avn,float act,float x, float y,float angle, float vitesseMAX);
        GLvoid creerChapeau() const override;
};