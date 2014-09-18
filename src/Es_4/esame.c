/* 
** Questo programma legge i voti riportati dai
** cento studenti del corso di Laboratorio di
** Informatica I e determina la loro distribuzione.
** Stabilisce, cioe' , quanti studenti hanno
** riportato il voto 1, quanti il voto 2, e cosi'
** via, fino a 30.
** Il programma stabilisce anche quanti studenti
** hanno superato l'esame.
**
** NOTA: per evitare di dover digitare cento numeri 
** ad ogni esecuzione, procurarsi il file voti.txt,
** copiarlo nella cartella che contiene il file
** eseguibile, ed eseguire il programma.
** 
** Supponendo che l'eseguibile si chiami "esame",
** dare:
**
** "./esame < voti.txt"
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i, v[100]; /* contatore, vettore voti */
	i = 0;
	while ( i < 100 ) /* riempio il vettore */
	{
		scanf("%d", &v[i]);
		i++;
	}
	/* contatore voti, vettore numero di voti */
	int h, n[30]; 
	h = 1;
	while ( h <= 30 )
	{
		int e;
		e = 0;
		/* gli array partono da n[0], non da n[1] */
		n[h-1] = 0; 
		while ( e < 100 )
		{	
			/* se nei voti esisete
			** un numero uguale a h */
			if ( v[e] == h ) 
			{	
				/* incrementa il numero di persone
				** che ha preso quel voto */
				n[h-1]++; 
			}
			e++;
		}
		printf("%d studenti hanno preso %d\n",
		n[h-1], h);
		h++;
	}
	
	/* contatore, numero di persone con voto > 17 */
	int f, pass; 
	f = 18;
	pass = n[17];
	while ( f < 30 )
	{
		pass = pass + n[f];
		f++;
	}
	printf("\nAssumendo che il voto per cui l'esame"
	" si ritiene passato sia 18,\n%d studenti hanno "
	"passato l'esame\n", pass);

	exit(EXIT_SUCCESS);
}

