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

struct image_t{
	char *s_oSimple;
	char *s_xSimple;
	char *s_oWin;
	char *s_xWin;
	char *s_default;
};

ModelOXO *create_model(unsigned int p_player){

	ModelOXO *l_model = malloc(sizeof(ModelOXO));
	ImageOXO *l_image = malloc(sizeof(ImageOXO));

	if(l_model == NULL || l_image == NULL)
		return(NULL);

	l_model->s_placed = 0;
	l_model->s_player = s_playerO;
	l_image->s_oSimple = "images/o.png";
	l_image->s_xSimple = "images/x.png";
	l_image->s_oWin = "images/o_gagnant.png" ;
	l_image->s_xWin = "images/x_gagnant.png";
	l_image->s_default = "images/default.png";

	return(l_model);
}

void add_action(ModelOXO *p_model){
	assert(p_model != NULL);
	printf("toto\n");

//	if(p_model->s_placed < MAX_CASE)
//		p_model->s_placed++;

//	p_model->s_player = (p_model->s_player == s_playerO)
//									? s_playerX : s_playerO;
}

void new_game(ModelOXO *p_model){
	assert(p_model != NULL);

	p_model->s_placed = 0;
	p_model->s_player = s_playerO;
}
