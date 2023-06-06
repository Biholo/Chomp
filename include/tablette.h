
#ifndef __TABLETTE__
#define __TABLETTE__

#define NB_LIGNES 8
#define NB_COLONNES 16

#include <stdio.h>
#include <stdlib.h>

typedef struct Tablette {
    int** tab;
    int nb_lignes;
    int nb_colonnes;
}Tablette;

/**
 * @brief Crée et return une tablette en fonction des dimenssions prit en paramètre.
 * 
 * @param nb_lignes (int) Nombre de lignes
 * @param nb_colonnes (int) Nombre de colonnes
 * @return (Tablette*)
 */
Tablette* creer_tablette(int nb_lignes, int nb_colonnes);


#endif
