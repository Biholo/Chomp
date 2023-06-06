#include "../include/joueur.h"

Joueur adversaire(Joueur Joueur) {
    /* Change le tour*/
    if (Joueur == JOUEUR_1) 
        return JOUEUR_2;

    return JOUEUR_1;
}