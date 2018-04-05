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
	printf("*a + 2 = %d\n", *a + 2);
	printf("a[0] = %d\n", a[0]);
	printf("*a = %d\n", *a);
	printf("a = %d\n", a);
	a = a + 2;
//	*a = *a + 2;
	printf("new a[0] = %d\n", a[0]);
	printf("new a = %d\n", *a);
	printf("new a[-1] = %d\n", a[-1]);
	printf("new a[-2] = %d\n", a[-2]);
		
	/* static array */
	printf("\n<---- Dinamic array --->\n");
	int b[10];
	for ( i = 0; i < 10; i++)
		b[i] = i;
	printf("b + 2 [0] = %d\n", (b + 2)[0]);
	printf("*b + 2 = %d\n", *b + 2);
	printf("b[0] = %d\n", b[0]);
	printf("*b = %d\n", *b);
	printf("b = %d\n", b);
	*b = *b + 2;
	printf("new b[0] = %d\n", b[0]);
	printf("new b = %d\n", *b);
	printf("new b[-1] = %d\n", b[-1]);
	printf("new b[-2] = %d\n", b[-2]);
	
	/* initialized array */
	printf("\n<---- Initialized array --->\n");
	int c[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("c + 2 [0] = %d\n", (c + 2)[0]);
	printf("*c + 2 = %d\n", *c + 2);
	printf("c[0] = %d\n", c[0]);
	printf("*c = %d\n", *c);
	printf("c = %d\n", c);
	*c = *c + 2;
	printf("new c[0] = %d\n", c[0]);
	printf("new c = %d\n", *c);
	printf("new c[-1] = %d\n", c[-1]);
	printf("new c[-2] = %d\n", c[-2]);

	/* initialized array */
	printf("\n<---- Initialized array --->\n");
	int d[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("d + 2 [0] = %d\n", (d + 2)[0]);
	printf("*d + 2 = %d\n", *d + 2);
	printf("d[0] = %d\n", d[0]);
	printf("*d = %d\n", *d);
	printf("d = %d\n", d);
	*d = *d + 2;
	printf("new d[0] = %d\n", d[0]);
	printf("new d = %d\n", *d);
	printf("new d[-1] = %d\n", d[-1]);
	printf("new d[-2] = %d\n", d[-2]);


	
	return 0;
}
