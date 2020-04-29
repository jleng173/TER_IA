#pragma once
#include "Batiment.hpp"
#include "Forme.hpp"
#include "Guerrier.hpp"
#include "Arbaletrier.hpp"
#include "Joueur.hpp"

class Caserne : public Batiment {
    public:

    Caserne(float x, float y, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void creerBatiment() const override;
    void creerGuerrier(Joueur * J);
    void creerArbaletrier(Joueur * J);
};