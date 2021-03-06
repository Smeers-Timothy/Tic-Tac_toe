/**
 * @file controller.h
 * @brief Contrôleur (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date Created on: 9 avr. 2021
 */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <gtk/gtk.h>

#include "model.h"
#include "view.h"

/**
 * @struct controller_t
 * @brief Implémentation du contrôleur pour le OXO.
 *
 */
typedef struct controller_t{
	struct view_t *s_view; /**< vue du OXO */
	ModelOXO *s_model; /**< modèle du OXO*/
	unsigned int s_number; /**< Le numéro de la case selectionné */
}ControllerOXO;

/**
 * @fn ControllerOXO create_controller*(struct view_t*, ModelOXO*)
 * @brief Crée un contrôleur pour le OXO en fonction d'une vue et d'un modèle.
 *
 * @pre p_view != NULL && p_model != NULL
 * @post Un controller est créé
 * @param p_view Un pointeur sur la structure de la vue du OXO à prendre en compte.
 * @param p_model Un pointeur sur le modèle à prendre en compte
 * @return ControllerOXO *l_controller n pointeur sur le controller à prendre en compte
 * 			NULL en cas d'erreur.
 */
ControllerOXO *create_controller(struct view_t *p_view, ModelOXO *p_model);

/**
 * @fn void click_grid(GtkWidget*, gpointer)
 * @brief Signal pour un click sur un bouton de la table
 *
 * @pre p_widget != NULL && p_data != NULL
 * @post /
 * @param p_widget L'instance à connecté
 * @param p_data données à transmettre aux appels @c_handler.
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
