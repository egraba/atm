#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <tomlc17.h>

/*
 * Return codes.
 */
enum rc {
	SCREEN_OK,
	SCREEN_ERROR,
};

/* Setup */
int setup_screen(toml_result_t *result, const char* filename);
void tear_down_screen(toml_result_t *result);

/* Generic screens */
int display(toml_result_t *result, const char *screen);

/* Error screens */
int display_error(const char *message);

#endif
