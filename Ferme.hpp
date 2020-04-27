#pragma once
#include "Batiment.hpp"
#include "Forme.hpp"


class Ferme:public  Batiment{
    public:
        Ferme(TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
        void creerBatiment() const override;

};