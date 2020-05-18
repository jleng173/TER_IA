#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ppm.hpp"
#include <string>
// #include "Guerrier.hpp"
// #include "Paysan.hpp"
// #include "Arbaletrier.hpp"
// #include "Tour.hpp"
// #include "Ferme.hpp"
#include "Personnage.hpp"
#include "Batiment.hpp"
#include "Tour.hpp"
#include "Caserne.hpp"
#include "Chateau.hpp"
#include "Joueur.hpp"

class InterfaceHUD{
    public:

    InterfaceHUD(float _x, float _y, int mode, TEXTURE_STRUCT * T_HUD, TEXTURE_STRUCT * T_HUD2, TEXTURE_STRUCT * T_Pierre, TEXTURE_STRUCT * T_Img_Guerrier,TEXTURE_STRUCT * T_Img_Paysan, TEXTURE_STRUCT * T_Img_Arbaletrier, TEXTURE_STRUCT * T_Img_Or, TEXTURE_STRUCT * T_Img_Pierre,TEXTURE_STRUCT * T_Img_Nourriture, TEXTURE_STRUCT * T_Img_Bois, TEXTURE_STRUCT * T_Img_Mouvement, TEXTURE_STRUCT * T_Img_Stop, TEXTURE_STRUCT * T_Img_Attaquer, TEXTURE_STRUCT * T_Img_Construire, TEXTURE_STRUCT * T_Img_Caserne, TEXTURE_STRUCT * T_Img_Ferme, TEXTURE_STRUCT * T_Img_Tour, TEXTURE_STRUCT * T_Img_Cancel);
    GLvoid creerInterfaceHUD(std::vector<Personnage *> p, std::vector<Batiment *> b,Joueur * j);

    void drawText(std::string text, int length, int x, int y);
    GLvoid drawIconCharacter();
    GLvoid drawIconAction(bool paysan, std::vector<Personnage *> p, std::vector<Batiment *> b);
    void drawUnitInformation(std::vector<Personnage *> p, std::vector<Batiment *> b);
    int ActionClick(std::vector<Personnage *> p, std::vector<Batiment *> b, Joueur * j);

    private:

    float x;
    float y;
    int modeAction;
    TEXTURE_STRUCT * Texture_HUD;
    TEXTURE_STRUCT * Texture_HUD2;
    TEXTURE_STRUCT * Texture_Pierre;
    TEXTURE_STRUCT * Texture_Img_Guerrier;
    TEXTURE_STRUCT * Texture_Img_Paysan;
    TEXTURE_STRUCT * Texture_Img_Arbaletrier;
    TEXTURE_STRUCT * Texture_Img_Or;
    TEXTURE_STRUCT * Texture_Img_Pierre;
    TEXTURE_STRUCT * Texture_Img_Nourriture;
    TEXTURE_STRUCT * Texture_Img_Bois;
    TEXTURE_STRUCT * Texture_Img_Mouvement;
    TEXTURE_STRUCT * Texture_Img_Attaquer;
    TEXTURE_STRUCT * Texture_Img_Stop;
    TEXTURE_STRUCT * Texture_Img_Construire;
    TEXTURE_STRUCT * Texture_Img_Caserne;
    TEXTURE_STRUCT * Texture_Img_Ferme;
    TEXTURE_STRUCT * Texture_Img_Tour;
    TEXTURE_STRUCT * Texture_Img_Cancel;
};