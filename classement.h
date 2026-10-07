#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include "donnees.h"

/**
 * \file classement.h
 * \brief Gestion des classements, comparaisons et bilans (déclarations et prototypes).
 */

/**
 * \brief Calcule le rang d'un participant dans un concours donné.
 * \details Le rang est défini comme 1 + le nombre de participants ayant un score 
 *          strictement supérieur. Les ex æquo obtiennent le même rang (ex: 1, 1, 3...).
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param p Indice du participant (compris entre 0 et nb_participants - 1).
 * \param c Indice du concours (compris entre 0 et nb_concours - 1, en tant qu'indice et non identifiant).
 * \return Le rang calculé du participant (à partir de 1).
 * 
 * \pre app != NULL
 * \pre p >= 0 && p < app->nb_participants
 * \pre c >= 0 && c < app->nb_concours
 */
int calculer_rang(const Application *app, int p, int c);

/**
 * \brief Affiche le classement complet d'un concours.
 * \details Affiche le nom du concours suivi des lignes de classement triées par ordre de score décroissant. 
 *          Si l'identifiant saisi est invalide, affiche "Identifiant incorrect".
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param id_concours Identifiant du concours saisi par l'utilisateur (à partir de 1).
 * 
 * \pre app != NULL
 */
void afficher_classement(const Application *app, int id_concours);

/**
 * \brief Compare les résultats de deux concours.
 * \details Affiche le ratio et le pourcentage de progression d'un concours à l'autre 
 *          pour les participants concernés. Gère les erreurs d'identifiants, 
 *          l'absence de participants ou l'incompatibilité des concours.
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param id_concours1 Identifiant du premier concours (base, à partir de 1).
 * \param id_concours2 Identifiant du second concours (comparé, à partir de 1).
 * 
 * \pre app != NULL
 */
void afficher_comparaison(const Application *app, int id_concours1, int id_concours2);

/**
 * \brief Affiche le classement avec l'évolution des places depuis le dernier bilan.
 * \details Affiche les lignes de classement incluant l'écart de places, puis mémorise 
 *          les rangs actuels comme nouvelle référence pour le prochain bilan.
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param id_concours Identifiant du concours (à partir de 1).
 * 
 * \pre app != NULL
 */
void afficher_bilan(Application *app, int id_concours);

#endif