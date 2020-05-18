#include "Ferme.hpp"

Ferme::Ferme(Joueur * J, float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille) : Batiment(x,y,T_chateau, T_pierre, T_toit, T_porte, T_paille){
    hp=250;
    hpMax=250;
    hitbox.x1 = position[0]-1.25;
    hitbox.y1 = position[1]-1.25;
    hitbox.x2 = position[0]+1.25;
    hitbox.y2 = position[1]+1.25;
    J->setMaxUnites(J->getMaxUnites()+1);
    enConstruction=false;
    nom="Ferme";
}

void Ferme::creerBatiment() const{
    glPushMatrix();{

        glTranslatef(position[0],position[1],3);
        if(selected)
            barreHp(7);
        glRotatef(90,1.0,0.0,0.0);
        Forme forme;
        struct cube1 batiment = forme.creerCube(2.5);
        struct pyramide1 pyramide1 = forme.creerPyramide(3);
        glPushMatrix();{
            glEnable(GL_TEXTURE_2D);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
            forme.afficheCube(batiment);
            glDisable(GL_TEXTURE_2D);
            glPushMatrix();{
                    glEnable(GL_TEXTURE_2D);
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_paille->width, Texture_paille->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_paille->data);
                    glTranslatef(0,5,0);
                    forme.affichePyramide(pyramide1);
                    glDisable(GL_TEXTURE_2D);
            }
            glPopMatrix();
        }
        glPopMatrix();
        
    }glPopMatrix();
}