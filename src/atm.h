#ifndef __ATM_H__
#define __ATM_H__

enum {
	ATM_OK,
	ATM_ERROR,
};

enum atm_state {
	IN_SERVICE,
	OUT_OF_SERVICE,
	IN_USE,
};

struct atm {
	enum atm_state a_state;
};

#endif
