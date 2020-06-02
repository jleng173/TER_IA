
#include "init.hpp"
// Constructor
initGL::initGL() {}

//Destructor
initGL::~initGL() {}


/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void initGL::generalInit(unsigned int width,unsigned int height)	// We call this right after our OpenGL window is created.
{
    ppm p;
    glClearColor(0.1f, 0.4f, 0.7f, 0.0f);	// This Will Clear The Background Color To Black
   // glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
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

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,1000.0f);
    
    glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

}



int initGL::mainInit(int argc, char** argv, void (*DrawGLScene)(),int WIDTH, int HEIGHT) 
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
    glutInitWindowSize(WIDTH, HEIGHT);  

    /* the window starts at the upper left corner of the screen */
    glutInitWindowPosition(0, 0);  

    /* Open a window */  
    window = glutCreateWindow("OpenGL");  

    /* Register the function to do all our OpenGL drawing. */
    glutDisplayFunc(DrawGLScene);  

    /* Go fullscreen.  This is as soon as possible. */
     //   glutFullScreen();

    /* Even if there are no events, redraw our gl scene. */
    glutIdleFunc(DrawGLScene); 

    /* Register the function called when our window is resized. */
    glutReshapeFunc(&ReSizeGLScene);

    /* Register the function called when the keyboard is pressed. */
    glutKeyboardFunc(&touche_pressee);

    glutMouseFunc(&mouseClicks);

    glutPassiveMotionFunc(&mouseMove);


    /* Initialize our window. */
    generalInit(WIDTH, HEIGHT);



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

void initGL::touche_pressee(unsigned char key, int x, int y) 
{

    usleep(100);
    float limite = 19;
    switch (key) {    
    case ESCAPE: 
	   exit(1);                   	
	    break;    
    case TOUCHE_MIN_X:
        construction=1;
        break;
    case TOUCHE_MIN_Z: 
	   xrot-=1.0f;                 	
	    break;    
    case TOUCHE_MIN_Q: 
	   yrot-=1.0f;               	
	    break;    
    case TOUCHE_MIN_S: 
	   xrot+=1.0f;                	
	    break;    
    case TOUCHE_MIN_D: 
	   yrot+=1.0f;                	
	    break;       
    case TOUCHE_MIN_E: 
	   z-=1.0f;               	
	    break;      
    case TOUCHE_MIN_R: 
	   z+=1.0f;               	
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
        action=0;
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


    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      xcam = 0.0f;
      ycam = 0.0f;
      break;

	
    }	

}

void initGL::mouseClicks(int button, int state, int x, int y){
    float mx = x ;
    float my = y ;
    // Clic gauche 
    if(button == 0) {
        if ( pose == 2)
            pose = 0;
        else if (pose == 0) {
            pose = 1;
            xpose = mx;
            ypose = my;
        }
    }
    // Clic droit
    if(button == 2) {

        switch (selection) { 
        case 0:
            selection = 1;
            xpose = mx;
            ypose = my;
        break;
        case 1:
            selection = 2;
            xpose = mx;
            ypose = my;
        break;
        case 2:
            selection = 3;
            xpose = mx;
            ypose = my;
        break;
        default:
            selection = 0;
            xpose = mx;
            ypose = my;
        break;
        
        }
    }    
}

void initGL::mouseMove(int x, int y){
  xpose = x;
  ypose = y;
}

