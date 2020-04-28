#include "InterfaceHUD.hpp"

InterfaceHUD::InterfaceHUD(){

}

GLvoid InterfaceHUD::creerInterfaceHUD(){

        glMatrixMode(GL_PROJECTION);
    glPushMatrix();{
      glLoadIdentity();
      glOrtho(0.0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT, 0.0, -1.0, 10.0);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glDisable(GL_DEPTH_TEST);

      glClear(GL_DEPTH_BUFFER_BIT);

      glBegin(GL_POLYGON);
          glColor3f(0.5f, 0.5f, 0.5f);
          glVertex2f(0.0, 0.0);
          glVertex2f(100, 0.0);
          glVertex2f(100, 10.0);
          glVertex2f(0.0, 10.0);
      glEnd();

      glBegin(GL_POLYGON);
          glColor3f(0.0f, 0.0f, 0.0f);
          glVertex2f(100.0, 0.0);
          glVertex2f(200, 0.0);
          glVertex2f(200, 10.0);
          glVertex2f(100.0, 10.0);
      glEnd();

      //Interface du bas
        //1er bloc
      glBegin(GL_QUADS);
          glColor3f(1.0f, 0.0f, 0.0f);
          glVertex2f(0.0, GLUT_SCREEN_HEIGHT);
          glVertex2f(0.0, GLUT_SCREEN_HEIGHT-50.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-50.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
      glEnd();

      glBegin(GL_QUADS);
          glColor3f(0.0f, 1.0f, 1.0f);
          glVertex2f(0+5, GLUT_SCREEN_HEIGHT-10);
          glVertex2f(0+5, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3-5, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(GLUT_SCREEN_WIDTH/3-5, GLUT_SCREEN_HEIGHT-10);
      glEnd();

        //2e bloc
      glBegin(GL_QUADS);
          glColor3f(0.0f, 0.0f, 1.0f);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
          glVertex2f(GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
      glEnd();
      
        //3e bloc
      glBegin(GL_QUADS);
          glColor3f(1.0f, 1.0f, 0.0f);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3, GLUT_SCREEN_HEIGHT-50.0);
          glVertex2f(GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT-50.0);
          glVertex2f(GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
      glEnd();

      glBegin(GL_QUADS);
          glColor3f(0.0f, 1.0f, 1.0f);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT);
          glVertex2f(2*GLUT_SCREEN_WIDTH/3+5, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(GLUT_SCREEN_WIDTH-5, GLUT_SCREEN_HEIGHT-40.0);
          glVertex2f(GLUT_SCREEN_WIDTH-5, GLUT_SCREEN_HEIGHT);
      glEnd();
      // END 2D
      glMatrixMode(GL_PROJECTION);
    }
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    std::string texte="Victor attacks Timotei ! It's a critical hit !";
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