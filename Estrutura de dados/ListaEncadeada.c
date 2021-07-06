/* Sintese 
    objetivo "LSE - Lista Simplesmente Encadeada"
    autor "Alex Vieira Lopes"
    data "06/07/2021"*/
    
#include <stdio.h>
#include <stdlib.h>

struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;	
};
int menu(void);
void incluir(struct tNo **, struct tNo *);


int main (void){
	struct tNo *lista=NULL, *p;
	int opcao, codigo;
	
	do{
		opcao = menu();
		switch (opcao){
			case 1:
		    	printf("\t\t*** inclusao ***\n\n");	
		    	p = malloc(sizeof(struct tNo));
		    	printf("Digite o codigo...: ");
		    	scanf("%d", &(p->dado.codigo));
		    	printf("Digite a descricao: ");
		    	fflush(stdin);
		    	gets(p->dado.descricao);
		    	incluir(&lista, p);
			break;
				case 2:
		    	printf("\t\t**Consulta**");	
		    	printf("Digite o codigo: ");
		    //	scanf("%d", &dado.codigo:);
			break;
				case 3:
		    	printf("\t\t**Listagem**");	
			break;
				case 4:
		    	printf("\t\t**Alteracao**");	
			break;
				case 5:
		    	printf("\t\t**Exclusao**");	
			break;
			
		}
	} while (opcao != 0);
	return 0;
}

int menu(void){
	int op;
	printf("\n\n*** Menu ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Consulta\n");
	printf("3. Listagem\n");
	printf("4. Alteracao\n");
	printf("5. Exclusao\n");
	printf("0. Sair\n\n");
	printf("Escolha sua opcao: ");
	scanf("%d", &op);
	return op;
}
void incluir(struct tNo **lst, struct tNo *novo){
	if((*lst) == NULL) {
		novo->prox = NULL;
		(*lst) = novo;
	}
	else {
	}
}
