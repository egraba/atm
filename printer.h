#ifndef __PRINTER_H__
#define __PRINTER_H__

#include "device.h"

#define PRINTER_OK 0
#define PRINTER_ERROR 1

struct printer {
	struct device p_device;
}

int print();

int light_on();
int light_off();
int light_flash();

#endif
