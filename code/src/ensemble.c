
#include "ensemble.h"
#include "common.h"


ensemble_t puissance(uint16_t numero_elt)
{
        ensemble_t puissance = 1;

        for (uint16_t i = 1; i <= numero_elt; ++i)
                puissance *= 2;

        return puissance;
}

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
        const uint8_t taille = sizeof(ensemble_t) * 8;
        uint8_t cardinal = 0;
        uint16_t puissance = 1;

        for (uint8_t i = 0; i < taille; ++i) {

                if (puissance & e)
                        ++cardinal;

                puissance *= 2;
        }

        return cardinal;
}

bool ensemble_appartient(ensemble_t e, uint16_t numero_elt)
{
        bool appartient = false;

        if (e & puissance(numero_elt))
                appartient = true;

        return appartient;
}

bool ensemble_inclu(ensemble_t e1, uint16_t e2)
{
        return (ensemble_intersection(e1, e2) == e2);
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
        *e |= puissance(numero_elt);
}

void ensemble_retirer_elt(ensemble_t *e, uint16_t numero_elt)
{
        *e &= ensemble_complementaire(puissance(numero_elt));
}

void ensemble_afficher(const char *msg, ensemble_t e)
{
        const uint8_t taille = sizeof(ensemble_t) * 8;
        uint16_t puissance = 1;

        printf("Ensemble :\n\n");
        printf("%s\n\n", msg);


        for (uint8_t i = 0; i < taille; ++i) {

                if (puissance & e)
                        printf("1");

                else
                        printf("0");

                puissance *= 2;
        }

        printf("\n\n\n");
}
