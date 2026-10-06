#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "screen.h"

/*
 * Print terminal size at the bottom left of the terminal.
 */
static void
print_terminal_size(void)
{
	mvprintw(LINES -1, 0, "%d x %d", LINES, COLS);
	refresh();
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s file screen\n", getprogname());
	exit(EXIT_FAILURE);
}

/*
 * Display the screen given in argument.
 */
int
main(int argc, char *argv[])
{
	toml_result_t result;

	if (argc != 3)
		usage();

	init_screen(&result, argv[1]);
	print_terminal_size();
	display(&result, argv[2]);
	end_screen(&result);

	return (EXIT_SUCCESS);
}
