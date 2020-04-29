#pragma once
#include "Personnage.hpp"
#include "Joueur.hpp"
#include "Batiment.hpp"
#include "Caserne.hpp"
#include "Ferme.hpp"
#include "Tour.hpp"

class Paysan:public Personnage{
protected:

public:
    Paysan(float x, float y,float angle, float vitesseMAX);
    void construireCaserne(Joueur * J,float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void construireFerme(Joueur * J,float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void construireTour(Joueur * J,float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    GLvoid creerChapeau() const override;
    GLvoid creerAccessoire() const override;

};