#include <stdio.h>
#include <stdlib.h>

void BubbleSort (float *vet, int Tamanho)
{
	int i, flag;
	float aux;
	for (i = 0, flag = 0; i < Tamanho - 1; i++)
		if (vet[i] > vet[i + 1]){
			aux = vet[i];
			vet[i] = vet[i + 1];
			vet[i + 1] = aux;
			flag = 1;
			}
	if (flag == 1) BubbleSort (vet, 7);
	else return;
}

main ()
{
	int i, cont, T, N;
	double Soma;
	float dificuldade, vet[7];
	char *nome, aux, lixo;

	scanf ("%d", &N);

	for (cont = 0; cont < N; cont++){

		/* Usando Realloc para ler construir um vetor com precisamente o tamanho do nome */

		scanf ("%c", &lixo);
		i = 0;
		T = 1;
		nome = (char *) malloc(sizeof(char));
		do{
			scanf ("%c", &aux);
			if (aux != '\n') nome[i++] = aux;
			if (i >= T)
				nome = (char *) realloc(nome, sizeof(char)*++T);
		} while (aux != '\n');
		nome[i] = '\0';
		
		/* Lendo a dificuldade da prova e um vetor com as notas */
		scanf ("%f", &dificuldade);
		for (i = 0; i < 7; i++) scanf ("%f", &vet[i]);

		/*Organizo o vetor e ignoro a primeira e última posição */
		BubbleSort(vet, 7);
		for (i = 1, Soma = 0; i < 6; i++) Soma += vet[i];
		printf ("%s %.2lf\n", nome, Soma*dificuldade);
		free(nome);
		}
}
