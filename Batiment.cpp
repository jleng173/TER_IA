#include "Batiment.hpp"

Batiment::Batiment(float x, float y,TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille): Element(x, y){
        Texture_chateau = T_chateau;
        Texture_pierre = T_pierre;
        Texture_toit = T_toit;
        Texture_porte = T_porte;
        Texture_paille = T_paille;

}

GLvoid Batiment::barreHp(){

    float lonHp = (6/(float)hpMax)*hp-3;
    glPushMatrix();{
        glColor3f(1,0,0);
        //glRotatef(90,1.0,0.0,0.0);
 	glBegin( GL_QUADS );
	 	glVertex3f(-3, 1.5, 4);
		glVertex3f(-3, 1, 4);
		glVertex3f(3, 1, 4);
        glVertex3f(3, 1.5, 4);   
    glEnd();
    glColor3f(0,1,0);
     	glBegin( GL_QUADS );
	 	glVertex3f(-3, 1.5, 4);
		glVertex3f(-3, 1, 4);
		glVertex3f(lonHp, 1, 4);
        glVertex3f(lonHp, 1.5, 4);   
    glEnd();
    glColor3f(1,1,1);
    //creerAccessoire();
    }glPopMatrix();
}

Hitbox Batiment::getHitbox(){
    return hitbox;
}