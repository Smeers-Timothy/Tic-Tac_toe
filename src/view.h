/**
 * @file view.h
 * @brief Vue (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date Created on: 9 avr. 2021
 */
#ifndef VIEW_H_
#define VIEW_H_

#include <gtk/gtk.h>

#include "controller.h"

/**
 * @struct vue_t
 * @brief Implémentation de la vue du OXO en type opaque
 */
typedef struct view_t ViewOXO;

/**
 * @fn ViewOXO create_OXO_vue*(ModelOXO*)
 * @brief Crée une vue pour le OXO en fonction d'un certain modèle.
 *
 * @pre p_model != NULL
 * @post Une vue est créée
 * @param s_model le modèle du OXO à prendre en compte.
 * @return ViewOXO *, un pointeur sur une nouvelle vue.
 *         NULL en cas d'erreur.
 */
ViewOXO *create_view(ModelOXO *p_model);

/**
 * @fn void destroy_window(GtkWidget*, gpointer)
 * @brief Détruit la fenetre de jeux et tout ses enfant
 *
 * @pre p_widget != NULL
 * @post p_widget == NULL
 * @param p_widget un pointeur sur la fenetre GtkWidget
 * @param p_data pointeur vers le widget
 */
void destroy_window(GtkWidget *p_widget, gpointer p_data);

/**
 * @fn GtkWidget create_window*()
 * @brief Crée et initalise la fenetre
 *
 * @pre /
 * @post la fenetre est créée
 * @return GtkWidget *l_window un pointeur sur la fenetre
 * 			NULL en cas d'erreur.
 */
GtkWidget *create_window();

/**
 * @fn GtkButton load_image_button*()
 * @brief Permet de chargé une image vide et l'atribue dans un bouton
 *
 * @pre /
 * @post un bouton GtkWidget est créé avec une image par defaut
 * @return GtkWidget *l_button un pointeur sur un bouton
 * 			NULL en cas d'erreur.
 */
GtkButton *load_image_button();

/**
 * @fn void create_table(ViewOXO*, GtkWidget**)
 * @brief Permet de créé une table comprenant les boutons
 *
 * @pre p_view != NULL && p_button > 0
 * @post la table est créé avec n boutton
 * @param p_view un pointeur sur la vue du OXO à prendre en compte
 * @param p_button un tableau de GtkWidget contenant les boutons
 */
void create_table(ViewOXO *p_view, GtkWidget **p_button);

/**
 * @fn void create_principal_box(ViewOXO*)
 * @brief Création de la box principale comprenant tout les boutons
 *
 * @pre p_view != NULL
 * @post tout les bouton sont créé et placer dans la fenetre
 * @param p_view un pointeur sur la vue du OXO à prendre en compte
 */
void create_principal_box(ViewOXO *p_view);

/**
 * @fn void create_new_game_button(ViewOXO*)
 * @brief Création du bouton de nouvelle artie
 *
 * @pre p_view != NULL
 * @post le bouton nouvelle partie est créé
 * @param p_view un pointeur sur la vue du OXO à prendre en compte
 */
void create_new_game_button(ViewOXO *p_view);

/**
 * @fn void draw_window(ViewOXO*, GtkWidget*)
 * @brief Permet de dessiner la fenetre principale
 *
 * @pre p_view != NULL && p_window != NULL
 * @post La fenetre principale s'affiche à l'écran
 * @param p_view un pointeur sur la vue du OXO à prendre en compte
 * @param p_window La fenetre à dessiner
 */
void draw_window(ViewOXO *p_view, GtkWidget *p_window);

#endif /* VIEW_H_ */
