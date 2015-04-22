#ifndef SUSPECT_H
#define SUSPECT_H

#include "ensemble.h"

/* Suspect du jeu Qui est-ce. */
struct suspect {
        char *nom;
        ensemble_t attributs;
        struct suspect *suiv;
        struct suspect *prec;
};

/* Liste doublement chainée de suspects. */
struct liste_suspects {
        uint16_t nb_suspects;
        struct suspect *tete;
        struct suspect *queue;
};

/* Retourne un nouveau suspect initialisé en fonction des paramètres
 * nom et attributs. */
struct suspect *creer_suspect(const char *nom, ensemble_t attributs);

/* Créé une nouvelle liste de suspects, initialement vide. */
struct liste_suspects *creer_liste_suspects(void);

/* Détruit la liste de suspects passée en paramètre. */
void detruire_liste_suspects(struct liste_suspects **l);

/* Ajoute le suspect s en fin de la liste de suspects l. */
void ajouter_suspect(struct liste_suspects *l, struct suspect *s);

/* Retire le suspect s de la liste de suspects l. */
void retirer_suspect(struct liste_suspects *l, struct suspect *s);

/* Affiche les noms de tous les suspects de la liste l. */
void affiche_liste_suspects(struct liste_suspects *l);

#endif /* SUSPECT_H */
