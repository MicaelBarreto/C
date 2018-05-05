#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int a=20;
	int b=50;
	
	int *pa;
	int *pb;
	
	pa=&a;
	pb=&b;
	
	printf("O valor do primeiro ponteiro e %d",pa);
	printf("\nO valor do segundo ponteiro e %d",pb);
	printf("\n-------------------------------- \n");
	printf("\nO valor do primeiro e %d",*pa);
	printf("\nO valor do segundo e %d",*pb);
	
	printf("\n\n\n\n");
	system("pause");
	
	return(0);
	
}
