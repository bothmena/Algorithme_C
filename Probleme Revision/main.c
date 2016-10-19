// Created by bothmena on 18/10/16.

#include <stdio.h>
#include <math.h>
#include "main.h"

char *days[7] = {"lundi   ", "mardi   ", "mercredi", "jeudi   ", "vendredi", "samedi  ", "dimanche"};
const float PRIX_CHOCOLAT = 2.5;
const float PRIX_NOUGATINE = 3.2;
const float PRIX_PISTACHE = 3.8;

int main() {

    struct Day week[7];

    printf("Initialisation...\n");
    initialiser(week);
    printf("--------------------------\n\n");

    printf("Remplissage de la semaine...\n");
    vendre(week);
    printf("--------------------------\n\n");

    printf("Calcul de la recette...\n");
    calculerRecette(week);
    printf("--------------------------\n");

    printf("Selection Top: \n\n");
    afficherRecette(week);
    printf("--------------------------\n\n");

    printf("Selection Top: \n");
    selectionnerTop(week);
    printf("--------------------------\n\n");

    printf("Calcul de la moyenne...\n");
    float moy = calculerMoy(week);
    printf("la moyenne des prix de la semaine est: %f\n", moy);
    printf("--------------------------\n");

    printf("Calcul de l'ecart type...\n");
    float ecart = calculerEcartType(week, moy);
    printf("l'ecart type des prix de la semaine est: %f\n", ecart);
    printf("--------------------------\n");

    return 1;
}

void initialiser(struct Day week[7]) {

    int i;
    for (i = 0; i < 7; i++) {

        week[i] = (struct Day) {.name = days[i], .chocolat = 0, .nougatine = 0, .pistache = 0, .income = 0.0};
    }
}

void vendre(struct Day week[7]) {

    int jour = 0;
    printf("listes des commandes :\n");
    printf("\t1: vendre un gatteaux au chocolat.\n");
    printf("\t2: vendre un gatteaux au nougatine.\n");
    printf("\t3: vendre un gatteaux au pistache.\n");
    printf("\t0: passer à la prochaine journée.\n");
    while (jour < 7) {

        int action = -1;
        do {

            printf("[%s] votre choix: ", days[jour]);
            scanf("%d", &action);
            switch (action) {
                case 0:
                    break;
                case 1:
                    week[jour].chocolat++;
                    break;
                case 2:
                    week[jour].nougatine++;
                    break;
                case 3:
                    week[jour].pistache++;
                    break;
                default:
                    printf("mauvais choix! Réessayer.\n");
            }

        } while (action != 0);
        jour++;
    }
}

void afficherRecette(struct Day week[7]) {

    int jour = 0;
    printf("Jour    \tChocolat\tnougatine\tpistache\tRecette\n");
    while (jour < 7) {

        printf("%s\t%d           %d           %d           %f\n", week[jour].name, week[jour].chocolat,
               week[jour].nougatine, week[jour].pistache, week[jour].income);
        jour++;
    }
}

void calculerRecette(struct Day week[7]) {

    int jour = 0;
    while (jour < 7) {

        week[jour].income = week[jour].chocolat * PRIX_CHOCOLAT + week[jour].nougatine * PRIX_NOUGATINE
                            + week[jour].pistache * PRIX_PISTACHE;
        jour++;
    }
}

void selectionnerTop(struct Day week[7]) {

    int jour = 0, day = 0;
    printf("meilleur gout par jour: \n");
    while (jour < 7) {

        day = week[jour].income > week[day].income ? jour : day;
        printf("%s => ", week[jour].name);
        week[jour].chocolat * PRIX_CHOCOLAT > week[jour].nougatine * PRIX_NOUGATINE ?
                printf("Chocolat (%fDT)\n", week[jour].chocolat * PRIX_CHOCOLAT) :
                week[jour].nougatine * PRIX_NOUGATINE > week[jour].pistache * PRIX_PISTACHE ?
                        printf("Nougatine (%fDT)\n", week[jour].nougatine * PRIX_NOUGATINE) :
                        printf("Pistache (%fDT)\n", week[jour].pistache * PRIX_PISTACHE);
        jour++;
    }
    printf("meilleur jour du semaine: %s (%fDt)", week[day].name, week[day].income);

}

float calculerMoy(struct Day week[7]) {

    float moy = 0;
    int j = 0;
    while (j++ < 7)
        moy += week[j].income / 7;

    return moy;
}

float calculerEcartType(struct Day week[7], float moy) {

    float ecartType = 0;

    int i = 0;
    while (i++ < 7)
        ecartType += powf(moy * week[i].income, 2);

    return sqrtf(ecartType / 7);
}
