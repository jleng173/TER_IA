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
#include "Carte.hpp"
#include "Forme.hpp"
#include "Batiment.hpp"
#include "Element.hpp"
#include "astar.hpp"

enum State {
    SLEEP = 1,
    FIRE,
    FLEE,
    ATTACK,
    PURSUIT,
    SEEKWOOD,
    SEEKSTONE,
    CHOP,
    MINE
};

class Personnage : public Element{

protected:
    std::string nom;
    float dmg;
    
    float avance;
    float action;
    float mouv;
    float mouvementbras;
    
    float orientation;

    //acceleration
    float velocite[2];
    float vitesseMAX;

    int selected;
    bool formed;
    std::array<float,3> couleur;

    State etat;

public:
    Personnage();
    Personnage(float x, float y,float angle, float vitesseMAX, std::array<float,3> couleur);
    Personnage(float avn,float act,float x, float y,float angle, float vitesseMAX,float mouv);

    GLvoid creerPersonnage();
    virtual GLvoid creerChapeau() const = 0;
    virtual GLvoid creerAccessoire() const = 0;

    void setPosition(float x, float y);


    GLvoid selectionne();
    GLvoid barreHp();
    bool isSelected();
    bool isFormed();
    void setSelected(int s);
    void setFormed(bool f);
    virtual void comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment) =  0;
    void updatePos( float time);

    Hitbox getHitbox();
    static GLvoid drawHalfSphere(int scaley, int scalex, GLfloat r);

    int getDmg();
    float getLastX();
    float getLastY();


    float getOrientation();
    float getvitesseMAX();

    float lastPosition[2];
    std::string getNom();
    
    State setEtat(State e);
    State getEtat();
    //Retourne les coordonnées x,y et la distance de l'ennemie le plus proche
    std::vector<float> rangeEnnemy(std::vector<Personnage*> listeEnnemies);

    std::vector<float> rangeBatiment(std::vector<Batiment*> listeBatiment);

    std::vector<std::vector<float>> ListPositions;
    void deplacementCibleAStar(float x, float y);
    void tpCibleAStar();
    std::vector<std::vector<float>> GenerateListPos(float x, float y);
    std::vector<std::vector<float>> GenerateListPosFuite(float x, float y);
};