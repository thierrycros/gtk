/*include header*/
#include "window.h"

void 
window(int argc, char *argv[])
{

	/*pointer to new window*/
	GtkWidget *window;
	
	/*pointer to new button*/
	GtkWidget *button;

	/*initialise window with cmd line args*/
	gtk_init(&argc, &argv);

	/*display the window*/
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	/*delete event handler*/
	g_signal_connect(window, "delete-event", G_CALLBACK (delete_event), NULL);
 
	/*destroy event handler*/
	g_signal_connect(window, "destroy", G_CALLBACK (destroy), NULL);

	/*window contianer width*/
	gtk_container_set_border_width(GTK_CONTAINER (window), 100);

	/*lable for button*/
	button = gtk_button_new_with_label("Hello World");

	/*pass the helloWorld_print function when button is pressed*/
	g_signal_connect(button, "clicked", G_CALLBACK (helloWorld_print), NULL);

	/*destroy the window when clicked*/
   g_signal_connect_swapped(button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

	/*put button into the window*/
	gtk_container_add(GTK_CONTAINER (window), button);

	/*display the button*/
	gtk_widget_show(button);

	/*display the window*/
	gtk_widget_show (window);
	
	/*main calls all GTK events*/
	gtk_main();

}

/* callback function print function */
static
void
helloWorld_print( GtkWidget *widget, gpointer data)
{
    g_print ("Hello World\n");
}

/*pop up dialog on quiting*/
static 
gboolean 
delete_event( GtkWidget *widget, GdkEvent *event, gpointer data)
{
    g_print ("delete event occurred\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete-event". */

    return TRUE;
}

/* destroy callback */
static 
void 
destroy( GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}
