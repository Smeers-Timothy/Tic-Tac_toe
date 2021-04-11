/*
 * view.c
 *
 *  Created on: 9 avr. 2021
 *      Author: tim04
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
	GtkWidget *s_button[BUTTON_NBR];
	GtkWidget *s_table;
	GtkWidget *s_new_game_button;
	GtkWidget *s_verticalBox;
	GtkWidget *s_horizontalBox;
};

ViewOXO *create_view(ModelOXO *p_model){
	assert(p_model != NULL);

	ViewOXO *l_view = malloc(sizeof(ViewOXO));

	if(l_view == NULL)
		return(NULL);

	l_view->s_model = p_model;

	return(l_view);
}

void update(ViewOXO *p_view){

}

void destroy_window(GtkWidget *pF, gpointer data){

	gtk_main_quit();
}

GtkWidget *create_window(){

	GtkWidget *l_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(l_window), "OXO");
	gtk_window_set_default_size(GTK_WINDOW(l_window), X_WINDOW_SIZE, Y_WINDOW_SIZE);
	gtk_window_set_position(l_window, GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable (GTK_WINDOW(l_window), FALSE);

	g_signal_connect(G_OBJECT(l_window), "destroy", G_CALLBACK(destroy_window), NULL);

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

void create_table(ViewOXO *p_view){

	p_view->s_table = gtk_table_new(ROW, COLUMN, TRUE);

	for(unsigned int i = 0, k = 0, row = 0 ; row < NBR_BUTTON ; i+=2, row+=2){

		p_view->s_button[row] = (GtkWidget*)load_image_button();
		p_view->s_button[row+1] = (GtkWidget*)load_image_button();

		if(i == 4){
			i = 0; k++;
		}
		gtk_table_attach(GTK_TABLE(p_view->s_table), p_view->s_button[row], i, i+1, k,
				k+1, GTK_FILL, GTK_FILL, 0, 0);
		gtk_table_attach(GTK_TABLE(p_view->s_table), p_view->s_button[row+1], i+1, i+2, k,
				k+1, GTK_FILL, GTK_FILL, 0, 0);
	}
}

void create_principal_box(ViewOXO *p_view){

	p_view->s_new_game_button = gtk_button_new_with_label("Nouvelle Partie");
	p_view->s_verticalBox = gtk_vbox_new(FALSE, 1);
	p_view->s_horizontalBox = gtk_hbox_new(TRUE, 1);
	gtk_box_pack_start(GTK_BOX(p_view->s_verticalBox), p_view->s_table, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(p_view->s_verticalBox), p_view->s_horizontalBox, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(p_view->s_horizontalBox), p_view->s_new_game_button, TRUE, FALSE, 4);
}

void draw_window(ViewOXO *p_view, GtkWidget *p_window){

	gtk_container_add(GTK_CONTAINER(p_window), GTK_WIDGET(p_view->s_verticalBox));
	gtk_widget_show_all(p_window);
}


