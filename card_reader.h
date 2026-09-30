#ifndef __CARD_READER_H__
#define __CARD_READER_H__

#include "device.h"

#define CARD_READER_OK 0
#define CARD_READER_ERROR 1

struct card_reader {
	struct device cr_device
};

int insert();
int eject();
int capture();

int light_on();
int light_off();
int light_flash();

#endif
