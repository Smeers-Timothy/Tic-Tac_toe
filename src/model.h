/**
 * @file model.h
 * @brief Modèle (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date Created on: 9 avr. 2021
 */
#ifndef MODEL_H_
#define MODEL_H_

#define NBR_BUTTON 16

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
 * @struct model_t
 * @brief Implémentation du modèle pour le OXO.
 *
 */
typedef struct model_t{
    Player s_player; /**< Le joueur */
	unsigned int s_placed; /**< Le nombre de bouton déja instancier */
	GtkWidget *s_image; /**< L'image à afficher  */
	GtkWidget *s_button[NBR_BUTTON]; /**< Le tableau de bouton de jeux */
}ModelOXO;

/**
 * @fn GtkWidget create_image*(const gchar*)
 * @brief Création d'une image venant d'un fichier
 *
 * @pre p_image != NULL
 * @post GtkWidget *l_image contient une image
 * @param p_image le nom de l'image
 * @return GtkWidget *l_image un pointeur sur l'image créée
 * 			NULL en cas d'erreur
 */
GtkWidget *create_image(const gchar *p_image);

/**
 * @fn ModelOXO create_model*(unsigned int)
 * @brief Crée un modèle OXO pour un joueur.
 *
 * @pre p_player == 0 || p_player == 1
 * @post Un model est créé
 * @param p_player le premier jouer à commencer à jouer
 * @return ModelOXO *l_model un pointeur sur le modele à prendre en compte
 * 			NULL en cas d'erreur
 */
ModelOXO *create_model(unsigned int p_player);

/**
 * @fn void add_action(ModelOXO*, guint)
 * @brief Ajoute une image X | O dans la case selectionner selon le joueur
 *
 * @pre p_model != NULL && (p_number >= 0 || p_number <= NBR_BUTTON)
 * @post Une image est placée à l'endroit selectionnée
 * @param p_model Un pointeur sur le modele à prendre en compte
 * @param p_number La case selectionnée
 */
void add_action(ModelOXO *p_model, guint p_number);

/**
 * @fn void new_game(ModelOXO*)
 * @brief Remet l'état de jeux comme au début pour lancé une nouvelle partie
 *
 * @pre p_model != NULL
 * @post Le jeux est réinitialisé
 * @param p_model Un pointeur sur le modele à prendre en compte
 */
void new_game(ModelOXO *p_model);

#endif /* MODEL_H_ */
