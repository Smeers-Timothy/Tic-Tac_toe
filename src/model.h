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

///**
// * @struct field_t
// * @brief Implémentation de tableau de valeur pour le gameboard
// *
// */
//typedef struct field_t{
//	int s_xCase[NBR_BUTTON+1];
//	int s_oCase[NBR_BUTTON+1];
//}Field;

/**
 * @struct model_t
 * @brief Implémentation du modèle pour le OXO.
 *
 */
typedef struct model_t{
//	Field s_field;
	int s_xCase[NBR_BUTTON+1];
	int s_oCase[NBR_BUTTON+1];
	int s_oPositif;
	int s_oNegatif;
	int s_selectedButton[NBR_BUTTON+1]; /**< Bouton sélectionner */
	unsigned int s_placed; /**< Le nombre de bouton déja instancier */
    Player s_player; /**< Le joueur */
	GtkWidget *s_image; /**< L'image à afficher  */
	GtkWidget *s_button[NBR_BUTTON]; /**< Le tableau de bouton de jeux */
	GtkWidget *s_newGameButton; /**< Le bouton de nouvelle partie */

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
 * @fn void add_action(ModelOXO*, guint, gulong)
 * @brief Ajoute une image X | O dans la case selectionner selon le joueur
 *
 * @pre joute une image X | O dans la case selectionner selon le joueur
 * @post Une image est placée à l'endroit selectionnée
 * @param p_model Un pointeur sur le modele à prendre en compte
 * @param p_number La case selectionnée
 * @param p_id L'id du signal
 */
void add_action(ModelOXO *p_model, guint p_number, gulong p_id);

/**
 * @fn void new_game(ModelOXO*)
 * @brief Remet l'état de jeux comme au début pour lancé une nouvelle partie
 *
 * @pre p_model != NULL
 * @post Le jeux est réinitialisé
 * @param p_model Un pointeur sur le modele à prendre en compte
 * @param p_number La case selectionnée
 * @param p_id L'id du signal
 */
void new_game(ModelOXO *p_model, guint p_number, gulong p_id);

/**
 * @fn gboolean win(ModelOXO*, int*, int)
 * @brief Permet de vérifier si il y a une possibilité de gagnat
 *
 * @pre
 * @post
 * @param p_model Un pointeur sur le modele à prendre en compte
 * @param p_playerO le joueur O
 * @param p_count une variable d'incrémentation
 * @return TRUE si la partie est gagnée sinon FALSE
 */
gboolean win(ModelOXO *p_model, int *p_playerO, int p_count);

/**
 * @fn gboolean browse_array(int, int*, int)
 * @brief Permet de parcourir un tableau pour y trouver une occurence
 *
 * @pre
 * @post
 * @param p_model Un pointeur sur le modele à prendre en compte
 * @param p_player L'occurence à trouver
 * @param tab Le tableau à parcourir
 * @param p_value la valeur à incrémenté pour trouver l'occurence
 * @return TRUE si une occurence à été trouvé sinon FALSE
 */
gboolean browse_positif_array(ModelOXO *p_model, int p_player, int *tab, int p_value);

/**
 * @fn gboolean browse_negatif_array(int, int*, int)
 * @brief Permet de parcourir un tableau pour y trouver une occurence
 *
 * @pre
 * @post
 * @param p_model Un pointeur sur le modele à prendre en compte
 * @param p_player L'occurence à trouver
 * @param tab Le tableau à parcourir
 * @param p_value la valeur à décrémenté pour trouver l'occurence
 * @return TRUE si une occurence à été trouvé sinon FALSE
 */
gboolean browse_negatif_array(ModelOXO *p_model, int p_player, int *tab, int p_value);

#endif /* MODEL_H_ */
