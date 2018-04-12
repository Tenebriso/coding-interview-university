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

unsigned long upper_power_of_two(unsigned long v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;

}

struct dynamic_array *new_dynamic_array(long int capacity)
{
	struct dynamic_array *new_darr;
	int round_capacity = 0;

	if (capacity & !(capacity & (capacity - 1)))
		return new_empty_dynamic_array();
	/* make capacity the closest greater power of two */
	capacity = upper_power_of_two(capacity);
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

void show_array(struct dynamic_array *darr)
{
	long int i;
	printf("SIZE %ld CAPACITY %ld\n", darr->size, darr->capacity);
	for (i = 0; i < darr->size; i++)
		printf("%d ", darr->arr[i]);
	printf("\n");
}

int double_capacity(struct dynamic_array *darr)
{
	struct dynamic_array *new_darr;
	long int i;
	new_darr = malloc(sizeof(struct dynamic_array));
	new_darr->capacity = darr->capacity * 2;
	new_darr->size = darr->size;
	new_darr->arr = realloc(darr->arr, new_darr->capacity);
	if (new_darr->arr == NULL) {
		free(darr->arr);
		free(darr);
		printf("ERROR: failed doubling the array size\n");
		return -ENOMEM;
	}
	free(darr);
	darr = new_darr;	
	return 0;
}

int halve_capacity(struct dynamic_array *darr)
{
	struct dynamic_array *new_darr;
	long int i;

	if (darr->capacity == 1)
		return 0;
	new_darr = malloc(sizeof(struct dynamic_array));
	new_darr->capacity = darr->capacity / 2;
	new_darr->size = darr->size;
	new_darr->arr = realloc(darr->arr, new_darr->capacity);
	if (new_darr->arr == NULL) {
		free(darr->arr);
		free(darr);
		printf("ERROR: failed doubling the array size\n");
		return -ENOMEM;
	}
	free(darr);
	darr = new_darr;
	return 0;
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
		printf("ERROR: index out of bounds %ld\n", index);
		return -EINVAL;
	}
	if (darr->size == darr->capacity)
		double_capacity(darr);
	for (i = darr->size; i > index; i--)
		darr->arr[i] = darr->arr[i - 1];
	darr->arr[index] = value;
	darr->size += 1;
	
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
	darr->size += 1;
}

long int find(struct dynamic_array *darr, int value)
{
	long int i;
	
	for (i = 0; i < darr->size; i++)
		if (darr->arr[i] == value)
			return i;
	return -1;
}

int pop(struct dynamic_array *darr)
{
	int ret_val;

	if (darr->size == 0) {
		printf("ERROR: empty array\n");
		return -EINVAL;
	}
	ret_val = darr->arr[darr->size - 1];
	darr->size -= 1;
	if (darr->size < (darr->capacity / 4))
		halve_capacity(darr);
	return ret_val;
}

int delete(struct dynamic_array *darr, long int index)
{
	int ret_val;
	long int i;

	if (index < 0 || index >= darr->size) {
		printf("ERROR: index out of bounds %ld\n", index);
		return -EINVAL;
	} else if (darr->size == 0) {
		printf("ERROR: empty array\n");
		return -EINVAL;
	}
	ret_val = darr->arr[index];
	for (i = index; i < darr->size - 1; i++)
		darr->arr[i] = darr->arr[i + 1];
	darr->size -= 1;
	if (darr->size < (darr->capacity / 4))
		halve_capacity(darr);
	return ret_val;
}

int remove_val(struct dynamic_array *darr, int value)
{
	long int index;

	index = find(darr, value);
	if (index != -1) {
		while (index != -1) {
			if (delete(darr, index) != value) {
				printf("ERROR: error deleting element at index %ld\n", index);
				return -EINVAL;
			}
			index = find(darr, value);
		}
		return 0;
	}
	printf("ERROR: invalid value %d\n", value);
	return -EINVAL;
}

