#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ppm.hpp"
#include <string>
class InterfaceHUD{
    public:

    InterfaceHUD();
    GLvoid creerInterfaceHUD();
    void drawText(std::string text, int length, int x, int y);
};