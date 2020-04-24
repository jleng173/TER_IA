#include "Arbaletrier.hpp"

Arbaletrier::Arbaletrier(float avn,float act,float x, float y,float angle, float vitesseMAX):Personnage(avn,act,x,y,angle,vitesseMAX){
    hp=150;
    hpMax=150;
    dmg=5;
    timeProjec = 0.0;
}

void Arbaletrier::creerAccessoire() const{

}

void Arbaletrier::tirArbalete(float x, float y){
     glPushMatrix();{
          
          float posDepart[3] = {position[0],position[1],0.0};
          float posCible[3] = {x,y,0.0};
          float sm = 10 ;
          float coordX = posCible[0]-posDepart[0];
          float coordY = posCible[1]-posDepart[1];
          float angledeTir = 0.183*( max(abs(coordX),abs(coordY)) );
          angledeTir = (angledeTir*angledeTir)/(2-( min(abs(coordX),abs(coordY)) / max(abs(coordX),abs(coordY)) ));
          float arrive[3] = {coordX,coordY,angledeTir};
          float scalaire = 1/sqrt(arrive[0]*arrive[0]+arrive[1]*arrive[1]);
          printf("         %f\n",scalaire);
          float u[3] = {arrive[0]*scalaire,arrive[1]*scalaire,arrive[2]*scalaire};
          float g[3] = {0.0,0.0,-3.4};

          
          float usmt[3];
          usmt[0] = u[0] * sm * timeProjec;
          usmt[1] = u[1] * sm * timeProjec;
          usmt[2] = u[2] * sm * timeProjec;

          float gt2[3];
          gt2[0] = g[0] * (timeProjec*timeProjec);
          gt2[1] = g[1] * (timeProjec*timeProjec);
          gt2[2] = g[2] * (timeProjec*timeProjec);

          gt2[0] /= 2.0;
          gt2[1] /= 2.0;
          gt2[2] /= 2.0;

          float pt[3];
          pt[0] = usmt[0] + gt2[0];
          pt[1] = usmt[1] + gt2[1];
          pt[2] = usmt[2] + gt2[2];

          timeProjec+=0.01;

          glTranslatef(pt[0]+posDepart[0],pt[1]+posDepart[1],pt[2]);
          glRotatef(angledeTir,u[0],u[1],u[2]);
          creerCarreau();

          if(pt[2] < -0.25)
            timeProjec = 0.0;

      printf("%f, %f, %f \n",pt[0]+posDepart[0],pt[1]+posDepart[1],pt[2]);

   }
  glPopMatrix();
}

GLvoid Arbaletrier::creerCarreau(){
    glPushMatrix();{
        glRotatef(90,1,0,0);
        //glScalef(15,15,15);

        glColor3f(0.65,0.5,0.1);
        GLUquadric* params = gluNewQuadric();
        gluCylinder(params,0.1,0.1,2,20,20);
        gluDeleteQuadric(params);

        
        glPushMatrix();{
            glColor3f(0.4,0.4,0.4);
            glRotatef(-90,0.5,0,0);
            Forme pointe;
            pointe.affichePyramide(pointe.creerPyramide(0.185));
        }glPopMatrix();

        glPushMatrix();{
            glColor3f(0.65,0.5,0.1);
            glTranslatef(0.0,0.0,2);
            GLUquadric* params = gluNewQuadric();
            gluDisk(params,0,0.1,20,20);
            gluDeleteQuadric(params);

        }glPopMatrix();

        glPushMatrix();{
            glColor3f(0.65,0.2,0.0);
            glBegin(GL_TRIANGLES);
                glVertex3f(0.1, 0.0, 1.2);
                glVertex3f(0.25, 0.0, 1.65);
                glVertex3f(0.1, 0.0, 1.9);
            glEnd();
        }glPopMatrix();

        glPushMatrix();{
            glBegin(GL_TRIANGLES);
                glVertex3f(-0.1, 0.0, 1.2);
                glVertex3f(-0.25, 0.0, 1.65);
                glVertex3f(-0.1, 0.0, 1.9);
            glEnd();
        }glPopMatrix();
        glColor3f(1.0,1.0,1.0);
    }glPopMatrix();
}

GLvoid Arbaletrier::creerChapeau() const{
    glPushMatrix();{
        glColor3f(0.7,0.7,0);
        // glScalef(0.8,0,0);
        // Personnage::drawHalfSphere(100,100,1);
        GLUquadric* params = gluNewQuadric();
        gluQuadricTexture(params, GL_TRUE);
        glRotatef(90,1,0,0);
        gluDisk(params,0,1,20,1);
        gluDeleteQuadric(params);
    }
    glPopMatrix();
}