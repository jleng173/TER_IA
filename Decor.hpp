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

    std::vector< std::vector<float> > getForet();
    std::vector< std::vector<float> > getMine();

    float getpositionDecorX();
    float getpositionDecorY();

    void deleteArbre(int id);
    void deleteRoche(int id);

    void degatArbre(int id, float degat);
    void degatRoche(int id,float degat);

private:
	GLvoid Arbre();
    GLvoid Roche();
 
 private:
    float positionDecorX;
    float positionDecorY;
    std::vector< std::vector<float> > _foret;
    std::vector< std::vector<float> > _mine;
};