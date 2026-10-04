#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "screen.h"

int
setup_screen(toml_result_t *result, const char *filename)
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

static void
print_headline(const char *message)
{
	mvprintw(1, find_x(message), message);
}

static void
print_instruction(const char *message)
{
	mvprintw(find_y(), find_x(message), message);
}

int
display(toml_result_t *result, const char *screen)
{
	char *hl_node = (char *) malloc(BUFSIZ);
	char *instr_node = (char *) malloc(BUFSIZ);
	toml_datum_t hl, instr;

	strcpy(hl_node, screen);
	strcat(hl_node, ".headline");
	hl = toml_seek(result->toptab, hl_node);

	strcpy(instr_node, screen);
	strcat(instr_node, ".instruction");
	instr = toml_seek(result->toptab, instr_node);

	if (hl.type != TOML_STRING && instr.type != TOML_STRING) {
		fprintf(stderr,
		    "both %s and %s properties are missing or invalid\n",
		    hl_node, instr_node);
		return (SCREEN_ERROR);
	}

	print_headline(hl.u.s);
	print_instruction(instr.u.s);
	getch();
	refresh();

	free(hl_node);
	free(instr_node);

	return (SCREEN_OK);
}

/*
 * Display an error screen.
 * 
 * Note: There is no configuration for these screens as errors cannot be
 * hardcoded in a config file.
 */
int
display_error(const char *message)
{
	print_instruction(message);
	getch();
	refresh();

	return (SCREEN_OK);
}
