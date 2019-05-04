#include <stdio.h>
#include <string.h>

main(){
    int i = 0;
    char word[27];
    int len;
    int resultado[999];
    int wordC[999];
    int aux = 0;
    int count=0;

    printf("Digite a Palavra:");
    fgets(word, sizeof(word), stdin);
    len = strlen(word);
    printf("%i\n",len);
    for(int j=0;j<len;j++){
       for(i=7;i>=0;i--){
      	   resultado[aux] = (int) (word[j] >> i) & 1 ? 1 : 0;
           aux++;
       }
    }
    
    printf("\nA Palavra Codificada em binario e: ");
   
    for(i=0;i<aux;i++){
	printf("%i", resultado[i]);
    }

    printf("\n");
    
    for(i=0;i<aux;i++){
		if((resultado[i]==0)&&(resultado[i+1]==1)){
			printf("‾‾|__");
		}else if((resultado[i]==1)&&(resultado[i+1]==0)){
			printf("__|‾‾");
		}else if((resultado[i]==0)&&(resultado[i+1]==0)){
			printf("‾‾|__|");
		}else if((resultado[i]==1)&&(resultado[i+1]==1)){
			printf("__|‾‾|");
		}
	}
	
	for(j=0;j<aux;j=j+8){
		for(i=j;i<j+8;i++){
			wordC[count] = wordC[count] << 1 | resultado[i];
		}
	count++;
	}
	
	printf("\nA Palavra Decodificada e: ");
	
	for(i=0;i<count-1;i++){
		printf("%c", wordC[i]);
	}

printf("\n");
 }

