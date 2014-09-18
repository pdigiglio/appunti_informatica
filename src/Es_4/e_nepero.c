/* 
** Partendo dalla formula:
**
** e = Somme(0 -> + inf.)[1/k!]
**
** il programma calcola successive approssimazioni
**  del numero e.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* definisco la funzione "fattoriale" */
double fatt (int x) {
	if ( x == 0 || x == 1 )
		return 1;
	else {
		/* pongo "i = x-1" in modo che incrementando 
		** x non s'incrementi la i nel ciclo */
		int i = x-1; 
		/* La condizione e' " i > 1 " perche'
		** cosi' l'ultimo prodotto e' " x*2"
		** visto che moltiplicare per 1 e' inutile
		*/
		while ( i > 1 ) {
			x = x*i;
			i = i-1;
		}
		return x;
	}
}

/* funzione principale */
int main (void) {
	int n; /* passi della sommatoria */
	int e; /* contatore */
	double sum; /* valore della sommatoria */

	printf("Inserire il numero di passi della somma"
	"toria da eseguire: ");
	scanf("%d", &n);

	e = 0;
	sum = 0.0;
	while ( e <= n ) {
		sum = sum + 1.0/fatt(e);
		e = e+1;
	}
	
	printf("Valore (approssimato) di e: %lf\n", sum);
	exit(EXIT_SUCCESS);
}