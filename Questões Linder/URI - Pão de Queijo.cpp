#include <stdio.h>

main ()
{
	int N, M, i, j, p = 0;
	while (scanf ("%d %d", &N, &M) != EOF){
		int vet[N][M];

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++){
				scanf ("%d", &vet[i][j]);
				if (vet[i][j] == 1) vet[i][j] = 9; 
				}

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
					if (vet[i][j] != 9) {
						if (i > 0) if (vet[i-1][j] == 9) p++;
						if (i < N - 1) if (vet[i+1][j] == 9) p++;
						if (j > 0) if (vet[i][j-1] == 9) p++; 
						if (j < M - 1) if (vet[i][j+1] == 9) p++; 
						vet[i][j] = p;
						p = 0;
					}				
		
		for (i = 0; i < N; i++, printf ("\n"))
			for (j = 0; j < M; j++)
				printf ("%d", vet[i][j]);
			}
}	
