
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <assert.h>

#include "controller.h"
#include "model.h"
#include "view.h"

/* DEFINE */
#define NBR_BUTTON 16

/* VARIABLES */

ViewOXO *s_view;
ModelOXO *s_model;
ControllerOXO *s_controller;
GtkWidget *s_window;

int create_MSV(){

	s_model = create_model(s_playerO);

	if(s_model == NULL)
		return(EXIT_FAILURE);

	s_view = create_view(s_model);

	if(s_view == NULL)
		return(EXIT_FAILURE);

	s_controller = create_controller(s_view, s_model);

	if(s_controller == NULL)
		return(EXIT_FAILURE);

	return(EXIT_SUCCESS);
}

int main(int argc, char **argv){

	create_MSV();

	if(create_MSV() != 0)
		return(EXIT_FAILURE);

	gtk_init(&argc, &argv);

	s_window = create_window();
	g_signal_connect(G_OBJECT(s_window), "destroy", G_CALLBACK(destroy_window), NULL);


	create_new_game_button(s_view);
	create_table(s_view, s_model->s_button);

	for(unsigned int i = 0; i< NBR_BUTTON; i++){
		g_object_set_data(G_OBJECT(s_model->s_button[i]), "position", (gpointer)i);
		g_signal_connect(G_OBJECT(s_model->s_button[i]), "clicked", G_CALLBACK(click_grid), s_controller);
	}

	create_principal_box(s_view);
	draw_window(s_view, s_window);

	gtk_main();

	return(EXIT_SUCCESS);

}
