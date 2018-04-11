#include <stdio.h>
#include <stdlib.h>

#define BASE_SIZE	16

struct dynamic_array {
	int *arr;
	long int size;
	long int capacity;
};


// create empty array of standard capacity
struct dynamic_array *new_empty_dynamic_array(void);

// create empty array of given capacity
struct dynamic_array *new_dynamic_array(long int capacity);

// number of currently held items
long int size(struct dynamic_array *darr);

// total capacity of array
long int capacity(struct dynamic_array *darr);

// returns true if array is empty
int is_empty(struct dynamic_array *darr);

// return the item at index
int at(struct dynamic_array *darr, long int index);

// add element at the end of array
void push(struct dynamic_array *darr, int val);

//add element at index
int insert(struct dynamic_array *darr, long int index, int value);

// add element at the start of array, before index 0
void prepend(struct dynamic_array *darr, int value);

// return index where the value is found, -1 if not found
long int find(struct dynamic_array *darr, int value);

// remove and return element at the end
int pop(struct dynamic_array *darr);

// remove and return element at index
int delete(struct dynamic_array *darr, long int index);

// finds element and returns all its occurances
int remove_val(struct dynamic_array *darr, int value);

// display all element of array
void show_array(struct dynamic_array *darr);

