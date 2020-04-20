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


	

//ARBRE
GLvoid Carte::Arbre(){
glPushMatrix();
  	{
	//glTranslatef(3,-0.8,-3);
	//glRotatef(-90,1,0,0);
		glPushMatrix();
  	{
	glColor3f(0.5,0.3,0.2);
	GLUquadric* qobj;
	qobj = gluNewQuadric();
	gluCylinder(qobj, 0.3, 0.3, 3.2, 10, 16);
	}
  	glPopMatrix();
	glTranslatef(0,0,3);
	glPushMatrix();
  	{
	glColor3f(0,0.3,0);
	GLUquadric* quad;
	quad = gluNewQuadric();
	gluSphere(quad,1,20,20);
	}
  	glPopMatrix();
}
  glPopMatrix();
}


//DECOR
GLvoid Carte::Decor(){
 glPushMatrix();{
int i,j;
for(i=-200;i<201;i=i+20){
glPushMatrix();
  	{
	glTranslatef(5,i,-0.8);
	Arbre();
	}

  	glPopMatrix();
glPushMatrix();
  	{
	glTranslatef(-5,i,-0.8);
	Arbre();
	}
  	glPopMatrix();

		for(j=-200;j<201;j=j+20){
		if(j>8 || j<-8){
		glPushMatrix();
  		{
		glTranslatef(j,i,-0.8);
		Arbre();
		}
  		glPopMatrix();}
		}
	}

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
