/* 
** Per semplificare il programma, limitiamo le ope-
** razioni a somma (+) e prodotto (*). Limitiamo, 
** inoltre i numeri ad interi con una sola cifra.
**  
** In questo modo, non dobbiamo introdurre l'uso
** degli spazi per identificare univocamente i nu-
** meri. Ulteriore vincolo e' che si suppone che 
** l'espressione introdotta non sia affetta da er-
** rori.
*/

#include <stdio.h>
#include <stdlib.h>
/* contiene la funzione "isdigit()" */
#include <ctype.h> 

#define N 50

struct pila {
	/*
	** per tenere insieme due variabili
	** non omogenee, usiamo un record
	*/
	int val[N];
	int indice;
} valori;

void push (int v) {
	/* 
	** consideriamo uno stack come fissato, e suppo-
	** niamo che la funzione non produca risultati
	** 
	*/
	valori.val[valori.indice] = v;
	valori.indice++;
	/*
	** questa funzione non da' errore finche' il 
	** vettore non e' pieno. Se valori.indice = 50,
	**  c'e' un errore.
	*/
}

int pop (void) {
	valori.indice--;
	return valori.val[valori.indice];
	/*
	** questa funzione da' errore se il vettore e'
	** vuoto. Se valori.indice = 0, c'e' un errore.
	*/
}

int val (void) {
	/*
	** legge le sequenze di caratteri e compie
	** operazioni sui caratteri immessi
	*/
	int x, y;
	char c;
	printf ("Inserisci l'espressione: ");
	c = getchar();
	while ( c != '\n') {
		/* isdigit(c) produce 1 se c non e' una
		** cifra, 0 altrimenti */
		if ( isdigit(c) ) 
			push(c - '0');
		else if ( c == '+') {
			x = pop();
			y = pop();
			push(x+y);
		}
		else /* if ( c == '*') */ {
			x = pop();
			y = pop();
			push(x*y);
		}
		c = getchar();
	}
	return pop();
}

int main (void) {
	valori.indice = 0;
	printf("Risultato: %d\n", val());
	exit(EXIT_SUCCESS);
}