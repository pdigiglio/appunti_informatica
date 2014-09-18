/* 
** Questo programma traduce un'espressione algebrica
** dalla notazione infissa a quella postfissa. Fun-
** ziona solo per numeri di una sola cifra. Affin-
** che' funzioni, bisogna includere ogni espressione 
** tra parentesi tonde.
*/

#include <stdio.h>
#include <stdlib.h>
/* contiene la funzione "isdigit()" */
#include <ctype.h> 

#define N 50
/* stack */ 
struct pila {
	char val[N];
	int indice;
} valori;

void push (char v) {
	/* 
	** consideriamo uno stack come fissato, e sup-
	** poniamo che la funzione non produca risultati
	*/
	valori.val[valori.indice] = v;
	valori.indice++;
	/*
	** questa funzione non da' errore finche' il 
	** vettorenon e' pieno. Se valori.indice = 50, 
	** c'e' un errore.
	*/
}

/* non necessita di argomenti */
char pop (void) {
	valori.indice--;
	return valori.val[valori.indice];
        /*
        ** questa funzione da' errore se il vettore
        ** e' vuoto. Se valori.indice = 0, c'e' un
		** errore.
        */
}

char traduzione (void) {
	char c, temp;
	printf ("Inserisci notazione infissa (usa le pa"
	"rentesi): ");
	c = getchar();
	while ( c != '\n') {
		/* isdigit(c) produce 1 se c non e' una
		** cifra, 0 altrimenti.
		** E' un valore booleano, per questo la con-
		** dizione puo' essere scritta cosi' */
		if ( isdigit(c) ) {
			printf("%c", c);
		}
		else if ( c == '(' || c == '+' || c == '*' ) {
			push(c);
		}
		else if ( c == ')' ) {
			printf("%c", pop() );
			temp = pop();
		}
		c = getchar();
	}
	printf("\n");
}

int main (int argc, char *argv[]) {
	/* punta inizialmente alla prima posizione
	del vettore */
	valori.indice = 0; 
	traduzione();
	exit(EXIT_SUCCESS);
}