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
class InterfaceHUD{
    public:

    InterfaceHUD(TEXTURE_STRUCT * T_HUD, TEXTURE_STRUCT * T_HUD2);
    GLvoid creerInterfaceHUD(Personnage & p);
    GLvoid creerInterfaceHUD(Batiment & b);

    void drawText(std::string text, int length, int x, int y);

    private:

    TEXTURE_STRUCT * Texture_HUD;
    TEXTURE_STRUCT * Texture_HUD2;
};