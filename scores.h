#ifndef SCORES_H
#define SCORES_H

#include "donnees.h"

/**
 * \file scores.h
 * \brief Gestion de l'enregistrement des gains et de l'affichage des scores (déclarations et prototypes).
 */

/**
 * \brief Ajoute des points au score d'un participant dans un concours et affiche le résultat.
 * \details Vérifie successivement la validité de l'identifiant du participant, de celui du concours, 
 *          puis du nombre de points. Affiche un message d'erreur spécifique en cas de non-conformité, 
 *          ou "Gain enregistre" en cas de succès.
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param id_participant Identifiant saisi du participant (à partir de 1).
 * \param id_concours Identifiant saisi du concours (à partir de 1).
 * \param points Nombre de points à ajouter (doit être strictement positif).
 * 
 * \pre app != NULL
 */
void enregistrer_gain(Application *app, int id_participant, int id_concours, int points);

/**
 * \brief Affiche les scores de tous les concours pour un participant donné.
 * \details Affiche d'abord le prénom et le nom du participant, puis la liste de ses concours 
 *          ayant un score non nul (par identifiant de concours croissant). 
 *          Si aucun gain n'est enregistré, affiche "Aucun gain". 
 *          Si l'identifiant du participant est invalide, affiche "Identifiant incorrect".
 * 
 * \param app Pointeur vers la structure principale de l'application (non NULL).
 * \param id_participant Identifiant saisi du participant (à partir de 1).
 * 
 * \pre app != NULL
 */
void afficher_scores(const Application *app, int id_participant);

#endif