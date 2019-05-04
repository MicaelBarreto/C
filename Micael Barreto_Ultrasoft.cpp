//Sistema De Cadastramento e Gerênciamento de Clientes
#include <stdio.h>
#include <stdlib.h> /*system ("cls")*/
#include <string.h> /*strings*/
#include <locale.h> /*Português*/
#include <conio.h> /*getch()*/
#include <windows.h> /*Sleep()*/

void Inicio();
void Nao();
void Invalida();

struct pessoa{

char nome [50];
char CPF [15];
char sexo [4];
char nasc [12];
char tel [16];
char email [50];

};

int cod [1000];

int max=0;
int auxT=0;

main (){
	char opcao;
	int i=0;
	struct pessoa p[10000];
	char op;
	char buscaNome [50];
	int buscaCod;
	int buscaCod1;
	int buscaCod2;
	int flag=0;
	char aux;
	int flag1=0;
	char aux1;
	char opAlt;
	char opExcl;
	int flag2=0;
	int flag3=0;
	char sair;
    setlocale(LC_ALL, "Portuguese");
	
	Inicio();
	
     for (;;){
	
	printf ("#########################################\n");
	printf ("#                  HOME                 #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|       1- Cadastrar Cliente            |\n");
	printf ("|       2- Alterar Dados de Cliente     |\n");
	printf ("|       3- Exclusão de Cliente          |\n");
	printf ("|       4- Consultar Dados              |\n");
	printf ("|       5- Lista de Clientes            |\n");
	printf ("|       6- Sair                         |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	opcao = getch();
    
	system ("cls");
	
	
	if (opcao=='1') /*Cadastrar*/{
	 	max++;
	 	auxT++;
	
	printf ("#########################################\n");
	printf ("#                CADASTRO               #\n");
	printf ("#########################################\n");
	printf ("                  COD:%i\n",auxT);
	printf ("                                         \n");
	printf ("NOME: ");
	fgets (p[auxT].nome,50,stdin);
	printf ("\nCPF ");
	printf ("\n(Somente Numeros): ");
	fgets (p[auxT].CPF,15,stdin);
	printf ("\nSEXO ");
	printf ("\n(m ou f): ");
	fgets (p[auxT].sexo,4,stdin);
	printf ("\nDATA DE NASCIMENTO ");
	printf ("\n(Somente Numeros): ");
	fgets (p[auxT].nasc,12,stdin);
	printf ("\nTELEFONE ");
	printf ("\n(DDD+NNNNNNNN): ");
	fgets (p[auxT].tel,16,stdin);
	printf ("\nEMAIL: ");
	fgets (p[auxT].email,50,stdin);
	printf ("\n                                       \n");
	printf ("                                         \n");
	printf ("           \n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	
	cod[auxT]=auxT;
	system ("cls");
	
	}else 
	if (opcao=='2') /*Altera*/{
		
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("        Digite o Codigo do Cliente       \n");
	printf ("   \n");
	scanf ("%i", &buscaCod1);
	fflush(stdin); /*Limpar entrada e saida*/
	
	system ("cls");
	
	for (max=0;max<=auxT;max++){
		if (cod[max]==buscaCod1 && cod[max]!=0){
		

			
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("           Cliente %i Encontrado         \n",cod[max]);
	printf ("                                         \n");
	printf ("1-NOME: %s\n",p[max].nome);
	printf ("2-CPF:  %s\n",p[max].CPF);
	printf ("3-SEXO: %s\n",p[max].sexo);
	printf ("4-NASCIMENTO: %s\n",p[max].nasc);
	printf ("5-TELEFONE: %s\n",p[max].tel);
	printf ("6-EMAIL: %s\n",p[max].email);
	printf ("7-SAIR\n");
	printf ("                                         \n");
	printf ("           O que deseja alterar?         \n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	opAlt = getch();
	system ("cls");
	flag2++;
	
	if (opAlt=='1') /*Alterar Nome*/{
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("               \n");
	printf ("               \n");
	printf ("Digite o nome\n");
	fgets (p[max].nome,50,stdin);
	system ("cls");
	break;
	}else
	if (opAlt=='2') /*Alterar CPF*/{
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("               \n");
	printf ("%s\n",p[max].CPF);
	printf ("               \n");
	printf ("Digite o CPF\n");
	fgets (p[max].CPF,15,stdin);
	system ("cls");
	break;
	}else
	if (opAlt=='3') /*Alterar Sexo*/{
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("               \n");
	printf ("%s\n",p[max].sexo);
	printf ("               \n");
	printf ("Digite o sexo\n");
	fgets (p[max].sexo,4,stdin);
	system ("cls");
	break;
	}else
	if (opAlt=='4') /*Alterar Data*/{
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("               \n");
	printf ("%s\n",p[max].nasc);
	printf ("               \n");
	printf ("Digite a data de nascimento\n");
	fgets (p[max].nasc,12,stdin);
	system ("cls");
	break;
	}else
	if (opAlt=='5') /*Alterar Tel*/{
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("               \n");
	printf ("%s\n",p[max].tel);
	printf ("               \n");
	printf ("Digite o telefone\n");
	fgets (p[max].tel,16,stdin);
	system ("cls");
	break;
	}else
	if (opAlt=='6') /*Alterar Email*/{
	printf ("#########################################\n");
	printf ("#              ALTERAR DADOS            #\n");
	printf ("#########################################\n");
	printf ("               \n");
	printf ("%s\n",p[max].email);
	printf ("               \n");
	printf ("Digite o email\n");
	fgets (p[max].email,50,stdin);
	system ("cls");
	break;
	}else
	if (opAlt=='7') /*Sair*/{
		break;
	}else{
		Invalida();
	}
	
}
}
if (flag2==0) /*Cliente não encontrado*/{
	Nao();
}

}else
	if (opcao=='3') /*Exclui*/{
	printf ("#########################################\n");
	printf ("#             EXCLUIR CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("        Digite o Codigo do Cliente       \n");
	printf ("   \n");
	scanf ("%i", &buscaCod2);
	
	system ("cls");
	
	for (max=0;max<=auxT;max++){
		if (cod[max]==buscaCod2){
	printf ("#########################################\n");
	printf ("#             EXCLUIR CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("           Cliente %i Encontrado         \n",cod[max]);
	printf ("                                         \n");
	printf ("1-NOME: %s\n",p[max].nome);
	printf ("2-CPF:  %s\n",p[max].CPF);
	printf ("3-SEXO: %s\n",p[max].sexo);
	printf ("4-NASCIMENTO: %s\n",p[max].nasc);
	printf ("5-TELEFONE: %s\n",p[max].tel);
	printf ("6-EMAIL: %s\n",p[max].email);
	printf ("                                         \n");
	printf ("   Deseja Realmente Excluir o cliente?   \n");
	printf ("              1-SIM OU 2-NÃO             \n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	opExcl=getch();
	
	flag3++;
	system ("cls");
	
	if (opExcl=='1'){
		cod[max]=0;
	printf ("#########################################\n");
	printf ("#             EXCLUIR CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|      Cliente Excluido com sucesso     |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	
	Sleep (3000);
	system ("cls");
		break;
	}else{
		break;
	}
			
		}
		
	}
	
	if (flag3==0) /*Cliente não encontrado*/{
	Nao();
	
}

	}else
	if (opcao=='4') /*Consulta*/{
	printf ("#########################################\n");
	printf ("#            CONSULTA CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|       1- Consultar por Nome           |\n");
	printf ("|       2- Consultar por Código         |\n");
	printf ("|       3- Voltar à HOME                |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	op=getch();
	
	system ("cls");
	
	if (op=='1'){
		
	printf ("#########################################\n");
	printf ("#            CONSULTA CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("               Digite o Nome             \n");
	printf ("   \n");
	fgets (buscaNome,50,stdin);
	
	system ("cls");
	
	for (max=0;max<=auxT;max++){
		
		if (!strcmp(buscaNome,p[max].nome) && cod[max]!=0){
	printf ("#########################################\n");
	printf ("#            CONSULTA CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("            Cliente Encontrado           \n");
	printf ("                                         \n");
	printf (" NOME: %s\n",p[max].nome);
	printf (" CPF:  %s\n",p[max].CPF);
	printf (" SEXO: %s\n",p[max].sexo);
	printf (" NASCIMENTO: %s\n",p[max].nasc);
	printf (" TELEFONE: %s\n",p[max].tel);
	printf (" EMAIL: %s\n",p[max].email);
	printf (" COD: %i\n",cod[max]);
	printf ("                                         \n");
	printf ("      Pressione Enter Para Continuar      \n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
    aux=getch();
	
	
	

	     system ("cls");
	     flag++;
	     break;
			
		}
	}
	
	if (flag==0){
		Nao();
		
	}
	
	
		
	}else
	if (op=='2'){
		
	printf ("#########################################\n");
	printf ("#            CONSULTA CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("             Digite o Codigo             \n");
	printf ("   \n");
	scanf ("%i", &buscaCod);
	
	system ("cls");
	
      max=0;
	
	for (max=0;max<=auxT;max++){
		if (cod[max]==buscaCod && cod[max]!=0){
		

			
	printf ("#########################################\n");
	printf ("#            CONSULTA CLIENTE           #\n");
	printf ("#########################################\n");
	printf ("            Cliente Encontrado           \n");
	printf ("                                         \n");
	printf (" NOME: %s\n",p[max].nome);
	printf (" CPF:  %s\n",p[max].CPF);
	printf (" SEXO: %s\n",p[max].sexo);
	printf (" NASCIMENTO: %s\n",p[max].nasc);
	printf (" TELEFONE: %s\n",p[max].tel);
	printf (" EMAIL: %s\n",p[max].email);
	printf (" COD: %i\n",cod[max]);
	printf ("                                         \n");
	printf ("      Pressione Enter Para Continuar      \n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	aux = getch();
	

	

	
	flag1++;
	system ("cls");
	break;
}

	
		
		
	}
	
	if (flag1==0){
		Nao();
		}

		
	}else
	if (op=='3'){
		
	}else{
	Invalida();
		
	}
	


	}else
	if (opcao=='5') /*Lista*/{
		
	printf ("#########################################\n");
	printf ("#            LISTA DE CLIENTES          #\n");
	printf ("#########################################\n");
		for (max=1;max<=auxT;max++){

			if (cod[max]!=0){
				printf ("                                         \n");
				printf ("-----------------------------------------\n");
				printf ("%s\n",p[max].nome);
				printf ("%i\n",cod[max]);
				
			}
}
	printf ("-----------------------------------------\n");	
	printf ("      Pressione Enter Para Continuar     \n");		
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	sair=getch();
	system ("cls");
	}else
	if (opcao=='6') /*Saida*/{
		
	printf ("#########################################\n");
	printf ("#                                       #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                  Até                  |\n");
	printf ("|                   a                   |\n");
	printf ("|                Proxima                |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	break;
		
		
	}else{
	Invalida();
	}
  }
}

void Inicio(){
	printf ("#########################################\n");
	printf ("#                                       #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                  Bem                  |\n");
	printf ("|                Vindo(a)               |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#                                       #\n");
	printf ("#########################################\n");
	

    Sleep(3000);
	system ("cls");
	
	printf ("#########################################\n");
	printf ("#                                       #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                ULTRASOFT              |\n");
	printf ("|                  Ltda                 |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#                                       #\n");
	printf ("#########################################\n");
	
	Sleep (3000);
	system ("cls");
	
}

void Nao(){
	printf ("#########################################\n");
	printf ("#                                       #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|         Cliente não encontrado        |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");
	
	Sleep (3000);
	system ("cls");
}

void Invalida(){
	printf ("#########################################\n");
	printf ("#                                       #\n");
	printf ("#########################################\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|             Opção Invalida            |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("|                                       |\n");
	printf ("#########################################\n");
	printf ("#             ULTRASOFT,Ltda            #\n");
	printf ("#########################################\n");

	Sleep (3000);
	system ("cls");
}
