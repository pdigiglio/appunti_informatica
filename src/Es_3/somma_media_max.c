/*
** Questo programma legge dieci numeri interi, ne 
** calcola la somma e la media, e stabilisce qual
**  e' il numero piu' grande.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (void) {
	/* vettore, somma, massimo numero*/
	int p[10], somma, max; 
	int h, i, f; /* contatori */
	
	h = 0;
	while ( h < 10 ) {
		printf("(%d) Inserire numero: ", h+1);
		scanf("%d", &p[h]);
		h = h+1;
	}

	i = 0;
	somma = 0;
	while ( i < 10 ) {
		somma = somma + p[i];
		i = i+1;
	}
	printf("\nSomma: %d\n", somma);
	printf("Media: %lf\n", (double) somma/10);

	f = 0;
	while ( f < 10 ) {
		if ( p[f] < p[f+1])
			max = p[f+1];
		else 
			max = p[f];
		f = f+1;
	}
	printf("Il numero piu' grande e': %d\n", max);
	exit(EXIT_SUCCESS);
}