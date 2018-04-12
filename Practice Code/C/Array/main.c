#include "minunit.h"
#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

struct dynamic_array *darr;
int tests_run = 0;

void initializer() 
{
	darr = new_empty_dynamic_array();
}

static char * test_push() {
	push(darr, 1);
	push(darr, 2);
	mu_assert("error, darr[0] != 1", darr->arr[0] == 1);
	mu_assert("error, darr[1] != 2", darr->arr[1] == 2);
	mu_assert("error, size not updated to 2", darr->size == 2);
	return 0;
}

static char * test_find() {
	mu_assert("error, 2 is not found at index 1", 1 == find(darr, 2));
	mu_assert("error, 3 is non-existent and found", -1 == find(darr, 3));
	return 0;
}

static char * test_insert() {
	insert(darr, 2, 9);
	mu_assert("error, 9 is not added on position 2", darr->arr[2] == 9);
	insert(darr, 1, 7);
	mu_assert("error, 7 is not added on position 1", darr->arr[1] == 7);
	mu_assert("error, size not updated to 4", darr->size == 4);
	return 0;
}

static char * test_delete() {
	delete(darr, 1);
	mu_assert("error, 2 is not on position 1", darr->arr[1] == 2);
	mu_assert("error, size not decreased to 3", darr->size == 3);
	mu_assert("error, 7 deleted and found", find(darr, 7) == -1);
}

static char * test_prepend() {
	prepend(darr, 11);
	mu_assert("error, 11 not found at index 0", darr->arr[0] == 11);
	mu_assert("error, size not updated to 4", darr->size == 4);
	mu_assert("error, first element not shifted", darr->arr[1] == 1);
}

static char * test_pop() {
	int ret_val = darr->arr[darr->size - 1];
	long int curr_size = darr->size;
	mu_assert("error, invalid element removed", ret_val == pop(darr));
	mu_assert("error, size not decreased", darr->size == curr_size - 1);
}

static char * test_remove() {
	remove_val(darr, 1);
	mu_assert("error, 1 removed and found", find(darr, 1) == -1);
	mu_assert("error, size not decreased to 2", darr->size == 2);
	mu_assert("error, elements not shifted after first remove", darr->arr[1] == 2);
}

static char * test_everything() {
	darr = new_dynamic_array(7);
	mu_assert("error, invalid capacity created, expected 8", darr->capacity == 8);
	mu_assert("error, non-empty size", darr->size == 0);
	// push
	puts("push");
	push(darr, 0);
	mu_assert("error, size not increased to 1", darr->size == 1);
	mu_assert("error, element incorrectly pushed", darr->arr[0] == 0);
	// delete
	puts("delete");
	delete(darr, 0);
	mu_assert("error, element not correctly deleted", find(darr, 0) == -1);
	mu_assert("error, size not decreased", darr->size == 0);
	// is_empty
	puts("is_empty");
	mu_assert("error, empty reporting non empty", is_empty(darr) == 1);
	push(darr, 1);
	// prepend
	puts("prepend");
	prepend(darr, 2);
	mu_assert("error, element incorrectly prepended", darr->arr[0] == 2);
	mu_assert("error, elements not shifted", darr->arr[1] == 1);
	mu_assert("error, size not increased", darr->size == 2);
	// find
	puts("find");
	mu_assert("error, find returns incorrect index for 2", find(darr, 2) == 0);
	mu_assert("error, find returns incorrect index for 1", find(darr, 1) == 1);
	// insert
	puts("insert");
	insert(darr, 1, 3);
	mu_assert("error, element incorrectly inserted", darr->arr[1] == 3);
	mu_assert("error, elements not shifted", darr->arr[2] == 1);
	mu_assert("error, size not increased", darr->size == 3);
	// pop
	puts("pop");
	int ret_val = darr->arr[darr->size - 1];
	long int curr_size = darr->size;
	mu_assert("error, invalid element popped", pop(darr) == ret_val);
	mu_assert("error, size not decreased after pop", curr_size - 1 == darr->size);
	// double capacity
	puts("double capacity");
	push(darr, 4);
	push(darr, 6);
	push(darr, 5);
	mu_assert("error, non doubled capacity", darr->capacity == 8);
	// halve capacity
	puts("halve capacity");
	pop(darr);
	pop(darr);
	pop(darr);
	pop(darr);
	mu_assert("error, non halved capacity", darr->capacity == 4);
}

static char * all_tests() {
	mu_run_test(test_push);
	mu_run_test(test_find);
	mu_run_test(test_insert);
	mu_run_test(test_delete);
	mu_run_test(test_prepend);
	mu_run_test(test_pop);
	mu_run_test(test_remove);
	mu_run_test(test_everything);
	return 0;
}

int main(int argc, char **argv) {
	initializer();
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
