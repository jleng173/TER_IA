
#include "init.hpp"
// Constructor
initGL::initGL() {}

//Destructor
initGL::~initGL() {}

/*
unsigned int initGL::getHeight() {
	return m_height;
}


unsigned int initGL::getWidth() {
	return m_width;
}


void initGL::setHeight(unsigned int height) {
	m_height = height;
}


void initGL::setWidth(unsigned int width) {
	m_width = width;
}
*/
/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void initGL::generalInit(unsigned int width,unsigned int height)	// We call this right after our OpenGL window is created.
{
    ppm p;
    glClearColor(0.1f, 0.4f, 0.7f, 0.0f);	// This Will Clear The Background Color To Black
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    /*    glDepthFunc(GL_LESS);			// The Type Of Depth Test To Do */
    glDepthFunc(GL_LEQUAL);	  // Le type de test de profondeur 
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
    
    gluPerspective(180.0f,(GLfloat)width/(GLfloat)height,0.1f,10000.0f);	// Calculate The Aspect Ratio Of The Window
   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // setup blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
 
 	GLuint text[1];

	glEnable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1,text);
	glBindTexture(GL_TEXTURE_2D,text[0]);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// glGenerateMipmap(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_2D);
   

}
/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
GLvoid initGL::ReSizeGLScene(int Width, int Height)
{
    if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
	Height=1;

    glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
}



int initGL::mainInit(int argc, char** argv, void (*DrawGLScene)()) 
{  


    /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
       X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
    glutInit(&argc, argv);  

    /* Select type of Display mode:   
     Double buffer 
     RGBA color
     Depth buffer 
     Alpha blending */  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);  

    /* get a 640 x 480 window */
    glutInitWindowSize(1600, 900);  

    /* the window starts at the upper left corner of the screen */
    glutInitWindowPosition(0, 0);  

    /* Open a window */  
    window = glutCreateWindow("OpenGL");  

    /* Register the function to do all our OpenGL drawing. */
    glutDisplayFunc(DrawGLScene);  

    /* Go fullscreen.  This is as soon as possible. */
    //    glutFullScreen();

    /* Even if there are no events, redraw our gl scene. */
    glutIdleFunc(DrawGLScene); 

    /* Register the function called when our window is resized. */
    glutReshapeFunc(&ReSizeGLScene);

    /* Register the function called when the keyboard is pressed. */
    glutKeyboardFunc(&touche_pressee);

    glutMouseFunc(&mouseClicks);

    glutPassiveMotionFunc(&mouseMove);

    /* Register the function called when special keys (arrows, page down, etc) are pressed. */
    //glutSpecialFunc(&specialKeyPressed);

    /* Initialize our window. */
    generalInit(1600, 900);



  float color[] = {0.2, 0.2, 0.2 , 1};

  float specular[] = {0.5f, 0.5f, 0.5f, 1.0f};
  float diffuse[] = {0.6f, 0.6, 0.6f, 0.0f};
    float ambient[] = {0.55, 0.5, 0.5, 0.0f};
    float ambientfort[] = {1, 1, 0.7, 0.0f};
	float direction[]= {0, 0, -1};
    float light_position[] = {0,0,-4,1};
glEnable(GL_COLOR_MATERIAL);
GLfloat attenuation=1;


    
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    //glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);  
   

    glLightfv(GL_LIGHT4, GL_AMBIENT, ambientfort); 
    glLightfv(GL_LIGHT4, GL_POSITION, light_position);
    glLightf(GL_LIGHT4,GL_CONSTANT_ATTENUATION,attenuation);
    glLightfv(GL_LIGHT4,GL_SPOT_DIRECTION,direction);
    glLightf(GL_LIGHT4,GL_SPOT_CUTOFF,15);

 glEnable(GL_LIGHTING);

    
	glEnable(GL_LIGHT1);

	//glEnable(GL_LIGHT4); 
    glutMainLoop();  

    return 1;
}

void initGL::VM_init()        {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View

    glTranslatef(0,0,z);                  // move z units out from the screen.

    glRotatef(xrot,1.0f,0.0f,0.0f);		// Rotate On The X Axis
    glRotatef(yrot,0.0f,1.0f,0.0f);		// Rotate On The Y Axis

    glColor3f(1.0f, 1.0f, 1.0f);

}


/* The function called whenever a normal key is pressed. */
/*
void initGL::specialKeyPressed(int key, int x, int y) 
{
    usleep(100);

    switch (key) {    
    case GLUT_KEY_PAGE_UP: // move the cube into the distance.
	z-=0.02f;
	break;
    
    case GLUT_KEY_PAGE_DOWN: // move the cube closer.
	z+=0.02f;
	break;

    case GLUT_KEY_UP: // decrease x rotation speed;
	xrot-=30.0f;
	break;

    case GLUT_KEY_DOWN: // increase x rotation speed;
	xrot+=30.0f;
	break;

    case GLUT_KEY_LEFT: // decrease y rotation speed;
	yrot-=30.0f;
	break;
    
    case GLUT_KEY_RIGHT: // increase y rotation speed;
	yrot+=30.0f;
	break;

    default:
	break;


    }	
}
*/

void initGL::touche_pressee(unsigned char key, int x, int y) 
{
    /*printf("Xrot : %f \n",xrot);
    printf("Yrot : %f \n",yrot);
    printf("Z : %f \n\n",z);*/
    usleep(100);
    float limite = 19;
    switch (key) {    
    case ESCAPE: 
	   exit(1);                   	
	    break;    
    case TOUCHE_MIN_Z: 
	   xrot-=5.0f;                 	
	    break;    
    case TOUCHE_MIN_Q: 
	   yrot-=5.0f;               	
	    break;    
    case TOUCHE_MIN_S: 
	   xrot+=5.0f;                	
	    break;    
    case TOUCHE_MIN_D: 
	   yrot+=5.0f;                	
	    break;       
    case TOUCHE_MIN_E: 
	   z-=0.5f;               	
	    break;      
    case TOUCHE_MIN_R: 
	   z+=0.5f;               	
	    break;        
    case TOUCHE_MIN_B: 
	   if(blend==1) { 
           blend=0;
            glEnable(GL_BLEND);}
       else {
           blend=1;
           glDisable(GL_BLEND);}               	
	    break;
    case TOUCHE_MAJ_A:
        mouv=0;
        break;   
    case TOUCHE_MIN_A:
        if(avance<limite && mouv == 0)
            avance += 1;
        if(avance==limite && mouv == 0)
            mouv = 1;
        if(avance>-limite && mouv == 1)
        {
            avance -= 1;
        }
        if(avance==-limite && mouv == 1)
            mouv=0;
        break;   
    case TOUCHE_MIN_F:
        avance=0;
        if(action==0)
            mouv=2;
        if(action<3 && mouv==2){
            action+=0.5;
        }
        if(action==3 && mouv==2)
            mouv=3;
        if(action>0 && mouv==3)
            action-=0.5;
        break;

/*
    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_B: 
    
    case TOUCHE_MAJ_B: 
      blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L: 
 
      break;
*/
	
    }	

}

void initGL::mouseClicks(int button, int state, int x, int y){
    float mx = x ;
    float my = y ;
    if(button == 0) {
      pose = 1;
      xpose = mx;
      xpose = mx;
      ypose = my;
    }
}

void initGL::mouseMove(int x, int y){
  xpose = x;
  ypose = y;
}

