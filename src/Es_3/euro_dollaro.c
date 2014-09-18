/*
** Questo programma stampa una tabella di conversio-
** ne da euro a dollaro tra valori arbitrari (scel-
** ti a priori).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (void) {
	int i; /* dichiaro il contatore */
	double dollaro, sterlina;
	
	i = 1; /* primo valore del contatore */
	while ( i <= 20) {
		dollaro = i*1.4424;
		sterlina = i*0.8823;
		printf("%d euro - %lf dollari -  %lf sterli"
		"ne\n",  i, dollaro, sterlina);
		i = i+1;
	}
	
	exit(EXIT_SUCCESS);
}