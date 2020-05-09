#include "Guerrier.hpp"

Guerrier::Guerrier(float x, float y,float angle, float vitesseMAX):Personnage(x,y,angle,vitesseMAX){
    nom="Guerrier";
    hp=150;
    hpMax=150;
    dmg=5;
    selected = 0;
    vision = 30.0;
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

void Guerrier::comportement(std::vector<Personnage*> listeEnnemies, std::vector<Element *>  all) {
    std::vector<float> ennemieProche = rangeEnnemy(listeEnnemies);
    switch(etat){
        case SLEEP:
            if(voitEnnemie(ennemieProche) && !basHp()){
                etat = PURSUIT;
            } else if(voitEnnemie(ennemieProche) && basHp()){
                etat = FLEE;
            }
        break;

        case PURSUIT:
            deplacementCible(ennemieProche[0],ennemieProche[1],all);
            if(basHp()){
                etat = FLEE;
            }else if(contactEnnemie(ennemieProche)){
                etat = ATTACK;
            }else if(!voitEnnemie(ennemieProche)){
                etat = SLEEP;
            }
        break;

        case ATTACK:
        //Animation bras à revoire
            if(action==0)
            {
                mouvementbras=2;
                for(int i = 0; i < listeEnnemies.size(); i++){
                if(listeEnnemies[i]->getX()==ennemieProche[0] && listeEnnemies[i]->getY()==ennemieProche[1]){
                    listeEnnemies[i]->setHp(listeEnnemies[i]->getHp() - dmg);
                }
            }
            }
            if(action<30 && mouvementbras==2){
                action+=0.5;
            }
            if(action >= 30 && mouvementbras==2)
                mouvementbras=3;
            if(action>0 && mouvementbras==3)
                action-=0.5;

            if(basHp()){
                etat = FLEE;
            }else if(!contactEnnemie(ennemieProche)){
                etat = PURSUIT;
            }
        break;

        case FLEE:
            this->fuirCible(ennemieProche[0],ennemieProche[1],all);
            if(!voitEnnemie(ennemieProche)){
                etat = SLEEP;
            }else if(!basHp()){
                etat = PURSUIT;
            }
        break;

        default :
            etat = SLEEP;
        break;
    }
}

bool Guerrier::voitEnnemie(std::vector<float> ennemieProche){
    return (ennemieProche[2] <= vision);
}

bool Guerrier::basHp(){
    return (hp < hpMax/4);
}

bool Guerrier::contactEnnemie(std::vector<float> ennemieProche){
    return (ennemieProche[2] <=2);
}