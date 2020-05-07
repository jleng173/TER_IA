#include "Joueur.hpp"

Joueur::Joueur(){
    qteBois = 100;
    qteOr = 10;
    qtePierre = 100;
    maxUnites = 5;

}

void Joueur::addBois(int b){
    qteBois += b;
}
void Joueur::subtractBois(int b){
    qteBois -= b;
}
int Joueur::getBois(){
    return qteBois;
}

void Joueur::addPierre(int p){
    qtePierre += p;
}
void Joueur::subtractPierre(int p){
    qtePierre -= p;
}
int Joueur::getPierre(){
    return qtePierre;
}

void Joueur::addOr(int o){
    qteOr += o;
}
void Joueur::subtractOr(int o){
    qteOr -= o;
}
int Joueur::getOr(){
    return qteOr;
}

int Joueur::getMaxUnites(){
    return maxUnites;
}
void Joueur::setMaxUnites(int mu){
    maxUnites = mu;
}

// std::vector<std::shared_ptr<Batiment> > Joueur::getBatiments(){
//     return listeBatiments;
// }
std::vector<Personnage * > Joueur::getUnites(){
    return listeUnites;
}

void Joueur::addUnites(Personnage * p){
    listeUnites.push_back(p);
}

std::vector<Batiment * > Joueur::getBatiments(){
    return listeBatiments;
}

void Joueur::addBatiment(Batiment * b){
    listeBatiments.push_back(b);
}