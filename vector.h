#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>

struct vec {
	void *v_data;
	size_t v_elem_size;
	size_t v_size;
};

void vec_init(struct vec *v, size_t elem_size);
void vec_push(struct vec *v, const void *data);
void *vec_get(struct vec *v);
void *vec_pop(struct vec *v, size_t elem_size);
void vec_free(struct vec *v);

#endif
