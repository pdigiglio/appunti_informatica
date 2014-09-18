/*
** Questo programma stabilisce se un numero intero
** e' primo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) { 
	/* dichiaro i primi 10 numeri primi */
	int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	/* numero che verra' letto dal programma */
	int num;
	/* variabile di controllo dello stato di "if" */
	int success;
	int i, div; /* contatori */

	printf("Inserire un numero intero: ");
	scanf("%d", &num);
	
	success = 1; /* status del primo ciclo */
	i = 0;
	while ( i < 10 ) {
		/* divide "num" per i numeri primi in p[] */
		if ( num%p[i] == 0 && num != p[i] ) {
			printf("Il numero non e' primo\n");
			/* cambia lo status del ciclo */
			success = 0;
			break; /* esce dal ciclo */
		}
		else
			i = i+1;
	}
	
	/* viene eseguito solo se lo status del primo
	** ciclo e' diverso da 0 */
	if ( success != 0 ) {
		/* divisore del numero inserito. Lo incre-
		** mento di 2 in modo che resti dispari */
		div = p[9]+2; 
		while ( div <= num/2 ) {
			if ( num%div == 0 ) {
				printf("Il numero non e' primo\n");
				/* cambia lo status del ciclo */
				success = 0;
				break /* esce dal ciclo */
			}
			else
				div = div+2;
		}
		
		if ( success == 1 )
			printf("Il numero e' primo\n");
	}

	exit(EXIT_SUCCESS);
}