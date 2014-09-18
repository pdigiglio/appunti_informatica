#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int x;
	printf("***CTRL+D per ucire***\n");
	x = getchar();
	while ( x != EOF )
	{
		putchar(x);
		x = getchar();
	}
	exit(EXIT_SUCCESS);
}
