#include <stdio.h>
#include <stdlib.h>

int funcao1(int x, int y){
	int z;	
	z=x+y;
	return z;
	
}

int funcao2(int *v_lista){
	int i;
	for(i=0;i<3;i++){
		printf("\n%d",v_lista[i]);
	}
	
	return 0;
	
}

int main (){
	
	int valor1, valor2, resultado, i;
	int lista[3];
	
	printf("Digite o primeiro valor ");
	scanf("%d",&valor1);
	fflush(stdin);
	
	printf("\nDigite o segundo valor ");
	scanf("%d",&valor2);
	fflush(stdin);
	
	resultado=funcao1(valor1,valor2);
	
	printf("\nO Resultado e %d\n\n\n\n", resultado);
	
	lista[0]=valor1;
	lista[1]=valor2;
	lista[2]=resultado;
	
	while (i<3){
		printf("\nLista[%d] = %d",(i+1),lista[i]);
		i++;
	}
	
	funcao2(lista);
	
	return 0;
	
}
