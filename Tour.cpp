#include "Tour.hpp"

Tour::Tour(float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille):Batiment(x,y,T_chateau,T_pierre,T_toit,T_porte, T_paille){
    hp=1;
    hpMax=400;
    dmg=10;
    range=50;
	hitbox.x1 = position[0]-1;
    hitbox.y1 = position[1]-1;
    hitbox.x2 = position[0]+1;
    hitbox.y2 = position[1]+1;
	enConstruction=true;
	delaiConstruction=20;
	nom="Tour";
	timeProjec = 0.0;
    etat=SLEEP;
}

//Modélisation du batiment
void Tour::creerBatiment() const{
	glPushMatrix();{
		Forme f;
		glTranslatef(position[0],position[1],1);
		if(selected)
			barreHp(11);
		glRotatef(90,1.0,0.0,0.0);
		glRotatef(90,0.0,1.0,0.0);
		glPushMatrix();{
			//Tour
			glEnable(GL_TEXTURE_2D);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				gluQuadricTexture(params, GL_TRUE);
				glRotatef(90,1,0,0);
				glTranslatef(0,0,-10);
				gluCylinder(params,1.5,1.5,10,20,1);
				gluDeleteQuadric(params);
			}glPopMatrix();
			//Toiture			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				gluQuadricTexture(params, GL_TRUE);
				glRotatef(90,1,0,0);
				glTranslatef(0,0,-12);
				gluCylinder(params,0,2.5,3,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
            
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_porte->width, Texture_porte->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_porte->data);

			glPushMatrix();{
				struct cube1 porte = f.creerCube(2.5);
				glScalef(0.1,0.4,0.2);
				glTranslatef(-15,2.5,0);
				f.afficheCube(porte);
			}
			glPopMatrix();
			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

int Tour::getDmg(){
	return dmg;
}

//Modélisation du carrreau et translation vers la cible
//Baisse des points de vie de l'ennemi lorsqu'il atteint la cible
void Tour::tirArbalete(float x, float y,  std::vector<Element*> listeElements){
     glPushMatrix();{
          
          float posDepart[3] = {position[0],position[1],0.0};
          float posCible[3] = {x,y,0.0};
          float sm = 10 ;
          float coordX = posCible[0]-posDepart[0];
          float coordY = posCible[1]-posDepart[1];
          float angledeTir = 0.183*( std::max(abs(coordX),abs(coordY)) );
          angledeTir = (angledeTir*angledeTir)/(2-( std::min(abs(coordX),abs(coordY)) / std::max(abs(coordX),abs(coordY)) ));
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

//Modelisation du carreau
GLvoid Tour::creerCarreau(){
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

//Comportement de la tour en présence d'ennemi
//Attaque si un ennemi est à sa portée
//Reste endormie sinon
void Tour::comportement(std::vector<Personnage*> listeEnnemies,std::vector<Batiment*> listeBatiment) {
    std::vector<float> ennemieProche = rangeEnnemy(listeEnnemies);
    std::vector<float> batimentProche = rangeBatiment(listeBatiment);
    switch(etat){
        case SLEEP:
            timeProjec = 0.0;
            if(elementPortee(ennemieProche) || elementPortee(batimentProche) ){
                etat = FIRE;
            }
        break;

        case FIRE:
        if( elementPortee(ennemieProche) ){

            std::vector<Element*> elemEnnemies = {};
            for (int i = 0 ; i < listeEnnemies.size() ; i++){
                elemEnnemies.push_back(dynamic_cast<Element*>(listeEnnemies[i]));
            }
            tirArbalete(ennemieProche[0],ennemieProche[1],elemEnnemies);

        }else if (elementPortee(batimentProche)){

            std::vector<Element*> elemBatiment = {};
            for (int i = 0 ; i < listeBatiment.size() ; i++){
                elemBatiment.push_back(dynamic_cast<Element*>(listeBatiment[i]));
            }
            tirArbalete(batimentProche[0],batimentProche[1],elemBatiment);

        } else {
            etat = SLEEP;
        }
        break;

        default :
            etat = SLEEP;
        break;
    }
}

//Détection d'unité ennemi
std::vector<float> Tour::rangeEnnemy(std::vector<Personnage*> listeEnnemies) {
    std::vector<float> ennemyproche= {0,0,INFINITY};
    float distanceMin = INFINITY;
    for(int i = 0 ; i < listeEnnemies.size() ; i++){
        float calculx = listeEnnemies[i]->getX()-position[0];
        float calculy = listeEnnemies[i]->getY()-position[1];
        float distance = sqrtf((calculx*calculx)+(calculy*calculy));
        
        if(distance < distanceMin){
            distanceMin = distance;
            ennemyproche[0] = listeEnnemies[i]->getX();
            ennemyproche[1] = listeEnnemies[i]->getY();
        }
    }
    ennemyproche[2] = distanceMin;
    return ennemyproche;
}

//Détection de batiment ennemi
std::vector<float> Tour::rangeBatiment(std::vector<Batiment*> listeBatiment){
    std::vector<float> batimentproche= {0,0,INFINITY};
    float distanceMin = INFINITY;
    for(int i = 0 ; i < listeBatiment.size() ; i++){
        float calculx = listeBatiment[i]->getX()-position[0];
        float calculy = listeBatiment[i]->getY()-position[1];
        float distance = sqrtf((calculx*calculx)+(calculy*calculy));
        
        if(distance < distanceMin){
            distanceMin = distance;
            batimentproche[0] = listeBatiment[i]->getX();
            batimentproche[1] = listeBatiment[i]->getY();
        }
    }
    batimentproche[2] = distanceMin;
    return batimentproche;
 }

bool Tour::elementPortee(std::vector<float> elementProche) {
    return ( elementProche[2] > 2 && elementProche[2] <= range );

}