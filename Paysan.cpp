#include "Paysan.hpp"

Paysan::Paysan(float avn,float act,float x, float y,float angle, float vitesseMAX):Personnage(avn,act,x,y,angle,vitesseMAX){
    hp=75;
    dmg=2;
}

GLvoid Paysan::creerBatiment()