#include "Ferme.hpp"

Ferme::Ferme(TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille) : Batiment(T_chateau, T_pierre, T_toit, T_porte, T_paille){

}

void Ferme::creerBatiment() const{
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
}