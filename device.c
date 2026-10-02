#include "device.h"

void
device_init(struct device *d)
{
	d->d_state = STATE_OK;
}
