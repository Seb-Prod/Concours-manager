# Application de Gestion de Concours et de Scores

Ce projet est une application en langage C conçue de manière modulaire. Elle permet de gérer des participants, de créer des concours, d'enregistrer des points (gains), d'afficher des classements, des comparaisons entre concours ainsi que des bilans d'évolution des places.

---

## 📁 Architecture du Projet

Le code source est réparti en plusieurs modules fonctionnels, munis de gardes d'inclusion (`#ifndef`) et documentés via Doxygen :

* **`main.c`** : point d'entrée principal, initialise l'application et gère la boucle interactive.
* **`affichage.c` / `affichage.h`** : fonctions utilitaires d'affichage (aide globale, accord singulier/pluriel, nettoyage d'écran portable).
* **`saisie.c` / `saisie.h`** : lecture des entrées de l'utilisateur et extraction des arguments.
* **`commandes.c` / `commandes.h`** : analyse, identification et typage des commandes textuelles.
* **`participants.c` / `participants.h`** : gestion des inscriptions et du répertoire des participants.
* **`concours.c` / `concours.h`** : création et gestion des différents concours.
* **`scores.c` / `scores.h`** : enregistrement et consultation des scores par participant.
* **`classement.c` / `classement.h`** : calcul des classements, comparaisons de concours et bilans d'évolution des places.
* **`donnees.h`** : définition des structures de données globales (`Application`).
* **`tests/`** : fichiers de test d'intégration et scripts de validation automatique.

---

## 🚀 Compilation

Pour compiler l'ensemble des modules sous Linux, macOS ou WSL, avec les avertissements activés :

```bash
gcc -Wall -Wextra *.c -o programme
```

---

## 🧪 Exécution et Tests

### 1. Exécution interactive

Lancez l'exécutable directement pour interagir en console :

```bash
./programme
```

### 2. Test par redirection de fichier

Un scénario complet peut être joué via l'entrée standard :

```bash
./programme < tests/test_global.txt
```

### 3. Exécution avec écho des commandes (mise au point)

L'option de compilation `-DECHO_SAISIE` affiche le prompt et rappelle chaque commande lue (précédée de `> `). C'est utile pour relire une sortie, mais elle ajoute du texte au résultat : **ne pas l'utiliser pour comparer à un fichier de sortie attendu.**

```bash
gcc -Wall -Wextra -DECHO_SAISIE *.c -o programme && ./programme < tests/test_global.txt
```

### 4. Tests automatisés

Un script de test automatisé est disponible dans `tests/`. Donnez-lui les droits d'exécution avant de le lancer :

```bash
chmod +x tests/run_tests.sh
./tests/run_tests.sh
```

---

## 📖 Documentation (Doxygen)

Les fichiers sources (`.c`) et d'en-tête (`.h`) sont documentés au format Doxygen (`\brief`, `\param`, `\return`, etc.). La documentation HTML/LaTeX peut être générée si un fichier `Doxyfile` est présent à la racine :

```bash
doxygen Doxyfile
```