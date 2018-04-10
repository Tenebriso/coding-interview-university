#include "dynamic_array.h"
#include <errno.h>

struct dynamic_array *new_empty_dynamic_array(void)
{
	struct dynamic_array *new_darr;
	new_darr = malloc(sizeof(struct dynamic_array));
	new_darr->size = 0;
	new_darr->capacity = BASE_SIZE;
	new_darr->arr = malloc(BASE_SIZE * sizeof(int));
	return new_darr;
}

struct dynamic_array *new_dynamic_array(long int capacity)
{
	struct dynamic_array *new_darr;
	int round_capacity = 0;

	if (capacity & !(capacity & (capacity - 1)))
		return new_empty_dynamic_array();
	/* make capacity the closest greater power of two */
	while (round_capacity < capacity)
		round_capacity <<= 1;
	capacity = round_capacity;
    new_darr = malloc(sizeof(struct dynamic_array));
	new_darr->size = 0;
	new_darr->capacity = capacity;
	new_darr->arr = malloc(capacity * sizeof(int));
	return new_darr;
}

long int size(struct dynamic_array *darr)
{
	return darr->size;
}

long int capacity(struct dynamic_array *darr)
{
	return darr->capacity;
}

int is_empty(struct dynamic_array *darr) 
{
	return (darr->size == 0);
}

int at(struct dynamic_array *darr, long int index)
{
	return darr->arr[index];
}

void double_capacity(struct dynamic_array *darr)
{
	struct dynamic_array *new_darr;
	long int i;

	new_darr = malloc(2 * darr->capacity * sizeof(struct dynamic_array));
	for (i = 0; i < darr->size; i++)
		new_darr->arr[i] = darr->arr[i];
	new_darr->capacity = darr->capacity * 2;
	new_darr->size = darr->size;
	free(darr);
	*darr = *new_darr;
}

void halve_capacity(struct dynamic_array *darr)
{
	struct dynamic_array *new_darr;
	long int i;

	new_darr = malloc(darr->capacity / 2 * sizeof(struct dynamic_array));
	for (i = 0; i < darr->size; i++)
		new_darr->arr[i] = darr->arr[i];
	new_darr->capacity = darr->capacity / 2;
	new_darr->size = darr->size;
	free(darr);
	*darr = *new_darr;
}

void push(struct dynamic_array *darr, int val)
{
	if (darr->size == darr->capacity) 
		double_capacity(darr);
	darr->arr[darr->size] = val;
	darr->size += 1;
}

int insert(struct dynamic_array *darr, long int index, int value)
{
	long int i;
	
	if (index < 0 || index > darr-> size) {
		printf("ERROR: index out of bounds\n");
		return -EINVAL;
	}
	if (darr->size == darr->capacity)
		double_capacity(darr);
	for (i = darr->size; i > index; i--)
		darr->arr[i] = darr->arr[i - 1];
	darr->arr[index] = value;
	
	return 0;
}

void prepend(struct dynamic_array *darr, int value)
{
	long int i;
	if (darr->size == darr->capacity)
		double_capacity(darr);
	for (i = darr->size; i > 0; i--)
		darr->arr[i] = darr->arr[i - 1];
	darr->arr[0] = value;
}

int pop(struct dynamic_array *darr)
{
	int ret_val;

	if (darr->size == 0)
	{
		printf("ERROR: empty array\n");
		return -EINVAL;
	}
	ret_val = darr->arr[darr->size - 1];
	darr->size -= 1;
	if (darr->size < 4 * darr->capacity)
		halve_capacity(darr);
	return ret_val;
}

int delete(struct dynamic_array *darr, long int index)
{
	int ret_val;
	long int i;

	if (index < 0 || index >= darr->size) {
		printf("ERROR: index out of bounds");
		return -EINVAL;
	} else if (darr->size == 0) {
		printf("ERROR: empty array");
		return -EINVAL;
	}
	ret_val = darr->arr[index];
	for (i = index; i < darr->size - 1; i++)
		darr->arr[i] = darr->arr[i + 1];
	darr->size -= 1;
	if (darr->size < 4 * darr->capacity)
		halve_capacity(darr);
	return ret_val;
}

long int find(struct dynamic_array *darr, int value)
{
	long int i;
	
	for (i = 0; i < darr->size; i++)
		if (darr->arr[i] == value)
			return i;
	return -1;
}
