
#include "../include/position.h"
#include "../include/coup.h"

Coup clic_vers_case(Coup coup, Position pos){
    Coup temp_coup;
    int y = (coup.y - LINES/2 + (pos.tab->nb_lignes * 4)/2) /4;
    int x = (coup.x - COLS/2 + (pos.tab->nb_colonnes * 7)/2) /7;
    temp_coup.x = x;
    temp_coup.y = y;
    return temp_coup;

} 

Coup lire_coup(Position pos){
    Coup c, coup;
    int touche = getch(); 
    MEVENT ev;

    while(1) {
        if(touche == KEY_MOUSE && getmouse(&ev) == OK){
            c.x = ev.x;
            c.y = ev.y;
            coup = clic_vers_case(c, pos);
            if(est_legal(pos, coup)){
                break;
            }
        }
        touche = getch();   
    }
    return coup;
}

int est_legal(Position pos, Coup coup){
   
    /* Vérifie si un coup est possible*/
    if(coup.x >= 0 && coup.y >= 0 && coup.x < pos.tab->nb_colonnes && coup.y < pos.tab->nb_lignes){
        if(pos.tab->tab[coup.y][coup.x]) {
            return 1;
        }
        return 0; 
    }
    else {
        return 0;
    } 
}