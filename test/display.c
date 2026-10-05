#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "screen.h"

static void
print_terminal_size(void)
{
	mvprintw(LINES -1, 0, "%d x %d", LINES, COLS);
	refresh();
}

static void
usage()
{
	fprintf(stderr, "usage: %s file screen\n", getprogname());
	exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
	toml_result_t result;

	if (argc != 3)
		usage();

	setup_screen(&result, argv[1]);
	print_terminal_size();
	display(&result, argv[2]);
	tear_down_screen(&result);

	return (EXIT_SUCCESS);
}
