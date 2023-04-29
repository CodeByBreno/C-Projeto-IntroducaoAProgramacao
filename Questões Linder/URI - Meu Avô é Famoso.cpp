#include <stdio.h>
#include <stdlib.h>

main ()
{
	typedef struct{
		int jogador;
		int quant;
	} Ficha;
	
	Ficha *num, aux2;
	int N, M, i, j, *vet, aux, flag, gap;
	do{
		scanf ("%d %d", &N, &M);
		if (!N && !M) break;
		vet = (int *) malloc(sizeof(int)*N*M);
		num = (Ficha *) calloc(N*M, sizeof(Ficha));
		
		/* Lendo os elementos da matriz */
		for (i = 0; i < N*M; i++)
			scanf ("%d", &vet[i]);
			
		/* Ordenando o vetor usando um Comb Sort*/
		gap = N*M;
		do {
			if (gap != 1) gap /= 1.3;
			for (i = 0, j = gap, flag = 0; j < N*M; i++, j++)
				if (vet[i] > vet[j]){
					aux = vet[i];
					vet[i] = vet[j];
					vet[j] = aux;
					flag = 1;
				}
		} while (!(flag == 0 && gap == 1));
			
		/* Contando a quantidade de vezes que cada número aparece */
		for (i = 0, j = 0; i < N*M; i++){
			if (!i) num[j].jogador = vet[i];
			else{
				if (vet[i] == num[j].jogador) num[j].quant++;
				else num[++j].jogador = vet[i];
			}
		}

		/*Encontrando a maior e a segunda maior quantidade de vezes que um jogador aparece*/
		for (i = 0, M = -1, N = -1; i <= j; i++){
			if (num[i].quant > M){
				N = M;
				M = num[i].quant;
				}
			else if (num[i].quant != M && num[i].quant > N) N = num[i].quant;
		}
		for (i = 0; i <= j; i++) if (num[i].quant == N) printf ("%d ", num[i].jogador);
		printf ("\n");
		free(vet);
		free(num);

	}while (1);
}
