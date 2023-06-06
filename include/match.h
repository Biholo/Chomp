#ifndef __MATCH__
#define __MATCH__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct Match {
    int joueur1; /* nombre victoire pour joueur1*/
    int joueur2; /* nombre victoire pour joueur2*/
    int totalManche;
    int currentManche;
}Match;


/**
 * @brief Initialise un match.
 * 
 * @return (Match)
 */Match init_match();

/**
 * @brief Permet de jouer un match (qui prend en coup plusieur round).
 */
void gameMatch();

#endif