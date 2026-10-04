#include <stdio.h>
#include <stdlib.h>

#include <tomlc17.h>

#include "screen.h"

static int
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
	display(&result, argv[2]);
	tear_down_screen(&result);

	return (EXIT_SUCCESS);
}
