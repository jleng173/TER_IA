#pragma once
#include "Personnage.hpp"
#include <stdbool.h>


class Guerrier : public Personnage{
    protected:

    public:
        Guerrier(float x, float y,float angle, float vitesseMAX);
        GLvoid creerChapeau() const override;
        GLvoid creerAccessoire() const override;

};