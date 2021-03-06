#include "Chateau.hpp"

Chateau::Chateau(float x, float y, std::vector<Decor*> decors,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille):Batiment(x,y,T_chateau, T_pierre, T_toit, T_porte,  T_paille){
    hp=1000;
    hpMax=1000;
    hitbox.x1 = position[0]-5;
    hitbox.y1 = position[1]-5;
    hitbox.x2 = position[0]+5;
    hitbox.y2 = position[1]+5;
    enConstruction=false;
    nom="Chateau";
    _decors = decors;
}

void Chateau::creerPaysan(Joueur * J){
    
    if (J->getUnites().size() < J->getMaxUnites() && (J->getOr()-2) > 0){
        Personnage * PersPaysan = new Paysan(position[0],position[1]-15,0,7,J->getCouleur(),_decors, J,Texture_chateau,Texture_pierre,Texture_toit,Texture_porte,Texture_paille);
        J->subtractOr(2);
        J->addUnites(PersPaysan);
    }
}

void Chateau::creerBatiment() const{
    glPushMatrix();{
        glTranslatef(position[0],position[1],4.5);
        if(selected)
            barreHp(9);
        glRotatef(90,1.0,0.0,0.0);
        Forme forme;
        struct cube1 batiment1 =forme.creerCube(4.5);
        glEnable(GL_TEXTURE_2D);	
        glPushMatrix();{
            //1ere Tour
            glPushMatrix();{
                GLUquadric* params = gluNewQuadric();
                gluQuadricTexture(params, GL_TRUE);
                glRotatef(90,1,0,0);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
                glTranslatef(-3,3,-5);
                gluCylinder(params,1.5,1.5,10,20,1);
                gluDisk(params,0,1.5,20,1);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
				glTranslatef(0,0,-1.8);
				gluCylinder(params,0,2,2,20,1);
                gluDeleteQuadric(params);
            }
            glPopMatrix();
            //2eme Tour
            glPushMatrix();{
                GLUquadric* params = gluNewQuadric();
                gluQuadricTexture(params, GL_TRUE);
                glRotatef(90,1,0,0);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
                glTranslatef(3,-3,-5);
                gluCylinder(params,1.5,1.5,10,20,1);
                gluDisk(params,0,1.5,20,1);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
				glTranslatef(0,0,-1.8);
				gluCylinder(params,0,2,2,20,1);
                gluDeleteQuadric(params);
            }
            glPopMatrix();
            //3eme Tour
            glPushMatrix();{
                GLUquadric* params = gluNewQuadric();
                gluQuadricTexture(params, GL_TRUE);
                glRotatef(90,1,0,0);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
                glTranslatef(3,3,-5);
                gluCylinder(params,1.5,1.5,10,20,1);
                gluDisk(params,0,1.5,20,1);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
				glTranslatef(0,0,-1.8);
				gluCylinder(params,0,2,2,20,1);
                gluDeleteQuadric(params);
            }
            glPopMatrix();
            //4eme Tour
            glPushMatrix();{
                GLUquadric* params = gluNewQuadric();
                gluQuadricTexture(params, GL_TRUE);
                glRotatef(90,1,0,0);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
                glTranslatef(-3,-3,-5);
                gluCylinder(params,1.5,1.5,10,20,1);
                gluDisk(params,0,1.5,20,1);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
				glTranslatef(0,0,-1.8);
				gluCylinder(params,0,2,2,20,1);
                gluDeleteQuadric(params);
            }
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
        }
        glPopMatrix();
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();{
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_chateau->width, Texture_chateau->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_chateau->data);
            glScalef(0.6,0.95,0.6);
            glTranslatef(0,-0.82,0);
            forme.afficheCube(batiment1);
        }
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }glPopMatrix();
}