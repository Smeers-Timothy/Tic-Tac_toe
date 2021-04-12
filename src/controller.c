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

void set_button_number(ControllerOXO *p_controller, unsigned int p_count){
	assert(p_controller != NULL && (p_count >= 0 || p_count <= 16));

	p_controller->s_number = p_count;
}

unsigned int get_button_number(ControllerOXO *p_controller){
	assert(p_controller != NULL);

	return(p_controller->s_number);
}

void click_grid(GtkWidget *p_widget, gpointer p_data){
	assert(p_widget != NULL && p_data != NULL);

	ControllerOXO *l_controller = (ControllerOXO *)p_data;
	unsigned int l_number = g_object_get_data(p_widget, "position");

	set_button_number(l_controller, l_number);
	printf("toto : %d\n",l_number);
	add_action(l_controller->s_model, get_button_number(l_controller));
}

void click_new_game(GtkWidget *p_widget, gpointer p_data){


}
