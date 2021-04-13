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

	for(unsigned int i = 0; i < NBR_BUTTON+1; i++){
		l_model->s_oCase[i] = -1;
		l_model->s_xCase[i] = -1;
	}

	l_model->s_placed = 0;
	l_model->s_player = p_player;
	l_model->s_image = create_image("default.png");

	return(l_model);
}

void add_action(ModelOXO *p_model, guint p_number, gulong p_id){
	assert(p_model != NULL && (p_number >= 0 || p_number <= NBR_BUTTON));

	if(p_model->s_placed < NBR_BUTTON) {

		if(p_model->s_player == s_playerO){
			p_model->s_image = create_image("o.png");
			gtk_button_set_image(GTK_BUTTON(p_model->s_button[p_number]), p_model->s_image);
			p_model->s_oCase[p_number] = p_number;

			for(unsigned int i = 0; i< NBR_BUTTON; i++){
				if(win(p_model, p_model->s_oCase, i) != FALSE){

					p_model->s_image = create_image("o_gagnant.png");
					gtk_button_set_image(GTK_BUTTON(p_model->s_button[p_model->s_oPositif]), p_model->s_image);
					p_model->s_image = create_image("o_gagnant.png");
					gtk_button_set_image(GTK_BUTTON(p_model->s_button[p_model->s_oNegatif]), p_model->s_image);
					p_model->s_image = create_image("x_gagnant.png");
					gtk_button_set_image(GTK_BUTTON(p_model->s_button[i]),p_model->s_image);
					p_model->s_image = create_image("default.png");

					i = NBR_BUTTON;

					for(unsigned int j = 0; j<NBR_BUTTON; j++){
						guint l_number = g_object_get_data(G_OBJECT(p_model->s_button[j]), "position");
						gulong l_id = g_object_get_data(G_OBJECT(p_model->s_button[j]), "button_id");

						if(g_signal_handler_is_connected(p_model->s_button[l_number], l_id) == TRUE){
							int l_tmp = -1;

							if(p_model->s_selectedButton[l_number] <= l_id && l_tmp != p_model->s_selectedButton[l_number] ){
								g_signal_handler_unblock(p_model->s_button[l_number],l_id);
								l_tmp = p_model->s_selectedButton[l_number];
							}
						}
					}
					for(unsigned int j = 0; j<NBR_BUTTON; j++){
						guint l_number = g_object_get_data(G_OBJECT(p_model->s_button[j]), "position");
						gulong l_id = g_object_get_data(G_OBJECT(p_model->s_button[j]), "button_id");
						g_signal_handler_block(p_model->s_button[l_number],l_id);
					}
				}
			}
		}else{
			p_model->s_image = create_image("x.png");
			gtk_button_set_image(GTK_BUTTON(p_model->s_button[p_number]), p_model->s_image);
			p_model->s_xCase[p_number] = p_number;

			for(unsigned int i = 0; i< NBR_BUTTON; i++){
				if(win(p_model, p_model->s_oCase, i) != FALSE){

					p_model->s_image = create_image("o_gagnant.png");
					gtk_button_set_image(GTK_BUTTON(p_model->s_button[p_model->s_oPositif]), p_model->s_image);
					p_model->s_image = create_image("o_gagnant.png");
					gtk_button_set_image(GTK_BUTTON(p_model->s_button[p_model->s_oNegatif]), p_model->s_image);
					p_model->s_image = create_image("x_gagnant.png");
					gtk_button_set_image(GTK_BUTTON(p_model->s_button[i]),p_model->s_image);
					p_model->s_image = create_image("default.png");

					i = NBR_BUTTON;

					for(unsigned int j = 0; j<NBR_BUTTON; j++){
						guint l_number = g_object_get_data(G_OBJECT(p_model->s_button[j]), "position");
						gulong l_id = g_object_get_data(G_OBJECT(p_model->s_button[j]), "button_id");

						if(g_signal_handler_is_connected(p_model->s_button[l_number], l_id) == TRUE){
							int l_tmp = -1;

							if(p_model->s_selectedButton[l_number] <= l_id && l_tmp != p_model->s_selectedButton[l_number] ){
								g_signal_handler_unblock(p_model->s_button[l_number],l_id);
								l_tmp = p_model->s_selectedButton[l_number];
							}
						}
					}
					for(unsigned int j = 0; j<NBR_BUTTON; j++){
						guint l_number = g_object_get_data(G_OBJECT(p_model->s_button[j]), "position");
						gulong l_id = g_object_get_data(G_OBJECT(p_model->s_button[j]), "button_id");
						g_signal_handler_block(p_model->s_button[l_number],l_id);
					}
				}
			}
		}
p_model->s_placed++;
p_model->s_player = (p_model->s_player == s_playerO) ? s_playerX : s_playerO;
}
g_signal_handler_block(p_model->s_button[p_number], p_id);
p_model->s_selectedButton[p_number] = p_id;

}



void new_game(ModelOXO *p_model, guint p_number, gulong p_id){
	assert(p_model != NULL);

	p_model->s_placed = 0;
	p_model->s_player = s_playerO;
	p_model->s_image = create_image("default.png");

	for(unsigned int i= 0; i < NBR_BUTTON; i++){
		p_model->s_oCase[i] = 0;
		p_model->s_xCase[i] = 0;
	}

	gtk_button_set_image(GTK_BUTTON(p_model->s_button[p_number]), p_model->s_image);

	if(g_signal_handler_is_connected(p_model->s_button[p_number], p_id) == TRUE){
		int l_tmp = -1;

		if(p_model->s_selectedButton[p_number] <= p_id && l_tmp != p_model->s_selectedButton[p_number] ){
			g_signal_handler_unblock(p_model->s_button[p_number],p_id);
			l_tmp = p_model->s_selectedButton[p_number];
		}
	}
}


gboolean browse_positif_array(ModelOXO *p_model, int p_player, int *tab, int p_value){

	for(unsigned int i = 0; i <NBR_BUTTON; i++){
		if(tab[i] != -1){
			if(tab[i]+p_value == p_player){
				p_model->s_oNegatif = tab[i];
				return(TRUE);
			}
		}
	}
	return(FALSE);
}

gboolean browse_negatif_array(ModelOXO *p_model, int p_player, int *tab, int p_value){

	for(unsigned int i = 0; i < NBR_BUTTON; i++){
		if(tab[i] != -1){
			if(tab[i]-p_value == p_player){
				p_model->s_oPositif = tab[i];
				return(TRUE);
			}
		}
	}
	return(FALSE);
}

gboolean win(ModelOXO *p_model, int *p_playerO, int p_count){

	int row[8] = {1,2,5,6,9,10,13,14};
	int column[8] = {4,5,6,7,8,9,10,11};
	int diagonal[4] = {5,6,9,10};

	int l_xValue = p_model->s_xCase[p_count];

	/* LIGNE */
	if(browse_positif_array(p_model, l_xValue, row, 0) != FALSE){
		if(browse_negatif_array(p_model, l_xValue, p_playerO, 1) &&
				browse_positif_array(p_model, l_xValue, p_playerO, 1) != FALSE){
			return(TRUE);
		}
	}
	/* COLONNE */
	if(browse_positif_array(p_model, l_xValue, column, 0) != FALSE){
		if(browse_negatif_array(p_model, l_xValue, p_playerO, 4) &&
				browse_positif_array(p_model, l_xValue, p_playerO, 4) != FALSE)
			return(TRUE);
	}
	/* DIAGONALES */
	if(browse_positif_array(p_model, l_xValue, diagonal, 0) != FALSE){
		if(browse_negatif_array(p_model, l_xValue, p_playerO, 3) &&
				browse_positif_array(p_model, l_xValue, p_playerO, 3) != FALSE)
			return(TRUE);

		if(browse_negatif_array(p_model, l_xValue, p_playerO, 5) &&
				browse_positif_array(p_model, l_xValue, p_playerO, 5) != FALSE)
			return(TRUE);
	}
	return(FALSE);
}
