#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

class PositionSouris {
public:
    PositionSouris(float modelViewMat[16],float modelProjetMat[16],float xpose,float ypose,int WIDTH,int HEIGHT);

    float positionX;
    float positionY;
    float positionZ;

    float * mxm(float * m1, float * m2);
    float * mxv(float * m, float * v);
    int gluInvertMatrixd(const float src[16], float inverse[16]);
};