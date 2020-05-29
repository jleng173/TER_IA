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
        //Transitions :
        // Si il y a un ennemi dans le champ de vision
        bool voitElement(std::vector<float> elementProche);
        // Si le guerrier est à 1/4 ou moins de sa vie
        bool basHp();
        // Si le guerrier est au corp à corp avec un element
        bool contactElement(std::vector<float> elementProche, std::string elem);
};