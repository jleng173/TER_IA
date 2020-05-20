#pragma once
#include <algorithm>
#include <vector>
#include "Batiment.hpp"
#include "Forme.hpp"
#include "Personnage.hpp"

class Tour : public Batiment{
    public:
        Tour(float x, float y, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
        void creerBatiment() const override;
        int getDmg();
        void tirArbalete(float x, float y, std::vector<Personnage*> listeEnnemies);
        GLvoid creerCarreau();
        void comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment,std::vector<Element *>  all);
        std::vector<float> rangeEnnemy(std::vector<Personnage*> listeEnnemies);
        bool ennemieLongPortee(std::vector<float> ennemieProche);

    private:
        int dmg;
        float range;
        float timeProjec;
        State etat;

};