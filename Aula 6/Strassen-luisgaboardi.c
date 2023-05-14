#include "functions.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int n;
	//system("clear");
	printf("Multiplicação de Matrizes Quadradas\n\n");

	printf("1) Gerar matrizes\n");
	printf("2) Sair\n\n");
	printf(">> ");

	int entrada;
	scanf("%d", &entrada);

	clock_t inicio, fim;
    double tempo_decorrido;

	if(entrada == 1)
	{
		n = GenerateMatrixes();

		printf("Multiplicando...\nResultado:\n\n");

		inicio = clock(); // registra o tempo inicial

		C = strassenMultiply(A, B, n);

		fim = clock(); // registra o tempo final

        tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // calcula o tempo decorrido

		//printMatrix(C, n);

        printf("Tempo decorrido: %.6f segundos\n", tempo_decorrido);

	}
	else { exit(EXIT_SUCCESS); }

	return 0;
}
