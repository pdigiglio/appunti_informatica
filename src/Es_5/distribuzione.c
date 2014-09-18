/*
** Definiamo una successione di numeri interi x0, 
** x1... con (x0 arbitrario) in questo modo (per 
** i > 0):
**
** xi = bx(i-1) (mod m)
** 
** con b, m costanti. (mod m) denota il resto della
** divisione per m.
**
** Questo programma, fissati i valori di x0 , b e m,
** produce i primi 2m valori della successione, te-
** nendo traccia della distribuzione dei valori gen-
** erati. Per ogni i compreso fra 0 e m, il program-
** ma conta quante volte i compare nella successione.
**
** Fissato m = 1024, cerca valori di b per cui la
** distribuzione sia uniforme, cioe' ogni valore di
** i compaia esattamente due volte.
*/

#include <stdio.h>
#include <stdlib.h>

/* calcolo i valori per cui la distribuzione e'
** uniforme */
int uni_search (int x) {
	int z;
	z = 1024;/* contatore ciclo, contatore numeri */
    int h, p[z]; 
    /* riempio il vettore di zeri */
	h = 0;
	while ( h < z ) {
		p[h] = 0;
		h++;
	}

	/* produco e stampo i termini della sommatoria */
	int j, r;
	j = 1;
	r = z + 1;
	while ( j <= 2*z ) {
		p[x] = p[x] + 1;
		x = (r*x)%z;
		if ( p[x] > 2 ) {
			r++;
			j = 1;
		}
		else
			j++;
	}
	return r;
}

int main (void) {
	/* raccolgo i dati */
	int m, b, x;

	printf("Inserisci un intero per m: ");
	scanf("%d", &m);
	printf("Inserisci un intero per b: ");
	scanf("%d", &b);
	printf("Inserisci un intero per X(0): ");
	scanf("%d", &x);
	
	/* contatore ciclo, contatore numeri */
	int e, n[m]; 
	/* riempio il vettore di zeri */
	e = 0;
	while ( e < m ) {
		n[e] = 0;
		e++;
	}

	/* produco e stampo i termini della sommatoria */
	int i;
	i = 1;
	while ( i < 2*m ) {
		n[x] = n[x] + 1;
		x = (b*x)%m;
		printf("%d ", x);
		i++;
	}

	if ( i == 2*m) {
		n[x] = n[x] + 1;
		x = (b*x)%m;
		printf("%d\n", x);
		i++;
	}
	
	/* stampo il n. di volte che un numero compare */
	int f;
	f = 0;
	while ( f < m ) {
		printf("Il valore %d e' comparso %d volte."
		"\n", f, n[f]);
		f++;
	}
	
	printf("\nFissato m = 1024, il valore di b per "
	"cui\nla successione e' uniforme: %d\n",
	uni_search(x));
	exit(EXIT_SUCCESS);
}
