#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <algorithm>
#include <vector>
#include "Personnage.hpp"
#include "Element.hpp"

using namespace std;

class Arbaletrier : public Personnage{
    protected:
        float timeProjec;
        float range;

    public:
        Arbaletrier(float x, float y,float angle, float vitesseMAX);
        void tirArbalete(float x, float y, std::vector<Element*> listeElements);
        GLvoid creerCarreau();
        GLvoid creerChapeau() const override;
        GLvoid creerAccessoire() const override;
        void comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment,std::vector<Element *>  all) override;
        //Transitions
        bool CourtePortee(std::vector<float> elementProche);
        bool LongPortee(std::vector<float> elementProche);
};