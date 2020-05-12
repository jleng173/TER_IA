#include "Carte.hpp"

Carte::Carte(){
    Decor d;
    decor = d;
    //faire une boucle parcourant tout les Decor puis appelant leur méthode generate
    decor.GenerateForet(100);
    decor.GenerateMine(10);
    tailleCarte = 250;
                
};

void Carte::solcarte(){
    glPushMatrix();{

    glRotatef(45,0.0,0.0,1.0);
        glPushMatrix();{
        
            glColor3f(0.2,0.8,0.2);
            glBegin(GL_QUADS);
                glTexCoord2f(-1.0,2.0);
                glVertex3f(-tailleCarte,tailleCarte,0);
                glTexCoord2f(2.0,2.0); 
                glVertex3f(tailleCarte,tailleCarte,0);
                glTexCoord2f(2.0,-1.0);
                glVertex3f(tailleCarte,-tailleCarte,0);
                glTexCoord2f(-1.0,-1.0);
                glVertex3f(-tailleCarte,-tailleCarte,0);
            glEnd();
            glColor3f(1,1,1);
        }glPopMatrix();

        
  	glPushMatrix();{
      decor.Mine();
      decor.Foret();
	}glPopMatrix();

    }glPopMatrix();
}

int Carte::getTailleCarte(){
    return tailleCarte;
}