/*
** Questo programma legge dei numeri interi e ne
** stampa la somma, la differenza, il prodotto e
** il quoziente
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main (int argc, char * argv[]) {
	int n1, n2; /* i numeri che saranno inseriti*/
	
	/* acquisico i numeri */
	printf("Inserire il primo numero: ");
	scanf("%d", &n1);
	printf("Inserire il secondo numero: ");
	scanf("%d", &n2);

	/* stampo a schermo le operazioni */
	printf("Somma: %d\n", n1+n2);
	printf("Differenza: %d\n", n1-n2);
	printf("Prodotto: %d\n", n1*n2);
	printf("Quoziente (intero): %d\n", n1/n2);

	exit (EXIT_SUCCESS);
}