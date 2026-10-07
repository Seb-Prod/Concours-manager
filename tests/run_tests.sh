#!/bin/bash
gcc -Wall -Wextra *.c -o programme

# Exécution
./programme < tests/input_test.txt > tests/output_brut.txt

# Nettoyage des séquences d'échappement ANSI (comme \033[2J) pour la comparaison
sed 's/\x1B\[[0-9;]*[JKmsu]//g' tests/output_brut.txt > tests/output_actuel.txt

if diff -u tests/expected_output.txt tests/output_actuel.txt; then
    echo "=== TOUS LES TESTS SONT PASSÉS AVEC SUCCÈS ==="
    exit 0
else
    echo "=== ÉCHEC DES TESTS : LA SORTIE DIFFÈRE ==="
    exit 1
fi