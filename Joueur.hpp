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
    Joueur();

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

    // std::vector<std::shared_ptr<Batiment> > getBatiments();
    std::vector<Personnage* > getUnites();
    void addUnites(Personnage* p);
    //Enleve les personnages morts
    void removeUnites();

    std::vector<Batiment* > getBatiments();
    void addBatiment(Batiment* b);
    

private:
    int qteBois;
    int qtePierre;
    int qteOr;
    int maxUnites;
    std::vector<Personnage*> listeUnites;
    std::vector<Batiment*> listeBatiments;
};  