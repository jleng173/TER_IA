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
    //printf("id %d  id autre %d \n", id,autre->id);
    if( id != autre->id){
        //printf("COORD HITBOX ELEM (%f,%f) et (%f,%f) // COORD HITBOX AUTRE ELEM (%f,%f)(%f,%f) \n",this->getHitbox().x1,getHitbox().y1,getHitbox().x2,getHitbox().y2,autre->getHitbox().x1,autre->getHitbox().y1,autre->getHitbox().x2,autre->getHitbox().y2);
        return (getHitbox().x2 >= autre->getHitbox().x1 && getHitbox().x1 <= autre->getHitbox().x2) &&
            (getHitbox().y2 >= autre->getHitbox().y1 && getHitbox().y1 <= autre->getHitbox().y2);
    }else
        return false;

}

void Element::setHitbox(Hitbox h){
    this->hitbox = h;
}

bool Element::testSiColision(const std::vector<Element *> all){
   // for(auto& e :all){
   //printf("\n");
    for (int i = 0 ; i< all.size() ; i++){
        if(Colision(all[i])){
                //printf("COORD HITBOX ELEM (%f,%f) et (%f,%f) // COORD HITBOX AUTRE ELEM (%f,%f)(%f,%f) \n",this->getHitbox().x1,getHitbox().y1,getHitbox().x2,getHitbox().y2,all[i]->getHitbox().x1,all[i]->getHitbox().y1,all[i]->getHitbox().x2,all[i]->getHitbox().y2);
            return true;
        }
    }
    return false;
}