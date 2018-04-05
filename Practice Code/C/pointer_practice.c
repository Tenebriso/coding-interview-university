#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* dinamically allocated array */
	printf("\n<---- Static array --->\n");
	int *a = malloc(10 * sizeof(int)), i;
	
	for (i = 0; i < 10; i++)
		a[i] = i;
	printf("a + 2 [0] = %d\n", (a + 2)[0]);
	printf("a[0] = %d\n", a[0]);
	a = a + 2;
	printf("new a[0] = %d\n", a[0]);
	printf("new a[-1] = %d\n", a[-1]);
		
	/* static array */
	printf("\n<---- Dinamic array --->\n");
	int b[10];
	for ( i = 0; i < 10; i++)
		b[i] = i;
	printf("b + 2 [0] = %d\n", (b + 2)[0]);
	printf("b[0] = %d\n", b[0]);
	*b = *b + 2;
	printf("new b[0] = %d\n", b[0]);
	printf("new b[-1] = %d\n", b[-1]);
	
	/* initialized array */
	printf("\n<---- Initialized array --->\n");
	int c[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("c + 2 [0] = %d\n", (c + 2)[0]);
	printf("c[0] = %d\n", c[0]);
	*c = *c + 2;
	printf("new c[0] = %d\n", c[0]);
	printf("new c[-1] = %d\n", c[-1]);


	return 0;
}
