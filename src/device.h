#ifndef __DEVICE_H__
#define __DEVICE_H__

#define STATE_OK 0
#define STATE_ERROR 1

struct device {
	int d_state;
};

void device_init(struct device *d);

#endif
