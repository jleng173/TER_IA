#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h>
#include <algorithm>
#include "Personnage.hpp"

using namespace std;


class Arbaletrier : public Personnage{
    protected:
        float timeProjec;

    public:
        Arbaletrier(float avn,float act,float x, float y,float angle, float vitesseMAX);
        void tirArbalete(float x, float y);
        GLvoid creerCarreau();
        GLvoid creerChapeau() const override;
        GLvoid creerAccessoire() const override;
};