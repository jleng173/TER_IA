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
}
  glPopMatrix();
}


//DECOR
GLvoid Decor::PlacementArbre(){
int i,j;
for(i=-200;i<201;i=i+20){
glPushMatrix();
  	{
	glTranslatef(5,i,-0.1);
	Arbre();
	}

  	glPopMatrix();
glPushMatrix();
  	{
	glTranslatef(-5,i,-0.1);
	Arbre();
	}
  	glPopMatrix();

		for(j=-200;j<201;j=j+20){
		if(j>8 || j<-8){
		glPushMatrix();
  		{
		glTranslatef(j,i,-0.1);
		Arbre();
		}
  		glPopMatrix();}
		}
	}
	glColor3f(1,1,1);
}