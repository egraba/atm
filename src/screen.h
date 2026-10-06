#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <tomlc17.h>

enum screen_return_code {
	SCREEN_OK,
	SCREEN_ERROR,
};

/* Setup */
int init_screen(toml_result_t *result, const char* filename);
void end_screen(toml_result_t *result);

/* Generic screens */
int display(toml_result_t *result, const char *screen);

/* Error screens */
int display_error(const char *message);

#endif
