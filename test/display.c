#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "screen.h"

enum mode {
	STD_SCREEN,
	ERROR_SCREEN,
};

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
	fprintf(stderr, "usage: %s file [-s screen] [-e message] \n",
	    getprogname());
	exit(EXIT_FAILURE);
}

/*
 * Display the screen given in argument.
 */
int
main(int argc, char *argv[])
{
	char *file;
	char *scr;
	char *msg;
	toml_result_t result;
	enum mode mode;
	int ch = 0;

	if (argc < 3)
		usage();

	file = argv[1];

	argv[1] = argv[0];
	argc--;
	argv++;

	while ((ch = getopt(argc, argv, "f:s:e:")) != -1) {
		switch (ch) {
		case 'f':
			file = optarg;
			break;
		case 's':
			mode = STD_SCREEN;
			scr = optarg;
			break;
		case 'e':
			mode = ERROR_SCREEN;
			msg = optarg;
			break;
		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;

	if (argc != 0)
		usage();

	init_screen(&result, file);
	print_terminal_size();
	if (mode == STD_SCREEN)
		display(&result, scr);
	else
		display_error(msg);
	end_screen(&result);

	return (EXIT_SUCCESS);
}
