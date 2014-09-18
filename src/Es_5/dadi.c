/*
** Questo  programma simula una serie di 1000 lanci 
** di due dadi. Esso stampare anche, alla fine della
** serie di lanci, la percentuale di uscita di ogni
** risultato (per risultato si intende la somma dei
** punteggi dei due dadi in ogni lancio).
**
** Alla fine, traccia un istogramma orizzontale del-
** le frequenze dei risultati.
*/

#include <stdio.h>
#include <stdlib.h>
               
int main (void) {
	int b, x;
	printf("Inserisci un intero per b: ");
	scanf("%d", &b);
	printf("Inserisci un intero per X(0): ");
	scanf("%d", &x);
		
	/* contatore ciclo, contatore numeri */
	int e, n[11]; 
	/* riempio il vettore di zeri */
	e = 0;
	while ( e < 12 ) {
		n[e] = 0;
		e++;
	}

	/* produco i risultati dei dadi */
	int i = 1;
	while ( i <= 10 ) {
		int g = 1;
		while ( g <= 10) {
			int h=1;
			while ( h <= 10) {
				x = (b*x)%11 + 10;
				n[x-10] = n[x-10] + 1;
				h++;
			}
			b++; /* in modo da aumentare il fattore casuale */
			g++;
		}
		x++; /* in modo da aumentare il fattore casuale */
		i++;
	}

	
	/* stampo la frequenza dei risultati trovati */
	int f = 0;
	while ( f < 11 ) {
		printf("La percentuale del risultato %d e':"
		"%lf per cento.\n", f+2, (double) n[f]/10);
		f++;
	}
	
	/* stampo un istogramma */
	int r;
	r = 0;
	printf("\nISTOGRAMMA\n");
	printf("Numero : percentuale ( '-' = 1%)\n");
	while ( r < 11 ) {	
		printf("%d : ", r+2);
		int t;
		t = 0;
		while ( t < ((n[r]-2)/10) ) {
			printf("-");
			t++;
		}
		if ( t = (n[r]-2)/10 ) {
			printf("-|\n");
			t++;
		}
		r++;
	}
	exit(EXIT_SUCCESS);
}