/*
	@autor: Robson Ken Iti Arita;
	@data: 07/05/2021;
	@nome: Cadastro de Clientes;
*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct cli
{
	char nome[50],
		 cpf[15],
		 email[50],
		 telefone[15],
	 	 cep[10],
		 logradouro[30],
		 numero[10],
		 bairro[30],
		 cidade[20],
		 estado[20];
	int id;
	struct cli *proximo;
}cliente;

typedef struct
{
	cliente *inicio;
	cliente *final;
	int contador;
}descritor;

void InicializaLista(descritor *);
int CadastraCliente(descritor *, int);
int ExcluiCliente(descritor *, int);
void ImprimeLista(descritor *);
int main()
{
	
	int codigo = 1, n;
	descritor lista;
	
	InicializaLista(&lista);
	
	while(1)
	{
		printf("Digite '1' para adicionar um cliente\n");
		printf("Digite '2' para remover um cliente\n");
		printf("Digite '3' para listar os clientes\n");
		printf("Digite '4' para finalizar\n");
		scanf("%d", &n);
		puts("");
		
		if(n == 1)
		{
			if(CadastraCliente(&lista, codigo) == TRUE)
			{
				printf("Cadastro Realizado\n");
				codigo ++;
			}
			
			else
			printf("Erro de alocacao na memoria\n");
		}
		else if(n == 2)
		{
			if(lista.contador == 0)
			{
				puts("Lista vazia\n");
				continue;
			}
			printf("Digite o codigo do cliente a ser removido\n");
			scanf("%d", &n);
			if(ExcluiCliente(&lista, n) == TRUE)
			printf("Cliente removido\n");
			
			else
			printf("Cliente nao encontrado\n");
			
			n = 2;
		}
		else if(n == 3)			
			ImprimeLista(&lista);
		
		else if(n == 4)
		break;
		
		else
		printf("Valor incorreto\n");
		
		puts("");
	}
	puts("Execucao finalizada");
	return 0;
}
void InicializaLista(descritor *lista)
{
	lista->inicio = NULL;
	lista->final = NULL;
	lista->contador = 0;
}
int CadastraCliente(descritor *lista, int cod)
{
	cliente *aux;
	
	aux = malloc(sizeof(cliente));
	
	if(aux == NULL)
	return FALSE;
	
	aux->id = cod;
	aux->proximo = NULL;
	puts("Obs: Entrada de valores sem espacamento");
	printf("Digite o nome do cliente\n");
	scanf("%s", aux->nome);
	printf("Digite o e-mail do cliente\n");
	scanf("%s", aux->email);
	printf("Digite o CPF ou CNPJ do cliente\n");
	scanf("%s", aux->cpf);
	printf("Digite o telefone do cliente\n");
	scanf("%s", aux->telefone);
	printf("Digite o CEP do cliente\n");
	scanf("%s", aux->cep);
	printf("Digite o logradouro do cliente\n");
	scanf("%s", aux->logradouro);
	printf("Digite o numero do cliente\n");
	scanf("%s", aux->numero);
	printf("Digite o bairro do cliente\n");
	scanf("%s", aux->bairro);
	printf("Digite a cidade do cliente\n");
	scanf("%s", aux->cidade);
	printf("Digite o estado do cliente\n");
	scanf("%s", aux->estado);

	if(lista->inicio == NULL)
		lista->inicio = aux;
		
	else
		lista->final->proximo = aux;
		
	lista->final = aux;
	lista->contador = lista->contador + 1;
	
	return TRUE;
}
int ExcluiCliente(descritor *lista, int cod)
{
	cliente *aux;
		aux = lista->inicio;
		lista->final = NULL;
		while (aux != NULL)
		{	
			if (aux->id == cod)
			break;
		
			lista->final = aux;
			aux = aux->proximo;
		}
	
		if (aux == NULL)
			return FALSE;
		else
		{	
			if (lista->final == NULL)
				lista->inicio = aux->proximo;
			else
				lista->final->proximo = aux->proximo;
		
			if (aux == lista->final)
				lista->final = lista->final;
				
			lista->contador = lista->contador -1;
			
			free(aux);	
		}
		return TRUE;
}
void ImprimeLista(descritor *lista)
{
	cliente *aux;
	int i;
	
	if(lista->inicio == NULL)
		printf("Lista vazia\n");
	
	else
	{
		printf("\nConteudo da lista:\n");
		printf("\nA lista possui %d elementos\n\n", lista->contador);
		aux = lista->inicio;
		while(aux != NULL)
		{
			printf("Codigo: %d\n", aux->id);
			printf("Nome: %s\n", aux->nome);
			printf("E-mail: %s\n", aux->email);
			printf("CPF ou CNPJ: %s\n", aux->cpf);
			printf("Telefone: %s\n", aux->telefone);
			printf("CEP: %s\n", aux->cep);
			printf("Logradouro: %s\n", aux->logradouro);
			printf("Numero: %s\n", aux->numero);
			printf("Bairro: %s\n", aux->bairro);
			printf("Cidade: %s\n", aux->cidade);
			printf("Estado: %s\n", aux->estado);
			aux = aux->proximo;
			puts("");
		}
	}
}
