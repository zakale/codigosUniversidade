/*sintese 
   objetivo Ler palavras de um arquivo e retornar a seguinte informação: o código da palavra; a palavra lida; a sua função.
  contendo entrada pelo teclado, caracter especial e acentuação e letras maisuculas e minusculas*/
  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

#define TAM 300
//void aberturaArq();
//void leituraArq();

int main (void){
	setlocale(LC_ALL, "Portuguese_Brasil");
	char palavra[TAM];
	
	FILE *arq; 	
	arq = fopen("primeiraTarefa.txt", "a+");
	
	if(arq == NULL){
		printf("problema na criacao do arquivo");
		return ;
	}
	printf("\t\t\t**** Digite uma frase ****\n\n ");
	fflush(stdin);
    gets(palavra );
    fprintf(arq, "\n%s", palavra);
    printf("%s", palavra);

    fclose(arq);
	
	return 0;
}
/*
void aberturaArq(void){
	
	FILE *arq; 
	int resultado;
	char str[TAM];
	
	arq = fopen("primeiraTarefa.txt", "a");
	
	if(arq == NULL){
		printf("problema na criacao do arquivo");
		return ;
	}
	fprintf(arq, "%s", str);

	
	
      printf("\n\n %s", str);
  
	fclose(arq);
}
void leituraArq(void){
		FILE *arq; 
	int resultado;
	char str[TAM];
	
	arq = fopen("primeiraTarefa.txt", "r");
	
	if(arq == NULL){
		printf("problema na criacao do arquivo");
		return ;
	}
	fscanf(arq, "%s", &str);
	printf("%s", str);
	
	fclose(arq);
}*/
	

