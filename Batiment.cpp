#include "Batiment.hpp"
#include "Forme.hpp"

Batiment::Batiment(TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille){
        Texture_chateau = T_chateau;
        Texture_pierre = T_pierre;
        Texture_toit = T_toit;
        Texture_porte = T_porte;
        Texture_paille = T_paille;
}

void Batiment::creerChateau(){
                Forme forme;
		struct cube1 batiment1 =forme.creerCube(4.5);
		glEnable(GL_TEXTURE_2D);	
		glPushMatrix();{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
			//1ere Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				gluQuadricTexture(params, GL_TRUE);
				glRotatef(90,1,0,0);
				glTranslatef(-3,3,-5);
				gluCylinder(params,1.5,1.5,10,20,1);
				gluDisk(params,0,1.5,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//2eme Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				gluQuadricTexture(params, GL_TRUE);
				glRotatef(90,1,0,0);
				glTranslatef(3,-3,-5);
				gluCylinder(params,1.5,1.5,10,20,1);
				gluDisk(params,0,1.5,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//3eme Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				gluQuadricTexture(params, GL_TRUE);
				glRotatef(90,1,0,0);
				glTranslatef(3,3,-5);
				gluCylinder(params,1.5,1.5,10,20,1);
				gluDisk(params,0,1.5,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//4eme Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				gluQuadricTexture(params, GL_TRUE);
				glRotatef(90,1,0,0);
				glTranslatef(-3,-3,-5);
				gluCylinder(params,1.5,1.5,10,20,1);
				gluDisk(params,0,1.5,20,1);
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
}

void Batiment::creerCaserne(){
        Forme forme;
        struct cube1 batiment = forme.creerCube(3);
        struct cube1 mur = forme.creerCube(3);
        struct pyramide1 pyramide1 = forme.creerPyramide(4);
        glEnable(GL_TEXTURE_2D);
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
}

GLvoid Batiment::creerTour()
{
        Forme f;
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

void Batiment::creerFerme(){
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
