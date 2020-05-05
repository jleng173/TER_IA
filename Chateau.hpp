#pragma once
#include "Batiment.hpp"
#include "Forme.hpp"
#include "Paysan.hpp"
#include "Element.hpp"
#include "Joueur.hpp"


class Chateau : public Batiment{
    public:

    Chateau(float x, float y, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void creerPaysan(Joueur * J);
    void creerBatiment() const override;

};