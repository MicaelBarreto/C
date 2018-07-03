#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main(){
	
	int vet[5];
	int i;
	int j;
	int aux;
	int op;
	FILE *fp;
	char bS[25] = "BubbleSort.txt";
	
	for(i=0;i<5;i++){
		printf("Digite um valor: ");
		scanf("%d", &vet[i]);
		system("cls");
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			if(vet[j]>vet[j+1]){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1]=aux;
			}
		}
	}
	
	 if ((fp = fopen(bS, "w"))!= NULL){
	 	 fp = fopen(bS, "w");
	 	 for (j=0;j<4;j++){
    		fprintf(fp,"%d - ",vet[j]);
    		printf("%d - ",vet[j]);
        }
    		fprintf(fp,"%d",vet[4]);
    		printf("%d",vet[4]);
    
	}else{
        printf("Falha ao criar o Arquivo");
        exit(1);
    }
    fclose(fp);
	 
	
	return 0;
}
