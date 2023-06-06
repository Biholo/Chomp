
#include "../include/tablette.h"

Tablette* creer_tablette(int nb_lignes, int nb_colonnes){
    Tablette* t = malloc(sizeof(Tablette));
    t->nb_colonnes = nb_colonnes;
    t->nb_lignes = nb_lignes;
    t->tab = malloc(nb_lignes * sizeof(int*));
    for(int i = 0; i < nb_lignes;  i++){
        t->tab[i] = malloc(nb_colonnes * sizeof(int));
        for(int j = 0; j < nb_colonnes; j++){
            t->tab[i][j] = 1;
        }
    }
    return t;
}


