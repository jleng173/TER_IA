#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Decor.hpp"

class Carte {
public:
	// Constructor
	Carte();

    void solcarte();
	int getTailleCarte();

private:
	Decor decor;
	int tailleCarte;
 
};