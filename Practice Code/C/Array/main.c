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

	return 0;
}

static char * test_find() {
	mu_assert("error, 2 is not found at index 1", 1 == find(darr, 2));
	mu_assert("error, 3 is non-existent and found", -1 == find(darr, 3));

	return 0;
}

static char * all_tests() {
	mu_run_test(test_push);
	mu_run_test(test_find);
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
