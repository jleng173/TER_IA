#include "Paysan.hpp"

Paysan::Paysan(float x, float y,float angle, float vitesseMAX):Personnage(x,y,angle,vitesseMAX){
    nom="Paysan";
    hp=75;
    hpMax=75;
    dmg=2;
    selected = 0;
    vision = 25.0;
}

void Paysan::construireCaserne(Joueur * J,float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille){
    if(J->getBois() >= 2 && J->getPierre() >= 8){
        J->subtractBois(2);
        J->subtractPierre(8);
        Batiment * cas = new Caserne(x,y,T_chateau,T_pierre,T_toit,T_porte,T_paille);
        J->addBatiment(cas);
    }
}

void Paysan::construireFerme(Joueur * J,float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille){
    if(J->getBois() >= 4 && J->getPierre() >= 1){
        J->subtractBois(4);
        J->subtractPierre(1);
        Batiment * ferm = new Ferme(x,y,T_chateau,T_pierre,T_toit,T_porte,T_paille);
        J->addBatiment(ferm);
    }
}

void Paysan::construireTour(Joueur * J,float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille){
    if(J->getBois() >= 5 && J->getPierre() >= 5){
        J->subtractBois(5);
        J->subtractPierre(5);
        Batiment * tower = new Tour(x,y,T_chateau,T_pierre,T_toit,T_porte,T_paille);
        
        J->addBatiment(tower);
    }
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
        glColor3f(0.6,0.6,0.6);
        glPushMatrix();{     
            glScalef(0.3,0.3,0.3);
            glTranslatef(5.5,-3.25,0);
            glRotatef(-135,0,0,1);
            f.affichePyramide(pic);
        }
        glPopMatrix();
        glPushMatrix();{
            glScalef(0.3,0.3,0.3);
            glTranslatef(-5.5,-3.25,0);
            glRotatef(135,0,0,1);
            f.affichePyramide(pic);
        }
        glPopMatrix();
        glPushMatrix();{
            glScalef(0.8,0.3,0.3);
            f.afficheCube(base);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(-1.02,-0.35,0);
            glRotatef(45,0,0,1);
            glScalef(0.6,0.3,0.3);
            f.afficheCube(base);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(1.02,-0.35,0);
            glRotatef(-45,0,0,1);
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

void Paysan::comportement(std::vector<Personnage*> listeEnnemies,std::vector<Element *>  all){
    std::vector<float> ennemieProche = rangeEnnemy(listeEnnemies);
    switch(etat){
        case SLEEP:
            if(voitEnnemie(ennemieProche)){
                etat = FLEE;
            }
        break;

        case FLEE:
            fuirCible(ennemieProche[0],ennemieProche[1],all);
            if(!voitEnnemie(ennemieProche)){
                etat = SLEEP;
            }
        break;

        default :
            etat = SLEEP;
        break;
    }
}

bool Paysan::voitEnnemie(std::vector<float> ennemieProche){
    return(ennemieProche[2] <= vision);
}
