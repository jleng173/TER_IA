#include "Guerrier.hpp"

Guerrier::Guerrier(float avn,float act,float x, float y,float angle, float vitesseMAX):Personnage(avn,act,x,y,angle,vitesseMAX){
    hp=150;
    dmg=5;
}

GLvoid Guerrier::creerChapeau() const{
    glPushMatrix();{
        GLUquadric* params = gluNewQuadric();
        gluQuadricTexture(params, GL_TRUE);
        glRotatef(90,1,0,0);
        glTranslatef(0,0,-0.8);
        //Partie haute
        glPushMatrix();{
            glColor3f(0.2,0.2,0.2);
            gluDisk(params,0,0.3,100,1);
            gluCylinder(params,0.3,0.6,0.5,20,1);
        }
        glPopMatrix();
        //Partie centrale
        glPushMatrix();{
            glColor3f(0.7,0.7,0);
            glTranslatef(0,0,0.5);
            gluCylinder(params,0.6,0.6,0.1,20,1);
        }
        glPopMatrix();
        //Partie basse
        glPushMatrix();{
            glTranslatef(0,0,0.6);
            glColor3f(0.2,0.2,0.2);
            gluCylinder(params,0.6,0.4,0.65,20,1);
            gluDeleteQuadric(params);
        }
        glPopMatrix();
    }
    glPopMatrix();
}

GLvoid Guerrier::creerAccessoire() const{

}