#include "Batiment.hpp"

Batiment::Batiment(float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille): Element(x, y){
        position[0]= x;
        position[1]= y;
        Texture_chateau = T_chateau;
        Texture_pierre = T_pierre;
        Texture_toit = T_toit;
        Texture_porte = T_porte;
        Texture_paille = T_paille;
        selected = 0;
}



GLvoid Batiment::barreHp(int z) const{

    float lonHp = (6/(float)hpMax)*hp-3;
    glPushMatrix();{
        glColor3f(1,0,0);
 	glBegin( GL_QUADS );
	 	glVertex3f(-3, 1.5, z);
		glVertex3f(-3, 1, z);
		glVertex3f(3, 1, z);
        glVertex3f(3, 1.5, z);   
    glEnd();
    glColor3f(0,1,0);
     	glBegin( GL_QUADS );
	 	glVertex3f(-3, 1.5, z);
		glVertex3f(-3, 1, z);
		glVertex3f(lonHp, 1, z);
        glVertex3f(lonHp, 1.5, z);   
    glEnd();
    glColor3f(1,1,1);
    }glPopMatrix();
}

bool Batiment::isSelected(){
    return selected;
}

void Batiment::setSelected(int s){
    selected = s;
}


bool Batiment::getEnConstruction(){
    return enConstruction;
}

void Batiment::setEnConstruction(bool b){
    enConstruction=b;
}

std::string Batiment::getNom(){
    return nom;
}