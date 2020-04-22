// #include "Guerrier.hpp"

// Guerrier::Guerrier(float avn,float act,float x, float y,float angle, float vitesseMAX):Personnage(avn,act,x,y,angle,vitesseMAX){
//     hp=150;
//     dmg=5;
// }

// GLvoid Guerrier::creerChapeau() const{
//     glPushMatrix();{
//         glColor3f(0.7,0.7,0);
//         // glScalef(0.8,0,0);
//         // Personnage::drawHalfSphere(100,100,1);
//         GLUquadric* params = gluNewQuadric();
//         gluQuadricTexture(params, GL_TRUE);
//         glRotatef(90,1,0,0);
//         gluDisk(params,0,1,20,1);
//         gluDeleteQuadric(params);
//     }
//     glPopMatrix();
// }