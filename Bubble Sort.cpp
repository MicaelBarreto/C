#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct numbers{
	int num;
	struct numbers *prev;
	struct numbers *next;
}N;

void start(N **v){
	*v = NULL;
}

void insert_first(N **v, int numaux){
	numbers *e;
	e = (numbers*) malloc(sizeof(numbers));
	e->num = numaux;
	e->prev = NULL;
	e->next = NULL;
	*v = e;
}

void insert(N **v, int numaux){
	numbers *e;
	
	e =((numbers*)malloc(sizeof(numbers)));
	e->num = numaux;
	e->next= (*v) -> next; 
	e->prev = *v; 
	(*v)->next = e;
	e->next->prev = e;
	
	*v = e;
		
}

int sort(N **v){
	numbers *e;
	
	if((*v)->num > (*v)->next->num){
		(*v)->next->prev = (*v)->prev;
		(*v)->prev->next = (*v)->next;
		(*v)->prev = (*v)->prev->prev;
		e = (*v)->next;
		*v = e;
		
		return 1;
	}else{
		return 0;
	}
}

void remove(N **v){
	numbers *e;

	(*v)->next->prev = (*v)->prev;
	(*v)->prev->next = (*v)->next;
	e = (*v)->next;
	free(*v);
	*v = e;

}

int main(){
	
	int i = 0;
	N *e;
	int op;
	int tam = 0;
	start(&e);
	int aux;
	
	while(1){
	
		if(tam==0){
			
			tam++;
			
			printf("Adicione um valor(Insert a Number): ");
			scanf("%i", &i);
			fflush(stdin);
			
			system("cls");
			
			insert_first(&e, i);
	
		}else{
			
			printf("Escolha uma opcao(Choose an option)\n1-Inserir(Insert)\n2-Remover(Remove)\n3-Proximo(Next)\n4-Anterior(Previous)\n5-Listar(List)\n6-Sair(Quit)\n\n\n%d\n\n\n", e->num);
			scanf("%i", &op);
			fflush(stdin);
		
			system("cls");
			
			if(op==1){
			
				tam++;
				printf("Adicione um valor(Insert a Number): ");
				scanf("%i", &i);
				fflush(stdin);
				
				insert(&e, i);
				
					
				for(;;){
					aux = sort(&e);
					
					if(aux == 0){
						break;
					}
				}
				
				system("cls");
				
				
			}else if(op==2){
				tam--;
				remove(&e);
			}else if(op==3){
				e = e->next;
			}else if(op==4){
				e = e->prev;
			}else if(op==5){
				
			
			}else if(op==6){
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

