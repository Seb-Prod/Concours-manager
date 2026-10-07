/**
 * \file affichage.c
 * \brief Implémentation des fonctions utilitaires d'affichage, de gestion de l'écran et d'aide.
 */

#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"

/**
 * \copydoc accord
 */
const char *accord(int n, const char *singulier, const char *pluriel)
{
    return (n >= 2) ? pluriel : singulier;
}

/**
 * \copydoc effacer_ecran
 */
void effacer_ecran(void)
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls"); // Pour Windows
#else
    system("clear"); // Pour Mac et Linux
#endif
}

/**
 * \copydoc afficher_aide
 */
void afficher_aide(void)
{
    printf("=== LISTE DES COMMANDES DISPONIBLES ===\n");
    printf("- EXIT : Quitter le programme\n");
    printf("- INSCRIRE <prenom> <nom> : Inscrire un nouveau participant\n");
    printf("- PARTICIPANTS : Afficher la liste des participants\n");
    printf("- CREER <nom_concours> : Créer un nouveau concours\n");
    printf("- CONCOURS : Afficher la liste des concours\n");
    printf("- GAIN <id_part> <id_concours> <points> : Ajouter des points a un participant\n");
    printf("- SCORES <id_part> : Afficher les scores d'un participant\n");
    printf("- CLASSEMENT <id_concours> : Afficher le classement d'un concours\n");
    printf("- COMPARAISON <id_concours1> <id_concours2> : Comparer deux concours\n");
    printf("- BILAN <id_concours> : Afficher le bilan d'un concours (evolution des places)\n");
    printf("- AIDE : Afficher cette aide\n");
}