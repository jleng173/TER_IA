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
        void comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment) override;
        //Transitions
        bool voitElement(std::vector<float> elementProche);
        bool basHp();
        bool contactElement(std::vector<float> elementProche, std::string elem);
};