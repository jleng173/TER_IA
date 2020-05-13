#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

class Decor{
public:
	// Constructor
	Decor(float dx, float dy);
    void GenerateForet(int nombre);
    void GenerateMine(int nombre);
    void Foret();
	void Mine();

    private:
	GLvoid Arbre();
    GLvoid Roche();
 
 private:
    float decox;
    float decoy;
    std::vector< std::vector<float> > _foret;
    std::vector< std::vector<float> > _mine;
};