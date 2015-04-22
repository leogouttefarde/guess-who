
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


bool lire_reponse();


#endif /* JEU_H */
