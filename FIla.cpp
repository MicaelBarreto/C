#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int main(){
	
	struct seniors{
		char name[20];
		int age;
	};
	
	struct notSeniors{
		char name[20];
		int age;
	};
	
	struct seniors s[5];
	struct notSeniors ns[5];
	bool vs[5];
	bool vns[5];
	char auxName[20];
	int auxAge;
	int i;
	int j=0;
	int k;
	int n;
	int m;
	int l=0;
	int o=0;
	int op;
	int qts=0;
	int qtns=0;
	
	for (i=0;i<5;i++){
		vs[i]=false;
		vns[i]=false;
	}
	
	i=0;
	
	while(1){
		printf("Choose an Option\n1-Insert\n2-Retire\n3-List\n4-Exit\n\nNot Seniors\nentrance=%i\nexit=%i\n\nSeniors\nentrance=%i\nexit=%i\n\n",i,o,l,j);
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
		
		if(op==1){
		
			if(i>4){
				i=0;
			}
			
			if(l>4){
				l=0;
			}
			
			printf("Insert a name: ");
			gets(auxName);
			fflush(stdin);
			printf("\nInsert the age: ");
			scanf("%i", &auxAge);
			fflush(stdin);
			system("cls");
			
			if(auxAge>=60){
				if(qts==5){
					printf("The Line is Already Full\n");
			
					system("pause");
					fflush(stdin);
					system("cls");
				}else{
					strcpy(s[l].name, auxName);
					s[l].age = auxAge;
					vs[l] = true;
					l++;
					qts++;
				}
			}else{
				if(qtns==5){
					printf("The Line is Already Full\n");
			
					system("pause");
					fflush(stdin);
					system("cls");
			
				}else{
					strcpy(ns[i].name, auxName);
					ns[i].age = auxAge;
					vns[i] = true;
					i++;
					qtns++;	
				}
			}
			
			
		}else if(op==2){
			if((qts==0)&&(qtns==0)){
				
				printf("There is no Person registred\n\n");
				
				system("pause");
				fflush(stdin);
				system("cls");
				
			}else{
				if(qts>0){
					if(j<=4){
						vs[j]=false;
						j++;
						qts--;
					}else if(j>4){
						j=0;
						vs[j]=false;
						j++;
						qts--;
					}
				}else{
					if(o<=4){
						vns[o]=false;
						o++;
						qtns--;
					}else if(o>4){
						o=0;
						vns[o]=false;
						o++;
						qtns--;
					}
				}
				
			}
			
		}else if(op==3){
			printf("Seniors: ");
			for(k=0;k<5;k++){
	
				if(vs[k]==false){
					printf("");
				}else{
					printf(" || %s / %i",s[k].name,s[k].age);
				}

			}
			
			printf("\n\nNot Seniors: ");
			for(n=0;n<5;n++){
				
				if(vns[n]==false){
					printf("");
				}else{
					printf(" || %s / %i",ns[n].name,ns[n].age);
				}
					
				}
			
				printf("\n\n");
				system("pause");
				fflush(stdin);
				system("cls");
			
		}else if(op==4){
			break;
		}else{
			
			printf("Invalid Option\n");
				
			system("pause");
			fflush(stdin);
			system("cls");	
			
		} 
	}
	
	
	return 0;
}
