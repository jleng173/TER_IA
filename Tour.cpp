#include "Tour.hpp"

Tour::Tour(float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille):Batiment(x,y,T_chateau,T_pierre,T_toit,T_porte, T_paille){
    hp=1;
    hpMax=400;
    dmg=10;
    range=5;
	hitbox.x1 = position[0]-1;
    hitbox.y1 = position[1]-1;
    hitbox.x2 = position[0]+1;
    hitbox.y2 = position[1]+1;
	enConstruction=true;
	delaiConstruction=20;
}

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
			}
			glPopMatrix();
			//Toiture			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				gluQuadricTexture(params, GL_TRUE);
				glRotatef(90,1,0,0);
				glTranslatef(0,0,-12);
				gluCylinder(params,0,2.5,3,20,1);
				// glTranslatef(0,0,3);
				// gluDisk(params,0,2.5,20,1);
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