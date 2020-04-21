#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

class Personnage {
public:
    Personnage(float a);

    GLvoid creerPersonnage();

    float avance;
};