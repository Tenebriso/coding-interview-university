#include "dynamic_array.h"
#include <errno.h>

static struct dynamic_array *darr;

struct dynamic_array new_dynamic_array(long int capacity)
{
	struct dynamic_array *new_darr;
        new_darr = malloc(capacity * sizeof(struct dynamic_array));
	new_darr->size = 0;
	new_darr->capacity = capacity;
	return *new_darr;
}

struct dynamic_array new_empty_dynamic_array(void)
{
	struct dynamic_array *new_darr;
	new_darr = malloc(BASE_SIZE * sizeof(struct dynamic_array));
	new_darr->size = 0;
	new_darr->capacity = BASE_SIZE;
	return *new_darr;
}

long int size(void)
{
	return darr->size;
}

long int capacity(void)
{
	return darr->capacity;
}

void double_capacity(void)
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

void halve_capacity(void)
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

void push(int val)
{
	if (darr->size == darr->capacity) 
		double_capacity();
	darr->arr[darr->size] = val;
	darr->size += 1;
}

int add_at(long int index, int value)
{
	long int i;
	
	if (index < 0 || index > darr-> size) {
		printf("ERROR: index out of bounds\n");
		return -EINVAL;
	}
	if (darr->size == darr->capacity)
		double_capacity();
	for (i = darr->size; i > index; i--)
		darr->arr[i] = darr->arr[i - 1];
	darr->arr[index] = value;
	
	return 0;
}

int pop(void)
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
		halve_capacity();
	return ret_val;
}

int remove_at(long int index)
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
		halve_capacity();
	return ret_val;
}

int main()
{

	return 0;
}
