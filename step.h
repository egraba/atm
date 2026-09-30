#ifndef __STEP_H__
#define __STEP_H__

#include <stdbool.h>

#define STEP_OK 0
#define STEP_ERROR 1

typedef struct {
    void* action;
    char* screen;
    bool is_async;
} step;

int execute(step* s);

#endif
