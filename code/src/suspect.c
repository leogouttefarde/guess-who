
#include "suspect.h"
#include "common.h"


struct suspect *creer_suspect(const char *name, ensemble_t attributs)
{
        struct suspect *suspect = NULL;

        if (name != NULL) {
                suspect = calloc(1, sizeof(struct suspect));

                if (suspect != NULL) {
                        suspect->nom = (char*)name;
                        suspect->attributs = attributs;
                }
        }

        return suspect;
}

struct liste_suspects *creer_liste_suspects(void)
{
        struct liste_suspects *liste = calloc(1, sizeof(struct liste_suspects));

        return liste;
}

void detruire_liste_suspects(struct liste_suspects **l)
{
        if (l != NULL && (*l) != NULL) {
                struct suspect *suspect = (*l)->tete;
                struct suspect *suiv;

                /* Libération de tous les suspects */
                while (suspect) {
                        // Si allocation dynamique du nom
                        // SAFE_FREE(suspect->nom);

                        suiv = suspect->suiv;
                        SAFE_FREE(suspect);
                        suspect = suiv;
                }

                SAFE_FREE(*l);
        }
}

void ajouter_suspect(struct liste_suspects *liste, struct suspect *suspect)
{
        if (liste != NULL && suspect != NULL) {
                suspect->suiv = NULL;

                /* S'il y a une queue, on met le suspect après */
                if (liste->queue != NULL) {
                        suspect->prec = liste->queue;
                        liste->queue->suiv = suspect;
                        liste->queue = suspect;
                }

                /* S'il n'y en a pas, c'est le seul suspect */
                else {
                        liste->tete = suspect;
                        liste->queue = suspect;
                }

                ++liste->nb_suspects;
        }
}

void retirer_suspect(struct liste_suspects *liste, struct suspect *suspect)
{
        if (liste != NULL && suspect != NULL) {
                struct suspect *suiv = suspect->suiv;
                struct suspect *prec = suspect->prec;


                // Elément normal de la liste
                if (prec && suiv) {
                        prec->suiv = suiv;
                        suiv->prec = prec;
                }

                // Tete
                else if (!prec && suiv) {

                        // On vérifie si c'est bien la tete
                        if (liste->tete == suspect) {
                                suiv->prec = prec;
                                liste->tete = suiv;
                        }
                }

                // Queue
                else if (prec && !suiv) {

                        // On vérifie si c'est bien la queue
                        if (liste->queue == suspect) {
                                prec->suiv = NULL;
                                liste->queue = prec;
                        }
                }

                // Ni tete ni queue : élément unique
                else {
                        liste->tete = NULL;
                        liste->queue = NULL;
                }

                // S'il n'y a qu'un élément,
                // on s'assure qu'il ne pointe nulle part
                if (liste->tete && (liste->tete == liste->queue)) {
                        liste->tete->suiv = NULL;
                        liste->tete->prec = NULL;
                }

                // Destruction du suspect après retrait
                SAFE_FREE(suspect);


                if (liste->nb_suspects > 0)
                        --liste->nb_suspects;
        }
}

void affiche_liste_suspects(struct liste_suspects *l)
{
        if (l != NULL) {
                struct suspect *suspect = l->tete;
                struct suspect *suiv;

                printf("Liste de %d suspects :\n\n", l->nb_suspects);

                while (suspect) {
                        suiv = suspect->suiv;

                        if (suspect->nom != NULL)
                                printf("%s\n", suspect->nom);

                        else
                                printf("Suspect sans nom");

                        suspect = suiv;
                }
        }
}
