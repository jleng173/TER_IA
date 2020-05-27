#include "Arbaletrier.hpp"

Arbaletrier::Arbaletrier(float x, float y,float angle, float vitesseMAX, std::array<float,3> col):Personnage(x,y,angle,vitesseMAX,col){
    nom="Arbaletrier";
    hp=100;
    hpMax=100;
    dmg=5;
    timeProjec = 0.0;
    selected = 0;
    range = 50;
}

void Arbaletrier::creerAccessoire() const{
    Forme fa;
    struct cube1 base = fa.creerCube(1);
    struct pyramide1 pic = fa.creerPyramide(1);
    glPushMatrix();{
        glScalef(2,2,2);
        glTranslatef(0,-1.5,0);
        glRotatef(90,0,0,1);
        //Partie arc
        glPushMatrix();{
            glColor3f(0.6,0.4,0.12);
            glScalef(0.1,0.5,0.1);
            fa.afficheCube(base);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0.6,0.4,0.12);
            glTranslatef(-0.2,0.65,0);
            glRotatef(45,0,0,1);
            glScalef(0.1,0.3,0.1);
            fa.afficheCube(base);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0.6,0.4,0.12);
            glTranslatef(-0.2,-0.65,0);
            glRotatef(-45,0,0,1);
            glScalef(0.1,0.3,0.1);
            fa.afficheCube(base);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1,1,1);
            glRotatef(-45,0,0,1);
            glTranslatef(-0.2,-0.8,0);
            glScalef(0.6,0.01,0.01);
            fa.afficheCube(base);
        }
        glPopMatrix();

        glPushMatrix();{
            glColor3f(1,1,1);
            glRotatef(45,0,0,1);
            glTranslatef(-0.2,0.8,0);
            glScalef(0.6,0.01,0.01);
            fa.afficheCube(base);
        }
        glPopMatrix();

        //Flèche
        glPushMatrix();{
            glTranslatef(0.3,0,0);
            glPushMatrix();{
                glColor3f(0.6,0.5,0.4);
                glTranslatef(-0.2,0,0);
                glScalef(0.1,0.05,0.05);
                fa.afficheCube(base);
            }
            glPopMatrix();
            glPushMatrix();{
                glRotatef(-90,0,0,1);
                glScalef(0.1,0.1,0.07);
                glColor3f(0.3,0.3,0.3);
                fa.affichePyramide(pic);
            }
            glPopMatrix();
        }
        glPopMatrix();

        //Partie centrale
        glPushMatrix();{
            glColor3f(0.6,0.4,0.12);
            glTranslatef(-1,0,0);
            glScalef(1,0.2,0.1);
            fa.afficheCube(base);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0.6,0.4,0.12);
            glTranslatef(-1.7,0,0.2);
            glScalef(0.1,0.1,0.2);
            fa.afficheCube(base);
        }
        glPopMatrix();
    }
    glPopMatrix();
}

void Arbaletrier::tirArbalete(float x, float y, std::vector<Element*> listeElements){
     glPushMatrix();{
          
          float posDepart[3] = {position[0],position[1],0.0};
          float posCible[3] = {x,y,0.0};
          float sm = 10 ;
          float coordX = posCible[0]-posDepart[0];
          float coordY = posCible[1]-posDepart[1];
          float angledeTir = 0.183*( max(abs(coordX),abs(coordY)) );
          angledeTir = (angledeTir*angledeTir)/(2-( min(abs(coordX),abs(coordY)) / max(abs(coordX),abs(coordY)) ));
          float arrive[3] = {coordX,coordY,angledeTir};
          float scalaire = 1/sqrt(arrive[0]*arrive[0]+arrive[1]*arrive[1]);
          float u[3] = {arrive[0]*scalaire,arrive[1]*scalaire,arrive[2]*scalaire};
          float g[3] = {0.0,0.0,-3.4};

          
          float usmt[3];
          usmt[0] = u[0] * sm * timeProjec;
          usmt[1] = u[1] * sm * timeProjec;
          usmt[2] = u[2] * sm * timeProjec;

          float gt2[3];
          gt2[0] = g[0] * (timeProjec*timeProjec);
          gt2[1] = g[1] * (timeProjec*timeProjec);
          gt2[2] = g[2] * (timeProjec*timeProjec);

          gt2[0] /= 2.0;
          gt2[1] /= 2.0;
          gt2[2] /= 2.0;

          float pt[3];
          pt[0] = usmt[0] + gt2[0];
          pt[1] = usmt[1] + gt2[1];
          pt[2] = usmt[2] + gt2[2];

          timeProjec+=0.02;

          glTranslatef(pt[0]+posDepart[0],pt[1]+posDepart[1],pt[2]);

          float angle = position[1] / sqrt(position[0]*position[0] + position[1]*position[1]);
          angle = acos(angle)* 180 / 3.14159265;
          if (position[0] > x)
            angle *=-1;
          glPushMatrix();{
            glRotatef(angle,0,0,1);
            glRotatef(-35+(timeProjec*10),1,0,0);
            creerCarreau();
          }glPopMatrix();

          if(pt[2] < -0.25){
            timeProjec = 0.0;

            // Baisse des pv
            for(int i = 0; i < listeElements.size(); i++){
                if(listeElements[i]->getX()==x && listeElements[i]->getY()==y){
                    listeElements[i]->setHp(listeElements[i]->getHp() - dmg);
                }
            }
          }

   }
  glPopMatrix();
}

GLvoid Arbaletrier::creerCarreau(){
    glPushMatrix();{
        glRotatef(-90,1,0,0);

        glColor3f(0.65,0.5,0.1);
        GLUquadric* params = gluNewQuadric();
        gluCylinder(params,0.1,0.1,2,20,20);
        gluDeleteQuadric(params);

        
        glPushMatrix();{
            glColor3f(0.4,0.4,0.4);
            glRotatef(-90,0.5,0,0);
            Forme pointe;
            pointe.affichePyramide(pointe.creerPyramide(0.185));
        }glPopMatrix();

        glPushMatrix();{
            glColor3f(0.65,0.5,0.1);
            glTranslatef(0.0,0.0,2);
            GLUquadric* params = gluNewQuadric();
            gluDisk(params,0,0.1,20,20);
            gluDeleteQuadric(params);

        }glPopMatrix();

        glPushMatrix();{
            glColor3f(0.65,0.2,0.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(0.1, 0.0, 1.2);
                glVertex3f(0.25, 0.0, 1.65);
                glVertex3f(0.1, 0.0, 1.9);
            glEnd();
        }glPopMatrix();

        glPushMatrix();{
            glBegin(GL_TRIANGLES);
                glVertex3f(-0.1, 0.0, 1.2);
                glVertex3f(-0.25, 0.0, 1.65);
                glVertex3f(-0.1, 0.0, 1.9);
            glEnd();
        }glPopMatrix();
        glColor3f(1.0,1.0,1.0);
    }glPopMatrix();
}

GLvoid Arbaletrier::creerChapeau() const{
    glPushMatrix();{
        glColor3f(0.7,0.7,0);
        GLUquadric* params = gluNewQuadric();
        gluQuadricTexture(params, GL_TRUE);
        glRotatef(90,1,0,0);
        gluDisk(params,0,1,20,1);
        gluDeleteQuadric(params);
    }
    glPopMatrix();
}

void Arbaletrier::comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment) {
    std::vector<float> ennemieProche = rangeEnnemy(listeEnnemies);
    std::vector<float> batimentProche = rangeBatiment(listeBatiment);
    switch(etat){
        case SLEEP:
            timeProjec = 0.0;
            if(CourtePortee(ennemieProche)){
                etat = FLEE;
                this->ListPositions.clear();
            }else if(LongPortee(ennemieProche) || LongPortee(batimentProche) ){
                etat = FIRE;
            }
        break;

        case FIRE:
            if(LongPortee(ennemieProche)){
                std::vector<Element*> elemEnnemies = {};
                for (int i = 0 ; i < listeEnnemies.size() ; i++){
                   elemEnnemies.push_back(dynamic_cast<Element*>(listeEnnemies[i]));
                }
                tirArbalete(ennemieProche[0],ennemieProche[1],elemEnnemies);
            }
            else if (LongPortee(batimentProche)){
                std::vector<Element*> elemBatiments = {};
                for (int i = 0 ; i < listeBatiment.size() ; i++){
                   elemBatiments.push_back(dynamic_cast<Element*>(listeBatiment[i]));
                }
                tirArbalete(batimentProche[0],batimentProche[1],elemBatiments);
            }

            if(CourtePortee(ennemieProche) || CourtePortee(batimentProche)){
                etat = FLEE;
                this->ListPositions.clear();
            }else if(!LongPortee(ennemieProche) && !LongPortee(batimentProche) ){
                etat = SLEEP;
            }
        break;

        case FLEE:
            if (this->ListPositions.empty()){
                this->ListPositions = GenerateListPosFuite(ennemieProche[0],ennemieProche[1]);
            }
            timeProjec = 0.0;
            if(!CourtePortee(ennemieProche)){
                etat = SLEEP;
            }
        break;

        default :
            etat = SLEEP;
        break;
    }
}

bool Arbaletrier::CourtePortee(std::vector<float> elementProche){
    return ( elementProche[2] <= ((float)range/3));
}

bool Arbaletrier::LongPortee(std::vector<float> elementProche) {
    return ( elementProche[2] > ((float)range/3) && elementProche[2] <= range );

}
