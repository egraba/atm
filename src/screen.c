#include <string.h>

#include <ncurses.h>

#include "screen.h"

void
setup_screen()
{
	initscr();
}

void
tear_down_screen()
{
	endwin();
}

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

void
display_idle_loop()
{
	char *m = strdup("Insert your card");

	mvprintw(find_y(), find_x(m), m);
	getch();
	refresh();
}
