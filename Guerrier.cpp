#include "Guerrier.hpp"

Guerrier::Guerrier(float x, float y,float angle, float vitesseMAX, std::array<float,3> col):Personnage(x,y,angle,vitesseMAX,col){
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

void Guerrier::comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment, std::vector<Element *>  all) {
    std::vector<float> ennemieProche = rangeEnnemy(listeEnnemies);
    std::vector<float> batimentProche = rangeBatiment(listeBatiment);
    switch(etat){
        case SLEEP:
            if((voitElement(ennemieProche) || voitElement(batimentProche)) && !basHp()){
                etat = PURSUIT;
                this->ListPositions.clear();
            } else if(voitElement(ennemieProche) && basHp()){
                etat = FLEE;
                this->ListPositions.clear();
            }
        break;

        case PURSUIT:
            if(voitElement(ennemieProche)){
                if (this->ListPositions.empty()){
                    this->ListPositions = GenerateListPos(ennemieProche[0],ennemieProche[1]);
                }
            }else if(voitElement(batimentProche)){
                if (this->ListPositions.empty()){
                    this->ListPositions = GenerateListPos(batimentProche[0],batimentProche[1]);
                }
            }

            if(basHp()){
                etat = FLEE;
                this->ListPositions.clear();
            }else if(contactElement(ennemieProche,"Personnage") || contactElement(batimentProche,"Batiment")){
                etat = ATTACK;
            }else if(!voitElement(ennemieProche) && !voitElement(batimentProche)){
                etat = SLEEP;
            }
        break;

        case ATTACK:
        //Animation bras à revoir
            if(action==0)
            {
                mouvementbras=2;
                if(contactElement(ennemieProche,"Personnage")) {
                    for(int i = 0; i < listeEnnemies.size(); i++){
                        if(listeEnnemies[i]->getX()==ennemieProche[0] && listeEnnemies[i]->getY()==ennemieProche[1]){
                            listeEnnemies[i]->setHp(listeEnnemies[i]->getHp() - dmg);
                        }
                    }
                }else if(contactElement(batimentProche,"Batiment")) {
                    for(int i = 0; i < listeBatiment.size(); i++){
                        if(listeBatiment[i]->getX()==batimentProche[0] && listeBatiment[i]->getY()==batimentProche[1]){
                            listeBatiment[i]->setHp(listeBatiment[i]->getHp() - dmg);
                        }
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
                this->ListPositions.clear();
            }else if(!contactElement(ennemieProche,"Personnage") || !contactElement(batimentProche,"Batiment")){
                etat = PURSUIT;
                this->ListPositions.clear();
            }
        break;

        case FLEE:
            if(voitElement(ennemieProche)){
                //this->fuirCible(ennemieProche[0],ennemieProche[1],all);
                if (this->ListPositions.empty()){
                    this->ListPositions = GenerateListPosFuite(ennemieProche[0],ennemieProche[1]);
                }
            }else if (voitElement(batimentProche)){
                //this->fuirCible(batimentProche[0],batimentProche[1],all);
                if (this->ListPositions.empty()){
                    this->ListPositions = GenerateListPosFuite(batimentProche[0],batimentProche[1]);
                }
            }
            if(!voitElement(ennemieProche)){
                etat = SLEEP;
            }else if(!basHp()){
                etat = PURSUIT;
                this->ListPositions.clear();
            }
        break;

        default :
            etat = SLEEP;
        break;
    }
}

bool Guerrier::voitElement(std::vector<float> elementProche){
    return (elementProche[2] <= vision);
}

bool Guerrier::basHp(){
    return (hp < hpMax/4);
}

bool Guerrier::contactElement(std::vector<float> elementProche,std::string elem){
    if (elem == "Personnage"){
        return (elementProche[2] <=3);
    } else if (elem == "Batiment"){
        return (elementProche[2] <=6);
    }
}