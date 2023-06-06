#ifndef __COUP__
#define __COUP__

#include <ncurses.h>

#include "position.h"

typedef struct Coup {
    int x;
    int y;
}Coup;

/**
 * @brief Récupère une position pour return un coup. 
 * 
 * @param pos (Position)
 * @return (Coup)
 */
Coup lire_coup(Position pos);

/**
 * @brief Vérifie si un coup est possible.
 * 
 * @param pos (Position)
 * @param coup (Coup)
 * @return (int)
 */
int est_legal(Position pos, Coup coup);


#endif