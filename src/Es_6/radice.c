/*
** La radice quadrata di un numero reale puo' essere
** calcolata, in modo approssimato, come segue: sia
** x il numero del quale vogliamo calcolare la ra-
** dice quadrata; stabiliamo una soglia 's' relativa
** alla precisione del risultato; partiamo da una
** stima g; se |g^2 - x| < s, consideriamo g come
** risultato accettato; altrimenti calcoliamo una
** nuova stima per mezzo della formula (x/g + g)/2 e
** ripetiamo il procedimento.
** 
** Questo un programma che applica la procedura des-
** critta e stampa il numero di iterazioni compiute
** per arrivare al risultato.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* funzione "valore assoluto */
double v_assoluto (double n) {
	if ( n >= 0)
		return n;
	else
		return -n;
}

double stima (double x, double g) {
	if ( g > 0 && g < x) {
		g = ((x/g)+g)/2;
		return g;
	}
	else 
		return -1;
}

/* funzione "radice quadrata" */
double radice (double x, double s) {
	double g;
	
	if ( x < 0)
		g = -1;

	else if ( x == 0)
		g = 0;

	else if ( x == 1 )
		g = 1;

	else  {
		if ( x > 0 && x < 1)
			g = x;
		else if (x > 1 && x < 2)
			g = 1;
		else if ( x >= 2)
			g = x/2;

		while ( v_assoluto(pow(g, 2)-x) >= s ) {
			g = stima(x, g);
			/* se ci sono errori in "stima(x, g)",
			** g = -1 */
			if (stima(x, g) == -1)
				break;
		}
	}
	return g;
}

int main (void) {
	double y, p, r;
	printf("Inserire il radicando: ");
	scanf("%lf", &y);
	printf("Inserire il grado di precisione: ");
	scanf("%lf", &p);

	r = radice(y, p);
	if ( r != -1) {
		printf("\nRadice approssimata di %lf: %lf"
		"\n", y, r);
		exit(EXIT_SUCCESS);
	}
	else
		printf("ERRORE");
		exit(EXIT_FAILURE);
}
