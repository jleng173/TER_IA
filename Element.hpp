#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <memory>
#include "ppm.hpp"
#include "init.hpp"

struct Hitbox
{
    float x1;
    float y1;
    float x2;
    float y2;
};

class Element{

public:
    // Constructor
    Element(float x,float y);

    bool Colision( Element * autre);
    bool testSiColision(const std::vector<Element *> all);
    Hitbox getHitbox(){return hitbox;};
    void setHitbox(Hitbox h);

    float getX(){return position[0];};
    float getY(){return position[1];};
    int getHp(){return hp;};
    void setHp(int h){hp = h;};
    int getHpMax(){return hpMax;};

    static int current_id;
    int id;
protected:
    //hitbox représenté par 2 cordonnées formant un rectangle
    //point en bas à gauche (hitbox.x1,hitbox.y1)
    //point en haut à droite (hitbox.x2,hitbox.y2)
    Hitbox hitbox;
    float position[2];
    int hp;
    int hpMax;
 
    };