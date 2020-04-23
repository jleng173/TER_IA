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
    Forme f;
    struct cube1 base = f.creerCube(1);
    struct pyramide1 pic = f.creerPyramide(1);
    glPushMatrix();{
        glTranslatef(0,-2.5,0);
        //Partie haute
        glPushMatrix();{
            glColor3f(0.6,0.6,0.6);
            glPushMatrix();{     
                glScalef(0.3,0.3,0.3);
                glTranslatef(3,0,0);
                glRotatef(-90,0,0,1);
                f.affichePyramide(pic);
            }
            glPopMatrix();
            glPushMatrix();{
                glScalef(0.3,0.3,0.3);
                glTranslatef(-3,0,0);
                glRotatef(90,0,0,1);
                f.affichePyramide(pic);
            }
            glPopMatrix();
            glPushMatrix();{
                glScalef(0.6,0.3,0.3);
                f.afficheCube(base);
            }
            glPopMatrix();
        }
        glPopMatrix();


        glPushMatrix();{
            glColor3f(0.5,0.25,0.25);
            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params, GL_TRUE);
            glRotatef(90,1,0,0);
            glTranslatef(0,0,0);
            gluCylinder(params,0.2,0.2,4,100,100);
        }
        glPopMatrix();
    }
    glPopMatrix();
}