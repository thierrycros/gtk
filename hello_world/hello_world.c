/*
	simple hello world with gtk
	 
	compile commands 
	gcc -o hello_world hello_world.c `pkg-config --cflags --libs gtk+-3.0'

*/

/*include window to program*/
#include "window.h"

int
main(int argc, char *argv[])
{

	/*new window*/
	window(argc, argv);

	/*return success*/
	return 0;

}

