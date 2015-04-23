
/**
 * Fichier : jeu.c
 * Description : Programme principal du jeu qui-est-ce
 * Auteur : Léo Gouttefarde
 * Date : 23/04/2015
 */

#include "jeu.h"


/* Jeu "Qui-est-ce ?" */
int main(void)
{
        struct liste_suspects *liste = NULL;
        uint8_t question;
        uint8_t nb_quests = 14;
        ensemble_t questions = ensemble_vide();
        ensemble_t indices = ensemble_vide();
        const char *mess_questions[] = QUESTIONS;
        const ensemble_t masques[] = MASQUES;
        struct suspect *suspect, *suiv;

        srand(time(NULL));

        /* Création de la listes des suspects du jeu qui-est-ce */
        liste = creer_liste_suspects();
        ajout_suspects(liste);


        printf("\033[37;1mQui-est-ce ?\033[0m\n\n");

        do {
                /* Tirage aléatoire d'une question */
                do {
                        question = rand() % nb_quests;
                } while (ensemble_appartient(questions, question));


                /* Interrogation de l'utilisateur */
                printf("%s ? (o/n) ", mess_questions[question]);
                ensemble_ajouter_elt(&questions, question);


                /* Lecture de la réponse */
                bool reponse = lire_reponse();


                /* Traitement de la réponse */
                if (reponse) {
                        ensemble_ajouter_elt(&indices, question);

                        /* Suppression des questions inutiles
                         * (tout masque contenant l'indice obtenu) */
                        for (uint8_t i = 0; i < SIZE(masques); ++i) {

                                if (ensemble_appartient(masques[i], question)) {
                                        questions = ensemble_union(masques[i], questions);
                                        break;
                                }
                        }
                }
                else {
                        /* S'il ne reste plus qu'une possibilité
                         * dans un masque, on en déduit un nouvel indice */
                        deduction_indice(question, &questions, &indices);
                }


                suspect = liste->tete;

                /* Retrait des suspects innocents de la liste */
                while (suspect != NULL) {

                        suiv = suspect->suiv;

                        /* Si une personne ne correspond pas à la description,
                         * on la retire des suspects */
                        if (!(ensemble_intersection(suspect->attributs, questions) == indices)) {
                                retirer_suspect(liste, suspect);
                        }

                        suspect = suiv;
                }


        /* On arrête de poser des questions quand elles ont toutes été posées
         * ou qu'on a un coupable */
        } while ((ensemble_cardinal(questions) < nb_quests) && (liste->nb_suspects > 1));


        /* Résultat de la partie */
        if (liste->nb_suspects == 1)
                printf("\033[32;1m\n%s est coupable.\033[0m\n", liste->tete->nom);

        else if (liste->nb_suspects > 1) {
                printf("\033[37;1m\nPlusieurs suspects mais pas de coupable identifiable :\033[0m\n");
                affiche_liste_suspects(liste);
        }
        else
                printf("\033[37;1m\nPas de coupable.\033[0m\n");


        /* Libération de la liste et des suspects */
        detruire_liste_suspects(&liste);


        return EXIT_SUCCESS;
}

/* Ajoute tous les suspects du jeu */
void ajout_suspects(struct liste_suspects *liste)
{
        const char *suspects[] = NOMS_SUSPECTS;
        const ensemble_t attributs[] = ATTRIBUTS_SUSPECTS;
        struct suspect *suspect = NULL;

        /* Création puis ajout de l'ensemble des suspects */
        for (uint8_t i = 0; i < SIZE(suspects); ++i) {
                suspect = creer_suspect(suspects[i], attributs[i]);
                ajouter_suspect(liste, suspect);
        }
}

/* Déduit un indice à partir de réponses négatives */
void deduction_indice(uint8_t question, ensemble_t *questions, ensemble_t *indices)
{
        const ensemble_t masques[] = MASQUES;

        for (uint8_t i = 0; i < SIZE(masques); ++i) {
                ensemble_t masque = masques[i];

                /* Recherche d'un masque qui contienne la question */
                if (ensemble_appartient(masque, question)) {
                        ensemble_t connus = ensemble_intersection(masque, *questions);

                        const uint8_t nb_masque = ensemble_cardinal(masque);
                        const uint8_t nb_connus = ensemble_cardinal(connus);

                        /* S'il ne reste plus qu'une possibilité
                         * dans un masque, on en déduit un nouvel indice */
                        if (nb_connus == (nb_masque - 1)) {
                                ensemble_t complementaire = ensemble_complementaire(connus);
                                ensemble_t indice = ensemble_intersection(masque, complementaire);

                                /* Mémorisation de l'indice déduit */
                                *indices = ensemble_union(*indices, indice);
                                *questions = ensemble_union(*questions, indice);
                        }

                        break;
                }
        }
}

/* Lit la réponse de l'utilisateur et
 * renvoie oui ou non */
bool lire_reponse()
{
        bool reponse, erreur;
        char entree, buf;

        do {
                erreur = false;

                /* On vide le flux d'entrée après lecture
                 * du premier caractère */
                entree = (buf = getchar());
                while (buf != '\n' && buf != EOF && (buf = getchar()));

                /* Détection de la réponse */
                switch (tolower(entree)) {
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
                                printf("Erreur de frappe. Répondez par oui ou par non (o/n) : ");
                }

        /* Gestion des erreurs de frappe */
        } while (erreur);

        return reponse;
}
