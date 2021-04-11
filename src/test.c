#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "OXO.h"

void changeImage(GtkWidget *bouton, gpointer data);
void nouvellePartie(GtkWidget *partie, gpointer data);

int main(int argc, char **argv){
        GtkWidget *pFenetre;
        GtkWidget *pVBox;
        GtkWidget *pHBox;
        GtkWidget *pBouton_nouvelle_partie;
        GtkWidget *pBouton[16];
        GtkWidget *pImage[16];
        int nombre = 0;

    gtk_init(&argc, &argv);

    //creation d'une fenetre
    pFenetre = creer_fenetre();

    //creation de 16 boutons et 16 images
    for(int i = 0 ; i < 16 ; i++){
       pBouton[i] = creer_bouton();
       pImage[i] = creer_image();
    }

    //Creationn d'un bouton Nouvelle partie
    pBouton_nouvelle_partie = gtk_button_new_with_label("Nouvelle partie");
    pVBox = gtk_vbox_new(TRUE, 0);

    //fusion de l image et le bouton en 4x4
    for (int i  = 0; i<16;  i++){
        if(i % 4 == 0){
        pHBox = gtk_hbox_new(TRUE, 0);
        gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 2);
        }

        gtk_box_pack_start(GTK_BOX(pHBox), pBouton[i], TRUE,TRUE, 2);
        gtk_container_add(GTK_CONTAINER(pBouton[i]), pImage[i]);
    }

    //affiche le bouton de la nouvelle partie
    gtk_box_pack_start(GTK_BOX(pVBox), pBouton_nouvelle_partie, TRUE,TRUE, 2);



    //Permet de faire un click dans la case pour ensuite mettre une image
    for(int i = 0 ; i< 16; i++){
        g_signal_connect(G_OBJECT(pBouton[i]), "clicked", G_CALLBACK(changeImage),&nombre);
    }

    //Permet de faire un click dans la case nouvelle partie pour ensuite mettre toutes les images en blanc
    g_signal_connect(G_OBJECT(pBouton_nouvelle_partie), "clicked", G_CALLBACK(nouvellePartie), NULL);

    gtk_container_add(GTK_CONTAINER(pFenetre), pVBox);

    for(int i = 0 ; i< 16; i++){
        //vers le widget de l'image
        g_object_set_data(G_OBJECT(pBouton[i]), "image", pImage[i]);
    }
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[0]", pImage[0]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[1]", pImage[1]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[2]", pImage[2]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[3]", pImage[3]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[4]", pImage[4]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[5]", pImage[5]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[6]", pImage[6]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[7]", pImage[7]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[8]", pImage[8]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[9]", pImage[9]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[10]", pImage[10]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[11]", pImage[11]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[12]", pImage[12]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[13]", pImage[13]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[14]", pImage[14]);
    g_object_set_data(G_OBJECT(pBouton_nouvelle_partie), "blanc[15]", pImage[15]);

    gtk_widget_show_all(pFenetre);
    gtk_main();

return EXIT_SUCCESS;
}//fin main()

void changeImage(GtkWidget *bouton, gpointer data){
    int *nombre = data;

    /* On récupère le pointeur vers l'image qui est dans le bouton */
    GtkWidget *pImage = g_object_get_data(G_OBJECT(bouton), "image");
    if (*nombre  % 2 == 0){
        gtk_image_set_from_file(GTK_IMAGE(pImage), "o.png");
    }
    else{
        gtk_image_set_from_file(GTK_IMAGE(pImage), "x.png");
    }

    *nombre += 1;
}

void nouvellePartie(GtkWidget *partie, gpointer data){
    GtkWidget *pImage[16];

    pImage[0]= g_object_get_data(G_OBJECT(partie), "blanc[0]");
    pImage[1]= g_object_get_data(G_OBJECT(partie), "blanc[1]");
    pImage[2]= g_object_get_data(G_OBJECT(partie), "blanc[2]");
    pImage[3]= g_object_get_data(G_OBJECT(partie), "blanc[3]");
    pImage[4]= g_object_get_data(G_OBJECT(partie), "blanc[4]");
    pImage[5]= g_object_get_data(G_OBJECT(partie), "blanc[5]");
    pImage[6]= g_object_get_data(G_OBJECT(partie), "blanc[6]");
    pImage[7]= g_object_get_data(G_OBJECT(partie), "blanc[7]");
    pImage[8]= g_object_get_data(G_OBJECT(partie), "blanc[8]");
    pImage[9]= g_object_get_data(G_OBJECT(partie), "blanc[9]");
    pImage[10]= g_object_get_data(G_OBJECT(partie), "blanc[10]");
    pImage[11]= g_object_get_data(G_OBJECT(partie), "blanc[11]");
    pImage[12]= g_object_get_data(G_OBJECT(partie), "blanc[12]");
    pImage[13]= g_object_get_data(G_OBJECT(partie), "blanc[13]");
    pImage[14]= g_object_get_data(G_OBJECT(partie), "blanc[14]");
    pImage[15]= g_object_get_data(G_OBJECT(partie), "blanc[15]");

    for(int i = 0 ; i< 16; i++){
        gtk_image_set_from_file(GTK_IMAGE(pImage[i]), "default.png");
    }
}
