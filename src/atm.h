#ifndef __ATM_H__
#define __ATM_H__

#include "device.h"
#include "vector.h"

enum atm_state {
	IN_SERVICE,
	OUT_OF_SERVICE,
};

struct atm {
	enum atm_state a_state;
	struct vec a_devices;
};

enum atm_return_code {
	ATM_OK,
	ATM_ERROR,
};

void devices_init(struct atm *a);
int init_operations();
int select_protocol();
int init_customization();

int put_in_service(struct atm *a);
int put_out_of_service(struct atm *a);

#endif
