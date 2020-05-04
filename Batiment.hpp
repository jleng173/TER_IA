#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "ppm.hpp"
#include "init.hpp"
#include "Element.hpp"


class Batiment : Element{

public:
    // Constructor
    Batiment(float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    virtual void creerBatiment() const = 0;
    Hitbox getHitbox();
    GLvoid barreHp(int z) const;

    TEXTURE_STRUCT * Texture_chateau;
    TEXTURE_STRUCT * Texture_pierre;
    TEXTURE_STRUCT * Texture_toit;
    TEXTURE_STRUCT * Texture_porte;
    TEXTURE_STRUCT * Texture_paille;

    bool isSelected();
    void setSelected(int s);
    int getHp();
    int getHpMax();
    float getX();
    float getY();

protected:
    float hp;
    float hpMax;
    float position[2];
    //hitbox représenté par 2 cordonnées formant un rectangle
    //point en bas à gauche (hitbox.x1,hitbox.y1)
    //point en haut à droite (hitbox.x2,hitbox.y2)
    Hitbox hitbox;
    bool selected;
};
