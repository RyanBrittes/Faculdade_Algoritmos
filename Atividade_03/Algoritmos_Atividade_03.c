#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Estrutura Banco, responsável por conter as informações do cliente contida em cada no da estrutura
struct Banco {
	int numero_conta;
	struct Banco *anterior;
	struct Banco *proximo;
};
//Redefinição do nome da estrutura Banco para node, podendo ser chamada pelo novo nome agora
typedef struct Banco node;

//Funcao responsavel por inserir elementos na lista pelo inicio
void insertListFirst(node* List){
	//Declaração e alocação de memória para aux
	node* aux = (node*) malloc(sizeof(node));
	//Verificação se existe espaço disponível para aux ser utilizada, caso não exista a função será encerrada com uma mensagem
	if(!aux){
		printf("\nSem espaço em memória");
		exit(1);
	} 
	//Caso haja o espaço em memória disponível, serão requisitas as informações do novo nó e realizas algumas operações para que este elemento seja adicionado ao fim da lista
	else {
		
		//Solicitação do número da conta do cliente
		printf("\nInforme o número da conta do cliente: ");
		scanf("%d", &aux->numero_conta);
		
		aux->proximo = NULL;
		aux->anterior = NULL;
		//Análise se o elemento é o primeiro da lista, caso seja, ele será adicionado
		if(List->proximo == NULL){
			List->proximo = aux;
		} 
		//Caso ele não seja único na lista, será adicionado no inicio antes de qualquer elemento 
		else {
			printf("Inserindo...");
			node* tmp = List->proximo;
			tmp->anterior = aux;
			aux->proximo = tmp;
			List->proximo = aux;
		}
	}
}

//Funcao responsavel por remover elementos dentro da lista
void removeList(node* List){
	//Declaração dos atributos que serão utilizados nas operações, sendo elas o valor a ser removido e as variáveis auxiliares
	int conta;
	node *aux, *tmp = NULL;
	//Verificação se a lista está vazia ou não, caso esteja será exibida uma mensagem
	if(List->proximo == NULL){
		printf("\nLista Vazia!");
	} 
	//Caso não esteja, serão realizas as operações para remover o objeto mencionado
	else {
		//Solicitação do valor a ser removido
		printf("\nDigite o número da conta que deseja remover: ");
		scanf("%d", &conta);
		//Atribuição às variáveis auxiliares da referência da lista, para que consigam percorrer até encontrar o objeto ou não
		aux = List->proximo;
		aux->anterior = NULL;
		tmp = List;
		//Loop de repetição responsável por percorrer a lista, encerrando quando encotrar o elemento mencionado ou se a lista chegar ao fim
		while(aux->proximo != NULL && aux->numero_conta != conta){
			aux = aux->proximo;
			tmp = tmp->proximo;
		}
		//Caso a lista chegue ao fim e não encontre o elemento mencionado, irá finalizar a aplicação com uma mensagem
		if(aux->proximo == NULL && aux->numero_conta != conta){
			printf("\nItem não encontrado, tente novamente");
		} 
		//Caso o seja encontrado será retornada uma mensagem e a operação de remover o objeto será concluida
		else {
			if(aux->anterior == NULL && aux->proximo == NULL){
				printf("\nRemovendo...");
				List->proximo = NULL;
			} else{
				printf("\nRemovendo...");
				free(aux);
				aux->anterior = tmp;
				aux = aux->proximo;
				tmp->proximo = aux;
			}
		}
	}
}

//Funcao responsavel por listar os elementos contidos dentro da lista
void printList(node* List){
	
	//Verificando se a lista está vazia, caso esteja irá retornar uma mensagem
	if(List->proximo == NULL){
		printf("\nLista Vazia!");
	} 
	//Caso não esteja vazia, irá percorrer a lista e imprimir os atributos contidos em cada nó
	else {
		//Declaração e atribuição de aux para receber o primeiro elemento da lista
		node* aux = List->proximo;
		//Loop responsável por percorre a lista até o fim, imprimindo os resultados e encerrando sua aplicação quando chegar ao fim
		while(aux != NULL){
			printf("\n*****************************************");
			printf("\nNumero da conta: %d", aux->numero_conta);
			printf("\nEndereço Node: %d", aux);
			printf("\nEndereço anterior: %d", aux->anterior);
			printf("\nEndereço próximo: %d", aux->proximo);
			printf("\n*****************************************\n");
			aux->anterior = aux;
			aux = aux->proximo;
		}
	}
}

//Funcao principal responsavel por chamar as funcoes dentro da lista e realizar as suas operacoes e resultados previstos
int main(){
	//Declaração e atribuição de um espaço na memória para a variável CABECA_LISTA, que servirá de referência para as operações, começando sempre com um ponteiro direcionado para um espaço vazio "NULL"
	setlocale(LC_ALL, "");
	node* List = (node*) malloc(sizeof(node));
	List->proximo = NULL;
	int opt;
	
	//Inicialização do programa com um painel de opções, solicitando ao usuário uma opção para realizar uma ação dentro do programa
	do{
		printf("\n\nEscolha um opção:\n");
		printf("\n1 - Listar contas");
		printf("\n2 - Adicionar uma conta");
		printf("\n3 - Remover uma conta");
		printf("\n0 - Sair\n");
		scanf("%d", &opt);
		
		switch(opt){
			//Caso seja digitado 1, será realizada a impressão da lista, chamando a função "printList", com os atributos contidos em cada nó
			case 1:
				printf("***Opção Listar***");
				printList(List);
				break;
				
			//Caso seja digitado 2, será chamada a função de inserir "insertListFirst", responsável por realizar a atribuição de um novo nó no início da lista	
			case 2:
				printf("***Opção Adicionar***");
				insertListFirst(List);
				break;
			
			//Caso seja digitado 3, será chamada a função de remoção "remover", responsável por realizar a remoção de um nó na lista
			case 3:
				printf("***Opção Remover***");
				removeList(List);
				break;
			
			//Caso seja digitado 0, será finalizado o loop e o programa irá encerrar sua aplicação
			case 0:
				printf("***Encerrando***");
				break;
			
			//Caso o valor não seja uma das opções acima, será retornada uma mensagem e o painel de opções irá solicitar novamente uma opção válida
			default:
				printf("Opção inválida, tente novamente!");
		}
		
	} 
	 //Condição para o loop encerrar sua aplicação
	while (opt > 0);
	
	return 0;
}
