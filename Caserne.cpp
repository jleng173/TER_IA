#include "Caserne.hpp"

Caserne::Caserne(float x, float y, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille) : Batiment(x,y,T_chateau, T_pierre, T_toit, T_porte, T_paille){
    hp=1;
    hpMax=700;
    hitbox.x1 = position[0]-5;
    hitbox.y1 = position[1]-5;
    hitbox.x2 = position[0]+5;
    hitbox.y2 = position[1]+5;
    delaiConstruction=20;
    enConstruction=true;
    nom="Caserne";
}

//Modélisation du batiment
void Caserne::creerBatiment() const{

    glPushMatrix();{

    Forme forme;
    struct cube1 batiment = forme.creerCube(3);
    struct cube1 mur = forme.creerCube(3);
    struct pyramide1 pyramide1 = forme.creerPyramide(4);


    glTranslatef(position[0],position[1],3);
    if(selected)
        barreHp(9);

    glRotatef(90,1.0,0.0,0.0);
        glEnable(GL_TEXTURE_2D);
    glPushMatrix();{
        //Cour de la caserne
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
        //Toiture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
        glPushMatrix();{
                glTranslatef(0,6,0);
                glScalef(1.5,1,1);
                forme.affichePyramide(pyramide1);
        }
        glPopMatrix();
        //Fondation
        glScalef(1.5,1,1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_chateau->width, Texture_chateau->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_chateau->data);
        forme.afficheCube(batiment);
    }
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    }glPopMatrix();
}

//Creation du guerrier et ajout dans la liste des unités disponibles du Joueur J
void Caserne::creerGuerrier(Joueur * J){
        if (J->getUnites().size() < J->getMaxUnites() && (J->getOr() - 5) > 0){
                Personnage * PersGuerrier = new Guerrier(position[0],position[1]-10,0,10,J->getCouleur());
                J->subtractOr(5);
                J->addUnites(PersGuerrier);
        }       
}

//Creation de l'arbaletrier et ajout dans la liste des unités disponibles du Joueur J
void Caserne::creerArbaletrier(Joueur * J){
        if (J->getUnites().size() < J->getMaxUnites() && (J->getOr() - 4) > 0){
                Personnage * PersArbaletrier = new Arbaletrier(position[0],position[1]-10,0,9,J->getCouleur());
                J->subtractOr(4);
                J->addUnites(PersArbaletrier);
        } 
}