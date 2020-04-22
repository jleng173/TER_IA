#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

class Personnage {
public:
    Personnage(float av, float ac, int mo);

    GLvoid creerPersonnage();

    float avance;
    float action;
    int mouv;
};