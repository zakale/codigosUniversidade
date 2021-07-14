/* Sintese 
    objetivo "LSE - Lista Simplesmente Encadeada"
    autor "Alex Vieira Lopes"
    data "14/07/2021"*/
    
#include <stdio.h>
#include <stdlib.h>

//*** Declaracoes de tipos *****************************************************
struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tNo **);
void incluir(struct tNo **, struct tNo *);
void excluir(struct tNo **, struct tNo *);
struct tNo *consultar(struct tNo *, int);
void listar(struct tNo *);
void destruir(struct tNo **);

//*** Bloco Principal **********************************************************
int main(void) {
	struct tNo *lista, *p;
	int opcao, codigo;
	
	inicializar(&lista);
	do {
        opcao = menu();
        switch (opcao) {
               case 1: 
                    printf("\n\n*** Inclusao ***\n\n");
                    p = malloc(sizeof(struct tNo)); // Criar um no
                    printf("Digite o codigo...: ");
                    scanf("%d", &(p->dado.codigo));
                    printf("Digite a descricao: ");
                    fflush(stdin);
                    gets(p->dado.descricao);
                    incluir(&lista, p); // Incluir o no com produto criado na lista
	                break;
               case 2: 
                    printf("\n\n*** Consulta ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    p = consultar(lista, codigo);
                    if (p != NULL)
                    	printf("Encontrou: %s\n", p->dado.descricao);
                    else
                    	printf("Codigo nao encontrado!\n");
	                break;
               case 3: 
                    printf("\n\n*** Listagem ***\n\n");
                    listar(lista); // Listar (mostrar na tela) todos os produtos
	                break;
               case 4: 
                    printf("\n\n*** Alteracao ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    p = consultar(lista, codigo);
                    if (p != NULL) {
                    	printf("Descricao atual........: %s\n", p->dado.descricao);
	                    printf("Digite a nova descricao: ");
	                    fflush(stdin);
	                    gets(p->dado.descricao);
					}
                    else
                    	printf("Codigo nao encontrado!\n");
	                break;
               case 5: 
                    printf("\n\n*** Exclusao ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    p = consultar(lista, codigo);
                    if (p != NULL)
                    	excluir(&lista, p);
                    else
                    	printf("Codigo nao encontrado!\n");
	                break;
        }
    } while (opcao != 0);
	destruir(&lista);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
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

//*** Inicializar **************************************************************
void inicializar(struct tNo **lst) {
	(*lst) = NULL;
}

//*** Incluir ******************************************************************
void incluir(struct tNo **lst, struct tNo *novo) {
	struct tNo *p = (*lst), *q;
	if (((*lst) == NULL) || (novo->dado.codigo < (*lst)->dado.codigo)) { // Lista vazia OU inicio
		novo->prox = (*lst);
		(*lst) = novo;
	}
	else { // fim ou meio
		while ((p != NULL) && (p->dado.codigo < novo->dado.codigo)) {
			q = p;
			p = p->prox;
		}
		q->prox = novo;
		novo->prox = p;
	}
}

//*** Excluir ******************************************************************
void excluir(struct tNo **lst, struct tNo *vitima) {
	struct tNo *p = (*lst), *q;
	if ((*lst) == vitima) // Unico OU Inicio
		(*lst) = vitima->prox;
	else { // fim e meio
		while (p != vitima) {
			q = p;
			p = p->prox;
		}
		q->prox = vitima->prox;
	}
	free(vitima);
}

//*** Consultar ****************************************************************
struct tNo *consultar(struct tNo *lst, int codigo) {
	struct tNo *p = lst;
	while (p != NULL) {
		if (p->dado.codigo == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}

//*** Listar *******************************************************************
void listar(struct tNo *lst) {
	struct tNo *p = lst;
	while (p != NULL) {
		printf("%d - %s\n", p->dado.codigo, p->dado.descricao);
		p = p->prox;
	}
}

//*** Destruir *****************************************************************
void destruir(struct tNo **lst) {
	struct tNo *p = (*lst), *q;	
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(lst);
}

//*** FIM **********************************************************************
