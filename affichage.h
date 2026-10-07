#ifndef AFFICHAGE_H
#define AFFICHAGE_H

/**
 * \file affichage.h
 * \brief Gestion des fonctions d'affichage, de l'interface et de la mise en forme textuelle.
 */

/**
 * \brief Sélectionne la forme textuelle appropriée (singulier ou pluriel) selon un nombre.
 * \details Retourne le singulier si \p n vaut 0 ou 1, et le pluriel si \p n est supérieur ou égal à 2.
 * 
 * \param n Nombre entier servant de condition pour l'accord.
 * \param singulier Chaîne de caractères à retourner si \p n vaut 0 ou 1.
 * \param pluriel Chaîne de caractères à retourner si \p n est supérieur ou égal à 2.
 * \return Un pointeur vers la chaîne de caractères choisie.
 */
const char *accord(int n, const char *singulier, const char *pluriel);

/**
 * \brief Efface l'écran du terminal de manière portable.
 * \details Utilise la commande système "cls" sous Windows et "clear" sous UNIX/Linux/macOS.
 */
void effacer_ecran(void);

/**
 * \brief Affiche l'aide globale listant l'ensemble des commandes disponibles.
 */
void afficher_aide(void);

#endif