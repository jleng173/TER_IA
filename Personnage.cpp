#include "Personnage.hpp"

Personnage::Personnage(float avn,float act,float x, float y, float angle, float v){
    avance=avn;
    action=act;
    mouv = 0;
    position[0] = x;
    position[1] = y;
    orientation = angle;
    vitesseMAX = v;
}

Personnage::Personnage(float avn,float act,float x, float y, float angle, float v, float m){
    avance=avn;
    action=act;
    mouv = m;
    position[0] = x;
    position[1] = y;
    orientation = angle;
    vitesseMAX = v;
}

void Personnage::updatePos( float time){
    position[0] += velocite[0] * time;
    position[1] += velocite[1] * time;
    orientation = atan2(-velocite[0],velocite[1]) * 180 / 3.14159265;
}

void Personnage::deplacementCible(float x, float y){
    //SeekKinematic mouvement

    velocite[0] = x - position[0];
    velocite[1] = y - position[1];

    //Normalisation du vecteur velocite
    float v = sqrt(velocite[0]*velocite[0]+velocite[1]*velocite[1]);
    if (v > 0.02){
        velocite[0] = velocite[0]/v;
        velocite[1] = velocite[1]/v;

        if(avance<19 && mouv == 0)
            avance += 0.1;
        if(avance >= 19 && mouv == 0)
            mouv = 1;
        if(avance>-19 && mouv == 1){
            avance -= 0.1;
        }
        if(avance <=-19 && mouv == 1)
            mouv=0; 
    }else{
        mouv=0; 
        avance = 0;

    }
   // printf("a = %f \n",avance);
    velocite[0] *= vitesseMAX;
    velocite[1] *= vitesseMAX;

    updatePos(0.01);
}

GLvoid Personnage::creerPersonnage()
{
    glTranslatef(position[0],position[1],0);
    
    glPushMatrix();{

        glScalef(5,5,5);
        glRotatef(90,1.0,0.0,0.0);
        glRotatef(orientation,0,1,0);

        Forme f;
        struct cube1 membre = f.creerCube(1.5);
        
        glPushMatrix();{        
            glPushMatrix();{
                glColor3f(0.1,0.1,0.1);
                glutSolidSphere(0.5,10,100);
            }
            glPopMatrix();
            //Corps
            glPushMatrix();{
                glTranslatef(0,-1.5,0);
                glColor3f(0.1,0.1,0.1);
                glScalef(0.3,0.7,0.2);
                f.afficheCube(membre);
            }
            glPopMatrix();
            //Bras gauche   (epaule jusqu'au bas)
                //1er Articulation
            glPushMatrix();{
                glRotatef(avance,1,0,0);
                glPushMatrix();{
                    glColor3f(0,1,1);
                    glTranslatef(0.6,-0.8,0);
                    glutSolidSphere(0.2,10,100);
                }
                glPopMatrix();
                glPushMatrix();{
                    glTranslatef(0.7,-1.2,0);
                    glColor3f(0,0,1);
                    glScalef(0.1,0.2,0.1);
                    f.afficheCube(membre);
                }
                glPopMatrix();
                    //2e Articulation
                glPushMatrix();{
                    glColor3f(0,1,1);
                    glTranslatef(0.7,-1.6,0);
                    glutSolidSphere(0.2,10,100);
                }
                glPopMatrix();
                glPushMatrix();{
                    glTranslatef(0.7,-2,0);
                    glColor3f(1,0,0);
                    glScalef(0.1,0.2,0.1);
                    f.afficheCube(membre);
                }
                glPopMatrix();
                    //Main Gauche
                glPushMatrix();{
                    glColor3f(0,1,0);
                    glTranslatef(0.7,-2.4,0);
                    glutSolidSphere(0.15,10,100);
                }
                glPopMatrix();
            }
            glPopMatrix();
        }
        glPopMatrix();
        //Bras droit
            //Articulation
        glPushMatrix();{
            glRotatef(-avance,1,0,0);
            if(mouv==2 || mouv==3){
                glRotatef(-45+action,1,0,0);
            }
            glPushMatrix();{
                glColor3f(0,1,1);
                glTranslatef(-0.6,-0.8,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(-0.7,-1.2,0);
                glColor3f(0,0,1);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
                //Articulation    
            glPushMatrix();{
                glColor3f(0,1,1);
                glTranslatef(-0.7,-1.6,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            if(mouv==2 || mouv==3){
                    glRotatef(-90+action,1,0,0);
                    glTranslatef(0,1.6,-1.6);
            }
            glPushMatrix();{
                glPushMatrix();{
                    // glRotatef(action,1,0,0);
                    glTranslatef(-0.7,-2,0);
                    glColor3f(1,0,0);
                    glScalef(0.1,0.2,0.1);
                    f.afficheCube(membre);
                }
                glPopMatrix();
                //Main droite
                glPushMatrix();{
                    glColor3f(0,1,0);
                    glTranslatef(-0.7,-2.4,0);
                    glutSolidSphere(0.15,10,100);
                }
                glPopMatrix();
            }
            glPopMatrix();
        }
        glPopMatrix();




        //Jambe gauche   (cuisse jusqu'au pied)
                //Articulation
        glPushMatrix();{
            glTranslatef(-0.25,-1.8,0);
            glRotatef(-avance,1,0,0);
            glPushMatrix();{
                glColor3f(0,1,1);
                glTranslatef(0.6,-0.8,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(0.7,-1.2,0);
                glColor3f(0,0,1);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
                //Articulation
            glPushMatrix();{
                glColor3f(0,1,1);
                glTranslatef(0.7,-1.6,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(0.7,-2,0);
                glColor3f(1,0,0);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
            glPushMatrix();{
                glColor3f(0,1,0);
                glTranslatef(0.7,-2.4,0);
                glutSolidSphere(0.15,10,100);
            }
            glPopMatrix();
        }
        glPopMatrix();
        //Jambe droit
            //Articulation
        glPushMatrix();{
            glTranslatef(0.25,-1.8,0);
            glRotatef(avance,1,0,0);
            glPushMatrix();{
                glColor3f(0,1,1);
                glTranslatef(-0.6,-0.8,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(-0.7,-1.2,0);
                glColor3f(0,0,1);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
                //Articulation    
            glPushMatrix();{
                glColor3f(0,1,1);
                glTranslatef(-0.7,-1.6,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(-0.7,-2,0);
                glColor3f(1,0,0);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
            glPushMatrix();{
                glColor3f(0,1,0);
                glTranslatef(-0.7,-2.4,0);
                glutSolidSphere(0.15,10,100);
            }
            glPopMatrix();
        }
        glPopMatrix();
    }
    glPopMatrix();
}