#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct elemento{
	int num;
	struct elemento *ant;
	struct elemento *drt;
	struct elemento *eqd;
}El;

void inicializa(el **v){
	*v = NULL;
}

void insere_primeiro(El **v, int numaux){
	elemento *e;
	e = (elemento*) malloc(sizeof(elemento));
	e->num = numaux;
	e->ant = e;
	e->drt = e;
	e->eqd = e;
	*v = e;
}

void insere(El **v, int numaux){
	elemento *e;
	
	if
	
	e =((elemento*)malloc(sizeof(elemento)));
	e->num = numaux;
	e->pv= (*v) -> pv; 
	e->va = *v; 
	(*v)->pv = e;
	e ->pv->va = e;
	
	*v = e;
		
}

int main(){
	
	
	return 0;
}

