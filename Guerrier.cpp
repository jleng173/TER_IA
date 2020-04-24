#include "Guerrier.hpp"

Guerrier::Guerrier(float avn,float act,float x, float y,float angle, float vitesseMAX):Personnage(avn,act,x,y,angle,vitesseMAX){
    hp=150;
    hpMax=150;
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
    Forme fe;
    struct cube1 garde = fe.creerCube(1);
    glPushMatrix();{
        //Partie haute
        glPushMatrix();{
            glColor3f(0.7,0.7,0.7);
            // glRotatef(45,0,1,0);
            // glScalef(0.3,0.5,0.2);
            glBegin( GL_TRIANGLES );
                //Face lame 1
                glVertex3f( -0.4f, 0.0f, 0.0f );
                glVertex3f( 0.0f, 0.5f, 0.0f );
                glVertex3f( 0.0f, 0.0f, -0.1f );

                //Face lame 2
                glVertex3f( 0.0f, 0.0f, -0.1f );
                glVertex3f( 0.0f, 0.5f, 0.0f );
                glVertex3f( 0.4f, 0.0f, 0.0f );
                //Face lame 3
                glVertex3f( 0.0f, 0.0f, 0.1f );
                glVertex3f( 0.0f, 0.5f, 0.0f );
                glVertex3f( 0.4f, 0.0f, 0.0f );
                //Face lame 4
                glVertex3f( 0.0f, 0.0f, 0.1f );
                glVertex3f( 0.0f, 0.5f, 0.0f );
                glVertex3f( -0.4f, 0.0f, 0.0f );
            glEnd();

            glBegin( GL_QUADS );
                glVertex3f( -0.4f, 0.0f, 0.0f );
                glVertex3f( 0.0f, 0.0f, -0.1f );
                glVertex3f( 0.0f, -5.0f, -0.1f );
                glVertex3f( -0.4f, -5.0f, 0.0f );


                glVertex3f( 0.4f, 0.0f, 0.0f );
                glVertex3f( 0.0f, 0.0f, -0.1f );
                glVertex3f( 0.0f, -5.0f, -0.1f );
                glVertex3f( 0.4f, -5.0f, 0.0f );

                glVertex3f( 0.4f, 0.0f, 0.0f );
                glVertex3f( 0.0f, 0.0f, 0.1f );
                glVertex3f( 0.0f, -5.0f, 0.1f );
                glVertex3f( 0.4f, -5.0f, 0.0f );

                glVertex3f( -0.4f, 0.0f, 0.0f );
                glVertex3f( 0.0f, 0.0f, 0.1f );
                glVertex3f( 0.0f, -5.0f, 0.1f );
                glVertex3f( -0.4f, -5.0f, 0.0f );

            glEnd();
        }
        glPopMatrix();
        //Base de l'épée
        glPushMatrix();{
            glScalef(0.6,0.1,0.2);
            glColor3f(0.1,0.1,0.1);
            glTranslatef(0.0f,-50.0f,0.0f);
            fe.afficheCube(garde);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0.5,0.25,0.25);
            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params, GL_TRUE);
            glRotatef(90,1,0,0);
            glTranslatef(0,0,5);
            gluCylinder(params,0.2,0.2,1.5,100,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0.5,1,1);
            GLUquadric* params = gluNewQuadric();
            gluQuadricTexture(params, GL_TRUE);
            glTranslatef(0,-6.5,0);
            glutSolidSphere(0.25,100,100);
        }
        glPopMatrix();
    }
    glPopMatrix();
}