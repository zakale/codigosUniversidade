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
void listar (struct tNo *);


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
		    	printf("\t\t*** Listagem ***\n\n");
		    	listar(lista);
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
void incluir(struct tNo **lst, struct tNo *novo) {
	struct tNo *p = (*lst), *q;
	if ((*lst) == NULL) { // Lista vazia
		novo->prox = NULL;
		(*lst) = novo;
	}
	else { // inicio, fim ou meio
		if (novo->dado.codigo < (*lst)->dado.codigo) { // inicio
			novo->prox = (*lst);
			(*lst) = novo;
		}
		else { // fim ou meio
			while (p->prox != NULL)
				p = p->prox;
			if (novo->dado.codigo > p->dado.codigo) { // fim
				p->prox = novo;
				novo->prox = NULL;
			}
			else { // meio
				p = (*lst);
				while (p->dado.codigo < novo->dado.codigo) {
					q = p;
					p = p->prox;
				}
				q->prox = novo;
				novo->prox = p;
			}
		}
	}
}

void listar (struct tNo *lst){
	struct tNo *p = lst;
	while (p != NULL) {
		printf("%d - %s\n", p->dado.codigo, p->dado.descricao);
		p = p->prox;
	}
}
