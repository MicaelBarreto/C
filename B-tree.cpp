#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>

int profundidadeMax = 0;
int somas[999];
int countS = 0;
//Arrumar Balanceamento!!!!

typedef struct elemento{
	int num;
	struct elemento *ant;
	struct elemento *drt;
	struct elemento *eqd;
}El;

void inicializa(El **v){
	*v = NULL;
}

void insere_primeiro(El **v, int numaux){
	elemento *e;
	e = (elemento*) malloc(sizeof(elemento));
	e->num = numaux;
	e->ant = NULL;
	e->drt = NULL;
	e->eqd = NULL;
	*v = e;
	profundidadeMax = 0;
}

void volta(El **v){
	for(;;){
		if((*v)->ant!=NULL){
			(*v)=(*v)->ant;
		}else{
			break;
		}
	}
}

void percorre(El **v, int numaux){
	
	for(;;){
		if((*v)->num>numaux){
			if((*v)->eqd!=NULL){
				(*v) = (*v)->eqd;
			}else{
				break;
			}
		}else{
			if((*v)->drt!=NULL){
				(*v) = (*v)->drt;
			}else{
				break;
			}
		}
	}
}

void profundidade(El **v){
	int profundidade = 0;
	for(;;){
		if ((*v)->ant != NULL){
			profundidade++;
			(*v)=(*v)->ant;
		}else{
			if(profundidade>profundidadeMax){
				profundidadeMax = profundidade;
			}
			break;
		}
	}
}

balanceamentoEqd(El **v, int soma){
	elemento *e = *v;
	if((*v)->ant!=NULL){
		balanceamentoEqd(&e->ant, soma+1);
	}else{
		somas[countS]=soma;
		countS++;
	}
}

balanceamentoDrt(El **v, int soma){
	elemento *e = *v;
	
	if((*v)->ant!=NULL){
		//printf("\nsoma = %i\n", soma);
		balanceamentoDrt(&e->ant, soma-1);
	}else{
		somas[countS]=soma;
		countS++;
	}
}

int balanceamento(){
	int i;
	int j;
	int menor = 0;
	int maior = 0;
	
	for(i=0;i<countS;i++){
		for(j=0;j<countS;j++){
			//printf("somas[%i] = %i \n", i,somas[i]);
			/*if (somas[j]>somas[i]){
				maior=somas[i];
				printf("\nmaior = %i\n", maior);
			}else{
				menor=somas[i];
			}*/
			
			if(somas[i]>somas[j] && somas[i]>maior){
				//printf("\nsoma[i] = %i\n", somas[i]);
				//printf("\nsoma[j] = %i\n", somas[j]);
				maior=somas[i];
				//printf("\nmaior = %i\n", maior);
				//printf("\nmaior = %i\n", maior);
			}
			
			if (somas[i]<somas[j] && somas[i]<menor){
				//printf("\nsoma[i] = %i\n", somas[i]);
				//printf("\nsoma[j] = %i\n", somas[j]);
				menor=somas[i];
				//printf("\nmenor = %i\n", menor);
			}
		}
	}
	//printf("maior = %i \n", maior);
	//printf("menor = %i \n", menor);
	//printf("%i ", (maior+menor));
	return (maior+menor);
}

void balUltimos (El **v, int raiz){
	elemento *e = *v;
	if(*v != NULL){
		if (((*v)->eqd == NULL) && ((*v)->drt == NULL)){
			if((*v)->num>raiz){
				balanceamentoDrt(&e, 0);
			}else{
				balanceamentoEqd(&e, 0);
			}
		}
		//printf("\n v->eqd = %i", e->eqd->num);
		balUltimos(&(*v)->eqd, raiz);
		//printf("\n v->drt = %i", e->drt->num);
		balUltimos(&(*v)->drt, raiz);
	}
}

void ultimos (El **v){
	elemento *e;
	if(*v != NULL){
		if (((*v)->eqd == NULL) && ((*v)->drt == NULL)){
			e = *v;
			profundidade(&e);
		}
		ultimos(&(*v)->eqd);
		ultimos(&(*v)->drt);
	}
}




bool lado(El **v, int numaux){
	for(;;){
		if((*v)->ant!=NULL){
			(*v)=(*v)->ant;
		}else{
			if((*v)->num>numaux){
				return true;
			}else{
				return false;
			}
		}
	}
	
}


void insere(El **v, int numaux){
	elemento *e;
	e =((elemento*)malloc(sizeof(elemento)));
	
	if((*v)->num>numaux){
		
		e->num = numaux;
		e->ant= (*v); 
		e->drt = NULL;
		e->eqd = NULL; 
		(*v)->eqd = e;
		
	}else{
		
		e->num = numaux;
		e->ant= (*v); 
		e->drt = NULL;
		e->eqd = NULL; 
		(*v)->drt = e;
	}
	
	
	
	*v = e;
		
}

void remover(El **v){ 
	elemento *e;
	e = *v;
	bool flag;
	
	
	
	if((*v)->ant == NULL){ //Raiz
		if((*v)->eqd == NULL){ //Não Tem Valor à esquerda
			if((*v)->drt != NULL){ //Tem Valor à direita
				(*v)->drt->ant = NULL;
				e = (*v)->drt;
				free(*v);
				(*v) = e;
			}else{
				free(*v);
			}
		
		}else{
			if((*v)->drt != NULL){
				if((*v)->eqd->drt == NULL){
					(*v)->eqd->ant = NULL;
					e = (*v)->eqd;
					(*v)->eqd->drt = (*v)->drt;
					(*v)->drt->ant = (*v)->eqd;
					free(*v);
					*v = e;
				}else{
					e = (*v)->eqd->drt;
					for(;;){
						if (e->drt != NULL){
							e = e->drt;
						}else{
							break;
						}
					}
					e->eqd = (*v)->eqd;
					e->drt = (*v)->drt;
					e->ant->drt = NULL;
					e->ant = NULL;
					(*v)->drt->ant = e;
					(*v)->eqd->ant = e;
					free(*v);
					*v = e;
				}
			}else{
				if((*v)->eqd->drt == NULL){
					(*v)->eqd->ant = NULL;
					e = (*v)->eqd;
					free(*v);
					*v = e;
				}else{
					e = (*v)->eqd->drt;
					for(;;){
						if (e->drt != NULL){
							e = e->drt;
						}else{
							break;
						}
					}
					e->eqd = (*v)->eqd;
					e->drt = NULL;
					e->ant->drt = NULL;
					e->ant = NULL;
					free(*v);
					*v = e;
				}
			}
			
		}
	}else{ //Não é raiz
		flag = (&e, e->num);
		if(flag == true){// Verifica Se esta a Direita ou esquerda -- true = direita / false = esquerda
			if((*v)->drt == NULL){ // Se o que esta a direita é null
				if((*v)->eqd != NULL){
					(*v)->eqd->ant = (*v)->ant;
					e = (*v)->eqd;
					
					if((*v)->ant->num > (*v)->num){ //Para saber se esta a Direita ou a esquerda do anterior
						(*v)->ant->eqd = e;
					}else{
						(*v)->ant->drt = e;
					}
					
					free(*v);
					*v = e;
				}else{
					
					if((*v)->ant->num > (*v)->num){ //Para saber se esta a Direita ou a esquerda do anterior
						(*v)->ant->eqd = NULL;
					}else{
						(*v)->ant->drt = NULL;
					}

					e = (*v)->ant;
					free(*v);
					*v = e;
				}
			
			}else{ // Se o que esta a direita não é null
				if((*v)->drt->eqd == NULL){// Verifica se o proximo a direita possui um a esquerda
					(*v)->drt->ant = (*v)->ant;
					e = (*v)->drt;
					
					if((*v)->ant->num > (*v)->num){ //Para saber se esta a Direita ou a esquerda do anterior
						(*v)->ant->eqd = e;
					}else{
						(*v)->ant->drt = e;
					}
					
					free(*v);
					*v = e;
				}else{ // Se tem um a esquerda
					e = (*v)->drt->eqd;
					for(;;){
						if (e->eqd != NULL){
							e = e->eqd;
						}else{
							break;
						}
					}
					e->eqd = (*v)->eqd;
					e->drt = (*v)->drt;
					e->ant->eqd = NULL;
					e->ant = (*v)->ant;
					
					if((*v)->ant->num > (*v)->num){ //Para saber se esta a Direita ou a esquerda do anterior
						(*v)->ant->eqd = e;
					}else{
						(*v)->ant->drt = e;
					}
					
					if((*v)->eqd != NULL){ // Se tem um filho a esquerda do que vai ser retirado
						(*v)->eqd->ant = e;
					}
					
					(*v)->drt->ant = e;
					
					free(*v);
					*v = e;
				}
			}
		}else{ // A esquerda Da raiz
			if((*v)->eqd == NULL){
				if((*v)->drt != NULL){
					(*v)->drt->ant = (*v)->ant;
					e = (*v)->drt;
					
					if((*v)->ant->num > (*v)->num){ //Para saber se esta a Direita ou a esquerda do anterior
						(*v)->ant->eqd = e;
					}else{
						(*v)->ant->drt = e;
					}
					
					
					free(*v);
					*v = e;
				}else{
					
					if((*v)->ant->num > (*v)->num){ //Para saber se esta a Direita ou a esquerda do anterior
						(*v)->ant->eqd = NULL;
					}else{
						(*v)->ant->drt = NULL;
					}
					
					e = (*v)->ant;
					free(*v);
					*v = e;
				}
			
			}else{
				if((*v)->eqd->drt == NULL){
					(*v)->eqd->ant = (*v)->ant;
					e = (*v)->eqd;
					(*v)->ant->eqd = e;
					free(*v);
					*v = e;
				}else{
					e = (*v)->eqd->drt;
					for(;;){
						if (e->drt != NULL){
							e = e->drt;
						}else{
							break;
						}
					}
					e->eqd = (*v)->eqd;
					e->drt = (*v)->drt;
					e->ant->drt = NULL;
					e->ant = (*v)->ant;
					(*v)->ant->eqd = e;
					
					if((*v)->drt != NULL){
						(*v)->drt->ant = e;
					}
					(*v)->eqd->ant = e;
					free(*v);
					*v = e;
				}
			}
		}
	}
	
	
}

void preOrdem (El **v){
	if (*v != NULL){
		printf("%d ", (*v)->num);
		
		if((*v)->eqd!=NULL){
			preOrdem(&(*v)->eqd);
		}
		if((*v)->drt!=NULL){
			preOrdem(&(*v)->drt);
		}
	}
}

void emOrdem (El **v){
	if(*v != NULL){
		emOrdem(&(*v)->eqd);
		printf("%d ", (*v)->num);
		emOrdem(&(*v)->drt);
	}
}

void posOrdem (El **v){
	if(*v != NULL){
		posOrdem(&(*v)->eqd);
		posOrdem(&(*v)->drt);
		printf("%d ", (*v)->num);
	}
}


int main(){
	
	int i = 0;
	El *n;
	int op;
	int tam = 0;
	inicializa(&n);
	
	/*int vetor[12]={5,3,2,4,8,10};
	insere_primeiro(&n, vetor[0]);
		for (int j=1;j<12;j++){
		volta(&n);
		percorre(&n, vetor[j]);
		insere(&n, vetor[j]);
	}

	tam = 12;*/
	
	while(1){
	
		if(tam==0){
			
			tam++;
			
			printf("Adicione um valor: ");
			scanf("%i", &i);
			fflush(stdin);
			
			system("cls");
			
			insere_primeiro(&n, i);
	
		}else{
			printf("Escolha uma opcao\n1-Adicionar Valor\n2-Retirar Valor\n3-Para Cima(^)\n4-Para Direita(>)\n5-Para Esquerda(<)\n6-PreOrdem\n7-EmOrdem\n8-Pos-Ordem\n9-Profundiade Maxima\n10-Balanceamento\n11-Sair\n\n\nValor Atual = %d\n\n", n->num);
			scanf("%i", &op);
			fflush(stdin);
		
			system("cls");
			
			if(op==1){
			
				tam++;
				printf("Adicione um valor: ");
				scanf("%i", &i);
				fflush(stdin);
				
				volta(&n);
				percorre(&n, i);
				insere(&n, i);
				
					
			
				system("cls");
				
				
			}else if(op==2){
				tam--;
				remover(&n);
			}else if(op==3){
				if(n->ant!=NULL){
					n = n->ant;
				}
			}else if(op==4){
				if(n->drt!=NULL){
					n = n->drt;
				}
			}else if(op==5){
				if(n->eqd!=NULL){
					n = n->eqd;
				}
			}else if(op==6){
				volta(&n);
				preOrdem(&n);
				printf("\n");
				system("pause");
				system("cls");
			}else if(op==7){
				volta(&n);
				emOrdem(&n);
				printf("\n");
				system("pause");
				system("cls");
			}else if(op==8){
				volta(&n);
				posOrdem(&n);
				printf("\n");
				system("pause");
				system("cls");	
			}else if(op==9){
				volta(&n);
				ultimos(&n);
				printf("Profundidade Maxima = %d", profundidadeMax);
				printf("\n");
				system("pause");
				system("cls");
			}else if(op==10){
				volta(&n);
				balUltimos(&n, n->num);
				int soma = balanceamento();
				if(soma>1){
					printf("A Arvore esta desbalanceada %d nivel(is) para a esquerda", soma-1);
				}else if(soma<(-1)){
					printf("A Arvore esta desbalanceada %d nivel(is) para a direita", soma+1);
				}else{
					printf("A Arvore esta balanceada");
				}
				printf("\n");
				system("pause");
				system("cls");
			}else if(op==10){
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

