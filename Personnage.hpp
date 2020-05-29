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
    
    //variables gèrent les animations de mouvement du personnage
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

    std::string getNom();
    
    State setEtat(State e);
    State getEtat();
    //Retourne les coordonnées x,y et la distance de l'ennemi le plus proche
    std::vector<float> rangeEnnemy(std::vector<Personnage*> listeEnnemies);
     //Retourne les coordonnées x,y et la distance de du batiment ennemi le plus proche
    std::vector<float> rangeBatiment(std::vector<Batiment*> listeBatiment);

    //Liste de toutes les coordonnées que le personnage va emprunter pour aller à une certaine position
    std::vector<std::vector<float>> ListPositions;
    //Fonction qui permet le déplacement d'un personnage entre sa postion actuel et une coordonnée 
    void deplacementCibleAStar(float x, float y);
    void tpCibleAStar();
    //Génère une liste de coordonnées partant du personnage jusqu'à un point donné
    std::vector<std::vector<float>> GenerateListPos(float x, float y);
    //Génère une liste de coordonnées partant du personnage jusqu'à l'opposé d'un point donné
    std::vector<std::vector<float>> GenerateListPosFuite(float x, float y);
};