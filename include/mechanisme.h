#ifndef __MECHANISME__
#define __MECHANISME__

#include <assert.h>

#include "coup.h"
#include "position.h"
#include "joueur.h"

/**
 * @brief Modifie le tableau (passe  de 1 à 0 les cases supprimés) lorsqu'un coup est joué.
 * 
 * @param tab (Tablette)
 * @param x (int) Coordonnées x
 * @param y (int) Coordonnées y
 */
void manger(Tablette *tab, int x, int y);

/**
 * @brief Vérifie si la partie est terminé.
 * 
 * @param pos (Position)
 * @param joueur_gagnat (Joueur*)
 * @return (int)
 */
int est_jeu_termnine(Position pos, Joueur * joueur_gagnant);

/**
 * @brief Modifie le plateau de pos en fonction du coup jouer et change le tour deu joueur.
 * 
 * @param pos (Position*)
 * @param coup (Coup)
 */
void jouer_coup(Position *pos, Coup coup);

/**
 * @brief Affiche le plateau de jeu .
 * 
 * @param pos (Position)
 */
void afficher_position(Position pos);

#endif