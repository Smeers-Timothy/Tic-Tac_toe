/*
 * model.c
 *
 *  Created on: 9 avr. 2021
 *      Author: tim04
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <gtk/gtk.h>
#include "model.h"

/* DEFINE */
#define NBR_BUTTON 16

GtkWidget *create_image(const gchar *p_image){

	GtkWidget *l_image = gtk_image_new_from_file(p_image);
	return(l_image);
}

ModelOXO *create_model(unsigned int p_player){

	ModelOXO *l_model = malloc(sizeof(ModelOXO));

	if(l_model == NULL)
		return(NULL);

	l_model->s_placed = 0;
	l_model->s_player = s_playerO;
	l_model->s_image = create_image("images/default.png");

	return(l_model);
}

void add_action(ModelOXO *p_model, guint p_number){
	assert(p_model != NULL);

	if(p_model->s_placed < NBR_BUTTON) {
		p_model->s_placed++;
		p_model->s_player = (p_model->s_player == s_playerO)
													? s_playerX : s_playerO;

		if(p_model->s_player == s_playerO){
			p_model->s_image = create_image("images/o.png");
			gtk_button_set_image(p_model->s_button[p_number], p_model->s_image);
		}else{
			p_model->s_image = create_image("images/x.png");
			gtk_button_set_image(p_model->s_button[p_number], p_model->s_image);
		}
	}

}

void new_game(ModelOXO *p_model){
	assert(p_model != NULL);

	p_model->s_placed = 0;
	p_model->s_player = s_playerO;
}
