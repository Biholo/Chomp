#ifndef __JOUEUR__
#define __JOUEUR__

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    JOUEUR_1,
    JOUEUR_2
}Joueur;

/**
 * @brief Return le joueur opposé, du joueur prit en paramètre.
 * 
 * @param Joueur (Joueur)
 * @return (Joueur)
 */
Joueur adversaire(Joueur Joueur);


#endif