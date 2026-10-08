/**
 * \file main.c
 * \brief Point d'entrée principal de l'application de gestion de concours et de scores.
 * \details Gère la boucle d'interaction principale, l'initialisation de l'affichage,
 *          la lecture et l'analyse des commandes utilisateur, ainsi que leur routage
 *          vers les différents modules fonctionnels (participants, concours, scores, classement).
 */

#include <stdio.h>
#include <stdlib.h>
#include "saisie.h"
#include "commandes.h"
#include "donnees.h"
#include "participants.h"
#include "concours.h"
#include "scores.h"
#include "classement.h"
#include "affichage.h"

/**
 * \brief Fonction principale du programme.
 * \details Efface l'écran selon le système d'exploitation, instancie la structure globale
 *          `Application` en mémoire statique, puis exécute la boucle interactive de saisie
 *          et de traitement des commandes jusqu'à la fermeture de l'application (`CMD_EXIT`).
 *
 * \return 0 en cas de fin normale du programme.
 */
int main()
{

    //effacer_ecran(); // Nettoyage de l'écran au démarrage

    char saisie[100];
    CommandeAnalysee commande;

    // static : initialisée à zéro, et hors de la pile
    static Application application;

    while (saisir_commande(saisie, sizeof(saisie)))
    {
        if (!analyser_saisie(saisie, &commande))
        {
            continue;
        }

        switch (commande.type)
        {
        case CMD_EXIT:
        {
            // printf("Fermeture du programme...\n");
            return 0;
        }

        case CMD_INSCRIRE:
        {
            char *mots[2];
            if (extraire_arguments(commande.arguments, mots, 2) == 2)
            {
                inscrire_participant(&application, mots[0], mots[1]);
            }
            break;
        }

        case CMD_PARTICIPANTS:
        {
            lister_participants(&application);
            break;
        }

        case CMD_CREER:
        {
            char *mots[1];
            if (extraire_arguments(commande.arguments, mots, 1) == 1)
            {
                ajouter_concour(&application, mots[0]);
            }
            break;
        }

        case CMD_CONCOURS:
        {
            lister_concours(&application);
            break;
        }

        case CMD_GAIN:
        {
            char *mots[3];
            if (extraire_arguments(commande.arguments, mots, 3) == 3)
            {
                enregistrer_gain(&application, atoi(mots[0]), atoi(mots[1]), atoi(mots[2]));
            }
            break;
        }

        case CMD_SCORES:
        {
            char *mots[1];
            if (extraire_arguments(commande.arguments, mots, 1) == 1)
            {
                afficher_scores(&application, atoi(mots[0]));
            }
            break;
        }

        case CMD_CLASSEMENT:
        {
            char *mots[1];
            if (extraire_arguments(commande.arguments, mots, 1) == 1)
            {
                afficher_classement(&application, atoi(mots[0]));
            }
            break;
        }

        case CMD_COMPARAISON:
        {
            char *mots[2];
            if (extraire_arguments(commande.arguments, mots, 2) == 2)
            {
                afficher_comparaison(&application, atoi(mots[0]), atoi(mots[1]));
            }
            break;
        }

        case CMD_BILAN:
        {
            char *mots[1];
            if (extraire_arguments(commande.arguments, mots, 1) == 1)
            {
                afficher_bilan(&application, atoi(mots[0]));
            }
            break;
        }

        case CMD_AIDE:
        {
            afficher_aide();
            break;
        }

        case CMD_INCONNUE:
        default:
            printf("Commande inconnue : '%s'. Tapez AIDE pour la liste.\n", commande.nom);
            break;
        }
    }

    return 0;
}