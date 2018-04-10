#define BASE_SIZE	16

struct dynamic_array {
	int *arr;
	long int size;
	long int capacity;
};

extern struct dynamic_array *darr;

// create empty array of standard capacity
struct dynamic_array new_empty_dynamic_array(void);

// create empty array of given capacity
struct dynamic_array new_dynamic_array(long int capacity);

// number of currently held items
long int size(void);

// total capacity of array
long int capacity(void);

// returns true if array is empty
int is_empty(void);

// return the item at index
int at(long int index);

// add element at the end of array
void push(int val);

//add element at index
int insert(long int index, int value);

// add element at the start of array, before index 0
void prepend(int value);

// remove and return element at the end
int pop(void);

// remove and return element at index
int remove_at(long int index);

// return index where the value is found, -1 if not found
long int find(int value);
