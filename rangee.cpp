#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
	
	bool validateur[5];
	int rangee[5];
	int inserer=0;
	int retirer=0;
	int i=0;
	int j=0;
	int k;
	int qt=0;
	int op;
	
	validateur[0]=false;
	validateur[1]=false;
	validateur[2]=false;
	validateur[3]=false;
	validateur[4]=false;
	
	for(;;){
		printf("--choisissez une option--\n1-inserer\n2-retirer\n3-liste\n4-partir\ni=%i\nj=%i\n",i,j);
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
		
		if(op==1){
			if(qt==5){
			
				printf("La file d'attente est pleine\n\n");
			
				system("pause");
				fflush(stdin);
				system("cls");
				
			}else{
				
				if (i>4){
					i=0;
				}
				
				rangee[i] = rand()%500;
				validateur[i]=true;
				
				printf("la valeur %i a ete inseree dans la file d'attente\n\n",rangee[i]);
				
				qt++;
				i++;


				system("pause");
				fflush(stdin);
				system("cls");	
				
			}
	
		}else if(op==2){
			if(qt==0){
				printf("Il n'y a pas de valeur a retirer\n\n");
				
				system("pause");
				fflush(stdin);
				system("cls");
			}else{
				if(j<=4){
					rangee[j] = 0;
					validateur[j]=false;
					j++;
					qt--;
				}else if(j>4){
					j=0;
					rangee[j] = 0;
					validateur[j]=false;
					j++;
					qt--;
				}
				
			}
			
			
		}else if(op==3){
			for(k=0;k<5;k++){
				if(validateur[k]==false){
					printf("-n/a");
				}else{
					printf("-%i", 	rangee[k]);
				}
			}
			
			printf("\n\n");
			
			system("pause");
			fflush(stdin);
			system("cls");
			
		}else if(op==4){
			break;
		}else{
			printf("entree non valide\n\n");
			
			system("pause");
			fflush(stdin);
			system("cls");
		}
	}
	
	
	
	return 0;
}
