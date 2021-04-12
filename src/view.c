/**
 * @file view.c
 * @brief Vue (pattern MVC) pour la gestion d'un Tic-Tac_Toe
 * @author Smeers Timothy
 * @version 0.1
 * @date Created on: 9 avr. 2021
 */
#include <stdlib.h>
#include <gtk/gtk.h>
#include <assert.h>

#include "view.h"
#include "controller.h"

/* DEFINE */
#define X_WINDOW_SIZE 400
#define Y_WINDOW_SIZE 470
#define NBR_BUTTON 16
#define ROW 4
#define COLUMN 4

struct view_t{
	ModelOXO *s_model; /**< Modèle du OXO */
	GtkWidget *s_table; /**< La table */
	GtkWidget *s_verticalBox; /**< Une vertical boxe */
	GtkWidget *s_horizontalBox; /**< Une horizontale boxe */
};

ViewOXO *create_view(ModelOXO *p_model){
	assert(p_model != NULL);

	ViewOXO *l_view = malloc(sizeof(ViewOXO));

	if(l_view == NULL){
		printf("Erreur d'allocation !\n");
		return(NULL);
	}
	l_view->s_model = p_model;

	return(l_view);
}

void destroy_window(GtkWidget *p_widget, gpointer p_data){
	assert(p_widget != NULL);

	gtk_main_quit();
}

GtkWidget *create_window(){

	GtkWidget *l_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	if(l_window == NULL){
		printf("Erreur de création de la fenetre !\n");
		return(NULL);
	}
	gtk_window_set_title(GTK_WINDOW(l_window), "OXO");
	gtk_window_set_default_size(GTK_WINDOW(l_window), X_WINDOW_SIZE, Y_WINDOW_SIZE);
	gtk_window_set_position(l_window, GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable (GTK_WINDOW(l_window), FALSE);

	return(l_window);
}

GtkButton *load_image_button(){

	GdkPixbuf *l_fileImage = gdk_pixbuf_new_from_file("images/default.png", NULL);

	if(l_fileImage == NULL){
		printf("Erreur de chargement de l’image !\n");
		return(NULL);
	}
	GdkPixbuf *l_pixbuf = gdk_pixbuf_scale_simple (l_fileImage, 100, 100, GDK_INTERP_NEAREST);
	GtkWidget *l_button = gtk_button_new();
	GtkWidget *l_image = gtk_image_new_from_pixbuf(l_pixbuf);
	gtk_button_set_image(GTK_BUTTON(l_button), l_image);

	return(GTK_BUTTON(l_button));
}

void create_table(ViewOXO *p_view, GtkWidget **p_button){
	assert(p_view != NULL && p_button > 0);

	p_view->s_table = gtk_table_new(ROW, COLUMN, TRUE);

	for(unsigned int i = 0, k = 0, row = 0 ; row < NBR_BUTTON ; i+=2, row+=2){

		p_button[row] = (GtkWidget*)load_image_button();
		p_button[row+1] = (GtkWidget*)load_image_button();

		if(i == ROW){
			i = 0; k++;
		}
		gtk_table_attach(GTK_TABLE(p_view->s_table), p_button[row], i, i+1, k,
				k+1, GTK_FILL, GTK_FILL, 0, 0);
		gtk_table_attach(GTK_TABLE(p_view->s_table), p_button[row+1], i+1, i+2, k,
				k+1, GTK_FILL, GTK_FILL, 0, 0);
	}
}

void create_principal_box(ViewOXO *p_view){
	assert(p_view != NULL);

	p_view->s_verticalBox = gtk_vbox_new(FALSE, 1);
	p_view->s_horizontalBox = gtk_hbox_new(TRUE, 1);
	gtk_box_pack_start(GTK_BOX(p_view->s_verticalBox), p_view->s_table, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(p_view->s_verticalBox), p_view->s_horizontalBox, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(p_view->s_horizontalBox), p_view->s_model->s_newGameButton, TRUE, FALSE, ROW);
}

void create_new_game_button(ViewOXO *p_view){
	assert(p_view != NULL);

	p_view->s_model->s_newGameButton = gtk_button_new_with_label("Nouvelle Partie");
}

void draw_window(ViewOXO *p_view, GtkWidget *p_window){
	assert(p_view != NULL && p_window != NULL);

	gtk_container_add(GTK_CONTAINER(p_window), GTK_WIDGET(p_view->s_verticalBox));
	gtk_widget_show_all(p_window);
}
