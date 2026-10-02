#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

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

/*
 * The main.
 */
int
main()
{
	struct atm a = {0};

	a.a_state = OUT_OF_SERVICE;
	devices_init(&a);

	initscr();
	cbreak();
	noecho();

	display_idle_loop();
	refresh();
	getch();

	endwin();
	return (EXIT_SUCCESS);
}
