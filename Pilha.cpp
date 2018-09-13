#include <stdio.h>
#include <stdlib.h>
// Push = Empilhar
// Pop = desmpilhar

int main(){
	
	int pilha[5];
	int ponto = 0;
	int op;
	int valor;
	int i;
	
	for(i=0;i<5;i++){
		pilha[i]=0;
	}
	
	
	while(1){
		printf("---------------------\nEscolha uma opcao:\n1-Empilhar(Push)\n2-Desempilhar(Pop)\n3-Mostrar Pilha\n4-Sair\n---------------------\n");
		scanf("%d", &op);
		system("cls");
		
		if(op==1){
			printf("Escolha um valor para empilhar(Push)\n");
			scanf("%d", &valor);
			pilha[ponto]=valor;
			printf("\n\n\n%d Empilhado(Pushed)\n",pilha[ponto]);
			ponto++;
			system("pause");
			system("cls");
			
		} else if(op==2){
			ponto--;
			pilha[ponto]=0;
		}else if(op==3){
			for (i=0;i<5;i++){
				if(pilha[i]!=0){
					printf("Pilha[%d] = %d\n",(i+1),pilha[i]);
				}	
			}
			
			system("pause");
			system("cls");
		}else if(op==4){
			break;
		}
	}
	
	return 0;
}
