#include "Element.hpp"


Element::Element(float x,float y){
    position[0] = x;
    position[1] = y;
}

bool Element::Colision( Element * autre){
return (getHitbox().x2 >= autre->getHitbox().x1 && getHitbox().x1 <= autre->getHitbox().x2) &&
       (getHitbox().y2 >= autre->getHitbox().y1 && getHitbox().y1 <= autre->getHitbox().y2);
}

bool Element::testSiColision(const std::vector<Element *> all){
    for(auto& e :all){
        if(Colision(e))
        return true;
    }
    return false;
}