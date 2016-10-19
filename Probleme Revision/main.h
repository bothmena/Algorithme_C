//
// Created by bothmena on 18/10/16.
//

#ifndef PROBLEME_REVISION_MAIN_H
#define PROBLEME_REVISION_MAIN_H

// Structres
struct Day {
    char *name;
    int chocolat;
    int nougatine;
    int pistache;
    float income;
};

//Functions

/**
 * permet d'initialiser la matrice de vente matV et le tableau des prix tabP à 0.
 *
 * @param week
 */
void initialiser( struct Day week[7] );

/**
 * permet de vendre un gâteau de type type au jour j passés en paramètres de la fonction
 *
 * @param week
 */
void vendre( struct Day week[7] );

/**
 * permet de remplir le tableau recette tabP à partir de la matrice de ventes MatV.
 * Sachant que les prix de ventes des gâteaux sont ainsi ( chocolat 2.5D,
 * nougatine 3.2D et pistache 3.8D)
 *
 * @param week
 */
void calculerRecette ( struct Day week[7] );

/**
 * permet d'afficher pour un jour donné, la recette et la quantité de gâteaux
 * vendue pour chaque type.
 *
 * @param week
 */
void afficherRecette( struct Day week[7] );

/**
 * permet de retourner le type et le nombre de vente du gâteau le plus vendu de la semaine.
 *
 * @param week
 */
void selectionnerTop( struct Day week[7] );

/**
 * permet de retourner la moyenne des prixsur la semaine.
 *
 * @param week
 */
float calculerMoy( struct Day week[7] );

/**
 * permet de retourner l’écart type des prix sur la semaine.
 *
 * @param tabP
 * @param moy
 * @return
 */
float calculerEcartType( struct Day week[7], float moy );

#endif //PROBLEME_REVISION_MAIN_H
