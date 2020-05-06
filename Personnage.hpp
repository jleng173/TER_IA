#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <vector>
#include <memory>
#include "Forme.hpp"
#include "Batiment.hpp"
#include "Element.hpp"

enum State {
    SLEEP = 1,
    FIRE,
    FLEE,
    ATTACK,
    PURSUIT
};

class Personnage : public Element{

protected:
    std::string nom;
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
    float mouvementbras;
    
    float position[2];
    float orientation;

    //acceleration
    float velocite[2];
    float vitesseMAX;

    int selected;


    State etat;

public:
    Personnage();
    Personnage(float x, float y,float angle, float vitesseMAX);
    Personnage(float avn,float act,float x, float y,float angle, float vitesseMAX,float mouv);

    GLvoid creerPersonnage();
    virtual GLvoid creerChapeau() const = 0;
    virtual GLvoid creerAccessoire() const = 0;

    GLvoid selectionne();
    GLvoid barreHp();
    bool isSelected();
    void setSelected(int s);

    virtual void comportement(std::vector<Personnage*> listeEnnemies, std::vector<Element *>  all) =  0;
    void updatePos( float time);
    void deplacementCible(float x, float y,std::vector<Element *>  all);
    void fuirCible(float x, float y,std::vector<Element *>  all);

    Hitbox getHitbox();
    static GLvoid drawHalfSphere(int scaley, int scalex, GLfloat r);

    int getHp();
    int getHpMax();
    int getDmg();
    float getX();
    float getY();

    float getOrientation();
    float getvitesseMAX();

    float lastPosition[2];
    std::string getNom();
    
    State setEtat(State e);

    //Retourne les coordonnées x,y et la distance de l'ennemie le plus proche
    std::vector<float> rangeEnnemy(std::vector<Personnage*> listeEnnemies);
};