#include "Forme.hpp"

Forme::Forme(){}

struct cube1 Forme::creerCube(float taille){
	struct cube1 cube; 
	cube.sommet8[0]=-taille;
	cube.sommet8[1]=-taille;
	cube.sommet8[2]=taille;

	cube.sommet7[0]=taille;
	cube.sommet7[1]=-taille;
	cube.sommet7[2]=taille;

	cube.sommet6[0]=taille;
	cube.sommet6[1]=taille;
	cube.sommet6[2]=taille;

	cube.sommet5[0]=-taille;
	cube.sommet5[1]=taille;
	cube.sommet5[2]=taille;

	cube.sommet4[0]=-taille;
	cube.sommet4[1]=-taille;
	cube.sommet4[2]=-taille;

	cube.sommet3[0]=-taille;
	cube.sommet3[1]=taille;
	cube.sommet3[2]=-taille;

	cube.sommet2[0]=taille;
	cube.sommet2[1]=taille;
	cube.sommet2[2]=-taille;

	cube.sommet1[0]=taille;
	cube.sommet1[1]=-taille;
	cube.sommet1[2]=-taille;

	return cube;
}


GLvoid Forme::afficheCube(struct cube1 cube){
	glPushMatrix();
		{
			glBegin(GL_QUADS);
			/* 1er face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet8[0],cube.sommet8[1],cube.sommet8[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet7[0],cube.sommet7[1],cube.sommet7[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet6[0],cube.sommet6[1],cube.sommet6[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet5[0],cube.sommet5[1],cube.sommet5[2]);
			}
			glPopMatrix();

			/* 2e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet4[0],cube.sommet4[1],cube.sommet4[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet3[0],cube.sommet3[1],cube.sommet3[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet2[0],cube.sommet2[1],cube.sommet2[2]);
				glTexCoord2f(1,1);
				glVertex3f(cube.sommet1[0],cube.sommet1[1],cube.sommet1[2]);
			}
			glPopMatrix();

			/* 3e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet3[0],cube.sommet3[1],cube.sommet3[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet5[0],cube.sommet5[1],cube.sommet5[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet6[0],cube.sommet6[1],cube.sommet6[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet2[0],cube.sommet2[1],cube.sommet2[2]);
			}
			glPopMatrix();

			/* 4e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet4[0],cube.sommet4[1],cube.sommet4[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet1[0],cube.sommet1[1],cube.sommet1[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet7[0],cube.sommet7[1],cube.sommet7[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet8[0],cube.sommet8[1],cube.sommet8[2]);
			}
			glPopMatrix();
		
			/* 5e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet1[0],cube.sommet1[1],cube.sommet1[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet2[0],cube.sommet2[1],cube.sommet2[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet6[0],cube.sommet6[1],cube.sommet6[2]);
				glTexCoord2f(1,1);
				glVertex3f(cube.sommet7[0],cube.sommet7[1],cube.sommet7[2]);
			}
			glPopMatrix();
			/* 6e face */
			glPushMatrix();
			{
				glTexCoord2f(0,1);
				glVertex3f(cube.sommet4[0],cube.sommet4[1],cube.sommet4[2]);
				glTexCoord2f(1,1);  
				glVertex3f(cube.sommet8[0],cube.sommet8[1],cube.sommet8[2]);
				glTexCoord2f(1,0);
				glVertex3f(cube.sommet5[0],cube.sommet5[1],cube.sommet5[2]);
				glTexCoord2f(0,0);
				glVertex3f(cube.sommet3[0],cube.sommet3[1],cube.sommet3[2]);
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();
}

struct pyramide1 Forme::creerPyramide(float taille){
	struct pyramide1 pyramide; 
	 pyramide.sommet5[0]=0;
	 pyramide.sommet5[1]=taille;
	 pyramide.sommet5[2]=0;

	 pyramide.sommet4[0]=-taille;
	 pyramide.sommet4[1]=-taille;
	 pyramide.sommet4[2]=taille;

	 pyramide.sommet3[0]=-taille;
	 pyramide.sommet3[1]=-taille;
	 pyramide.sommet3[2]=-taille;

	 pyramide.sommet2[0]=taille;
	 pyramide.sommet2[1]=-taille;
	 pyramide.sommet2[2]=-taille;

	 pyramide.sommet1[0]=taille;
	 pyramide.sommet1[1]=-taille;
	 pyramide.sommet1[2]=taille;

	return  pyramide;
}

GLvoid Forme::affichePyramide(struct pyramide1 pyramide)
{
    glPushMatrix();
	{
    glBegin( GL_TRIANGLES );
        //Face toit 1
		glTexCoord2f(0,0);
        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f );
		glTexCoord2f(0,1);
        glVertex3f( pyramide.sommet4[0], pyramide.sommet4[1], pyramide.sommet4[2] );
		glTexCoord2f(0.5,1);
        glVertex3f( pyramide.sommet1[0], pyramide.sommet1[1], pyramide.sommet1[2]);

        //Face toit 2
		glTexCoord2f(0.5,1);
        glVertex3f( pyramide.sommet3[0], pyramide.sommet3[1], pyramide.sommet3[2]);
        glTexCoord2f(0,0);
        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f);
        glTexCoord2f(0,1);
        glVertex3f( pyramide.sommet4[0], pyramide.sommet4[1], pyramide.sommet4[2]);

        //Face toit 3
		glTexCoord2f(0,1);
        glVertex3f( pyramide.sommet2[0], pyramide.sommet2[1], pyramide.sommet2[2]);
		glTexCoord2f(0,0);
        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f);
		glTexCoord2f(0.5,1);
        glVertex3f( pyramide.sommet1[0], pyramide.sommet1[1], pyramide.sommet1[2]);

        //Face toit 4
		glTexCoord2f(0,0);
        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f);
		glTexCoord2f(0.5,1);
        glVertex3f( pyramide.sommet2[0], pyramide.sommet2[1], pyramide.sommet2[2]);
		glTexCoord2f(0,1);
        glVertex3f( pyramide.sommet3[0], pyramide.sommet3[1], pyramide.sommet3[2]);

    glEnd();

    glBegin( GL_QUADS );
        glVertex3f(pyramide.sommet1[0], pyramide.sommet1[1], pyramide.sommet1[2]);
        glVertex3f(pyramide.sommet2[0], pyramide.sommet2[1], pyramide.sommet2[2]);
        glVertex3f(pyramide.sommet3[0], pyramide.sommet3[1], pyramide.sommet3[2]);
        glVertex3f(pyramide.sommet4[0], pyramide.sommet4[1], pyramide.sommet4[2]);
    glEnd();
    }
    glPopMatrix();
}

GLvoid Forme::rectangleSelection(float x1, float y1, float x2, float y2){

	glPushMatrix();{
		//Haut
 	glBegin( GL_QUADS );
	 	glVertex3f(x1, y1, 0);
		glVertex3f(x1, y1+0.2, 0);
		glVertex3f(x2, y1+0.2, 0);
        glVertex3f(x2, y1, 0);   
    glEnd();
		//Bas
	glBegin( GL_QUADS );
		glVertex3f(x1, y2, 0);
		glVertex3f(x2, y2, 0);
		glVertex3f(x2, y2-0.2, 0);
		glVertex3f(x1, y2-0.2, 0);   
    glEnd();
		//Gauche
	glBegin( GL_QUADS );
		glVertex3f(x1, y1, 0);
		glVertex3f(x1, y2, 0);
		glVertex3f(x1+0.2, y2, 0);
		glVertex3f(x1+0.2, y1, 0);   
    glEnd();
		//Droite
	glBegin( GL_QUADS );
		glVertex3f(x2-0.2, y2, 0);
		glVertex3f(x2, y2, 0);
		glVertex3f(x2, y1, 0);
		glVertex3f(x2-0.2, y1, 0);  
    glEnd();
	}glPopMatrix();
}
