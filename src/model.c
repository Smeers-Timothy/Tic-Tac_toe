/*
 * model.c
 *
 *  Created on: 9 avr. 2021
 *      Author: tim04
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "model.h"

/* DEFINE */
#define MAX_CASE 16



ModelOXO *create_model(unsigned int p_player){

	ModelOXO *l_model = malloc(sizeof(ModelOXO));

	if(l_model == NULL)
		return(NULL);

	l_model->s_placed = 0;
	l_model->s_player = s_playerO;
	l_model->s_image = "images/default.png";

	return(l_model);
}

void add_action(ModelOXO *p_model){
	assert(p_model != NULL);

	if(p_model->s_placed < MAX_CASE) {
		p_model->s_placed++;
		p_model->s_player = (p_model->s_player == s_playerO)
											? s_playerX : s_playerO;
		if(p_model->s_player == s_playerO)
			p_model->s_image = "images/o.png";
		else
			p_model->s_image = "images/x.png";
	}

}

void new_game(ModelOXO *p_model){
	assert(p_model != NULL);

	p_model->s_placed = 0;
	p_model->s_player = s_playerO;
}
