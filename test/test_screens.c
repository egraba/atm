#include <stdio.h>
#include <stdlib.h>

#include <tomlc17.h>

#include "screen.h"

static int
usage()
{
	fprintf(stderr, "usage: %s file\n", getprogname());
	return (EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
	toml_result_t result;

	if (argc != 2)
		usage();

	setup_screen(argv[1], &result);
	display_idle_loop(&result);
	tear_down_screen(&result);

	return (EXIT_SUCCESS);
}
