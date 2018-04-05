#include <stdio.h>
#include <stdlib.h>

#define BASE_SIZE	16

struct dynamic_array {
	int *arr;
	long int size;
	long int capacity;
};

// create empty array of given size
struct dynamic_array new_dynamic_array(long int capacity);

// create empty array of standard size
struct dynamic_array new_empty_dynamic_array(void);

// number of currently held items
long int size(void);

// total capacity of array
long int capacity(void);

// add element at the end of array
void push(int val);

//add element at index
int add_at(long int index, int value);

// remove and return element at the end
int pop(void);

// remove and return element at index
int remove_at(long int index);
