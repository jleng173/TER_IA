extern TEXTURE_STRUCT * Texture_chateau;
extern TEXTURE_STRUCT * Texture_toit;
extern TEXTURE_STRUCT * Texture_pierre;
extern TEXTURE_STRUCT * Texture_porte;
extern TEXTURE_STRUCT * Texture_paille;

GLvoid creer_chateau()
{
		struct cube1 batiment1 =creer_cube1(4.5);
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
			affiche_cube1(batiment1);
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
}

GLvoid creer_caserne()
{
		struct cube1 batiment =creer_cube1(3);		
		struct cube1 mur =creer_cube1(3);
		struct pyramide1 pyramide1 =creer_pyramide1(4);
		glEnable(GL_TEXTURE_2D);	
		glPushMatrix();{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
			glPushMatrix();{
				glTranslatef(-2.7,-1.2,4.5);
				glScalef(0.1,0.6,0.6);
				affiche_cube1(mur);
			}
			glPopMatrix();
			glPushMatrix();{
				glTranslatef(2.7,-1.2,4.5);
				glScalef(0.1,0.6,0.6);
				affiche_cube1(mur);
			}
			glPopMatrix();
			glPushMatrix();{
				glTranslatef(0,-1.2,6.6);
				glScalef(1,0.6,0.1);
				affiche_cube1(mur);
			}
			glPopMatrix();
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_toit->width, Texture_toit->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_toit->data);
			glPushMatrix();{
				glTranslatef(0,6,0);
				glScalef(1.5,1,1);
				affiche_pyramide(pyramide1);
			}
			glPopMatrix();
			glScalef(1.5,1,1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_chateau->width, Texture_chateau->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_chateau->data);
			affiche_cube1(batiment);

		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
}

GLvoid creer_ferme()
{
		struct cube1 batiment =creer_cube1(2.5);		
		struct pyramide1 pyramide1 =creer_pyramide1(3);
		glPushMatrix();{
			glEnable(GL_TEXTURE_2D);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);		
			affiche_cube1(batiment);
			glDisable(GL_TEXTURE_2D);
			glPushMatrix();{
				glEnable(GL_TEXTURE_2D);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_paille->width, Texture_paille->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_paille->data);		
				glTranslatef(0,5,0);
				affiche_pyramide(pyramide1);
				glDisable(GL_TEXTURE_2D);
			}
			glPopMatrix();
		}
		glPopMatrix();
}

GLvoid creer_tour()
{
	glPushMatrix();{
		//Tour
		glEnable(GL_TEXTURE_2D);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_pierre->width, Texture_pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_pierre->data);
		glPushMatrix();{
			GLUquadric* params = gluNewQuadric();
			gluQuadricTexture(params, GL_TRUE);
			glRotatef(90,1,0,0);
			glTranslatef(-3,2,-5);
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
			glTranslatef(-3,2,-7);
			gluCylinder(params,0,2.5,3,20,1);
			// glTranslatef(0,0,3);
			// gluDisk(params,0,2.5,20,1);
			gluDeleteQuadric(params);
		}
		glPopMatrix();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_porte->width, Texture_porte->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_porte->data);

		glPushMatrix();{
			struct cube1 porte = creer_cube1(2.5);
			glScalef(0.1,0.4,0.2);
			glTranslatef(-15,-10,10);
			affiche_cube1(porte);
		}
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
}
