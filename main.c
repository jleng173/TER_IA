// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test


#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "cube.c"
#include "ppm.h"
#include "batiment.c"
#include "carte.c"
#include <math.h>

//Taille Fenetre
 int WIDTH = 1600;
 int HEIGHT = 900;

//CAMERA
float xcam = 0.0;
float ycam = 0.0;

int pose = 0;
int mouse = 0;
float xpose = 0.0;
float ypose = 0.0;

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -15.0f; 

float posx, posy, posz = 0.0;

float m1[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

TEXTURE_STRUCT * Texture_tour;

void pretty_printer(float *m) 
{
  printf("%f %f %f %f\n", (float)m[0], (float)m[4], (float)m[8], (float)m[12]);
  printf("%f %f %f %f\n", (float)m[1], (float)m[5], (float)m[9], (float)m[13]);
  printf("%f %f %f %f\n", (float)m[2], (float)m[6], (float)m[10], (float)m[14]);
  printf("%f %f %f %f\n", (float)m[3], (float)m[7], (float)m[11], (float)m[15]);
}

float * mxm(float * m1, float * m2) 
{

  float * res = (float *)malloc(sizeof(float) * 16);

  res[0] = m1[0]*m2[0] + m1[4]*m2[1] + m1[8]*m2[2] + m1[12]*m2[3];
  res[1] = m1[1]*m2[0] + m1[5]*m2[1] + m1[9]*m2[2] + m1[13]*m2[3];
  res[2] = m1[2]*m2[0] + m1[6]*m2[1] + m1[10]*m2[2] + m1[14]*m2[3];
  res[3] = m1[3]*m2[0] + m1[7]*m2[1] + m1[11]*m2[2] + m1[15]*m2[3];

  res[4] = m1[0]*m2[4] + m1[4]*m2[5] + m1[8]*m2[6] + m1[12]*m2[7];
  res[5] = m1[1]*m2[4] + m1[5]*m2[5] + m1[9]*m2[6] + m1[13]*m2[7];
  res[6] = m1[2]*m2[4] + m1[6]*m2[5] + m1[10]*m2[6] + m1[14]*m2[7];
  res[7] = m1[3]*m2[4] + m1[7]*m2[5] + m1[11]*m2[6] + m1[15]*m2[7];

  res[8] = m1[0]*m2[8] + m1[4]*m2[9] + m1[8]*m2[10] + m1[12]*m2[11];
  res[9] = m1[1]*m2[8] + m1[5]*m2[9] + m1[9]*m2[10] + m1[13]*m2[11];
  res[10] = m1[2]*m2[8] + m1[6]*m2[9] + m1[10]*m2[10] + m1[14]*m2[11];
  res[11] = m1[3]*m2[8] + m1[7]*m2[9] + m1[11]*m2[10] + m1[15]*m2[11];

  res[12] = m1[0]*m2[12] + m1[4]*m2[13] + m1[8]*m2[14] + m1[12]*m2[15];
  res[13] = m1[1]*m2[12] + m1[5]*m2[13] + m1[9]*m2[14] + m1[13]*m2[15];
  res[14] = m1[2]*m2[12] + m1[6]*m2[13] + m1[10]*m2[14] + m1[14]*m2[15];
  res[15] = m1[3]*m2[12] + m1[7]*m2[13] + m1[11]*m2[14] + m1[15]*m2[15];

  return res;
}

float * mxv(float * m, float * v) 
{

  float * res = (GLfloat *)malloc(sizeof(GLfloat) * 16);

  res[0] = m[0]*v[0] + m[4]*v[1] + m[8]*v[2] + m[12]*v[3];
  res[1] = m[1]*v[0] + m[5]*v[1] + m[9]*v[2] + m[13]*v[3];
  res[2] = m[2]*v[0] + m[6]*v[1] + m[10]*v[2] + m[14]*v[3];
  res[3] = m[3]*v[0] + m[7]*v[1] + m[11]*v[2] + m[15]*v[3];

  return res;
}

int gluInvertMatrixd(const float src[16], float inverse[16])
{
    int i, j, k, swap;
    float t;
    float temp[4][4];

    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            temp[i][j] = src[i*4+j];

    for(int i=0;i<16;i++)
        inverse[i] = 0;
    inverse[0] = inverse[5] = inverse[10] = inverse[15] = 1.0f;

    for(i=0; i<4; i++)
    {
        swap = i;
        for (j = i + 1; j < 4; j++)
            if (fabs(temp[j][i]) > fabs(temp[i][i]))
                swap = j;

        if (swap != i) {
            //Swap rows.
            for (k = 0; k < 4; k++) {
                t = temp[i][k];
                temp[i][k] = temp[swap][k];
                temp[swap][k] = t;

                t = inverse[i*4+k];
                inverse[i*4+k] = inverse[swap*4+k];
                inverse[swap*4+k] = t;
            }
        }

        if (temp[i][i] == 0)
            return 0;

        t = temp[i][i];
        for (k = 0; k < 4; k++) {
            temp[i][k] /= t;
            inverse[i*4+k] /= t;
        }

        for (j = 0; j < 4; j++) {
            if (j != i) {
                t = temp[j][i];
                for (k = 0; k < 4; k++) {
                    temp[j][k] -= temp[i][k]*t;
                    inverse[j*4+k] -= inverse[i*4+k]*t;
                }
            }
        }
    }

}

GLvoid Modelisation()
{

  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
  glPushMatrix();
  {
    //Oriente la camera 
        gluLookAt(xcam,ycam,85,
                 xcam,ycam,0,
               0,1,0);

    // Matrice Vue
    float modelViewMat[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMat);
    // Matrice Projection
    float modelProjetMat[16];
    glGetFloatv(GL_PROJECTION_MATRIX, modelProjetMat);

    // Matrice Projection * Matrice Vue
    float * Mult = (float *)malloc(sizeof(float) * 16);
     Mult = mxm(modelProjetMat,modelViewMat);

    //Inverse du résultat de la matrice
    float * minverse = (float *)malloc(sizeof(float) * 16);
    gluInvertMatrixd(Mult,minverse);


    float * in = (float *)malloc(sizeof(float) * 4);
    float winZ = 1.0;

    in[0]=(2.0f*((float)(xpose-0)/(WIDTH-0)))-1.0f,
    in[1]=1.0f-(2.0f*((float)(ypose-0)/(HEIGHT-0)));
    in[2]=2.0* winZ -1.0;
    in[3]=1.0;

    // Vecteur des Positions
    float * Position = (float *)malloc(sizeof(float) * 16);
    Position = mxv(minverse,in);

    Position[0] /= Position[3];
    Position[1] /= Position[3];
    Position[2] /= Position[3];

printf("%f %f %f / %f,%f,%f \n",xcam,ycam,z,Position[0],Position[1],Position[2]);
  
    if (pose == 1){
      posx = Position[0];
      posy = Position[1];
      posz = Position[2];
      pose = 0;
    }
    if (pose == 0 && posx != 0){
       glPushMatrix();{
        
        glTranslatef(posx,posy,2.5);
        //glTranslatef(0,0,+17);
        glScalef(0.5,0.5,0.5);
        glRotatef(90,1.0,0.0,0.0);
        creer_chateau();
        //creer_tour();
       // pose = 0;
      // printf("%f\n",xpose);
      }glPopMatrix();
    }


    glPushMatrix();{
      glTranslatef(0,0,0);
      solcarte();
     }glPopMatrix();
    
  }
  glPopMatrix();

  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
