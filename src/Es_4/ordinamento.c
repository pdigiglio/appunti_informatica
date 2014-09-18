/* 
** Questo  programma  legge dodici numeri interi e 
** li carica in un vettore. Successivamente, dispone
** i numeri in ordine crescente.
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int i, p[13]; /* contatore, vettore */
	i = 0;
	while ( i < 12 ) {
		/* carico il vettore fino a p[11] */
		printf("%d) Inserire un intero: ", i+1);
		scanf("%d", &p[i]);
		i++;
	}

	int e, f; /* contatori */
	e = 0;
	while ( e < 11 ) {
		f = 0;
		while ( f < 11 ) {
			if ( p[f] > p[f+1] ) {
				/* uso p[12] come casella
				** temporanea */
				p[12] = p[f];
				p[f] = p[f+1];
				p[f+1] = p[12];
			}
			f++;
		}
	e++;
	}
	
	int g;
	g = 0;
	while ( g < 12 ) {
		printf("%d\n", p[g]);
		g++;
	}
	
	exit(EXIT_SUCCESS);
}