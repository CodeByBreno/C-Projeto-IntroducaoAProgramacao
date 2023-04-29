#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[101];
	int Peso;
	int Idade;
	float Altura;
} Rena;

Rena *pRena;

void Troca (int i, int j)
{
	Rena aux;
	aux = *(pRena + j);
	*(pRena + j) = *(pRena + i);
	*(pRena + i) = aux;

	return;
}

int ComparaNome(char *vet1, char *vet2)
{
	int i;
	for (i = 0; *(vet1 + i) != '\0'; i++){
		if (vet1[i] > vet2[i]) return 1;
		if (vet1[i] < vet2[i]) return 0;	
	}
}

main ()
{
	long int N;
	int R, P, i, j, cont;
	scanf ("%ld", &N);

	for (cont = 0; cont < N; cont++){
		scanf ("%d %d", &R, &P);

		/* Construindo um vetor com R renas usando alocação dinamica */
		pRena = (Rena*) malloc(R * sizeof(Rena));

		/*Lendo os dados de cada rena */
		for (i = 0; i < R; i++){
			scanf ("%s", (pRena + i) -> nome);
			scanf ("%d", &((pRena + i) -> Peso));
			scanf ("%d", &((pRena + i) -> Idade));
			scanf ("%f", &((pRena + i) -> Altura));
		}

		/* Organizando o vetor de renas segundo a ordem especificada*/ 
		for (i = 1; i < R; i++){
			for (j = 0; j < i; j++){
				if ((pRena + j) -> Peso < (pRena + i) -> Peso)
					Troca(i, j);
				else if ((pRena + j) -> Peso == (pRena + i) -> Peso){
					if ((pRena + j) -> Idade > (pRena + i) -> Idade)
						Troca(i, j);
					else if ((pRena + j) -> Idade == (pRena + i) -> Idade){
						if ((pRena + j) -> Altura > (pRena + i) -> Altura)
							Troca(i, j);
						else if ((pRena + j) -> Altura == (pRena + i) -> Altura)
							if (ComparaNome((pRena + j) -> nome, (pRena + i) -> nome)) 
								Troca(i, j);		
					}
				}
			}
		}
		printf ("CENARIO {%d}\n", cont + 1);
		for (i = 0; i < P; i++)
			printf ("%d - %s\n", i + 1, (pRena + i) -> nome);
	}
	free(pRena);
}
