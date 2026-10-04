#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>
#include <tomlc17.h>

#include "atm.h"
#include "device.h"
#include "screen.h"
#include "vector.h"

void
devices_init(struct atm *a)
{
	struct device card_reader = {0};
	struct device cash_dispenser = {0};
	struct device epp = {0};
	struct device printer = {0};

	vec_init(&a->a_devices, sizeof(struct device)); 
	vec_push(&a->a_devices, &card_reader);
	vec_push(&a->a_devices, &cash_dispenser);
	vec_push(&a->a_devices, &epp);
	vec_push(&a->a_devices, &printer);

	for (size_t i = 0; i < a->a_devices.v_size; i++)
		device_init((struct device *) vec_get(&a->a_devices));
}

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
	struct atm a = {0};
	toml_result_t result;

	if (argc != 2)
		usage();

	a.a_state = OUT_OF_SERVICE;
	devices_init(&a);

	setup_screen(&result, argv[1]);
	display(&result, "idle-loop");
	tear_down_screen(&result);

	return (EXIT_SUCCESS);
}
