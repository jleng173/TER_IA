#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ppm.hpp"
#include "init.hpp"
class Batiment {

public:
    // Constructor
    Batiment(TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void creerChateau();
    void creerTour();
    void creerFerme();
    void creerCaserne();

    TEXTURE_STRUCT * Texture_chateau;
    TEXTURE_STRUCT * Texture_pierre;
    TEXTURE_STRUCT * Texture_toit;
    TEXTURE_STRUCT * Texture_porte;
    TEXTURE_STRUCT * Texture_paille;
};
