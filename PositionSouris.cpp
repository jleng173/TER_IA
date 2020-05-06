#include "PositionSouris.hpp"

PositionSouris::PositionSouris(float modelViewMat[16],float modelProjetMat[16],float xpose,float ypose,int WIDTH,int HEIGHT) {
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

    positionX = Position[0];
    positionY = Position[1];
    positionZ = Position[2];
}

float * PositionSouris::mxm(float * m1, float * m2){

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

float * PositionSouris::mxv(float * m, float * v){

  float * res = (float *)malloc(sizeof(float) * 16);

  res[0] = m[0]*v[0] + m[4]*v[1] + m[8]*v[2] + m[12]*v[3];
  res[1] = m[1]*v[0] + m[5]*v[1] + m[9]*v[2] + m[13]*v[3];
  res[2] = m[2]*v[0] + m[6]*v[1] + m[10]*v[2] + m[14]*v[3];
  res[3] = m[3]*v[0] + m[7]*v[1] + m[11]*v[2] + m[15]*v[3];

  return res;
} 

int PositionSouris::gluInvertMatrixd(const float src[16], float inverse[16]){
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