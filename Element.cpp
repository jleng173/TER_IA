#include "Element.hpp"


Element::Element(float x,float y){
    id = current_id;
    current_id += 1;
    position[0] = x;
    position[1] = y;
    printf(" id %d \n",id);
}

int Element::current_id;

bool Element::Colision( Element * autre){
    if( id != autre->id){
        return (getHitbox().x2 >= autre->getHitbox().x1 && getHitbox().x1 <= autre->getHitbox().x2) &&
            (getHitbox().y2 >= autre->getHitbox().y1 && getHitbox().y1 <= autre->getHitbox().y2);
    }else
        return false;

}

void Element::setHitbox(Hitbox h){
    this->hitbox = h;
}

bool Element::testSiColision(const std::vector<Element *> all){
    for (int i = 0 ; i< all.size() ; i++){
        if(Colision(all[i])){
            return true;
        }
    }
    return false;
}