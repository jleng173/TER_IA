#include "InterfaceHUD.hpp"

InterfaceHUD::InterfaceHUD(TEXTURE_STRUCT * T_HUD, TEXTURE_STRUCT * T_HUD2, TEXTURE_STRUCT * T_Pierre, TEXTURE_STRUCT * T_Img_Guerrier,TEXTURE_STRUCT * T_Img_Paysan, TEXTURE_STRUCT * T_Img_Arbaletrier, TEXTURE_STRUCT * T_Img_Or, TEXTURE_STRUCT * T_Img_Pierre,TEXTURE_STRUCT * T_Img_Nourriture, TEXTURE_STRUCT * T_Img_Bois, TEXTURE_STRUCT * T_Img_Mouvement, TEXTURE_STRUCT * T_Img_Stop, TEXTURE_STRUCT * T_Img_Attaquer, TEXTURE_STRUCT * T_Img_Construire):
Texture_HUD(T_HUD),
Texture_HUD2(T_HUD2),
Texture_Pierre(T_Pierre),
Texture_Img_Guerrier(T_Img_Guerrier),
Texture_Img_Paysan(T_Img_Paysan),
Texture_Img_Arbaletrier(T_Img_Arbaletrier),
Texture_Img_Or(T_Img_Or),
Texture_Img_Pierre(T_Img_Pierre),
Texture_Img_Nourriture(T_Img_Nourriture),
Texture_Img_Bois(T_Img_Bois),
Texture_Img_Mouvement(T_Img_Mouvement),
Texture_Img_Stop(T_Img_Stop),
Texture_Img_Attaquer(T_Img_Attaquer),
Texture_Img_Construire(T_Img_Construire){

}

GLvoid InterfaceHUD::creerInterfaceHUD(std::vector<Personnage *> p, std::vector<Batiment *> b,Joueur * j){

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();{
      glLoadIdentity();
      glOrtho(0.0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT, 0.0, -1.0, 10.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glDisable(GL_DEPTH_TEST);

      glClear(GL_DEPTH_BUFFER_BIT);

      //Interface du haut
        //1er bloc
      glBegin(GL_QUADS);
          glColor3f(0.5f, 0.5f, 0.5f);
          glVertex2f(0.0, 0.0);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 0.0);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 10.0);
          glVertex2f(0.0, 10.0);
      glEnd();

        //2e bloc
      glEnable(GL_TEXTURE_2D);	
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_HUD->width, Texture_HUD->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_HUD->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 0.0f);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 0.0);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH, 0.0);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH, 10.0);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 10.0);
      glEnd();
      glDisable(GL_TEXTURE_2D);

        //Info ressources
      glBegin(GL_QUADS);
          glColor3f(0.0f, 0.0f, 0.0f);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+11, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+21, 2.5);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+21, 8.0);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+11, 8.0);
      glEnd();
      std::string infoOr="      " + std::to_string(j->getOr());
      drawText(infoOr,infoOr.size(),GLUT_SCREEN_WIDTH/2+12,7);

      glEnable(GL_TEXTURE_2D);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Or->width, Texture_Img_Or->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Or->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+11, 2.5);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+16, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+16, 8.0);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+11, 8.0);
      glEnd();
      glDisable(GL_TEXTURE_2D);

      glBegin(GL_QUADS);
          glColor3f(0.0f, 0.0f, 0.0f);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+23, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+33, 2.5);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+33, 8.0);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+23, 8.0);
      glEnd();
      std::string infoBois="      " + std::to_string(j->getBois());
      drawText(infoBois,infoBois.size(),GLUT_SCREEN_WIDTH/2+24,7);

      glEnable(GL_TEXTURE_2D);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Bois->width, Texture_Img_Bois->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Bois->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+23, 2.5);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+28, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+28, 8.0);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+23, 8.0);
      glEnd();
      glDisable(GL_TEXTURE_2D);

      glBegin(GL_QUADS);
          glColor3f(0.0f, 0.0f, 0.0f);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+35, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+46, 2.5);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+46, 8.0);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+35, 8.0);
      glEnd();
      std::string infoPierre="       " + std::to_string(j->getPierre());
      drawText(infoPierre,infoPierre.size(),GLUT_SCREEN_WIDTH/2+36,7);

      glEnable(GL_TEXTURE_2D);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Pierre->width, Texture_Img_Pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Pierre->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+35, 2.5);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+40, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+40, 8.0);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+35, 8.0);
      glEnd();
      glDisable(GL_TEXTURE_2D);

      glBegin(GL_QUADS);
          glColor3f(0.0f, 0.0f, 0.0f);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+48, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+61, 2.5);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+61, 8.0);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+48, 8.0);
      glEnd();
      std::string infoUnite="       " + std::to_string(j->getUnites().size())+ "/" + std::to_string(j->getMaxUnites());
      drawText(infoUnite,infoUnite.size(),GLUT_SCREEN_WIDTH/2+49,7);

      glEnable(GL_TEXTURE_2D);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Nourriture->width, Texture_Img_Nourriture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Nourriture->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+48, 2.5);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/2+53, 2.5);
          glTexCoord2f(0,1);          
          glVertex2f(GLUT_SCREEN_WIDTH/2+53, 8.0);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/2+48, 8.0);
      glEnd();
      glDisable(GL_TEXTURE_2D);

      //Interface du bas
        //1er bloc
      glEnable(GL_TEXTURE_2D);	
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_HUD2->width, Texture_HUD2->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_HUD2->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(0,0);
          glVertex2f(0.0, GLUT_SCREEN_HEIGHT);
          glTexCoord2f(0,1);
          glVertex2f(0.0, GLUT_SCREEN_HEIGHT-50.0);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-50.0);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
      glEnd();
      glDisable(GL_TEXTURE_2D);

      glBegin(GL_QUADS);
          glColor3f(0.0f, 1.0f, 1.0f);
          glVertex2f(0+5, GLUT_SCREEN_HEIGHT-10);
          glVertex2f(0+5, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3-5, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3-5, GLUT_SCREEN_HEIGHT-10);
      glEnd();

        //2e bloc
      glEnable(GL_TEXTURE_2D);	
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_HUD->width, Texture_HUD->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_HUD->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
          glTexCoord2f(0,1);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-40.0);
          glTexCoord2f(1,1);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-40.0);
          glTexCoord2f(1,0);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
      glEnd();
      glDisable(GL_TEXTURE_2D);
      glEnable(GL_TEXTURE_2D);	
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Pierre->width, Texture_Pierre->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Pierre->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(0,0);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-40);
          glTexCoord2f(0,0.5);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-50.0);
          glTexCoord2f(1,0.5);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-50.0);
          glTexCoord2f(1,0);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-40);
      glEnd();
      glDisable(GL_TEXTURE_2D);
            //Portrait
      glBegin(GL_POLYGON);
          glColor3f(1.0f, 0.0f, 1.0f);
          glVertex2f(GLUT_SCREEN_WIDTH/3+7.5, GLUT_SCREEN_HEIGHT-5);
          glVertex2f(GLUT_SCREEN_WIDTH/3+7.5, GLUT_SCREEN_HEIGHT-30.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+10, GLUT_SCREEN_HEIGHT-35.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+14, GLUT_SCREEN_HEIGHT-35.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+16.5, GLUT_SCREEN_HEIGHT-30.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+16.5, GLUT_SCREEN_HEIGHT-5);
      glEnd();
            //Information personnage
      glBegin(GL_POLYGON);
          glColor3f(0.0f, 0.0f, 0.0f);
          glVertex2f(GLUT_SCREEN_WIDTH/3+17.5, GLUT_SCREEN_HEIGHT-5);
          glVertex2f(GLUT_SCREEN_WIDTH/3+17.5, GLUT_SCREEN_HEIGHT-30.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+20, GLUT_SCREEN_HEIGHT-35.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+57.5, GLUT_SCREEN_HEIGHT-35.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+60, GLUT_SCREEN_HEIGHT-30.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+60, GLUT_SCREEN_HEIGHT-5);
      glEnd();

      //Bloc Action Personnage
      glEnable(GL_TEXTURE_2D);	
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_HUD2->width, Texture_HUD2->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_HUD2->data);
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(0,0);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
          glTexCoord2f(0,1);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-50.0);
          glTexCoord2f(1,1);
          glVertex2f(GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT-50.0);
          glTexCoord2f(1,0);
          glVertex2f(GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
      glEnd();
      glDisable(GL_TEXTURE_2D);

      
      drawUnitInformation(p,b);
        //3e bloc


            //Cases
      

      // END 2D
      glMatrixMode(GL_PROJECTION);
    }
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    std::string Title = "COMMAND & CONQUER TOTAL WAR-CRAFT: AGE OF EMPIRE";
    drawText(Title,Title.size(),5,6);

}

void InterfaceHUD::drawText(std::string text, int length, int x, int y){
  glMatrixMode(GL_PROJECTION);
  double *matrix = new double[16];
  glGetDoublev(GL_PROJECTION_MATRIX, matrix);
  glLoadIdentity();
  glOrtho(0.0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT, 0.0, -1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();{
    glColor3f(1,1,1);
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0;i<length;i++){
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
    }
  }
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixd(matrix);
  glMatrixMode(GL_MODELVIEW);
}

GLvoid InterfaceHUD::drawIconCharacter(){
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0,0);
    glVertex2f(GLUT_SCREEN_WIDTH/3+20, GLUT_SCREEN_HEIGHT-32.5);
    glTexCoord2f(0,1);
    glVertex2f(GLUT_SCREEN_WIDTH/3+20, GLUT_SCREEN_HEIGHT-25.0);
    glTexCoord2f(1,1);
    glVertex2f(GLUT_SCREEN_WIDTH/3+25, GLUT_SCREEN_HEIGHT-25.0);
    glTexCoord2f(1,0);
    glVertex2f(GLUT_SCREEN_WIDTH/3+25, GLUT_SCREEN_HEIGHT-32.5);
    glEnd();
}

// Si bool est à true, affiche l'icone construire
GLvoid InterfaceHUD::drawIconAction(bool paysan){

      glPushMatrix();{
        glEnable(GL_TEXTURE_2D);	
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Mouvement->width, Texture_Img_Mouvement->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Mouvement->data);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0,0.75);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-32);
            glTexCoord2f(0,0.25);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-42.0);
            glTexCoord2f(1,0.25);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-42.0);
            glTexCoord2f(1,0.75);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-32);
        glEnd();
        glDisable(GL_TEXTURE_2D);
      }
      glPopMatrix();

      glPushMatrix();{
        glTranslatef(20,0,0);
        glEnable(GL_TEXTURE_2D);	
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Stop->width, Texture_Img_Stop->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Stop->data);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0,1);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-32);
            glTexCoord2f(0,0);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-42.0);
            glTexCoord2f(1,0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-42.0);
            glTexCoord2f(1,1);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-32);
        glEnd();
        glDisable(GL_TEXTURE_2D);
      }
      glPopMatrix();

      glPushMatrix();{
        glTranslatef(40,0,0);
        glEnable(GL_TEXTURE_2D);	
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Attaquer->width, Texture_Img_Attaquer->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Attaquer->data);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glTexCoord2f(0,0.75);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-32);
            glTexCoord2f(0,0.25);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-42.0);
            glTexCoord2f(1,0.25);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-42.0);
            glTexCoord2f(1,0.75);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-32);
        glEnd();
        glDisable(GL_TEXTURE_2D);
      }
      glPopMatrix();

            //2e rangée
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(0,1);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-20);
          glTexCoord2f(0,0);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-30.0);
          glTexCoord2f(1,0);
          glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-30.0);
          glTexCoord2f(1,1);
          glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-20);
      glEnd(); 

      glPushMatrix();{
        glTranslatef(20,0,0);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-20);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-30.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-30.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-20);
        glEnd();
      }
      glPopMatrix();

      glPushMatrix();{
        glTranslatef(40,0,0);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 1.0f);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-20);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-30.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-30.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-20);
        glEnd();
      }
      glPopMatrix();

            //3e rangée
      if(paysan){
        glEnable(GL_TEXTURE_2D);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Construire->width, Texture_Img_Construire->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Construire->data);
      }
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 1.0f);
          glTexCoord2f(0,1);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-8);
          glTexCoord2f(0,0);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-18.0);
          glTexCoord2f(1,0);
          glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-18.0);
          glTexCoord2f(1,1);
          glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-8);
      glEnd();
      if(paysan)
        glDisable(GL_TEXTURE_2D);


      glPushMatrix();{
        glTranslatef(20,0,0);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-8);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-18.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-18.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-8);
        glEnd();
      }
      glPopMatrix();

      glPushMatrix();{
        glTranslatef(40,0,0);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 1.0f);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-8);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-18.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-18.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-8);
        glEnd();
      }
      glPopMatrix();
}

void InterfaceHUD::drawUnitInformation(std::vector<Personnage *> p, std::vector<Batiment *> b){
      float translate=0;
      int nbG = 0;
      int nbA = 0;
      int nbP = 0;
      std::vector<int> nbPerso;
      nbPerso.clear();
      bool g,a,paysan;
      g=false;
      a=false;
      paysan=false;
      if(p.size()==1){
        std::string infoNom=p[0]->getNom();
        drawText(infoNom,infoNom.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-30);
        std::string infoHP="HP: " + std::to_string(p[0]->getHp()) + "/" + std::to_string(p[0]->getHpMax());
        drawText(infoHP,infoHP.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-25);
        std::string infoDmg="Damages: " + std::to_string(p[0]->getDmg());
        drawText(infoDmg,infoDmg.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-20);
        if(p[0]->getNom()=="Paysan")
        {
          drawIconAction(true);
        }
        else
        {
          drawIconAction(false);
        }
      }
      if(p.size()>1){
          drawIconAction(false);
          for(int i=0;i<p.size();i++){
            glPushMatrix();{
              glTranslatef(translate,0,0);
              glEnable(GL_TEXTURE_2D);	
              // std::cout << p[i]->getNom() << std::endl ;
              if(p[i]->getNom()=="Guerrier"){
                if(g==false){
                  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Guerrier->width, Texture_Img_Guerrier->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Guerrier->data);
                  drawIconCharacter();
                  translate+=6;
                }
                g=true;
                nbG++;
              }
              if(p[i]->getNom()=="Arbaletrier"){
                if(a==false){
                  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Arbaletrier->width, Texture_Img_Arbaletrier->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Arbaletrier->data);
                  drawIconCharacter();
                  translate+=6;
                }
                a=true;
                nbA++;
              }
              if(p[i]->getNom()=="Paysan"){
                if(paysan == false){
                  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Paysan->width, Texture_Img_Paysan->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Paysan->data);
                  drawIconCharacter();
                  translate+=6;
                }
                paysan=true;
                nbP++;
              }
              glDisable(GL_TEXTURE_2D);
            }
            glPopMatrix();
          }
          if(nbP!=0)
            nbPerso.push_back(nbP);  
          if(nbG!=0)
            nbPerso.push_back(nbG);
          if(nbA!=0)
            nbPerso.push_back(nbA);
          for(int i=0;i<nbPerso.size();i++)
          {
            std::string texte = std::to_string(nbPerso[i]);
            drawText(texte,texte.size(),GLUT_SCREEN_WIDTH/3+20+i*6, GLUT_SCREEN_HEIGHT-32.5);
          }

      }

      if(b.size()==1 && p.size()<=0){
        std::string infoBatiment=b[0]->getNom();
        drawText(infoBatiment,infoBatiment.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-30);
        std::string infoHP="HP: " + std::to_string(b[0]->getHp()) + "/" + std::to_string(b[0]->getHpMax());
        drawText(infoHP,infoHP.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-25);
        if(b[0]->getNom()=="Tour"){
          std::string infoDmg="Damages: " + std::to_string(dynamic_cast<Tour *>(b[0])->getDmg());
          drawText(infoDmg,infoDmg.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-20);
        }
        drawIconAction(false);
      }

      if(b.size()>1 && p.size()<=0){
          // drawIconAction(false);
          // for(int i=0;i<b.size();i++){
          //   glPushMatrix();{
          //     glTranslatef(translate,0,0);
          //     glEnable(GL_TEXTURE_2D);	
          //     // std::cout << p[i]->getNom() << std::endl ;
          //     if(p[i]->getNom()=="Guerrier"){
          //       if(g==false){
          //         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Guerrier->width, Texture_Img_Guerrier->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Guerrier->data);
          //         drawIconCharacter();
          //         translate+=6;
          //       }
          //       g=true;
          //       nbG++;
          //     }
          //     if(p[i]->getNom()=="Arbaletrier"){
          //       if(a==false){
          //         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Arbaletrier->width, Texture_Img_Arbaletrier->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Arbaletrier->data);
          //         drawIconCharacter();
          //         translate+=6;
          //       }
          //       a=true;
          //       nbA++;
          //     }
          //     if(p[i]->getNom()=="Paysan"){
          //       if(paysan == false){
          //         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Texture_Img_Paysan->width, Texture_Img_Paysan->height, 0, GL_RGB, GL_UNSIGNED_BYTE, Texture_Img_Paysan->data);
          //         drawIconCharacter();
          //         translate+=6;
          //       }
          //       paysan=true;
          //       nbP++;
          //     }
          //     glDisable(GL_TEXTURE_2D);
          //   }
          //   glPopMatrix();
          // }
          // if(nbP!=0)
          //   nbPerso.push_back(nbP);  
          // if(nbG!=0)
          //   nbPerso.push_back(nbG);
          // if(nbA!=0)
          //   nbPerso.push_back(nbA);
          // for(int i=0;i<nbPerso.size();i++)
          // {
          //   std::string texte = std::to_string(nbPerso[i]);
          //   drawText(texte,texte.size(),GLUT_SCREEN_WIDTH/3+20+i*6, GLUT_SCREEN_HEIGHT-32.5);
          // }

      }     
}