#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<string.h>
#include<windows.h>

int main(){
	
	

	int i;
	int op;
	char player[25];
	char bot[25];
	bool valP = false;
	int inicio = rand()%1;
	int acertaBolas;
	int qualBola;
	int brancaChance;
	int oitoChance;
	bool valJog; //0-Bot 1-Player
	int jogadas=0;
	bool branca = true;
	int menores=7;
	int maiores=7;
	bool oito = true;
	int encacapa;
	bool quem;
	
	for(;;){
	
		printf("---------- SINUCANDO ----------\n   by Barreto e Rabuski ltda\n\n\n   1-Selecionar Personagem\n   2-Jogar\n   3-Sair \n\n-------------------------------\n");
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
		
		if(op==1){
			printf("---------- SELECIONE ----------\n\n   1-Lui Bone\n   2-Miguelzao\n   3-Ka\n   4-Pernambucano de Taubate\n\n-------------------------------\n");
			scanf("%i", &op);
			fflush(stdin);
			system("cls");
			
			if(op==1){
				
				strcpy(player, "Lui Bone");
				strcpy(bot, "Miguelzao");
				valP=true;
				
			}else if(op==2){
				
				strcpy(player, "Miguelzao");
				strcpy(bot, "Ka");
				valP=true;
				
			}else if(op==3){
				
				strcpy(player, "Ka");
				strcpy(bot, "Pernambucano de Taubate");
				valP=true;
				
			}else if(op==4){
				
				strcpy(player, "Pernambucano de Taubate");
				strcpy(bot, "Lui Bone");
				valP=true;
				
			}else{
				printf("-------------------------------\n\n\n   Entrada Invalida\n\n\n-------------------------------\n");
				system("pause");
				fflush(stdin);
				system("cls");
			}
		}else if(op==2){
			if(valP==true){
				break;
			}else{
				printf("-------------------------------\n\n\n   Personagem nao escolhido\n\n\n-------------------------------\n");
				system("pause");
				fflush(stdin);
				system("cls");
			}
			
		}else if(op==3){
			break;
			
		}else{
			
			printf("-------------------------------\n\n\n   Entrada Invalida\n\n\n-------------------------------\n");
			system("pause");
			fflush(stdin);
			system("cls");
			
		}
		
	}
	
		if (inicio==0){
			valJog=0;
		}else{
			valJog=1;
		}
		
		for(;;){
		
			acertaBolas = rand()%100;
			qualBola = 1 + rand()%13;
			branca = rand ()%100;
			oito = rand()%100;
			encacapa = rand()%100;
		
		if(valJog==true){
			printf("Sua vez!\n");
			system("pause");
			fflush(stdin);
			acertaBolas = rand()%100;
			qualBola = 1 + rand()%13;
			brancaChance = rand ()%100;
			oitoChance = rand()%100;
			encacapa = rand()%100;
			
			if((acertaBolas>20)&&(encacapa>50)){
				if(qualBola>7){
					maiores--;
					printf("voce acertou!, suas bolas sao as maiores!");
					quem=true;
				}else if(qualBola<=7){
					menores--;
					printf("voce acertou!, suas bolas sao as menores!");
					quem=false;
				}
				valJog = true;
				break;
			}
			valJog=false;
			system("pause");
			system("cls");
			fflush(stdin);
		}else{
			printf("Vez de %s\n", bot);
			Sleep(1000);
			
				if((acertaBolas>20)&&(encacapa>50)){
				if(qualBola>7){
					maiores--;
					printf("%s acertou!, suas bolas sao as menores!", bot);
					quem=false;
				}else if(qualBola<=7){
					menores--;
					printf("%s acertou!, suas bolas sao as maiores!", bot);
					quem=true;
				}
				valJog = false;
				break;
			}
			system("pause");
			system("cls");
			fflush(stdin);
			valJog=true;
		}
		
	}
	
	for(;;)	{
		
		if(valJog==true){
			printf("Sua vez!\n");
			system("pause");
			fflush(stdin);
			acertaBolas = rand()%100;
			qualBola = rand()%100;
			brancaChance = rand ()%100;
			oitoChance = rand()%100;
			encacapa = rand()%100;
			
			if(acertaBolas>25){
				if(encacapa>30){
					if(qualBola>25){
						printf("voce derrubou uma bola sua!");
						system("pause");
						system("cls");
						
						if (quem==true){
							maiores--;
						}else{
							menores--;
						}
					}else{
						printf("voce derrubou uma bola de %s", bot);
						system("pause");
						system("cls");
						valJog=false;
						
						if (quem==false){
							maiores--;
						}else{
							menores--;
						}
					}
				}
			}else{
				valJog=false;
			}
			
		}else if(valJog==false){
			printf("Vez de %s\n\n\n", bot);
			Sleep(1000);
			acertaBolas = rand()%100;
			qualBola = rand()%100;
			brancaChance = rand ()%100;
			oitoChance = rand()%100;
			encacapa = rand()%100;
			
			if(acertaBolas>25){
				if(encacapa>30){
					if(qualBola>25){
						printf("%s derrubou uma bola propria!\n\n\n", bot);
						system("pause");
						system("cls");
						
						if (quem==false){
							maiores--;
						}else{
							menores--;
						}
					}else{
						printf("%s derrubou uma bola sua\n\n", bot);
						system("pause");
						system("cls");
						valJog=true;
						
						if (quem==true){
							maiores--;
						}else{
							menores--;
						}
					}
				}
			}else{
				valJog=true;
			}
		}
	}
	return 0;
}
