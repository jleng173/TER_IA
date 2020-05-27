#include "Decor.hpp"

Decor::Decor(float dx, float dy){
	positionDecorX = dx;
	positionDecorY = dy;
};

//ARBRE
GLvoid Decor::Arbre(){
glPushMatrix();
  	{
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

GLvoid Decor::Roche(){
	glPushMatrix();{
		glRotatef(90,1,0,0);
		glTranslatef(0,0,1.25);
		
			glPushMatrix();{

				//Face avant
				glColor3f(0.7,0.7,0.6);
				glBegin(GL_POLYGON);
					glVertex3f(-1,0,0.5);
					glVertex3f(-1,1,0.3);
					glVertex3f(-0.5,1.5,0);
					glVertex3f(0.5,1.5,-0.2);
					glVertex3f(1,1,0);
					glVertex3f(1,0,0.3);
				glEnd();

				//Face arriere
				glBegin(GL_POLYGON);
					glVertex3f(-1,0,-1);
					glVertex3f(-1,0.5,-0.8);
					glVertex3f(-0.5,0.75,-0.9);
					glVertex3f(0.5,0.75,-0.9);
					glVertex3f(1,0.5,-1.2);
					glVertex3f(1,0,-1.4);
				glEnd();

				//Cotés
				glBegin(GL_QUADS);
					glVertex3f(-1,0,0.5);
					glVertex3f(-1,1,0.3);
					glVertex3f(-1.6,1.2,-0.3);
					glVertex3f(-1.9,0,-0.5);

					glVertex3f(-1,0,-1);
					glVertex3f(-1,0.5,-0.8);
					glVertex3f(-1.6,1.2,-0.3);
					glVertex3f(-1.9,0,-0.5);

					glVertex3f(1,0,0.3);
					glVertex3f(1,1,0);
					glVertex3f(1.5,1.2,-0.3);
					glVertex3f(1.8,0,-0.5);

					glVertex3f(1.5,1.2,-0.3);
					glVertex3f(1,0.5,-1.2);
					glVertex3f(1,0,-1.4);
					glVertex3f(1.8,0,-0.5);
				glEnd();

				//Dessus
				glColor3f(1,0.8,0.3);
				glBegin(GL_POLYGON);
					glVertex3f(-1,1,0.3);
					glVertex3f(-0.5,1.5,0);
					glVertex3f(-0.5,0.75,-0.9);
					glVertex3f(-1,0.5,-0.8);
					glVertex3f(-1.6,1.2,-0.3);
				glEnd();
				glColor3f(0.7,0.7,0.7);
				glBegin(GL_QUADS);
					glVertex3f(-0.5,1.5,0);
					glVertex3f(0.5,1.5,-0.2);
					glVertex3f(0.5,0.75,-0.9);
					glVertex3f(-0.5,0.75,-0.9);

					glVertex3f(0.5,1.5,-0.2);
					glVertex3f(1,1,0);
					glVertex3f(1,0.5,-1.2);
					glVertex3f(0.5,0.75,-0.9);
				glEnd();
				glColor3f(1,0.8,0.3);
				glBegin(GL_TRIANGLES);
					glVertex3f(1,1,0);
					glVertex3f(1.5,1.2,-0.3);
					glVertex3f(1,0.5,-1.2);
				glEnd();
			}
			glPopMatrix();
	}glPopMatrix();	
}


void Decor::Foret(){
	glPushMatrix();{
		glPushMatrix();{
			for(int i = 0 ; i <_foret.size() ; i++){
				glPushMatrix();{
					glTranslatef( _foret[i][0], _foret[i][1], 0.0);
					Arbre();
				}glPopMatrix();
			}

		}glPopMatrix();
	}glPopMatrix();
}

void Decor::Mine(){
	glPushMatrix();{
		glPushMatrix();{
			for(int i = 0 ; i <_mine.size() ; i++){
				glPushMatrix();{
					glTranslatef( _mine[i][0], _mine[i][1],0.0);
					Roche();
				}glPopMatrix();
			}
		}
		glPopMatrix();
	}glPopMatrix();
}

void Decor::GenerateForet(int nombre){
	std::srand (time(NULL));
		for (int i = 0 ; i < nombre ; i++){
			float x =(float) (std::rand()%50-25) ;
			float y = (float) (std::rand()%50-25);
			//vector avec coordonées de l'arbre et sa résistance
			std::vector<float>  add = {x+positionDecorX,y+positionDecorY,150.0};
			_foret.push_back(add);
		}
}

void Decor::GenerateMine(int nombre){
	std::srand(time(NULL));
		for (int i = 0 ; i < nombre ; i++){
			float x =(float) (std::rand()%10-5) ;
			float y = (float) (std::rand()%10-5);
			//vector avec coordonées du rocher et sa résistance
			std::vector<float>  add = {x+positionDecorX,y+positionDecorY,300.0};
			_mine.push_back(add);
		}
}

std::vector< std::vector<float> > Decor::getForet(){
	return _foret;
}

std::vector< std::vector<float> > Decor::getMine(){
	return _mine;
}

float Decor::getpositionDecorX(){
	return positionDecorX;
}

float Decor::getpositionDecorY(){
	return positionDecorY;
}

void Decor::deleteArbre(int id){
	_foret.erase(_foret.begin()+id);

}

void Decor::deleteRoche(int id){
	_mine.erase(_mine.begin()+id);
}

void Decor::degatArbre(int id, float degat){
	_foret[id][2] -= degat;
}

void Decor::degatRoche(int id, float degat){
	_mine[id][2] -= degat;
}