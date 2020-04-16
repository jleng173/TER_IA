struct pyramide1 {
	float sommet5[3];
	float sommet4[3];
	float sommet3[3];
	float sommet2[3];
	float sommet1[3];
};

struct pyramide1 creer_pyramide1(float taille){
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

GLvoid affiche_pyramide(struct pyramide1 pyramide)
{
    glPushMatrix();
	{
    glBegin( GL_TRIANGLES );
        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f );
        glVertex3f( pyramide.sommet4[0], pyramide.sommet4[1], pyramide.sommet4[2] );
        glVertex3f( pyramide.sommet1[0], pyramide.sommet1[1], pyramide.sommet1[2]);

        glVertex3f( pyramide.sommet3[0], pyramide.sommet3[1], pyramide.sommet3[2]);
        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f);
        glVertex3f( pyramide.sommet4[0], pyramide.sommet4[1], pyramide.sommet4[2]);

        glVertex3f( pyramide.sommet2[0], pyramide.sommet2[1], pyramide.sommet2[2]);
        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f);
        glVertex3f( pyramide.sommet1[0], pyramide.sommet1[1], pyramide.sommet1[2]);

        glVertex3f( 0.0f, pyramide.sommet5[1], 0.0f);
        glVertex3f( pyramide.sommet2[0], pyramide.sommet2[1], pyramide.sommet2[2]);
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
