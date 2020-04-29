#include "Caserne.hpp"

Caserne::Caserne(float x, float y, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille) : Batiment(x,y,T_chateau, T_pierre, T_toit, T_porte, T_paille){
    hp=700;
    hpMax=700;
    hitbox.x1 = position[0]-2;
    hitbox.y1 = position[1]-2;
    hitbox.x2 = position[0]+2;
    hitbox.y2 = position[1]+2;
}

void Caserne::creerBatiment() const{
    Forme forme;
    struct cube1 batiment = forme.creerCube(3);
    struct cube1 mur = forme.creerCube(3);
    struct pyramide1 pyramide1 = forme.creerPyramide(4);
    glEnable(GL_TEXTURE_2D);
    
    glPushMatrix();{
   // barreHp();
    glTranslatef(0.0,0.0,3);
    glRotatef(90,1.0,0.0,0.0);
    
    glPushMatrix();{
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
        glPushMatrix();{
                glTranslatef(-2.7,-1.2,4.5);
                glScalef(0.1,0.6,0.6);
                forme.afficheCube(mur);
        }
        glPopMatrix();
        glPushMatrix();{
                glTranslatef(2.7,-1.2,4.5);
                glScalef(0.1,0.6,0.6);
                forme.afficheCube(mur);
        }
        glPopMatrix();
        glPushMatrix();{
                glTranslatef(0,-1.2,6.6);
                glScalef(1,0.6,0.1);
                forme.afficheCube(mur);
        }
        glPopMatrix();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
        glPushMatrix();{
                glTranslatef(0,6,0);
                glScalef(1.5,1,1);
                forme.affichePyramide(pyramide1);
        }
        glPopMatrix();
        glScalef(1.5,1,1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_chateau->width, Texture_chateau->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_chateau->data);
        forme.afficheCube(batiment);
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    }glPopMatrix();
}

void Caserne::creerGuerrier(Joueur * J){
        if (J->getUnites().size() < J->getMaxUnites()){
                printf("CREATION D'UN GUERRIER \n");
                Personnage * PersGuerrier = new Guerrier(position[0],position[1]-3,0,5);
                J->subtractOr(5);
                J->addUnites(PersGuerrier);
        }       
}

void Caserne::creerArbaletrier(Joueur * J){
        if (J->getUnites().size() < J->getMaxUnites()){
                printf("CREATION D'UN ARBALETRIER \n");
                Personnage * PersArbaletrier = new Arbaletrier(position[0],position[1]-3,0,4);
                J->subtractOr(4);
                J->addUnites(PersArbaletrier);
        } 
}