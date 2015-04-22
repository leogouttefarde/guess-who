
#include "jeu.h"


int main(void)
{
        const char *masques[] = MASQUES;
        const char *suspects[] = NOMS_SUSPECTS;
        const ensemble_t attributs[] = ATTRIBUTS_SUSPECTS;
        struct liste_suspects *liste = NULL;
        struct suspect *suspect = NULL;

        srand(time(NULL));

        liste = creer_liste_suspects();

        for (uint8_t i = 0; i < SIZE(suspects); ++i) {
                suspect = creer_suspect(suspects[i], attributs[i]);
                ajouter_suspect(liste, suspect);
        }


        const ensemble_t plein = ensemble_plein();
        ensemble_t questions = ensemble_vide();
        ensemble_t indices = ensemble_vide();
        bool fin;
        uint8_t nb_quests = 14;

        do {
                int numero_elt;
                do {
                        numero_elt = rand() % nb_quests;
                } while (ensemble_appartient(questions, numero_elt));

                printf("Est que le suspect a %d ? (o/n) ", numero_elt);

                bool reponse = lire_reponse();


                ensemble_ajouter_elt(&questions, numero_elt);


                if (reponse == true) {
                        ensemble_ajouter_elt(&indices, numero_elt);


                        /* Suppression des questions inutiles
                           (tout masque conteneur de l'indice) */
                        for (int8_t i = 0; i < SIZE(masques); ++i) {

                                if (ensemble_appartient(masques[i], numero_elt)) {
                                        questions = ensemble_union(masques[i], questions);
                                        break;
                                }
                        }
                }
                else {
                        /* Si plus qu'une possibilité dans un masque, on en déduit l'indice */
                        for (int8_t i = 0; i < SIZE(masques); ++i) {

                                ensemble_t masque = masques[i];
                                if (ensemble_appartient(masque, numero_elt)) {
                                        ensemble_t connus = ensemble_intersection(masque, questions);
                                        uint8_t nb_masque = ensemble_cardinal(masque);
                                        uint8_t nb_connus = ensemble_cardinal(connus);

                                        if (nb_connus == (nb_masque - 1)) {
                                                ensemble_t complementaire = ensemble_complementaire(connus);
                                                ensemble_t indice = ensemble_intersection(masque, complementaire);

                                                indices = ensemble_union(indices, indice);
                                        }

                                        break;
                                }
                        }
                }



                // Retrait des suspects innocents de la liste
                struct suspect *suspect = liste->tete;
                struct suspect *suiv;

                while (suspect) {
                        suiv = suspect->suiv;

                        if (!ensemble_inclu(suspect->attributs, indices)) {
                                retirer_suspect(liste, suspect);
                        }

                        suspect = suiv;
                }


        } while ((ensemble_cardinal(questions) < nb_quests) && (liste->nb_suspects > 1));



        if (liste->nb_suspects == 1) {

                printf("Le coupable est : %s\n", liste->tete->nom);
        }
        else if (liste->nb_suspects > 1) {

                printf("Plusieurs suspects mais aucun coupable identifiable.\n");
                affiche_liste_suspects(liste);
        }
        else {
                printf("Pas de coupable.\n");
        }


        detruire_liste_suspects(&liste);


        return EXIT_SUCCESS;
}

bool lire_reponse()
{
        bool reponse, erreur;

        char car, buf;

        do {
                erreur = false;

                car = (buf = getchar());
                while (buf != '\n' && buf != EOF && (buf = getchar()));


                char min = tolower(car);

                switch (min) {
                        case 'o':
                        case 'y':
                        case '1':
                                reponse = true;
                                break;

                        case 'n':
                        case '0':
                                reponse = false;
                                break;

                        default:
                                erreur = true;
                                printf("Erreur de frappe. Répondez par 'o' ou 'n' (o/n) : ");
                }

        } while (erreur);

        return reponse;
}
