#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct no{
		int num;
		struct no *pv;
		struct no *va;
	}No;

void inicializa(No **v){
	*v = NULL;
}

void insere_primeiro(No **v, int numaux){
	no *lista;
	lista = (no*) malloc(sizeof(no));
	lista->num = numaux;
	lista->va = lista;
	lista->pv = lista;
	*v = lista;
}

void insere(No **v, int numaux){
	no *lista;
	
	lista =((no*)malloc(sizeof(no)));
	lista->num = numaux;
	lista->pv= (*v) -> pv; 
	lista->va = *v; 
	(*v)->pv = lista;
	lista ->pv->va = lista;
	
	*v = lista;
		
}

void remover(No **v){
	no *lista;

	(*v)->pv->va = (*v)->va;
	(*v)->va->pv = (*v)->pv;
	lista = (*v)->pv;
	free(*v);
	*v = lista;

}


int main(){
	
	int i = 0;
	No *n;
	int op;
	int tam = 0;
	inicializa(&n);
	
	while(1){
	
		if(tam==0){
			
			tam++;
			
			printf("Adicione um valor: ");
			scanf("%i", &i);
			fflush(stdin);
			
			system("cls");
			
			insere_primeiro(&n, i);
	
		}else{
			
			printf("Escolha uma opcao\n1-Adicionar Valor\n2-Retirar Valor\n3-Passar para o Proximo Valor\n4-Sair\n\n\n%d\n\n\n", n->num);
			scanf("%i", &op);
			fflush(stdin);
		
			system("cls");
			
			if(op==1){
			
				tam++;
				printf("Adicione um valor: ");
				scanf("%i", &i);
				fflush(stdin);
				
				insere(&n, i);
				
					
			
				system("cls");
				
				
			}else if(op==2){
				tam--;
				remover(&n);
			}else if(op==3){
				n = n->pv;
			}else if(op==4){
				break;
			}else{
				
				printf("Comando Invalido");
				
				Sleep(2000);
				system("cls");
				
			} 	
		}
		
			
	}
	
	
	
	return 0;
}

