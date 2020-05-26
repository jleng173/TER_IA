#include "Personnage.hpp"


Personnage::Personnage(float x, float y, float angle, float v, std::array<float,3> col):Element(x,y){
    avance=0;
    action=0;
    mouv = 0;
    mouvementbras = 0;
    position[0] = x;
    position[1] = y;
    hitbox.x1 = position[0]-1;
    hitbox.y1 = position[1]-1;
    hitbox.x2 = position[0]+1;
    hitbox.y2 = position[1]+1;
    orientation = angle;
    vitesseMAX = v;
    selected = 0;
    etat = SLEEP;
    std::copy(std::begin(col), std::end(col), std::begin(couleur));
    ListPositions = {};
}



void Personnage::updatePos( float time){
    position[0] += velocite[0] * time;
    position[1] += velocite[1] * time;
    hitbox.x1 = position[0]-1;
    hitbox.y1 = position[1]-1;
    hitbox.x2 = position[0]+1;
    hitbox.y2 = position[1]+1;
    orientation = (atan2(-velocite[0],velocite[1]) * 180 / 3.14159265)-180;
}

void Personnage::setPosition(float x, float y){
    position[0] = x;
    position[1] = y;
    // hitbox.x1 = position[0]-1;
    // hitbox.y1 = position[1]-1;
    // hitbox.x2 = position[0]+1;
    // hitbox.y2 = position[1]+1;
    //     orientation = (atan2(-velocite[0],velocite[1]) * 180 / 3.14159265)-180;
    // ListPositions.erase(ListPositions.begin()+0);

}

void Personnage::tpCibleAStar(){

    if(!ListPositions.empty()){
        deplacementCibleAStar(ListPositions[0][0],ListPositions[0][1]);
            if(avance<19 && mouv == 0)
                avance += 1;
            if(avance >= 19 && mouv == 0)
                mouv = 1;
            if(avance>-19 && mouv == 1){
                avance -= 1;
            }
            if(avance <=-19 && mouv == 1)
                mouv=0; 
    }else {
        //ListPositions.insert()
    }
    
}

std::vector<std::vector<float>> Personnage::GenerateListPos(float x, float y){
    Node unite;
    unite.x = getX()+250;
    unite.y = getY()+250;

    Node destination;
    destination.x = x+250;
    destination.y = y+250;

    std::vector<std::vector<float>> GListpos = {};

    for (Node node : astar::aStar(unite, destination)) {
        if(node.x <10000 && node.y <10000){
            std::vector<float> unePos = {(float)node.x-250,(float)node.y-250};
            GListpos.push_back(unePos);
        }
                
    }
    return GListpos;
}

std::vector<std::vector<float>> Personnage::GenerateListPosFuite(float x, float y){
    Node unite;
    unite.x = getX()+250;
    unite.y = getY()+250;

    Node destination;
    destination.x = getX()-x+250;
    destination.y = getY()-y+250;

    std::vector<std::vector<float>> GListpos = {};

    for (Node node : astar::aStar(unite, destination)) {
        if(node.x <10000 && node.y <10000){
            std::vector<float> unePos = {(float)node.x-250,(float)node.y-250};
            GListpos.push_back(unePos);
        }
                
    }
    return GListpos;
}

void Personnage::deplacementCibleAStar(float x, float y){
     //SeekKinematic mouvement

        velocite[0] = x - position[0];
        velocite[1] = y - position[1] ;

        //Normalisation du vecteur velocite
        float v = sqrt(velocite[0]*velocite[0]+velocite[1]*velocite[1]);
        if (v > 0.05*vitesseMAX){
            velocite[0] = velocite[0]/v;
            velocite[1] = velocite[1]/v;
            
            velocite[0] *= vitesseMAX;
            velocite[1] *= vitesseMAX;
            
         }else{
             mouv=0; 
             avance = 0;
             ListPositions.erase(ListPositions.begin()+0);
         }

        updatePos(0.04);

}

void Personnage::deplacementCible(float x, float y, std::vector<Element *>  all){
    lastPosition[0]=x;
    lastPosition[1]=y;
    int limiteC = sqrt((Carte::tailleCarte*2)*(Carte::tailleCarte*2)/2);
    if((x != 0) && (y !=0) && (x <= limiteC-y ) && (y  <= limiteC-x) && (x >= -1*limiteC+y) && (y >= -1*limiteC+x)){

        //SeekKinematic mouvement

        velocite[0] = x - position[0];
        velocite[1] = y - position[1];

        // if(testSiColision(all)){
        //     velocite[0] =  position[0] - x;
        //     velocite[1] =  position[1] - y;

        // }

        //Normalisation du vecteur velocite
        float v = sqrt(velocite[0]*velocite[0]+velocite[1]*velocite[1]);
        if (v > 0.02*vitesseMAX){
            velocite[0] = velocite[0]/v;
            velocite[1] = velocite[1]/v;

            if(avance<19 && mouv == 0)
                avance += 0.1*vitesseMAX;
            if(avance >= 19 && mouv == 0)
                mouv = 1;
            if(avance>-19 && mouv == 1){
                avance -= 0.1*vitesseMAX;
            }
            if(avance <=-19 && mouv == 1)
                mouv=0; 
            
            velocite[0] *= vitesseMAX;
            velocite[1] *= vitesseMAX;
            
        }else{
            mouv=0; 
            avance = 0;
        }

        updatePos(0.04);
    // printf("a = %f \n",avance)
    }
}

void Personnage::fuirCible(float x, float y,std::vector<Element *>  all){

    int limiteC = sqrt((Carte::tailleCarte*2)*(Carte::tailleCarte*2)/2);

    if((x != 0) && (y !=0) && (position[0] <= limiteC-position[1] ) && (position[1]  <= limiteC-position[0]) && (position[0] >= -1*limiteC+position[1]) && (position[1] >= -1*limiteC+position[0])){

        //FleeKinematic mouvement

        velocite[0] =  position[0] - x;
        velocite[1] =  position[1] - y;

        // if(testSiColision(all)){
        //     velocite[0] =  x - position[0];
        //     velocite[1] =  y - position[1];
        // }

        //Normalisation du vecteur velocite
        float v = sqrt(velocite[0]*velocite[0]+velocite[1]*velocite[1]);
        if (v > 0.02*vitesseMAX){
            velocite[0] = velocite[0]/v;
            velocite[1] = velocite[1]/v;

            if(avance<19 && mouv == 0)
                avance += 0.1*vitesseMAX;
            if(avance >= 19 && mouv == 0)
                mouv = 1;
            if(avance>-19 && mouv == 1){
                avance -= 0.1*vitesseMAX;
            }
            if(avance <=-19 && mouv == 1)
                mouv=0; 
            
            velocite[0] *= vitesseMAX;
            velocite[1] *= vitesseMAX;
            
        }else{
            mouv=0; 
            avance = 0;
        }

        updatePos(0.04);
    // printf("a = %f \n",avance)
    }else{
       // deplacementCible(x-5,y-5,all);
    }
}

Hitbox Personnage::getHitbox(){
    return hitbox;
}

GLvoid Personnage::selectionne(){
    glPushMatrix();{
        glColor3f(0,1,0);
        glTranslatef(0,-4,0);
        glRotatef(90,1.0,0.0,0.0);
        GLUquadric* params = gluNewQuadric();
        gluDisk(params,0.9,1,20,1);
		gluDeleteQuadric(params);
        glColor3f(1,1,1);
    }glPopMatrix();
}

GLvoid Personnage::barreHp(){

    float lonHp = (6/(float)hpMax)*hp-3;
    glPushMatrix();{
        glColor3f(1,0,0);
        //glRotatef(90,1.0,0.0,0.0);
 	glBegin( GL_QUADS );
	 	glVertex3f(-3, 1.5, 4);
		glVertex3f(-3, 1, 4);
		glVertex3f(3, 1, 4);
        glVertex3f(3, 1.5, 4);   
    glEnd();
    glColor3f(0,1,0);
     	glBegin( GL_QUADS );
	 	glVertex3f(-3, 1.5, 4);
		glVertex3f(-3, 1, 4);
		glVertex3f(lonHp, 1, 4);
        glVertex3f(lonHp, 1.5, 4);   
    glEnd();
    glColor3f(1,1,1);
    //creerAccessoire();
    }glPopMatrix();
}

bool Personnage::isSelected(){
    return selected;
}

void Personnage::setSelected(int s){
    selected = s;
}

GLvoid Personnage::creerPersonnage()
{
    
glPushMatrix();{
    glTranslatef(position[0],position[1],0);
    
    glPushMatrix();{

        //glScalef(5,5,5);
        if(selected)
            barreHp();
        glRotatef(90,1.0,0.0,0.0);
        glTranslatef(0,4,0);
        glRotatef(orientation,0,1,0);
        Forme f;
        struct cube1 membre = f.creerCube(1.5);
        glPushMatrix();{
             
            creerChapeau();
            glPushMatrix();{
                glColor3f(0.1,0.1,0.1);
                glutSolidSphere(0.5,10,100);
            }
            glPopMatrix();
            //Corps
            glPushMatrix();{
                glTranslatef(0,-1.5,0);
                glColor3f(couleur[0],couleur[1],couleur[2]);
                glScalef(0.3,0.7,0.2);
                f.afficheCube(membre);
            }
            glPopMatrix();
            //Bras gauche   (epaule jusqu'au bas)
                //1er Articulation
            glPushMatrix();{
                glRotatef(avance,1,0,0);
                glPushMatrix();{
                    glColor3f(1,1,1);
                    glTranslatef(0.6,-0.8,0);
                    glutSolidSphere(0.2,10,100);
                }
                glPopMatrix();
                glPushMatrix();{
                    glTranslatef(0.7,-1.2,0);
                    glColor3f(0,0,0);
                    glScalef(0.1,0.2,0.1);
                    f.afficheCube(membre);
                }
                glPopMatrix();
                    //2e Articulation
                glPushMatrix();{
                    glColor3f(1,1,1);
                    glTranslatef(0.7,-1.6,0);
                    glutSolidSphere(0.2,10,100);
                }
                glPopMatrix();
                glPushMatrix();{
                    glTranslatef(0.7,-2,0);
                    glColor3f(0,0,0);
                    glScalef(0.1,0.2,0.1);
                    f.afficheCube(membre);
                }
                glPopMatrix();
                    //Main Gauche
                glPushMatrix();{
                    glColor3f(0,0,0);
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
            if(mouvementbras==2 || mouvementbras==3){
                glRotatef(-45+action,1,0,0);
            }
            glPushMatrix();{
                glColor3f(1,1,1);
                glTranslatef(-0.6,-0.8,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(-0.7,-1.2,0);
                glColor3f(0,0,0);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
                //Articulation    
            glPushMatrix();{
                glColor3f(1,1,1);
                glTranslatef(-0.7,-1.6,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            if(mouvementbras==2 || mouvementbras==3){
                    glRotatef(-90+action,1,0,0);
                    glTranslatef(0,1.6,-1.6);
            }
            glPushMatrix();{
                glPushMatrix();{
                    // glRotatef(action,1,0,0);
                    glTranslatef(-0.7,-2,0);
                    glColor3f(0,0,0);
                    glScalef(0.1,0.2,0.1);
                    f.afficheCube(membre);
                }
                glPopMatrix();
                //Main droite
                glPushMatrix();{
                    glColor3f(0,0,0);
                    glTranslatef(-0.7,-2.4,0);
                    glutSolidSphere(0.15,10,100);
                }
                glPopMatrix();
                //Accessoire
                glPushMatrix();{
                    glTranslatef(-0.7,-2.5,2.5);
                    glRotatef(90,1,0,0);
                    // glRotatef(90,0,1,0);
                    glScalef(0.4,0.4,0.4);
                    creerAccessoire();
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
                glColor3f(1,1,1);
                glTranslatef(0.6,-0.8,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(0.7,-1.2,0);
                glColor3f(0,0,0);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
                //Articulation
            glPushMatrix();{
                glColor3f(1,1,1);
                glTranslatef(0.7,-1.6,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(0.7,-2,0);
                glColor3f(0,0,0);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
            glPushMatrix();{
                glColor3f(0,0,0);
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
                glColor3f(1,1,1);
                glTranslatef(-0.6,-0.8,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(-0.7,-1.2,0);
                glColor3f(0,0,0);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
                //Articulation    
            glPushMatrix();{
                glColor3f(1,1,1);
                glTranslatef(-0.7,-1.6,0);
                glutSolidSphere(0.2,10,100);
            }
            glPopMatrix();
            glPushMatrix();{
                glTranslatef(-0.7,-2,0);
                glColor3f(0,0,0);
                glScalef(0.1,0.2,0.1);
                f.afficheCube(membre);
            }
            glPopMatrix();
            glPushMatrix();{
                glColor3f(0,0,0);
                glTranslatef(-0.7,-2.4,0);
                glutSolidSphere(0.15,10,100);
            }
            glPopMatrix();
        }
        glPopMatrix();

        if (selected){
            selectionne();
        }

       glColor3f(1,1,1);
    }
    glPopMatrix();
}glPopMatrix();
}

GLvoid Personnage::drawHalfSphere(int scaley, int scalex, GLfloat r) {
   int i, j;
   GLfloat v[scalex*scaley][3];

   for (i=0; i<scalex; ++i) {
     for (j=0; j<scaley; ++j) {
       v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
       v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
       v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
     }
   }

   glBegin(GL_QUADS);
     for (i=0; i<scalex-1; ++i) {
       for (j=0; j<scaley; ++j) {
         glVertex3fv(v[i*scaley+j]);
         glVertex3fv(v[i*scaley+(j+1)%scaley]);
         glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
         glVertex3fv(v[(i+1)*scaley+j]);
       }
     }
   glEnd();
 }


int Personnage::getDmg(){
    return dmg;
}

float Personnage::getLastX(){
    return lastPosition[0];
}

float Personnage::getLastY(){
    return lastPosition[1];
}

float Personnage::getOrientation(){
    return orientation;
}

float Personnage::getvitesseMAX(){
    return vitesseMAX;
}

std::string Personnage::getNom(){
    return nom;
}

State Personnage::setEtat(State e){
    etat = e;
}

State Personnage::getEtat(){
   return etat;
}

std::vector<float> Personnage::rangeEnnemy(std::vector<Personnage*> listeEnnemies) {
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

 std::vector<float> Personnage::rangeBatiment(std::vector<Batiment*> listeBatiment){
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