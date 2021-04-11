/*
 * view.h
 *
 *  Created on: 9 avr. 2021
 *      Author: tim04
 */

#ifndef VIEW_H_
#define VIEW_H_

#include <gtk/gtk.h>

#include "controller.h"

/**
 * @file view.h
 * @brief Vue (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date 10/04/2021
 */

/**
 * @struct vue_t
 * @brief Implémentation de la vue du OXO en type opaque
 *
 *
 */
typedef struct view_t ViewOXO;

/**
 * @fn ViewOXO create_OXO_vue*(ModelOXO*)
 * @brief Crée une vue pour le OXO en fonction d'un certain modèle.
 *
 * @pre p_model != NULL
 * @post /
 * @param s_model le modèle du OXO à prendre en compte.
 * @return ViewOXO *, un pointeur sur une nouvelle vue.
 *         NULL en cas d'erreur.
 */
ViewOXO *create_view(ModelOXO *p_model);

/**
 * @fn void update(ViewOXO*)
 * @brief Redessine la vue suite à un changement.
 *
 * @pre /
 * @post /
 * @param p_view la vue à redessiner
 */
void update(ViewOXO *p_view);

/**
 * @fn void destroy_window(GtkWidget*, gpointer)
 * @brief
 *
 * @pre
 * @post
 * @param pF
 * @param data
 */
void destroy_window(GtkWidget *pF, gpointer data);

/**
 * @fn GtkWidget create_window*()
 * @brief
 *
 * @pre
 * @post
 * @return
 */
GtkWidget *create_window();

/**
 * @fn GtkButton load_image_button*()
 * @brief
 *
 * @pre
 * @post
 * @return
 */
GtkButton *load_image_button();

/**
 * @fn void create_table(GtkWidget*, GtkWidget*)
 * @brief
 *
 * @pre
 * @post
 * @param p_table
 */
void create_table(ViewOXO *p_view, GtkWidget **p_button);

/**
 * @fn void create_principal_box(GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*)
 * @brief
 *
 * @pre
 * @post
 * @param p_new_game_button
 * @param p_verticalBox
 * @param p_horizontalBox
 * @param p_table
 */
void create_principal_box(ViewOXO *p_view);

/**
 * @fn void draw_window(GtkWidget*, GtkWidget*)
 * @brief
 *
 * @pre
 * @post
 * @param p_window
 * @param p_verticalBox
 */
void draw_window(ViewOXO *p_view, GtkWidget *p_window);

/**
 * @fn void create_new_game_button(ViewOXO*)
 * @brief
 *
 * @pre
 * @post
 * @param p_view
 */
void create_new_game_button(ViewOXO *p_view);


#endif /* VIEW_H_ */
