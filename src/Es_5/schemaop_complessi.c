/*
** Semplice messa in opera di numeri complessi con
**  operazioni aritmetiche
*/

#include <stdio.h>
#include <stdlib.h>

#define N 2

/*
** La struttura n_complesso rappresenta un numero
** complesso. Considera le possibili rappresenta-
** zioni alternative.
*/
struct n_complesso {
	/* definisco un numero complesso
	** in forma algebrica, anche se
	** potrei definirlo in termini di
	** modulo e angolo
	*/
	
	double reale; /* parte reale */
	double immag; /* parte immaginaria */
};

/*
** La riga che segue definisce un nome alternativo
** per il tipo 'struct n_complesso'.
*/
typedef struct n_complesso Cmpl;

/*
** La funzione 'somma' esegue la somma di due numeri
** complessi, ricevuti come parametri, costruisce un
** oggetto di tipo 'Cmpl' corrispondente alla somma,
** e lo restituisce.
*/
Cmpl somma (Cmpl a, Cmpl b) {
	Cmpl r;
	r.reale = a.reale + b.reale;
	r.immag = a.immag + b.immag;
	
	return r;
}

/*
** La funzione 'prodotto' esegue il prodotto di due 
** numeri complessi, ricevuti come parametri, cos-
** truisce un oggetto di tipo 'Cmpl' corrispondente 
** al prodotto, e lo restituisce.
*/
Cmpl prodotto (Cmpl a, Cmpl b) {
	Cmpl r;
	r.reale = a.reale*b.reale - a.immag*b.immag;
	r.immag = a.reale*b.immag + a.immag*b.reale;
	
	return r;
}

int main () {
	int i;
	Cmpl beta, gamma;
	Cmpl v[N];
	
	/*
	** Fase di lettura dalla tastiera delle 
	** componenti di N numeri complessi.
	*/
	for ( i=0; i < N; i++ ) {
		printf("\n%d) Inserire la parte reale: ",
		i+1);
		scanf("%lf", &v[i].reale);
		printf("%d) Inserire la parte immaginaria: ",
		i+1);
		scanf("%lf", &v[i].immag);
	}

	beta = somma(v[0], v[1]);
	gamma = prodotto(v[0], v[1]);
	
	printf ("\nSomma = [%lf, %lf]\n", beta.reale,
	beta.immag);
	printf ("Somma = %lf + i*%lf\n", beta.reale,
	beta.immag);
	printf ("\nProdotto = [%lf, %lf]\n",
	gamma.reale, gamma.immag);
	printf ("Prodotto = %lf + i*%lf\n", gamma.reale,
	gamma.immag);
	
	exit(EXIT_SUCCESS);
}
