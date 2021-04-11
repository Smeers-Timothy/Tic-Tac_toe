/*
 * module.h
 *
 *  Created on: 9 avr. 2021
 *      Author: tim04
 */

#ifndef MODEL_H_
#define MODEL_H_

/**
 * @file model.h
 * @brief Modèle (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date 10/04/2021
 */

/**
 * @enum Player
 * @brief Définit les 2 possibilité de joueur : X ou O
 *
 */
typedef enum Player_t{
	s_playerO = 0,/**< O */
	s_playerX = 1/**< X */
}Player;

/**
 * @struct image_t
 * @brief Enumeration de toutes les images
 *
 */
typedef struct image_t ImageOXO;

/**
 * @struct model_t
 * @brief Implémentation du modèle pour le OXO.
 *
 */
typedef struct model_t{
    Player s_player; /**< Le joueur  */
	ImageOXO *s_image; /**< Les images à géré */
	unsigned int s_placed; /**< Le nombre de bouton déja instancier */
}ModelOXO;



/**
 * @fn ModelOXO create_model*(unsigned int)
 * @brief Crée un modèle OXO pour un joueur.
 *
 * @pre /
 * @post /
 * @param player le joueur
 * @return ModelOXO *, un pointeur vers un modèle de OXO.
 *         NULL en cas d'erreur
 */
ModelOXO *create_model(unsigned int p_player);

/**
 * @fn void add_action(ModelOXO*)
 * @brief Prévient que le joueur à jouer une case du OXO
 *
 * @pre p_model != NULL
 * @post /
 * @param p_model le modèle à modifier
 */
void add_action(ModelOXO *p_model);

/**
 * @fn void new_game(ModelOXO*)
 * @brief Prévient qu'une nouvelle partie doit être lancée
 *
 * @pre p_model != NULL
 * @post /
 * @param p_model le modèle à modifier
 */
void new_game(ModelOXO *p_model);

#endif /* MODEL_H_ */
