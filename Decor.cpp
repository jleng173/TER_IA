#include "Decor.hpp"

Decor::Decor(){};




//ARBRE
GLvoid Decor::Arbre(){
glPushMatrix();
  	{
	//glTranslatef(3,-0.8,-3);
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
	glColor3f(1,1,1);
}
  glPopMatrix();
}


void Decor::Foret(){
	//glScalef(0.5,0.5,0.5);
	glPushMatrix();{
		for(int i = 0 ; i <_foret.size() ; i++){
			glTranslatef( _foret[i][0], _foret[i][1], _foret[i][2]);
			Arbre();
		}

    }glPopMatrix();
}


void Decor::GenerateForet(int nombre){
	std::srand (time(NULL));
		for (int i = 0 ; i < nombre ; i++){
			float x =(float) (std::rand()%1000-500)/100 ;
			float y = (float) (std::rand()%1000-500)/100;
			//printf("%f %f \n",x,y);
			std::vector<float>  add = {x,y, 0.0};
			_foret.push_back(add);
		}
}