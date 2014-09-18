/*
** Questo programma legge venti numeri interi, li 
** carica in un vettore, e successivamente calcola
** la somma dei quadrati e la somma dei cubi dei va-
** lori nel vettore, stampandoli in una tabella.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
	int v[20]; /* vettore dei numeri inseriti */
	int i, e, f; /* contatori */
	int quad, cub; /* somme dei quadrati e dei cubi */

	i = 0;
	/* legge i 20 valori e li carica nel vettore */
	while ( i < 20 ) {
		printf("(%d) Inserire un numero intero: ",
		i+1);
		scanf("%d", &v[i]);
		i = i+1;
	}

	e = 1;
	/* calcola le somme quadratiche */
	quad = v[0]*v[0];
	while ( e < 20 ) {
		quad = quad + v[e]*v[e];
		e = e+1;
	}

	f = 1;
	/* calcola le somme dei cubi */
	cub = v[0]*v[0]*v[0]; 
	while ( f < 20 ) {
		cub = cub + v[f]*v[f]*v[f];
		f = f+1;
	}

	printf("Somma dei quadrati: %d || Somma dei cub"
	"i: %d \n", quad, cub);

	exit (EXIT_SUCCESS);
}