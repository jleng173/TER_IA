
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

void creer_tour()
{
		glPushMatrix();{
//			glEnable(GL_TEXTURE_2D);

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
