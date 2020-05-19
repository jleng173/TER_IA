#pragma once
#include "Personnage.hpp"
#include "Element.hpp"
#include <stdbool.h>


class Guerrier : public Personnage {
    protected:
        float vision;
        float range;
    public:
        Guerrier(float x, float y,float angle, float vitesseMAX,std::array<float,3> col);
        GLvoid creerChapeau() const override;
        GLvoid creerAccessoire() const override;
        //Gestion des états
        void comportement(std::vector<Personnage*> listeEnnemies,const std::vector<Element *>  all) override;
        //Transitions
        bool voitEnnemie(std::vector<float> ennemieProche);
        bool basHp();
        bool contactEnnemie(std::vector<float> ennemieProche);
};