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
#include "Decor.hpp"

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
    Paysan(float x, float y,float angle, float vitesseMAX, std::array<float,3> col, std::vector<Decor*> decors, Joueur * J, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille);
    void construireCaserne(Joueur * J,float x, float y);
    void construireFerme(Joueur * J,float x, float y);
    void construireTour(Joueur * J,float x, float y);
    GLvoid creerChapeau() const override;
    GLvoid creerAccessoire() const override;
    //recherche la ressource la plus proche, Pierre 'P' ou Bois 'B' en fonction de l'argument
    std::vector<float> rangeRessource( char r);
    //Gestion des états
    void comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment) override;
    //Transitions :
    // Si il y a un ennemi dans le champ de vision
    bool voitEnnemie(std::vector<float> ennemieProche);
    // Si le Joueur veut que le paysan récupère des pierres
    void modePierre();
    // Si le Joueur veut que le paysan coupe du bois
    void modeBois();
    // Si le paysan est proche d'une ressource      
    bool contact(std::vector<float> ressource);
    // Attribue la ressource récolté au Joueur
    void ajoutRessource(Joueur * J, char r);

private :
    Joueur * _J;
    std::vector<Decor*> _decors;
    bool _pierre;
    bool _bois;

};