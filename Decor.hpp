#pragma once
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
    void GenerateMine(int nombre);
    void Foret();
	void Mine();

    private:
	GLvoid Arbre();
    GLvoid Roche();
 
 private:
    std::vector< std::vector<float> > _foret;
    std::vector< std::vector<float> > _mine;
};