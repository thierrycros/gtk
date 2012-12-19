#ifndef WINDOW_H
#define WINDOW_h

/*include gtk to program*/
#include <gtk/gtk.h>

/*prototypes*/
void window(int argc, char *argv[]);
static void helloWorld_print(GtkWidget *widget, gpointer data);
static gboolean delete_event( GtkWidget *widget, GdkEvent *event, gpointer data);
static void destroy( GtkWidget *widget, gpointer data);
#endif
