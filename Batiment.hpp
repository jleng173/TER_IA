#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "ppm.hpp"
#include "init.hpp"
#include "Element.hpp"


class Batiment : public Element{

public:
    // Constructor
    Batiment(float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    virtual void creerBatiment() const = 0;
    GLvoid barreHp(int z) const;

    TEXTURE_STRUCT * Texture_chateau;
    TEXTURE_STRUCT * Texture_pierre;
    TEXTURE_STRUCT * Texture_toit;
    TEXTURE_STRUCT * Texture_porte;
    TEXTURE_STRUCT * Texture_paille;

    bool isSelected();
    void setSelected(int s);
    bool getEnConstruction();
    void setEnConstruction(bool b);
    std::string getNom();

protected:
    bool selected;
    bool enConstruction;
    float delaiConstruction;
    float debutDelai;
    std::string nom;
};
