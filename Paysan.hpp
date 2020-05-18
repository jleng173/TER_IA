#pragma once
#include <stdbool.h>
#include <vector>
#include "Element.hpp"
#include "Personnage.hpp"
#include "Joueur.hpp"
#include "Batiment.hpp"
#include "Caserne.hpp"
#include "Ferme.hpp"
#include "Tour.hpp"

class Paysan:public Personnage{
protected:
    float vision;
    bool construit;
    TEXTURE_STRUCT * Texture_chateau;
    TEXTURE_STRUCT * Texture_pierre;
    TEXTURE_STRUCT * Texture_toit;
    TEXTURE_STRUCT * Texture_porte;
    TEXTURE_STRUCT * Texture_paille;
public:
    Paysan(float x, float y,float angle, float vitesseMAX, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void construireCaserne(Joueur * J,float x, float y);
    void construireFerme(Joueur * J,float x, float y);
    void construireTour(Joueur * J,float x, float y);
    GLvoid creerChapeau() const override;
    GLvoid creerAccessoire() const override;
    //Gestion des états
    void comportement(std::vector<Personnage*> listeEnnemies,std::vector<Element*>  all) override;
    //Transitions
    bool voitEnnemie(std::vector<float> ennemieProche);

private:

};