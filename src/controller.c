/*
 * controller.c
 *
 *  Created on: 9 avr. 2021
 *      Author: tim04
 */

#include "controller.h"

#include <stdlib.h>
#include <assert.h>

ControllerOXO *create_controller(struct view_t *p_view, ModelOXO *p_model){
	assert(p_view != NULL && p_model != NULL);

	ControllerOXO *l_controller = malloc(sizeof(ControllerOXO));

	if(l_controller == NULL)
		return NULL;

	l_controller->s_view = p_view;
	l_controller->s_model = p_model;

	l_controller->s_addButton = NULL;
	l_controller->s_newGame = NULL;

	return(l_controller);
}

void click_grid(GtkWidget *p_widget, ModelOXO *p_model, gpointer p_data){
	assert(p_model != NULL && p_widget != NULL && p_data != NULL);

	ControllerOXO *l_controller = (ControllerOXO *)p_data;

	add_action(l_controller->s_model);
	update(l_controller->s_view);
}