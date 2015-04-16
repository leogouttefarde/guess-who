#include "ensemble.h"

ensemble_t ensemble_vide(void) {
        return 0;
}

ensemble_t ensemble_plein(void) {
        return 0;
}

uint16_t ensemble_cardinal(ensemble_t e) {
        return 0;
}

bool ensemble_appartient(ensemble_t e, uint16_t numero_elt) {
        return false;
}

ensemble_t ensemble_union(ensemble_t e1, ensemble_t e2) {
        return 0;
}

ensemble_t ensemble_intersection(ensemble_t e1, ensemble_t e2) {
        return 0;
}

ensemble_t ensemble_complementaire(ensemble_t e) {
        return 0;
}

void ensemble_ajouter_elt(ensemble_t *e, uint16_t numero_elt) {
}

void ensemble_retirer_elt(ensemble_t *e, uint16_t numero_elt) {
}

void ensemble_afficher(const char *msg, ensemble_t e) {
}
