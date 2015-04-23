
#ifndef JEU_H
#define JEU_H

#include "ensemble.h"
#include "suspect.h"
#include "common.h"


#define SIZE(n) (sizeof(n) / sizeof(n[0]))

#define NOMS_SUSPECTS {\
        "André",\
        "Philippe",\
        "Jean-Louis",\
        "François",\
        "Robert",\
        "Carole",\
        "Mélanie",\
        "Fabien",\
        "Patricia",\
        "Baptiste",\
        "Sébastien",\
        "Olivier",\
        "Nicolas",\
        "Luc",\
        "Simon",\
        "Maxime",\
        "Cédric",\
        "Pierre",\
        "Martin",\
        "Elodie",\
        "Victor",\
        "Georges",\
        "Thierry",\
        "Céline"\
        }

#define ATTRIBUTS_SUSPECTS {\
        HOMME | COIFFURE_CHAUVE | CHEVEUX_BLANCS | LUNETTES ,\
        HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | LUNETTES ,\
        HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | LUNETTES ,\
        HOMME | COIFFURE_COURT | CHEVEUX_BLANCS | CHAPEAU ,\
        HOMME | BARBE | COIFFURE_COURT | CHEVEUX_NOIRS,\
        FEMME | COIFFURE_COURT | CHEVEUX_ROUX | LUNETTES | CHAPEAU,\
        FEMME | COIFFURE_LONG | CHEVEUX_BLONDS,\
        HOMME | MOUSTACHE | COIFFURE_LONG | CHEVEUX_ROUX,\
        FEMME | COIFFURE_LONG | CHEVEUX_BLANCS,\
        HOMME | MOUSTACHE | BARBE | COIFFURE_CHAUVE | CHEVEUX_CHATAINS,\
        HOMME | COIFFURE_COURT | CHEVEUX_ROUX,\
        HOMME | MOUSTACHE | COIFFURE_COURT | CHEVEUX_CHATAINS,\
        HOMME | COIFFURE_CHAUVE | CHEVEUX_ROUX,\
        HOMME | BARBE | COIFFURE_COURT | CHEVEUX_BLONDS,\
        HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS | CHAPEAU,\
        HOMME | MOUSTACHE | COIFFURE_COURT | CHEVEUX_NOIRS,\
        HOMME | COIFFURE_CHAUVE | CHEVEUX_NOIRS | LUNETTES,\
        HOMME | COIFFURE_COURT | CHEVEUX_CHATAINS,\
        HOMME | COIFFURE_COURT | CHEVEUX_BLANCS,\
        FEMME | COIFFURE_LONG | CHEVEUX_CHATAINS | CHAPEAU,\
        HOMME | BARBE | COIFFURE_CHAUVE | CHEVEUX_ROUX,\
        HOMME | COIFFURE_COURT | CHEVEUX_BLONDS | CHAPEAU,\
        HOMME | MOUSTACHE | COIFFURE_COURT | CHEVEUX_BLONDS,\
        FEMME | COIFFURE_COURT | CHEVEUX_NOIRS\
        }

#define MASQUES {\
        GENRE,\
        COIFFURE,\
        CHEVEUX\
        }


#define QUESTIONS {\
        "Le coupable est-il un homme",\
        "Le coupable est-il une femme",\
        "Le coupable a-t-il une moustache",\
        "Le coupable a-t-il une barbe",\
        "Le coupable est-t-il plutôt chauve",\
        "Le coupable a-t-il les cheveux longs",\
        "Le coupable a-t-il les cheveux courts",\
        "Le coupable a-t-il les cheveux noirs",\
        "Le coupable a-t-il les cheveux chatains",\
        "Le coupable a-t-il les cheveux blancs",\
        "Le coupable a-t-il les cheveux roux",\
        "Le coupable a-t-il les cheveux blonds",\
        "Le coupable porte-t-il des lunettes",\
        "Le coupable a-t-il un chapeau"\
        }


/* Ajoute tous les suspects du jeu */
void ajout_suspects(struct liste_suspects *liste);

/* Déduit un indice à partir de réponses négatives */
void deduction_indice(uint8_t question, ensemble_t *questions, ensemble_t *indices);

/* Lit la réponse de l'utilisateur et
   renvoie oui ou non */
bool lire_reponse();


#endif /* JEU_H */
