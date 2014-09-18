
/*
** Genera una tabella di conversione delle tempera-
** ture da Fahreneheit a Chelsius
**
** Tratto, con adattamenti, da Kernighan, Ritchie: 
** The C programming language, Patience Hall PTR.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
	int lower, upper, step;
	float fahr, chelsius;

	lower = 0; /* Valore minimo, in gradi F,
			   ** della tabella */
	upper = 300; /* Valore massimo, in grafi F,
				 ** della tabella */
	step = 20; /* Passo d'incremento della tabella */

	fahr = lower;
	while ( fahr <= upper ) {
		chelsius = (5.0/9.0) * (fahr - 32.0);
		printf ("%3.0f %6.1f\n", fahr, chelsius);
		fahr = fahr + step;
	}

	exit(EXIT_SUCCESS);
}
