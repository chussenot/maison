#include <stdio.h>
#include<gtk/gtk.h>
#define PROJECT_NAME "maison"

static GtkWidget *window = NULL;

GtkWidget *
do_expander (GtkWidget *do_widget)
{
  GtkWidget *vbox;
  GtkWidget *label;
  GtkWidget *expander;
  
  if (!window)
  {
    window = gtk_dialog_new_with_buttons ("GtkExpander",
					  GTK_WINDOW (do_widget),
					  0,
					  GTK_STOCK_CLOSE,
					  GTK_RESPONSE_NONE,
					  NULL);
    gtk_window_set_resizable (GTK_WINDOW (window), FALSE);

    g_signal_connect (window, "response",
		      G_CALLBACK (gtk_widget_destroy), NULL);
    g_signal_connect (window, "destroy",
		      G_CALLBACK (gtk_widget_destroyed), &window);

    vbox = gtk_vbox_new (FALSE, 5);
    gtk_box_pack_start (GTK_BOX (gtk_dialog_get_content_area (GTK_DIALOG (window))), vbox, TRUE, TRUE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (vbox), 5);

    label = gtk_label_new ("Expander demo. Click on the triangle for details.");
    gtk_box_pack_start (GTK_BOX (vbox), label, FALSE, FALSE, 0);

    /* Create the expander */
    expander = gtk_expander_new ("Details");
    gtk_box_pack_start (GTK_BOX (vbox), expander, FALSE, FALSE, 0);

    label = gtk_label_new ("Details can be shown or hidden.");
    gtk_container_add (GTK_CONTAINER (expander), label);
  }

  if (!gtk_widget_get_visible (window))
    gtk_widget_show_all (window);
  else
    gtk_widget_destroy (window);

  return window;
}


int main(int argc, char **argv) {
  printf("This is project %s.\n", PROJECT_NAME);
  GtkWidget *win;
  gtk_init(&argc, &argv);
  win = do_expander(window); // gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(win), "Hello there");
  g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show(win);
  gtk_main();
}
