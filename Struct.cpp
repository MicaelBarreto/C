// ConsoleApplication1.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

	printf("\nBrincadeira Criar Struct");

	struct mercadoria {
		int qtd;
		float valor;
		char nome[20];
	};

	int i;
	struct mercadoria estoque[3];

	for (i=0;i<3;i++) {
		printf("\nDigite o nome da mercadoria: ");
		gets_s(estoque[i].nome);
		fflush(stdin);

		printf("\nDigite o Valor: ");
		scanf_s("%f", &estoque[i].valor);
		fflush(stdin);

		printf("\nDigite a Quantidade: ");
		scanf_s("%d", &estoque[i].qtd);
		fflush(stdin);

		system("cls");
	}

	for (i = 0;i < 3;i++) {
		printf("\nVoce digitou %s que custa %.2f e tem %i em estoque",estoque[i].nome, estoque[i].valor, estoque[i].qtd);
		
	}
	system("pause");

    return 0;
}

