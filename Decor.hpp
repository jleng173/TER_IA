#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <time.h>
#include <cstdlib>

class Decor{
public:
	// Constructor
	Decor();
    void GenerateForet(int nombre);
    void Foret();
	
    private:
	GLvoid Arbre();
 
 private:
    std::vector< std::vector<float> > _foret;
};