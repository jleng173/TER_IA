#include "Paysan.hpp"

Paysan::Paysan(float avn,float act,float x, float y,float angle, float vitesseMAX):Personnage(avn,act,x,y,angle,vitesseMAX){
    hp=75;
    dmg=2;
}

GLvoid Paysan::creerBatiment(){

}

GLvoid Paysan::creerChapeau() const{
    glPushMatrix();{
        glColor3f(0.7,0.7,0);
        // glScalef(0.8,0,0);
        Personnage::drawHalfSphere(100,100,1);
        GLUquadric* params = gluNewQuadric();
        gluQuadricTexture(params, GL_TRUE);
        glRotatef(90,1,0,0);
        gluDisk(params,0,1,20,1);
        gluDeleteQuadric(params);
    }
    glPopMatrix();
}

GLvoid Paysan::creerAccessoire() const{

}