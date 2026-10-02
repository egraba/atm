#include <stdio.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "screen.h"

int
setup_screen(const char *filename, toml_result_t *result)
{
	*result = toml_parse_file_ex(filename);

	if (!result->ok) {
		fprintf(stderr, "%s\n", result->errmsg);
		return (SCREEN_ERROR);
	}
	
	initscr();

	return (SCREEN_OK);
}

void
tear_down_screen(toml_result_t *result)
{
	endwin();
	toml_free(*result);
}

static int
find_x(const char *message)
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
display_idle_loop(toml_result_t *result)
{
	toml_datum_t instr = toml_seek(result->toptab, "idle-loop.instruction");

	if (instr.type != TOML_STRING) {
		fprintf(stderr, "%s\n",
		    "missing or invalid idle-loop.instruction property");
		return (SCREEN_ERROR);
	}

	mvprintw(find_y(), find_x(instr.u.s), instr.u.s);
	getch();
	refresh();

	return (SCREEN_OK);
}
