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

    float getPositionX(){return position[0];};
    float getPositionY(){return position[1];};

    static int current_id;
    int id;
protected:
    Hitbox hitbox;
    float position[2];
 
    };