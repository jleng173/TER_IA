#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ppm.hpp"
#include <string>
// #include "Guerrier.hpp"
// #include "Paysan.hpp"
// #include "Arbaletrier.hpp"
// #include "Chateau.hpp"
// #include "Caserne.hpp"
// #include "Tour.hpp"
// #include "Ferme.hpp"
#include "Personnage.hpp"
#include "Batiment.hpp"
#include "Joueur.hpp"

class InterfaceHUD{
    public:

    InterfaceHUD(TEXTURE_STRUCT * T_HUD, TEXTURE_STRUCT * T_HUD2, TEXTURE_STRUCT * T_Pierre, TEXTURE_STRUCT * T_Img_Guerrier,TEXTURE_STRUCT * T_Img_Paysan, TEXTURE_STRUCT * T_Img_Arbaletrier);
    GLvoid creerInterfaceHUD(std::vector<Personnage *> p, Joueur * j);
    GLvoid creerInterfaceHUD(Batiment & b);

    void drawText(std::string text, int length, int x, int y);
    GLvoid drawIcon();
    private:

    TEXTURE_STRUCT * Texture_HUD;
    TEXTURE_STRUCT * Texture_HUD2;
    TEXTURE_STRUCT * Texture_Pierre;
    TEXTURE_STRUCT * Texture_Img_Guerrier;
    TEXTURE_STRUCT * Texture_Img_Paysan;
    TEXTURE_STRUCT * Texture_Img_Arbaletrier;
};