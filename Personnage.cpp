#include "Personnage.hpp"
#include "Forme.hpp"

Personnage::Personnage(float a){
    avance=a;
}

GLvoid Personnage::creerPersonnage()
{
    Forme f;
    struct cube1 membre = f.creerCube(1.5);
	glPushMatrix();{
	    glColor3f(0.1,0.1,0.1);
	    glutSolidSphere(0.5,10,100);
	}
    glPopMatrix();
    //Corps
    glPushMatrix();{
        glTranslatef(0,-1.5,0);
	    glColor3f(0.1,0.1,0.1);
        glScalef(0.3,0.7,0.2);
	    f.afficheCube(membre);
	}
	glPopMatrix();
    //Bras gauche   (epaule jusqu'au bas)
        //1er Articulation
    glPushMatrix();{
        glRotatef(avance,1,0,0);
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(0.6,-0.8,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(0.7,-1.2,0);
            glColor3f(0,0,1);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
            //2e Articulation
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(0.7,-1.6,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(0.7,-2,0);
            glColor3f(1,0,0);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
            //Main Gauche
        glPushMatrix();{
            glColor3f(0,1,0);
            glTranslatef(0.7,-2.4,0);
            glutSolidSphere(0.15,10,100);
        }
        glPopMatrix();
    }
    glPopMatrix();
    //Bras droit
        //Articulation
    glPushMatrix();{
        glRotatef(-avance,1,0,0);
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(-0.6,-0.8,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(-0.7,-1.2,0);
            glColor3f(0,0,1);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
            //Articulation    
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(-0.7,-1.6,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(-0.7,-2,0);
            glColor3f(1,0,0);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0,1,0);
            glTranslatef(-0.7,-2.4,0);
            glutSolidSphere(0.15,10,100);
        }
        glPopMatrix();
    }
    glPopMatrix();




    //Jambe gauche   (cuisse jusqu'au pied)
        //Articulation
    glPushMatrix();{
        glTranslatef(-0.25,-1.8,0);
        glRotatef(-avance,1,0,0);
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(0.6,-0.8,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(0.7,-1.2,0);
            glColor3f(0,0,1);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
            //Articulation
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(0.7,-1.6,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(0.7,-2,0);
            glColor3f(1,0,0);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0,1,0);
            glTranslatef(0.7,-2.4,0);
            glutSolidSphere(0.15,10,100);
        }
        glPopMatrix();
    }
    glPopMatrix();
    //Jambe droit
        //Articulation
    glPushMatrix();{
        glTranslatef(0.25,-1.8,0);
        glRotatef(avance,1,0,0);
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(-0.6,-0.8,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(-0.7,-1.2,0);
            glColor3f(0,0,1);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
            //Articulation    
        glPushMatrix();{
            glColor3f(0,1,1);
            glTranslatef(-0.7,-1.6,0);
            glutSolidSphere(0.2,10,100);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(-0.7,-2,0);
            glColor3f(1,0,0);
            glScalef(0.1,0.2,0.1);
            f.afficheCube(membre);
        }
        glPopMatrix();
        glPushMatrix();{
            glColor3f(0,1,0);
            glTranslatef(-0.7,-2.4,0);
            glutSolidSphere(0.15,10,100);
        }
        glPopMatrix();
    }
    glPopMatrix();
}