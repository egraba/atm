#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "screen.h"

/*
 * Parse TOML config file and initialise screen (ncurses calls).
 */
int
init_screen(toml_result_t *result, const char *filename)
{
	*result = toml_parse_file_ex(filename);

	if (!result->ok) {
		fprintf(stderr, "%s\n", result->errmsg);
		return (SCREEN_ERROR);
	}

	initscr();
	curs_set(0);

	return (SCREEN_OK);
}

/*
 * End screen (ncurses calls) and free TOML config file.
 */
void
end_screen(toml_result_t *result)
{
	endwin();
	toml_free(*result);
}

/*
 * Return the column to display a centered message.
 */
static inline int
x_center(const char *message)
{
	return ((COLS - strlen(message)) / 2);
}

/*
 * Return the line to display a centered messsage.
 * Assumption: the message is a one-line one.
 */
static inline int
y_center(void)
{
	return ((LINES - 1) / 2);
}

/*
 * Print the headline.
 * Healine is a centered text at the top of the screen.
 */
static void
print_headline(const char *message)
{
	mvprintw(1, x_center(message), message);
}

/*
 * Print the instruction.
 * Instruction is centered text in the middle of the screen.
 */
static void
print_instruction(const char *message)
{
	mvprintw(y_center(), x_center(message), message);
}

/*
 * Display a screen.
 * The screens are defined in a TOML file.
 * They consists in headlines, instructions and function keys.
 */
int
display(toml_result_t *result, const char *screen)
{
	char *hl_node = (char *) malloc(BUFSIZ);
	char *instr_node = (char *) malloc(BUFSIZ);
	toml_datum_t scr;
	toml_datum_t hl;
	toml_datum_t instr;
	bool has_hl = false;
	bool has_instr = false;

	/* Check that the screen exists. */
	scr = toml_seek(result->toptab, screen);
	if (scr.type == TOML_UNKNOWN) {
		fprintf(stderr, "screen %s doesn't exist\n", screen);
		return (SCREEN_ERROR);
	}

	/* 
	 * Check that the screen is valid.
	 * The screen must contain:
	 * - either a headline or an instruction
	 * - function keys (optional)
	 */
	stpcpy(hl_node, screen);
	strcat(hl_node, ".headline");
	hl = toml_seek(result->toptab, hl_node);
	if (hl.type != TOML_STRING)
		has_hl = false;
	else
		has_hl = true;

	stpcpy(instr_node, screen);
	strcat(instr_node, ".instruction");
	instr = toml_seek(result->toptab, instr_node);
	if (instr.type != TOML_STRING)
		has_instr = false;
	else
		has_instr = true;

	if (!has_hl && !has_instr) {
		fprintf(stderr,
		    "both %s and %s properties are missing or invalid\n",
		    hl_node, instr_node);
		free(hl_node);
		free(instr_node);

		return (SCREEN_ERROR);
	}

	/* Print the screen. */
	if (has_hl) {
		print_headline(hl.u.s);
		free(hl_node);
	}

	if (has_instr) {
		print_instruction(instr.u.s);
		free(instr_node);
	}

	getch();
	refresh();

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
