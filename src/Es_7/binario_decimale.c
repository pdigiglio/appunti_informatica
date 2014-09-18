/*
** Nella rappresentazione in base 2 di un numero in 
** un vettore, per stabilire quale sia l'ultima ci-
** fra, collochiamo il valore '-1' nella posizione a
** destra dell'ultima cifra significativa. Ad esem-
** pio: 181 = 128 + 32 + 16 + 4 + 1 corrisponde ad
** un vettore contenente, nell'ordine, i valori
** 1 0 1 1 0 1 0 1 -1.
**
** Questo programma contiene due funzioni, decbin e
** bindec. La prima riceve come argomento un numero
** intero n e un vettore, e scrive nel vettore la
** rappresentazione binaria di n. La seconda, par-
** tendo da un vettore contenente le cifre della
** rappresentazione binaria di un numero, resti-
** tuisce il numero stesso.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 50

/* struttura contenente un binario */
struct binario {
	int v[N];
	int indice;
} bin_num;

/* funzione push */
void push (int d) {
	bin_num.v[bin_num.indice] = d;
	bin_num.indice++;
}

/* converte da decimale a binario */
int decbin (int n) {
	int success; /* variabile di controllo */
	success = 1; /* variabile di controllo vera */
	push(-1);
	while (n/2 != 0) {
		/* scrive il resto nel vettore binario */
		push(n%2); 
		n = n/2; /* aggiorna n */
		/* se il vettore finisce */
		if ( bin_num.indice > N-2 ) { 
			/* variabile di controllo falsa */
			success = 0;
			/* interrompe il ciclo */
			break; 
		}
	}
	/* se il quoziente e' 0 */
	if ( n/2 == 0 && success == 1 ) 
		push(n%2);
	return success;
}

int bindec ( int c ) {
	int i, z[N];
	/* c e' una cifra e i non supera la lunghezza
	** del vettore */
	for ( i = 0; isdigit(c) && i < N-2; i++) { 
		z[i] = c -'0'; /* assegno  z[i] = 'c'-'0' */	
		c = getchar();
	}
	
	int e, sum;
	sum = 0;
	for ( e = i-1; e >= 0; e-- )
		sum = sum + z[e] * pow(2, (i-1) - e);
	return sum;
}

int main (int argc, char *argv[]) {
	int x, c;
	printf("Inserire un numero in base 2: ");
	c = getchar();
	x = bindec(c);
	printf("Rappresentazione decimale: %d \n", x );
	/* la prima posizione vuota del vettore binario
	** e' 0 */
	bin_num.indice = 0; 
	int m;
	printf("\nInserire un numero in base 10: ");
	scanf("%d", &m );
	
	printf("Rappresentazione binaria: ");
	/* se non ci sono stati errori */
	if ( decbin(m) != 0 ) { 
		int e;
		for( e = bin_num.indice - 1; e >= 1; e--)
			/* stampa le cifre binarie */
			printf("%d", bin_num.v[e]); 
		if ( bin_num.v[e] == -1 )
			/* va a capo alla fine */
			printf("\n"); 
	}
	else /* if ( decbin(m) == 0) */
		printf("Numero troppo grande\n");
			
	exit(EXIT_SUCCESS);
}