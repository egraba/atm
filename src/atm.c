#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "atm.h"
#include "screen.h"

static void
usage()
{
	fprintf(stderr, "usage: %s file\n", getprogname());
	exit(EXIT_FAILURE);
}

/*
 * The main.
 */
int
main(int argc, char *argv[])
{
	toml_result_t result;

	if (argc != 2)
		usage();

	init_screen(&result, argv[1]);
	display(&result, "idle-loop");
	end_screen(&result);

	return (EXIT_SUCCESS);
}
