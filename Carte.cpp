#include "Carte.hpp"

Carte::Carte(){};
Carte::Carte(bool foret){
	GenerateForet();
};

void Carte::solcarte(){
    glPushMatrix();{

    glRotatef(45,0.0,0.0,1.0);
        glPushMatrix();{
        
            glColor3f(0.2,0.8,0.2);
            glBegin(GL_QUADS);
                glTexCoord2f(-1.0,2.0);
                glVertex3f(-250,250,0);
                glTexCoord2f(2.0,2.0); 
                glVertex3f(250,250,0);
                glTexCoord2f(2.0,-1.0);
                glVertex3f(250,-250,0);
                glTexCoord2f(-1.0,-1.0);
                glVertex3f(-250,-250,0);
            glEnd();
            glColor3f(1,1,1);
        }glPopMatrix();
    }glPopMatrix();
}


void Carte::Foret(){
	//glScalef(0.5,0.5,0.5);
	glPushMatrix();{
		for(int i = 0 ; i <_foret.size() ; i++){
			glTranslatef( _foret[i][0], _foret[i][1], _foret[i][2]);
			Arbre();
		}

    }glPopMatrix();
}


void Carte::GenerateForet(){
	std::srand (time(NULL));
		for (int i = 0 ; i < 100 ; i++){
			float x =(float) (std::rand()%1000-500)/100 ;
			float y = (float) (std::rand()%1000-500)/100;
			//printf("%f %f \n",x,y);
			std::vector<float>  add = {x,y, 0.0};
			_foret.push_back(add);
		}
}
