#include <gtk/gtk.h>

static void activate(GtkApplication* app, gpointer userData){
    GtkWidget *window;
    GtkWidget *label;
    
    window = gtk_application_window_new(app);
    label = gtk_label_new("Hello GNOME!");
    gtk_container_add(GTK_CONTAINER(window), label);
    gtk_window_set_title(GTK_WINDOW(window), "Welcome to GNOME");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);
    gtk_widget_show_all(window);
}

int main(int argc, char **args){
    GtkApplication *app;
    int status;

    app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, args);
    g_object_unref(app);

    return status;
}