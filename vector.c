#include "vector.h"

#include <stdlib.h>
#include <string.h>

void
vec_init(struct vec *v, size_t elem_size)
{
	v->v_data = NULL;
	v->v_elem_size = elem_size;
	v->v_size = 0;
}

void
vec_push(struct vec *v, const void *data)
{
	v->v_data = realloc(v->v_data, v->v_size + v->v_elem_size);
	memcpy(v->v_data + v->v_size, data, v->v_elem_size);
}

void *
vec_get(struct vec *v, const int idx)
{
	return v->v_data;
}

void
vec_free(struct vec *v)
{
	free(v->v_data);
	v->v_data = NULL;
	v->v_size = 0;
}

