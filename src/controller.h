/*
 * controller.h
 *
 *  Created on: 9 avr. 2021
 *      Author: tim04
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <gtk/gtk.h>

#include "model.h"
#include "view.h"

/**
 * @file controller.h
 * @brief Contrôleur (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date 10/04/2021
 */

/**
 * @struct controller_t
 * @brief Implémentation du contrôleur pour le OXO.
 *
 */
typedef struct controller_t{
	struct view_t *s_view; /**< vue du OXO */
	ModelOXO *s_model; /**< modèle du OXO*/
}ControllerOXO;

/**
 * @fn ControllerOXO create_controller*(struct view_t*, ModelOXO*)
 * @brief Crée un contrôleur pour le OXO en fonction d'une vue et d'un modèle.
 *
 * @pre p_view != NULL && p_model != NULL
 * @post /
 * @param p_view la vue du OXO à prendre en compte.
 * @param p_model le modèle du OXO à prendre en compte.
 * @return ControllerOXO *, un pointeur vers le contrôleur du OXO.
 *         NULL en cas d'erreur.
 */
ControllerOXO *create_controller(struct view_t *p_view, ModelOXO *p_model);

/**
 * @fn void click_grid(GtkWidget*, ModelOXO*, gpointer)
 * @brief Signal pour un click sur la grille
 *
 * @pre p_model != NULL && p_widget != NULL && p_data != NULL
 * @post
 * @param p_widget le widget en cause
 * @param p_model le modèle du OXO à prendre en compte.
 * @param p_data pointeur vers le controller
 */
void click_grid(GtkWidget *p_widget, gpointer p_data);

/**
 * @fn void click_new_game(GtkWidget*, gpointer)
 * @brief Signal pour un click sur le bouton de nouvelle partie
 *
 * @pre /
 * @post /
 * @param p_widget le widget en cause
 * @param p_data pointeur vers le controller
 */
void click_new_game(GtkWidget *p_widget, gpointer p_data);

#endif /* CONTROLLER_H_ */
