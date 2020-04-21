#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <cstdlib>

class Carte {
public:
	// Constructor
	Carte();
	Carte(bool foret);

    void solcarte();
	void GenerateForet();
	void Foret();
public:
	std::vector< std::vector<float> > _foret;
 
};