#pragma once
#include <stdio.h> 
#include <stdlib.h>
#include <iostream>
#include <memory> 
#include <vector>
#include "Batiment.hpp"
#include "Personnage.hpp"

class Joueur {

public:
    // Constructor
    Joueur(std::array<float,3> col);

    int getBois();
    void addBois(int b);
    void subtractBois(int b);

    int getPierre();
    void addPierre(int p);
    void subtractPierre(int p);

    int getOr();
    void addOr(int o);
    void subtractOr(int o);

    int getMaxUnites();
    void setMaxUnites(int mu);

    std::array<float,3> getCouleur();
    std::vector<Personnage* > getUnites();
    void addUnites(Personnage* p);
    //Enleve les personnages morts
    void removeElements();

    std::vector<Batiment* > getBatiments();
    void addBatiment(Batiment* b);
    

private:
    int qteBois;
    int qtePierre;
    int qteOr;
    int maxUnites;
    //Liste des unités que le joueur possède
    std::vector<Personnage*> listeUnites;
    //Liste des batiments que le joueur possède 
    std::vector<Batiment*> listeBatiments;
    std::array<float,3> couleur;
};  