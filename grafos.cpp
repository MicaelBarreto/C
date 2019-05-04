#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<locale.h>
#include<string.h>


char cores[] = {'a', 'b', 'c', 'd', 'e', 'l', 'p', 'r', 's', 'v'};
int id=0;

typedef struct grafo{
	int id;
	int valor;
	int qtdArest;
	int arest[8];
	int ant[8];
	int qtdAnt;
	char cor;
}Graph;

int main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	Graph g[100];
	int val;
	int cor;
	int i, j;
	int cId = 0;
	int cId1 = 0;
	int busca;
	int bId;
	int index = 0;
	int flag;
	int flag1 = 0;
	
	//Testes
	
	for(i=0;i<7;i++){
		g[i].valor	= i;
		//g[i].cor = cores[i];
		g[i].id = i;
		g[i].qtdArest = 0;
		g[i].qtdAnt=0;
			
			for(j=0;j<8;j++){
				g[i].arest[j]=NULL;
				g[i].ant[j]=NULL;
			}
		
		id++;
	}
	
	while(1){
		printf("Escolha uma opção\n1-Inserir\n2-Inserir Aresta\n3-Imprimir\n4-Busca em Profundidade\n5-Coloração\n6-Sair\n\n");
		scanf("%i", &op);
		
		fflush(stdin);
			
		system("cls");
		
		if (op==1){
			printf("Digite um valor:");
			scanf("%i", &val);
			system("cls");
			
			/*printf("Escolha uma cor\n");
			
			for(i=0; i<10;i++){
				printf ("%i - %c\n",i+1,cores[i]);
			}
		
			scanf("%i", &cor);
			system("cls");*/
			
			//insere(g[id], val, cor);
			
			g[id].valor	= val;
			//strcpy(g[id].cor, cores[cor-1]);
			g[id].cor = cores[cor-1];
			g[id].id = id;
			g[id].qtdArest = 0;
			
			for(i=0;i<8;i++){
				g[id].arest[i]=NULL;
				g[id].ant[j]=NULL;
			}
			g[id].qtdAnt=0;
			//printf("id = %i\nvalor = %i\nArestas = %i\ncor = %c\n\n", g[id].id, g[id].valor,g[id].qtdArest, g[id].cor);
			id++;
			
		}else if (op==2){
			
			if(id>0){
				for(i=0;i<id;i++){
					printf("%i:%i -> ",g[i].id, g[i].valor);
					if(g[i].qtdArest>0){
						for(j=0;j<g[i].qtdArest;j++){
							printf("%i:%i | ",g[g[i].arest[j]].id, g[g[i].arest[j]].valor);
						}
						printf("\n");
					}else{
						printf("\n");
					}
				}
				
				printf("Deseja fazer uma aresta de(id):");
				scanf("%i", &cId);
				
				printf("\nPara(id):");
				scanf("%i", &cId1);
				
				g[cId].arest[g[cId].qtdArest]=g[cId1].id;
				g[cId].qtdArest++;
				g[cId1].ant[g[cId1].qtdAnt] = g[cId].id;
				g[cId1].qtdAnt++;
				system("cls");
				
			}else{
				printf("Não há valores suficientes para criar uma aresta");
				Sleep(2000);
				system("cls");
			}
			
		}else if (op==3){
			for(i=0;i<id;i++){
					printf("%i:%i:%c -> ",g[i].id, g[i].valor, g[i].cor);
					if(g[i].qtdArest>0){
						for(j=0;j<g[i].qtdArest;j++){
							printf("%i:%i:%c | ",g[g[i].arest[j]].id, g[g[i].arest[j]].valor, g[g[i].arest[j]].cor);
						}
						printf("\n");
					}else{
						printf("\n");
					}
				}
				system("pause");
				system("cls");
				
		}else if(op==4){
			printf("Digite o valor que deseja buscar:");
			scanf("%i", &busca);
			
			system("cls");

			for(i=0;i<8;i++){
				if(g[i].valor==busca){
					index = i;
					flag++;
					break;
				}
			}
			
			if(flag == 0){
				printf("Valor não foi encontrado");
				system("pause");
				system("cls");
			}else{
				printf("Possivel Caminho:");
				for(;;){
					if(g[index].valor==NULL){
						break;
					}
					printf(" %i |", g[index].valor);
					index = g[index].ant[0];
				}
				printf("\n");
				system("pause");
				system("cls");
				
			}
		}else if (op==5){
			for(i=0;i<7;i++){
				printf("Escolha uma cor para %i:%i\n",g[i].id, g[i].valor);
				for(j=0; j<10;j++){
					printf ("%i - %c\n",j+1,cores[j]);
				}
				scanf("%i", &cor);
				system("cls");
				
				for(j=0;j<g[i].qtdAnt;j++){
					if(cores[cor-1] == g[g[i].ant[j]].cor){
						flag1++;
					}
				}
				
				if(flag1>0){
					printf("Cor Invalida escolha outra\n");
					system("pause");
					system("cls");
					i--;
					flag1=0;
				}else{
					g[i].cor = cores[cor-1];
					flag1=0;
				}
	
			}
		}else if (op==6){
			break;
		}else{
			printf("Comando Invalido");
					
			Sleep(2000);
			system("cls");
		}
	}
	
	return 0;
}


