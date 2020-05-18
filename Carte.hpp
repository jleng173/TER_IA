#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <unistd.h>
#include <vector>
#include <time.h>
#include "Decor.hpp"

class Carte {
public:
	// Constructor
	Carte();

    void solcarte();
	int getTailleCarte();

	std::vector<Decor*> decors;

private:
	float xdecor;
	float ydecor;
	int tailleCarte;
 
};