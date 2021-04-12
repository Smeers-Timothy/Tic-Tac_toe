/**
 * @file model.c
 * @brief Modèle (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date Created on: 9 avr. 2021
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <gtk/gtk.h>
#include "model.h"

/* DEFINE */
#define NBR_BUTTON 16

GtkWidget *create_image(const gchar *p_image){
	assert(p_image != NULL);

	GtkWidget *l_image = gtk_image_new_from_file(p_image);

	if(l_image == NULL){
		printf("Erreur de chargement de l'image !\n");
		return(NULL);
	}

	return(l_image);
}

ModelOXO *create_model(unsigned int p_player){
	assert(p_player == 0 || p_player == 1);

	ModelOXO *l_model = malloc(sizeof(ModelOXO));

	if(l_model == NULL){
		printf("Erreur d'allocation de mémoire !\n");
		return(NULL);
	}

	l_model->s_placed = 0;
	l_model->s_player = p_player;
	l_model->s_image = create_image("images/default.png");

	return(l_model);
}

void add_action(ModelOXO *p_model, guint p_number){
	assert(p_model != NULL && (p_number >= 0 || p_number <= NBR_BUTTON));

	if(p_model->s_placed < NBR_BUTTON) {

		if(p_model->s_player == s_playerO){
			p_model->s_image = create_image("images/o.png");
			gtk_button_set_image(p_model->s_button[p_number], p_model->s_image);
		}else{
			p_model->s_image = create_image("images/x.png");
			gtk_button_set_image(p_model->s_button[p_number], p_model->s_image);
		}
		p_model->s_placed++;
				p_model->s_player = (p_model->s_player == s_playerO)
															? s_playerX : s_playerO;
	}

}

void new_game(ModelOXO *p_model){
	assert(p_model != NULL);

	p_model->s_placed = 0;
	p_model->s_player = s_playerO;
}
