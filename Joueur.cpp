#include "Joueur.hpp"

Joueur::Joueur(std::array<float,3> col){
    qteBois = 100;
    qteOr = 100;
    qtePierre = 100;
    maxUnites = 5;
    std::copy(std::begin(col), std::end(col), std::begin(couleur));
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

std::array<float,3> Joueur::getCouleur(){
    return couleur;
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

void Joueur::removeUnites(){
    // Baisse des pv
    for(int i = 0; i < listeUnites.size(); i++){
        if(listeUnites[i]->getHp() <= 0){
            listeUnites.erase(listeUnites.begin()+i);
        }
    }
}

std::vector<Batiment * > Joueur::getBatiments(){
    return listeBatiments;
}

void Joueur::addBatiment(Batiment * b){
    listeBatiments.push_back(b);
}