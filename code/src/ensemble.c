
/**
 * Fichier : ensemble.c
 * Description : Gestion des ensembles
 * Auteur : Léo Gouttefarde
 * Date : 23/04/2015
 */

#include "ensemble.h"
#include "common.h"


ensemble_t ensemble_vide(void)
{
        return 0;
}

ensemble_t ensemble_plein(void)
{
        return ensemble_complementaire(ensemble_vide());
}

uint16_t ensemble_cardinal(ensemble_t e)
{
        uint8_t cardinal = 0;
        uint16_t bit = 1;

        /* Comptage du nombre de bits à 1 */
        for (uint8_t i = 0; i < 16; ++i) {

                if (bit & e)
                        ++cardinal;

                bit <<= 1;
        }

        return cardinal;
}

bool ensemble_appartient(ensemble_t e, uint16_t numero_elt)
{
        bool appartient = false;

        /* On vérifie si le bit correspondant est à 1 */
        if (e & (1 << numero_elt))
                appartient = true;

        return appartient;
}

ensemble_t ensemble_union(ensemble_t e1, ensemble_t e2)
{
        return (e1 | e2);
}

ensemble_t ensemble_intersection(ensemble_t e1, ensemble_t e2)
{
        return (e1 & e2);
}

ensemble_t ensemble_complementaire(ensemble_t e)
{
        return (~e);
}

void ensemble_ajouter_elt(ensemble_t *e, uint16_t numero_elt)
{
        *e |= (1 << numero_elt);
}

void ensemble_retirer_elt(ensemble_t *e, uint16_t numero_elt)
{
        *e &= ensemble_complementaire(1 << numero_elt);
}

void ensemble_afficher(const char *msg, ensemble_t e)
{
        uint16_t bit = 0x8000;

        printf("Ensemble : %s\n", msg);

        do {
                if (bit & e)
                        putchar('1');

                else
                        putchar('0');

        } while (bit >>= 1);

        printf("\n\n");
}
