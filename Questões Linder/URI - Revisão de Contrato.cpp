#include <stdio.h>

main ()
{
	int a, aux2, i, cont;
	char vet[101], aux[101];
	
	while (1){
		scanf ("%d %s", &a, vet);
		if (a == 0 && vet[0] == '0') break;
		
		for (i = 0, cont = 0; vet[i] != '\0'; i++){
			aux2 = vet[i];
			aux2 -= 48;
			if (aux2 != a){
				aux[cont] = vet[i];
				cont++;
			}	
		}
		aux[cont] = '\0';
		
		if (cont == 0) printf ("0\n");
		else{
			for (i = 0; aux[i] == '0'; i++);
			if (i < cont)  printf ("%s\n", aux + i);
			else printf ("0\n");	
		}
	}
}
