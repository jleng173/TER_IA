#include "actions.h"

extern GLfloat xrot;   
extern GLfloat yrot; 
extern GLuint blend;
extern GLuint light;

extern float xcam;
extern float zcam;

extern int pose;
extern float xpose;
extern float ypose;

extern int mouse;

void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

    switch (key) {    
    case ESCAPE: 
	exit(1);                   	
	break; 

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_B: 
    case TOUCHE_MAJ_B: 
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
    case TOUCHE_MAJ_L: 
      light = switch_light(light);
      break;

    case TOUCHE_MIN_Z: 
    case TOUCHE_MAJ_Z:
      zcam +=2;
	    break;

    case TOUCHE_MIN_Q: 
    case TOUCHE_MAJ_Q:
      xcam +=2;
	    break;

    case TOUCHE_MIN_S: 
    case TOUCHE_MAJ_S:
      zcam -=2;
	    break;

    case TOUCHE_MIN_D: 
    case TOUCHE_MAJ_D:
      xcam -=2;
	    break;

    case TOUCHE_MIN_E:
      pose = 1;
      xpose = xcam;
      ypose = zcam;
	    break; 
    case TOUCHE_MAJ_E:
      pose = 0;
	    break; 
    }

}

void mouseClicks(int button, int state, int x, int y) {
  //printf("%d\n",button);
  mouse = button;
  float mx = x ;
  float my = y ;
    if(button == 0) {
      pose = 1;
      xpose = mx;
      ypose = my;
    }
}