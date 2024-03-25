#include <stdio.h>
#include <stdlib.h>

int main() {

  // Ouvrir le fichier en lecture
  FILE *fichier = fopen("ressources/bdd_wordle.txt", "r");
  if (fichier == NULL) {
    printf("Erreur : impossible d'ouvrir le fichier bdd_wordle.txt\n");
    return 1;
  }

  // Déclarer une liste pour stocker les mots
  char **liste_mots = malloc(sizeof(char *) * 10000);

  // Lire chaque ligne du fichier
  char ligne[50];
  int i = 0;
  while (fgets(ligne, sizeof(ligne), fichier)) {
    // Supprimer le caractère '\n' en fin de ligne
    ligne[strcspn(ligne, "\n")] = '\0';

    // Allouer de la mémoire pour le mot
    liste_mots[i] = malloc(sizeof(char) * strlen(ligne) + 1);

    // Copier le mot dans la liste
    strcpy(liste_mots[i], ligne);

    i++;
  }

  // Fermer le fichier
  fclose(fichier);

  // Afficher le nombre de mots
  printf("Nombre de mots dans la base de données : %d\n", i);

  return 0;
}
