
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
    //glClearColor(1.0f, 0.2f, 0.2f, 1.0f);	// This Will Clear The Background Color To Black
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    /*    glDepthFunc(GL_LESS);			// The Type Of Depth Test To Do */
    glDepthFunc(GL_LEQUAL);	  // Le type de test de profondeur 
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix
    
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,1000.0f);	// Calculate The Aspect Ratio Of The Window
   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // setup blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
 
 	  GLuint text[1];
   

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
    glutInitWindowSize(640, 480);  

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

    /* Register the function called when special keys (arrows, page down, etc) are pressed. */
    //glutSpecialFunc(&specialKeyPressed);

    /* Initialize our window. */
    generalInit(640, 480);



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
    printf("Xrot : %f \n",xrot);
    printf("Yrot : %f \n",yrot);
    printf("Z : %f \n\n",z);
    usleep(100);

    switch (key) {    
    case ESCAPE: 
	   exit(1);                   	
	    break;    
    case TOUCHE_MIN_Z: 
	   xrot-=30.0f;                 	
	    break;    
    case TOUCHE_MIN_Q: 
	   yrot-=30.0f;               	
	    break;    
    case TOUCHE_MIN_S: 
	   xrot+=30.0f;                	
	    break;    
    case TOUCHE_MIN_D: 
	   yrot+=30.0f;                	
	    break;       
    case TOUCHE_MIN_E: 
	   z-=0.02f;               	
	    break;      
    case TOUCHE_MIN_R: 
	   z+=0.02f;               	
	    break;        
    case TOUCHE_MIN_B: 
	   if(blend==1) { 
           blend=0;
            glEnable(GL_BLEND);}
       else {
           blend=1;
           glDisable(GL_BLEND);}               	
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
	
/*
   case TOUCHE_MIN_Q:
	if (rota>360) rota=0;
	else 
	rota+=1;
	break;

   case TOUCHE_MIN_D: 
	if (rota<0) rota=360;
	else
	rota-=1;
	break;


   
 case TOUCHE_MIN_R: 
	if (rotrea==90) rotrea=0;
	else
	rotrea=90;
	break;
*/



    }	
}

