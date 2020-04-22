#include "Personnage.hpp"

class Paysan:public Personnage{
protected:

public:
    Paysan(float avn,float act,float x, float y,float angle, float vitesseMAX);
    GLvoid creerBatiment();
    GLvoid creerChapeau() const override;

};