/*
** Questo programma stabilisce se un numero e' pari
** o dispari.
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main (int argc, char * argv[]) {
	int n; /* il numero che sara' inserito */
	
	/* acquisico il numero */
    printf("Inserire un numero: ");
    scanf("%d", &n);

	/* verifico che sia pari */
	if ( n%2 != 0)
		printf("Il numero e' dispari\n");
	else
		printf("Il numero e' pari\n");

        exit(EXIT_SUCCESS);
}