#include "Carte.hpp"

Carte::Carte(){

    //std::srand (time(NULL));
    tailleCarte = 250;
    //Decor d;
   // decor = d;
    //faire une boucle parcourant tous les Decor puis appelant leur méthode generate
   // decor.GenerateForet(100);
    //decor.GenerateMine(20);

    printf("GENERATION DE LA CARTE ");
    for (int i = 2 ; i <= 10 ; i++){
        
        sleep(1);
        std::srand(time(NULL));
        xdecor =(std::rand()%(i*20*2))-i*20;
	    ydecor =(std::rand()%(i*20*2))-i*20;
        printf(".\n");
        //printf("%f %f \n",xdecor,ydecor);
        Decor * d = new Decor(xdecor,ydecor);
        d->GenerateForet(100);
        d->GenerateMine(20);
        decors.push_back(d);
    }
    printf("\n");

                
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
        
         for( int i = 0 ; i < decors.size() ; i++){
        
            glPushMatrix();{
                decors[i]->Foret();
                decors[i]->Mine();
            }glPopMatrix();
        }
        //decor.Mine();
        //decor.Foret();
	}glPopMatrix();

    }glPopMatrix();
}

int Carte::getTailleCarte(){
    return tailleCarte;
}