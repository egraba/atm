#include <stdlib.h>

#include "screen.h"

int
main()
{
	setup_screen();
	display_idle_loop();
	tear_down_screen();

	return (EXIT_SUCCESS);
}
