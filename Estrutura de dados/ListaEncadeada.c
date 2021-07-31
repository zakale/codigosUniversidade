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

struct tDescritor {
	struct tNo *ini;
	int qtd;
	struct tNo *fim;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tDescritor*);
void incluir(struct tDescritor*, struct tNo *);
void excluir(struct tDescritor*, struct tNo *);
struct tNo *consultar(struct tDescritor, int);
void listar(struct tDescritor);
void destruir(struct tDescritor*);

//*** Bloco Principal **********************************************************
int main(void) {
	struct tDescritor lista;
	struct tNo *p;
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
void inicializar(struct tDescritor *desc) {
	(*desc).ini = NULL;
	(*desc).qtd = 0;
	(*desc).fim = NULL;
}

//*** Incluir ******************************************************************
void incluir(struct tDescritor *desc, struct tNo *novo) {
	struct tNo *p = (*desc).ini, *q;
	if (((*desc).ini == NULL) || (novo->dado.codigo < (*desc).ini->dado.codigo)) { // Lista vazia OU inicio
		if ((*desc).ini == NULL) // lista vazia
			(*desc).fim = novo;
		novo->prox = (*desc).ini;
		(*desc).ini = novo;
	}
	else { // fim ou meio
		if (novo->dado.codigo > (*desc).fim->dado.codigo) { // fim
			(*desc).fim->prox = novo;
			novo->prox = NULL;
			(*desc).fim = novo;
		}
		else { // meio
			while (p->dado.codigo < novo->dado.codigo) {
				q = p;
				p = p->prox;
			}
			q->prox = novo;
			novo->prox = p;
		}
	}
	(*desc).qtd++;
}

//*** Excluir ******************************************************************
void excluir(struct tDescritor *desc, struct tNo *vitima) {
	struct tNo *p = (*desc).ini, *q;
	
	if ((*desc).qtd == 0) // unico
		(*desc).ini = (*desc).fim = NULL;
	else { // Inicio ou fim ou meio
		if ((*desc).ini == vitima) // Inicio
			(*desc).ini = vitima->prox;
		else { // fim e meio
			while (p != vitima) {
				q = p;
				p = p->prox;
			}
			q->prox = vitima->prox;
			if (vitima->prox == NULL)
				(*desc).fim = q;
		}
	}
	free(vitima);
	(*desc).qtd--;
}

//*** Consultar ****************************************************************
struct tNo *consultar(struct tDescritor desc, int codigo) {
	struct tNo *p = desc.ini;
	while (p != NULL) {
		if (p->dado.codigo == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}

//*** Listar *******************************************************************
void listar(struct tDescritor desc) {
	struct tNo *p = desc.ini;
	printf("Total %d\n", desc.qtd);
	while (p != NULL) {
		printf("%d - %s\n", p->dado.codigo, p->dado.descricao);
		p = p->prox;
	}
}

//*** Destruir *****************************************************************
void destruir(struct tDescritor *desc) {
	struct tNo *p = (*desc).ini, *q;	
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(desc);
}

//*** FIM **********************************************************************
