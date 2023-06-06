#include "../include/mechanisme.h"
#include "../include/tablette.h"
#include "../include/match.h"

Match init_match(){
    Match match;
    match.joueur1 = 0;
    match.joueur2 = 0;
    match.totalManche = 0;
    match.currentManche = 1;
    return match;
}

void gameMatch(){
    int nb_joueur1, nb_joueur2;
    int lignes, colonnes;
    Position pos;
    Coup coup;
    Joueur j;
    Joueur joueur_gagnant;
    Match match;
    match = init_match();
    j = JOUEUR_1;
    
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, FALSE);
    curs_set(FALSE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    
    mvprintw(0, 0, "Joueur 1: Veuillez entrer le nombre de manche que vous souhaiter jouer:");
    mvscanw(1, 0, "%d", &nb_joueur1);
    mvprintw(2, 0, "Joueur 2: Veuillez entrer le nombre de manche que vous souhaiter jouer:");
    mvscanw(3, 0, "%d", &nb_joueur2);
    
    mvprintw(4, 0, "Désormais, Initialison le plateau !");
    mvprintw(5, 0, "Veuillez indiquer le nombre de ligne:");
    mvscanw(5, 38, "%d", &lignes);
    mvprintw(6, 0, "Veuillez indiquer le nombre de colonnes:");
    mvscanw(6, 42, "%d", &colonnes);

    match.totalManche = (nb_joueur1 + nb_joueur2) / 2;
    noecho();
    
    
    while(match.totalManche >= match.currentManche){
        /* Initialisation d'une nouvelle manche*/
        /*Changement du joueur qui commence*/
        if(match.currentManche%2 == 1)
            pos.j = j;
        else
            pos.j = adversaire(j);
        Tablette* t = creer_tablette(lignes, colonnes);
        pos.tab = t;
        afficher_position(pos);
        refresh();
        //Tant qu'aucun joueur ne mange le dernier carré on continue.
        while(!est_jeu_termnine(pos, &joueur_gagnant)){
            coup = lire_coup(pos);
            jouer_coup(&pos, coup);
            afficher_position(pos);
            refresh();
        }

        mvprintw(0, (COLS / 2) - 15, "                                     ");
        
        if( pos.j == JOUEUR_1){
            mvprintw((LINES/2), (COLS/2) - 18, "Victoire de la manche %d par JOUEUR_1", match.currentManche);
            match.joueur1++;
        }
        else{
            mvprintw((LINES/2), (COLS/2) - 18, "Victoire de la manche %d par JOUEUR_2", match.currentManche);
            match.joueur2++;
        }
        mvprintw((LINES/2) + 1, (COLS/2) - 27, "Cliquer sur l'ecran pour jouer la prochaine manche !");

        if( match.currentManche == match.totalManche){
            clear();
            if(match.joueur1 == match.joueur2)
                mvprintw((LINES/2), (COLS/2) - 4, "EGALITE !");
            else if (match.joueur1 > match.joueur2)
                mvprintw((LINES/2), (COLS/2) - 10, "Victoire du JOUEUR_1");
            else
                mvprintw((LINES/2), (COLS/2) - 10, "Victoire du JOUEUR_2");
            mvprintw((LINES/2)+1, (COLS/2) - 16, "Récap: JOUEUR_1: %d et JOUEUR_2: %d", match.joueur1, match.joueur2);
            refresh();
        }
        match.currentManche++;
        refresh();
        getch();
        
    }
   
    endwin();
}