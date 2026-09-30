#include <string.h>

#include <ncurses.h>

#include "screen.h"

static int
find_x(char *message)
{
	return ((COLS - sizeof(message)) / 2);
}

static int
find_y()
{
	/*
	 * Assumption: the message is a one-line one.
	 */
	return ((LINES - 1) / 2);
}

int
display_idle_loop()
{
	char *m = strdup("Insert your card");

	mvprintw(find_y(), find_x(m), m);
}

int
display_out_of_service()
{
	return (0);
}
