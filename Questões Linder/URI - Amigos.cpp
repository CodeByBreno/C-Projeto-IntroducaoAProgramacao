#include <stdio.h>
#include <string.h>

char *vet, aux1[256], aux2[256], *pi3, *Inicio, *Fim;

void Save(char *pi, char *pi2)
{
	/* Salvando em aux1 e aux2 os conjuntos que serão operados */
	int i;
	for (i = 0; *(pi + 1 + i) != '}'; i++) aux1[i] = *(pi + 1 + i);
	aux1[i] = '\0';
	/*printf ("AUX1 = %s\n", aux1);*/
	for (i = 0; *(pi2 + 1 + i) != '}'; i++) aux2[i] = *(pi2 + 1 + i);
	aux2[i] = '\0';
	/*printf ("AUX2 = %s\n", aux2);*/
	return;
}

void Uniao(char *pi, char *pi2)
{
	int i, j , g = 1, c;
	Save (pi, pi2);

	/* Fazendo a União propriamente dita */
	i = strlen(aux1);
	for (j = 0; aux2[j] != '\0'; j++, g = 1){
		for (c = 0; aux1[c] != '\0'; c++)
			if (aux2[j] == aux1[c]){
				g = 0;
				break;
			}

		if (g){
			*(pi + 1 + i) = aux2[j]; 
			i++;
			}
		}

	*(pi + 1 + i) = '}';
	pi3 = pi + 2 + i;

	for (i = 0; *(pi3 + i) != '}'; i++)
		*(pi3 + i) = ' ';
	*(pi3 + i) = ' ';
	printf ("SOMA FEITA = %s\n", vet);
	return;	
}

void Dif(char *pi, char *pi2)
{
	int i, j, a = 1, c, g = 0;
	Save (pi, pi2);

	/* Fazendo a Diferença propriamente dita */

	for (i = 0, c = 0; aux1[i] != '\0'; i++, a = 1){
		for (j = 0; aux2[j] != '\0'; j++)
			if (aux2[j] == aux1[i]){
				a = 0;
				g = 1;
				break;
			}
		if (a) {
			*(pi + 1 + c) = aux1[i];
			c++;
		}
	}
	*(pi + 1 + c) = '}';
	pi3 = pi + 2 + c;

	i = 0;
	if (g){
		for (i = i; *(pi3 + i) != '}'; i++)
			*(pi3 + i) = ' ';
		*(pi3 + i++) = ' ';
	}

	for (i = i; *(pi3 + i) != '}'; i++)
		*(pi3 + i) = ' ';
	*(pi3 + i) = ' ';

	printf ("DIFERENCA FEITA = %s\n", vet);
	return;	
}

void Inter(char *pi, char *pi2)
{
	int i, j, c, g = 0, f = 0;
	Save (pi, pi2);

	/* Fazendo a Intersecção propriamente dita */
	for (i = 0, c = 0; aux1[i] != '\0'; i++, g = 0){
		for (j = 0; aux2[j] != '\0'; j++) 
			if (aux1[i] == aux2[j]) {
				g = 1;
				break;
				}

		if (g) {
			*(pi + 1 + c) = aux1[i];
			c++;
			}
		else f = 1;

		}

	*(pi + 1 + c) = '}';
	pi3 = pi + 2 + c;

	i = 0;
	if (f){
		for (i = i; *(pi3 + i) != '}'; i++)
			*(pi3 + i) = ' ';
		*(pi3 + i++) = ' ';
	}

	for (i = i; *(pi3 + i) != '}'; i++)
		*(pi3 + i) = ' ';
	*(pi3 + i) = ' ';
	printf ("INTERSECAO FEITA = %s\n", vet);
	return;		
}

void ResolvedorDeLinha (void)
{
	int i, c, aux;
	char *pi, *pi2, aux2;
	vet = Inicio;
	if (*(Inicio) == '(') vet = Inicio + 1;
	*(Fim) = '\0';

	printf ("LINHA = %s\n", vet);
	/* Primeira Fase: Busca e calculo de Intersecções */

	do{
		for (i = 0, aux = 0; i < Fim - Inicio; i++){
			if (!aux && *(vet + i) == '{') pi = vet + i;
			if (*(vet + i)  == '*') aux = 1;
			if (aux && *(vet + i) == '{') {
				pi2 = vet + i;
				break;
			}
		}

		if (aux) Inter(pi, pi2);

	} while (aux != 0);

	/* Segunda Fase: Busca e Calculo de Operadores gerais (+ e -) */
	
	do{
	
		for (i = 0, aux2 = '/'; i < Fim - Inicio; i++){
			if (aux2 == '/' && *(vet + i) == '{') pi = vet + i;
			if (*(vet + i) == '+' || *(vet + i) == '-') aux2 = *(vet + i);
			if (aux2 != '/' && *(vet + i) == '{') {
				pi2 = vet + i;
				break;
			}
		}

		if (aux2 == '+') Uniao(pi, pi2);
		if (aux2 == '-') Dif(pi, pi2);

	} while (aux2 != '/');

}

main ()
{
	int i = 0, j, g = 0;
	char exp[256], aux;
	while (scanf ("%256s", exp)){
		Inicio = exp;

		/* Localizando o parentese mais interno */
		do{
			if (exp[i] == '(') 
				Inicio = exp + i;
			
			if (exp[i] == ')'){
				Fim = exp + i;
				g = 1;
			}
			i++;

			if (g){
				ResolvedorDeLinha();
				g = 0;
				i = 0;
				*(Inicio) = ' ';
				*(Fim) = ' ';
			}

		}while (exp[i] != '\0');

		Inicio = exp;
		Fim = exp + i;
		ResolvedorDeLinha();

		/* Limpa espaços desnecessarios no inicio */
		for (i = 0; vet[i] == ' ';)
			vet = vet + ++i;

		/* Organizando o vetor inserido em ordem alfábetica */
		for (i = 2; vet[i] != '}'; i++)
			for (j = 1; j < i; j++)
				if (vet[j] > vet[i]){
					aux = vet[j];
					vet[j] = vet[i];
					vet[i] = aux;
				}

		printf ("%s\n", vet);
	
	}
}
