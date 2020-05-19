#include "Paysan.hpp"

Paysan::Paysan(float x, float y,float angle, float vitesseMAX,std::array<float,3> col, std::vector<Decor*> decors, Joueur * J, TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille):Personnage(x,y,angle,vitesseMAX,col),Texture_chateau(T_chateau),Texture_pierre(T_pierre),Texture_toit(T_toit),Texture_porte(T_porte),Texture_paille(T_paille){
    nom="Paysan";
    hp=60;
    hpMax=60;
    dmg=1;
    selected = 0;
    vision = 25.0;
    _decors = decors;
    _J = J;
    _pierre = false;
    _bois = false;
}

void Paysan::construireCaserne(Joueur * J,float x, float y){
    if(J->getBois() >= 2 && J->getPierre() >= 8){
        J->subtractBois(2);
        J->subtractPierre(8);
        Batiment * cas = new Caserne(x,y,Texture_chateau,Texture_pierre,Texture_toit,Texture_porte,Texture_paille);
        J->addBatiment(cas);
    }
}

void Paysan::construireFerme(Joueur * J,float x, float y){
    if(J->getBois() >= 4 && J->getPierre() >= 1){
        J->subtractBois(4);
        J->subtractPierre(1);
        Batiment * ferm = new Ferme(J,x,y,Texture_chateau,Texture_pierre,Texture_toit,Texture_porte,Texture_paille);
        J->addBatiment(ferm);
    }
}

void Paysan::construireTour(Joueur * J,float x, float y){
    if(J->getBois() >= 5 && J->getPierre() >= 5){
        J->subtractBois(5);
        J->subtractPierre(5);
        Batiment * tower = new Tour(x,y,Texture_chateau,Texture_pierre,Texture_toit,Texture_porte,Texture_paille);
        J->addBatiment(tower);
    }
}



GLvoid Paysan::creerChapeau() const{
    glPushMatrix();{
        glColor3f(0.7,0.7,0);
        // glScalef(0.8,0,0);
        Personnage::drawHalfSphere(100,100,1);
        GLUquadric* params = gluNewQuadric();
        gluQuadricTexture(params, GL_TRUE);
        glRotatef(90,1,0,0);
        gluDisk(params,0,1,20,1);
        gluDeleteQuadric(params);
    }
    glPopMatrix();
}

GLvoid Paysan::creerAccessoire() const{
    Forme f;
    struct cube1 base = f.creerCube(1);
    struct pyramide1 pic = f.creerPyramide(1);
    glPushMatrix();{
        glColor3f(0.6,0.6,0.6);
        glPushMatrix();{     
            glScalef(0.3,0.3,0.3);
            glTranslatef(5.5,-3.25,0);
            glRotatef(-135,0,0,1);
            f.affichePyramide(pic);
        }
        glPopMatrix();
        glPushMatrix();{
            glScalef(0.3,0.3,0.3);
            glTranslatef(-5.5,-3.25,0);
            glRotatef(135,0,0,1);
            f.affichePyramide(pic);
        }
        glPopMatrix();
        glPushMatrix();{
            glScalef(0.8,0.3,0.3);
            f.afficheCube(base);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(-1.02,-0.35,0);
            glRotatef(45,0,0,1);
            glScalef(0.6,0.3,0.3);
            f.afficheCube(base);
        }
        glPopMatrix();
        glPushMatrix();{
            glTranslatef(1.02,-0.35,0);
            glRotatef(-45,0,0,1);
            glScalef(0.6,0.3,0.3);
            f.afficheCube(base);
        }
        glPopMatrix();
    }
    glPopMatrix();


    glPushMatrix();{
        glColor3f(0.5,0.25,0.25);
        GLUquadric* params = gluNewQuadric();
        gluQuadricTexture(params, GL_TRUE);
        glRotatef(90,1,0,0);
        glTranslatef(0,0,0);
        gluCylinder(params,0.2,0.2,4,100,100);
    }
    glPopMatrix();
}

std::vector<float> Paysan::rangeRessource(char r){
    // ressourceProche -> (position x, position y, resistance, 
    //                     numéro du décor, position dans le vecteur, distance)
    std::vector<float> ressourceProche = {0,0,1};

    float distanceDecorMin = INFINITY;
    float distanceMin = INFINITY;
    int numDecorProche = -1;
    int numProche = 0;

    if ( r == 'P'){
        // On cherche le décor le plus près du Paysan
        for (int i = 0 ; i < _decors.size() ; i++){

            float calculDecorX = _decors[i]->getpositionDecorX() - position[0];
            float calculDecorY = _decors[i]->getpositionDecorY() - position[1];
            float distanceDecor = sqrtf((calculDecorX*calculDecorX)+(calculDecorY*calculDecorY));

            if (distanceDecor < distanceDecorMin && !(_decors[i]->getMine().empty())){
                distanceDecorMin = distanceDecor;
                numDecorProche = i;
            }
            
        }
        // On cherche le rocher le plus proche au sein de ce décor
        for (int j = 0 ; j < _decors[numDecorProche]->getMine().size() ; j++){
            float calculx = _decors[numDecorProche]->getMine()[j][0] - position[0];
            float calculy = _decors[numDecorProche]->getMine()[j][1] - position[1];
            float distance = sqrtf((calculx*calculx)+(calculy*calculy));

            if(distance < distanceMin){
                distanceMin = distance;
                ressourceProche = _decors[numDecorProche]->getMine()[j];
                numProche = j;
            }
        }
        ressourceProche.push_back(numDecorProche);
        ressourceProche.push_back(numProche);
        ressourceProche.push_back(distanceMin);
        
        return ressourceProche;


    }else if( r == 'B'){
        // On cherche le décor le plus près du Paysan
        for (int i = 0 ; i < _decors.size() ; i++){

            float calculDecorX = _decors[i]->getpositionDecorX() - position[0];
            float calculDecorY = _decors[i]->getpositionDecorY() - position[1];
            float distanceDecor = sqrtf((calculDecorX*calculDecorX)+(calculDecorY*calculDecorY));

            if (distanceDecor < distanceDecorMin && !(_decors[i]->getForet().empty())){
                distanceDecorMin = distanceDecor;
                numDecorProche = i;
            }
            
        }
        // On cherche l'arbre le plus proche au sein de ce décor
        for (int j = 0 ; j < _decors[numDecorProche]->getForet().size() ; j++){
            float calculx = _decors[numDecorProche]->getForet()[j][0] - position[0];
            float calculy = _decors[numDecorProche]->getForet()[j][1] - position[1];
            float distance = sqrtf((calculx*calculx)+(calculy*calculy));

            if(distance < distanceMin){
                distanceMin = distance;
                ressourceProche = _decors[numDecorProche]->getForet()[j];
                numProche = j;
            }
        }
        ressourceProche.push_back(numDecorProche);
        ressourceProche.push_back(numProche);
        ressourceProche.push_back(distanceMin);

        return ressourceProche;
    }
}


void Paysan::comportement(std::vector<Personnage*> listeEnnemies,std::vector<Element *>  all){
    std::vector<float> ennemieProche = rangeEnnemy(listeEnnemies);
    // ressourceProche -> (position x, position y, resistance, 
    //                     numéro du décor, position dans le vecteur, distance)
    std::vector<float> ressourceProche;

    switch(etat){
        case SLEEP:
            if(voitEnnemie(ennemieProche)){
                etat = FLEE;
            }else if(_bois){
                etat = SEEKWOOD;
            }else if(_pierre){
                etat = SEEKSTONE;
            }
        break;

        case SEEKWOOD :
            ressourceProche = rangeRessource('B');
            lastPosition[0] = ressourceProche[0];
            lastPosition[1] = ressourceProche[1];
            //deplacementCible(ressourceProche[0],ressourceProche[1],all);
            if(voitEnnemie(ennemieProche)){
                etat = FLEE;
            }else if(contact(ressourceProche)){
                etat = CHOP;
            }else if(_pierre){
                etat = SEEKSTONE;
            }else if(!_bois){
                etat = SLEEP;
            }
        break;

        case SEEKSTONE :
            ressourceProche = rangeRessource('P');
            lastPosition[0] = ressourceProche[0];
            lastPosition[1] = ressourceProche[1];
            //deplacementCible(ressourceProche[0],ressourceProche[1],all);
            if(voitEnnemie(ennemieProche)){
                etat = FLEE;
            }else if(contact(ressourceProche)){
                etat = MINE;
            }else if(_bois){
                etat = SEEKWOOD;
            }else if(!_pierre){
                etat = SLEEP;
            }
        break;

        case CHOP:
            ressourceProche = rangeRessource('B');
            if(action==0){
                mouvementbras=2;
            }
            if(action<30 && mouvementbras==2){
                action+=0.5;
            }
            if(action >= 30 && mouvementbras==2)
                mouvementbras=3;
            if(action>0 && mouvementbras==3)
                action-=0.5;

            _decors[ressourceProche[3]]->degatArbre(ressourceProche[4],this->getDmg());
            if( _decors[ressourceProche[3]]->getForet()[ressourceProche[4]][2] <= 0){
                _decors[ressourceProche[3]]->deleteArbre(ressourceProche[4]);
                ajoutRessource(_J,'B');
            }
        
            if(voitEnnemie(ennemieProche)){
                etat = FLEE;
            }else if(_pierre){
                etat = SEEKSTONE;
            }else if(!contact(ressourceProche)){
                etat = SLEEP;
            }
        break;

        case MINE:
            ressourceProche = rangeRessource('P');
            if(action==0){
                mouvementbras=2;
            }
            if(action<30 && mouvementbras==2){
                action+=0.5;
            }
            if(action >= 30 && mouvementbras==2)
                mouvementbras=3;
            if(action>0 && mouvementbras==3)
                action-=0.5;
            _decors[ressourceProche[3]]->degatRoche(ressourceProche[4],this->getDmg());           
            if( _decors[ressourceProche[3]]->getMine()[ressourceProche[4]][2] <= 0){
                _decors[ressourceProche[3]]->deleteRoche(ressourceProche[4]);
                ajoutRessource(_J,'P');
            }
            if(voitEnnemie(ennemieProche)){
                etat = FLEE;
            }else if(_bois){
                etat = SEEKWOOD;
            }else if(!contact(ressourceProche)){
                etat = SLEEP;
            }
        break;

        case FLEE:
            fuirCible(ennemieProche[0],ennemieProche[1],all);
            if(!voitEnnemie(ennemieProche)){
                etat = SLEEP;
            }
        break;

        default :
            etat = SLEEP;
        break;
    }
}

void Paysan::ajoutRessource(Joueur * J, char r){
    if (r == 'B'){
        J->addBois(2);
        J->addOr(1);
    } else if( r == 'P'){
        J->addPierre(6);
        J->addOr(3);
    }
}

bool Paysan::voitEnnemie(std::vector<float> ennemieProche){
    return(ennemieProche[2] <= vision);
}

void Paysan::modePierre(){
    if(_pierre == false){
        _pierre = true;
        _bois = false;
    }else {
        _pierre = false;
        _bois = false;
    }
    selected = false;
}

void Paysan::modeBois(){
    if(_bois == false){
        _bois = true;
        _pierre = false;
    }else {
        _bois = false;
        _pierre = false;
    }
    selected = false;
}

bool Paysan::contact(std::vector<float> ressource){
    return (ressource.back() <= 0.5);
}

