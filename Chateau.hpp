#pragma once
#include "Batiment.hpp"
#include "Forme.hpp"
class Chateau : public Batiment{
    public:

    Chateau(float x, float y, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void creerPaysan();
    void creerBatiment() const override;

};