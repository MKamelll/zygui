#include <stdio.h>
#include <gtk-4.0/gtk/gtk.h>
#include "main_window.h"

static void on_activate(GtkApplication* app, gpointer user_data)
{
    GtkWidget* window = create_main_window(app, user_data);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char* argv[])
{    
    GtkApplication* app = gtk_application_new("com.mkamelll.zygui", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    
    g_object_unref(app);
    return status;
}