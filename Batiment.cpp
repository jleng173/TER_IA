#include "Batiment.hpp"

Batiment::Batiment(TEXTURE_STRUCT * T_chateau,TEXTURE_STRUCT * T_pierre,TEXTURE_STRUCT * T_toit,TEXTURE_STRUCT * T_porte, TEXTURE_STRUCT * T_paille){
        Texture_chateau = T_chateau;
        Texture_pierre = T_pierre;
        Texture_toit = T_toit;
        Texture_porte = T_porte;
        Texture_paille = T_paille;
}
