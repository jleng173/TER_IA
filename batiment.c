
void creer_chateau()
{
		struct cube1 batiment1 =creer_cube1(4.5);
		glPushMatrix();{
//			glEnable(GL_TEXTURE_2D);

			//1ere Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(-3,2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//2eme Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(3,-2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//3eme Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(3,2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//4eme Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(-3,-2,-5);
				gluCylinder(params,2,2,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
//			glDisable(GL_TEXTURE_2D);
		}
		glPopMatrix();
		glScalef(0.6,0.95,0.6);
		glTranslatef(0,-0.82,0);
		affiche_cube1(batiment1);

}

void creer_caserne(TEXTURE_STRUCT * Texture_toit)
{
		struct cube1 batiment =creer_cube1(3);		
		struct cube1 mur =creer_cube1(3);
		struct pyramide1 pyramide1 =creer_pyramide1(3);
		glPushMatrix();{
			affiche_cube1(batiment);
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
			glPushMatrix();{
				glTranslatef(0,6,0);
				affiche_pyramide(pyramide1);
			}
			glPopMatrix();
		}
		glPopMatrix();
}

void creer_ferme()
{
		struct cube1 batiment =creer_cube1(2.5);		
		struct pyramide1 pyramide1 =creer_pyramide1(3);
		glPushMatrix();{
			affiche_cube1(batiment);
			glPushMatrix();{
				glTranslatef(0,5,0);
				affiche_pyramide(pyramide1);
			}
			glPopMatrix();
		}
		glPopMatrix();
}

void creer_tour()
{
		glPushMatrix();{
			//Tour
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(-3,2,-5);
				gluCylinder(params,1.5,1.5,10,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
			//Toiture			
			glPushMatrix();{
				GLUquadric* params = gluNewQuadric();
				glRotatef(90,1,0,0);
				glTranslatef(-3,2,-7.5);
				gluCylinder(params,0,2.5,3,20,1);
				gluDeleteQuadric(params);
			}
			glPopMatrix();
		}
		glPopMatrix();
}
