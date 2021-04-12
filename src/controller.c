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

	if(l_controller == NULL){
		printf("Erreur d'allocation de mémoire !\n");
		return(NULL);
	}

	l_controller->s_view = p_view;
	l_controller->s_model = p_model;

	return(l_controller);
}

void click_grid(GtkWidget *p_widget, gpointer p_data){
	assert(p_widget != NULL && p_data != NULL);

	ControllerOXO *l_controller = (ControllerOXO *)p_data;

	gpointer l_id = g_object_get_data(G_OBJECT(p_widget), "button_id");
	gpointer l_number = g_object_get_data(G_OBJECT(p_widget), "position");
	add_action(l_controller->s_model, l_number, l_id);
}

void click_new_game(GtkWidget *p_widget, gpointer p_data){
	assert(p_widget != NULL && p_data != NULL);

	ModelOXO *l_model = (ModelOXO *)p_data;
	gpointer l_id;
	gpointer l_number;

	for(unsigned int i = 0; i< NBR_BUTTON; i++){
		gpointer l_number = g_object_get_data(G_OBJECT(l_model->s_button[i]), "position");
		l_id = g_object_get_data(G_OBJECT(l_model->s_button[i]), "button_id");
		new_game(l_model, l_number, l_id);
		l_model->s_selectedButton[i] = -1;
	}
}
