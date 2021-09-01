/* Sintese
     objetivo - criar uma lista simplismente encadeada
     autor = alex vieira
     data 07/08/2021*/
     
     #include <stdio.h>
     #include <stdlib.h>
     
  struct tProdutos {
	int codigo; // chave
	char descricao[20];
	float valor;
};
    struct tNo {
	  struct tProdutos dado;
	  struct tNo *prox;
};

	 int menu(void);
     int main (void){
     	struct tNo *lista=NULL;
     	struct tNo *p;
     	struct tProdutos produto;
     	int opcao;
	
	do {
		opcao = menu();
		switch (opcao) {
			case 1:
				printf("\n\n*** Inclusao ***\n\n");
				
				printf("Digite o codigo...: ");
				scanf("%d", &produto.codigo);
				printf("Digite a descricao: ");
				fflush(stdin);
				gets(produto.descricao);
				printf("Digite o valor....: R$ ");
				scanf("%f", &produto.valor);
				
				p = malloc(sizeof(struct tNo));
				p->dado = produto; // (*p).dado = produto;
				
				// Incluir o produto (p) na lista (lista)
				// Inclusao no INICIO
				p->prox = lista;
				lista = p;
				
				break;
			case 2:
				printf("\n\n*** Listagem ***\n\n");
				p = lista;
				printf("Cod-- Descricao----------- Valor\n");
				while (p != NULL) {
					printf("%5d - %20s - R$ %.2f\n", p->dado.codigo, p->dado.descricao, p->dado.valor);
					p = p->prox;
				}
		}
	} while (opcao != 0);
	// sair... 
	// free(...);	
	return 0;
}


int menu(void) {
	int op;
	printf("\n\n*** menu ***\n\n");
	printf("1. Incluir\n");
	printf("2. Listar\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

