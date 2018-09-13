#include <stdio.h>
#include <stdlib.h>

int main() {
	int tamanho;
	int i;

	printf("\nPrograma para testar malloc");
	printf("\nDigite o tamanho do vetor");
	scanf("%d", &tamanho);
	fflush(stdin);

	int *vetor;
	vetor = (int *)malloc(tamanho * sizeof(int)); //Aqui eu pedi para reservar o valor que esta no tamanho vezes o tamanho que é um int

	for (i = 0;i < tamanho;i++) {
		vetor[i] = i;
	}

	printf("\n\n");
	printf("\n-------------------------------------------------\n");

	for (i = 0;i < tamanho;i++) {
		printf("Vetor[%d] = %d",(i+1), vetor[i],"\n");
	}
	
	free(vetor);
}


