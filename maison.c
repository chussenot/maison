#include <stdio.h>
#include<gtk/gtk.h>

#define PROJECT_NAME "maison"

int main(int argc, char **argv) {
  printf("This is project %s.\n", PROJECT_NAME);
  GtkWidget *win;
  gtk_init(&argc, &argv);
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(win), "Hello there");
  g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show(win);
  gtk_main();
}

