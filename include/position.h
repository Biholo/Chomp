#ifndef __POSITION__
#define __POSITION__

#include "tablette.h"
#include "joueur.h"

typedef struct Position {
    Tablette* tab;
    Joueur j;
} Position;

#endif