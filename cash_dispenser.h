#ifndef __CASH_DISPENSER_H__
#define __CASH_DISPENSER_H__

#include "device.h"

#define CASH_DISPENSER_OK 0
#define CASH_DISPENSER_UNKNOWN 1
#define CASH_DISPENSER_ERROR 2

struct cash_dispenser {
	struct device cd_device;
}

int open();
int close();

int light_on();
int light_off();
int light_flash();

#endif
