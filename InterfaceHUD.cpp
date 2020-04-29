#include "InterfaceHUD.hpp"

InterfaceHUD::InterfaceHUD(TEXTURE_STRUCT * T_HUD, TEXTURE_STRUCT * T_HUD2):Texture_HUD(T_HUD), Texture_HUD2(T_HUD2){

}

GLvoid InterfaceHUD::creerInterfaceHUD(Personnage & p){

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();{
      glLoadIdentity();
      glOrtho(0.0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT, 0.0, -1.0, 10.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glDisable(GL_DEPTH_TEST);

      glClear(GL_DEPTH_BUFFER_BIT);

      glBegin(GL_QUADS);
          glColor3f(0.5f, 0.5f, 0.5f);
          glVertex2f(0.0, 0.0);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 0.0);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 10.0);
          glVertex2f(0.0, 10.0);
      glEnd();

      glBegin(GL_QUADS);
          glColor3f(0.0f, 0.0f, 0.0f);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 0.0);
          glVertex2f(GLUT_SCREEN_WIDTH, 0.0);
          glVertex2f(GLUT_SCREEN_WIDTH, 10.0);
          glVertex2f(GLUT_SCREEN_WIDTH/2, 10.0);
      glEnd();

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
            //Portrait
      glBegin(GL_POLYGON);
          glColor3f(1.0f, 0.0f, 1.0f);
          glVertex2f(GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-5);
          glVertex2f(GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-30.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+7.5, GLUT_SCREEN_HEIGHT-35.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+12.5, GLUT_SCREEN_HEIGHT-35.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+15, GLUT_SCREEN_HEIGHT-30.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3+15, GLUT_SCREEN_HEIGHT-5);
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

      std::string infoHP="HP: " + std::to_string(p.getHp()) + "/" + std::to_string(p.getHpMax());
      drawText(infoHP,infoHP.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-30);
      std::string infoDmg="Damages: " + std::to_string(p.getDmg());
      drawText(infoDmg,infoDmg.size(),GLUT_SCREEN_WIDTH/3+20,GLUT_SCREEN_HEIGHT-25);

        //3e bloc
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

            //Cases
      glBegin(GL_QUADS);
          glColor3f(0.0f, 1.0f, 1.0f);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-30);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-30);
      glEnd();

      glPushMatrix();{
        glTranslatef(20,0,0);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-30);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-40.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-40.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-30);
        glEnd();
      }
      glPopMatrix();

      glPushMatrix();{
        glTranslatef(40,0,0);
        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 1.0f);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-30);
            glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-40.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-40.0);
            glVertex2f((2*GLUT_SCREEN_WIDTH/3+5)+(GLUT_SCREEN_WIDTH/12), GLUT_SCREEN_HEIGHT-30);
        glEnd();
      }
      glPopMatrix();


      // END 2D
      glMatrixMode(GL_PROJECTION);
    }
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    std::string texte=std::to_string(p.getHp());
    drawText(texte,texte.size(),1,3);

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