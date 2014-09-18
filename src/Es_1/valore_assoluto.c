/*
** Questo programma stampa il valore assoluto di un
** numero qualsiasi.
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main (int argc, char * argv[]) {
	/* il numero che sara' inserito*/
	float  num; 

	/* acquisisco i numeri */
	printf("Inserire un numero: ");
	scanf("%f", &num);

	/* stampo a schermo in valore assoluto */
	/* controlla che il numero sia positivo */
	if ( num >= 0 ) 
		printf("Valore assoluto: %f\n", num);
	else
		printf("Valore assoluto: %f\n", -num);

        exit (EXIT_SUCCESS);
}