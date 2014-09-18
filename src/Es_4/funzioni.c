/* 
** Questo programma calcola il valore di a^n per
** un numero "reale" a, e un intero n (anche negati-
** vo).Successivamente, calcola i valori delle fun-
** zioni:
**
** f(x) = 3x^3 - 2x^2 + (2x/5) - 1
** g(x) = x + (3/x^4)
**
** per valori di x in [-3, 3] a intervalli di am-
** piezza 0,25.
*/

#include <stdio.h>
#include <stdlib.h>

double pot (double a, int n) {
	if ( n == 0) /* a^0 = 1 */
		return 1;
	else if ( n > 0 ){
		int i;
		i = 1;
		while ( i < n ){
			a = a*a;
			i++;
		}
		return a;
	}
	else /*( n < 0 )*/{
		int i;
		i = 1;
		while ( i < n ) {
			a = (1/a)*(1/a);
			i++;
		}
		return a;
	}
}

int main (void) {
	/* calcolo i valori di f(x) con x in [-3, +3] */
	double x; /* contatre double (x) */
	x = -3.0;
	while ( x <= 3) {
		printf(" f(%lf) = %lf \n", x,
		3*pot(x, 3) - 2*pot(x, 2) + (0.4)*x - 1);
		x = x + 0.25;
	}
	
	/* calcolo i valori di g(z) con z in [-3, +3] */
	double z; /* contatre double (z) */
	z = -3.0;
	while ( z <= 3 ) {
		printf(" g(%lf) = %lf \n", z,
		z + (3/pot(z, 4)));
		z = z + 0.25;
	}

	exit(EXIT_SUCCESS);
}
