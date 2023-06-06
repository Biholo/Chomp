
#include "../include/coup.h"
#include "../include/joueur.h"
#include "../include/tablette.h"
#include "../include/position.h"
#include "../include/mechanisme.h"

void manger(Tablette *tab, int x, int y){
    /* Permet de modifier tab et change les valeurs du tableau en 0*/
    assert(tab != NULL);
    for(int i = y; i < tab->nb_lignes; i++){
        for(int j = x; j < tab->nb_colonnes; j++){
            tab->tab[i][j] = 0;
        }
    }
}

int est_jeu_termnine(Position pos, Joueur * joueur_gagnant){
    /* Vérifie si la case (0,0) a été mangé.*/
    if(pos.tab->tab[0][0] == 0) {
        *joueur_gagnant = pos.j;
        return 1;
    }
    return 0;
}

void jouer_coup(Position *pos, Coup coup){
    /* Permet de modifier le plateau de jeu selon le coup joué*/
    if(est_legal(*pos, coup)){
        manger(pos->tab, coup.x, coup.y);
        pos->j = adversaire(pos->j);
    }       
}


void afficher_case(int x, int y, Position pos){
    for(int i = 0; i < 3; i++){
        mvprintw(LINES/2 - (pos.tab->nb_lignes*4)/2 + i + y*4, COLS/2 - (pos.tab->nb_colonnes * 7)/2 + x * 7, "     ");
    }
}

void afficher_position(Position pos){
    clear();
    /* Affiche le jeu graphiquement*/
    attron(COLOR_PAIR(1));
    for(int i = 0; i < pos.tab->nb_lignes; i++){
        for(int j = 0; j < pos.tab->nb_colonnes; j++){
            if(pos.tab->tab[i][j] == 1)
                afficher_case(j, i, pos);
        }
    }
    attroff(COLOR_PAIR(1));
    if( pos.j == JOUEUR_1)
        mvprintw(0, (COLS/2) - 13, "C'est au tour du JOUEUR_1");
    else
        mvprintw(0, (COLS/2) - 13, "C'est au tour du JOUEUR_2");
}
