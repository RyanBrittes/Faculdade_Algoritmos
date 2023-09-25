#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Estrutura Banco, responsável por conter as informações do cliente contida em cada no da estrutura
struct Banco { 
    int numero_conta;  
    char nome_cliente[30]; 
    float saldo; 
    struct Banco *proximo; 
}; 
//Redefinição do nome da estrutura Banco para node, podendo ser chamada pelo novo nome agora
typedef struct Banco node;  

//Funcao responsavel por inserir elementos na lista pelo fim
void inserir_fim(node* CABECA_LISTA)
{
	//Declaração e alocação de memória para aux
    node* aux = (node*) malloc(sizeof(node));
    //Verificação se existe espaço disponível para aux ser utilizada, caso não exista a função será encerrada com uma mensagem
    if(!aux){
    	printf("Sem memoria suficiente!");
    	exit(1);
	}
	//Caso haja o espaço em memória disponível, serão requisitas as informações do novo nó e realizas algumas operações para que este elemento seja adicionado ao fim da lista
	else {
		//Solicitação do número da conta do cliente
		printf("Informe o numero da conta do cliente: ");
		scanf("%d", &aux->numero_conta);
		//Solicitação do saldo disponível do cliente
		printf("Informe o saldo do cliente: ");
		scanf("%f", &aux->saldo);
		//Solicitação do nome do cliente
		printf("Informe o nome do cliente: ");
		scanf("%s", &aux->nome_cliente);
		//Análise se o elemento é o primeiro da lista, caso seja, ele será adicionado
		if(CABECA_LISTA->proximo == NULL){
			CABECA_LISTA->proximo = aux; 
		}
		//Caso já exista algum elemento na lista, ela será percorrida até que o último elemento seja encontrado e o novo seja adicionado ao final da lista
		else {
			//Declaração da variável tmp, responsável por auxiliar no processo de percorre a lista e realizar a função de adicionar o elemento no final da lista
			node* tmp = CABECA_LISTA->proximo;
			//Loop que irá percorrer a lista, encerrando quando encontrar o último elemento da lista e caso seja inserido algum numero de conta já existente
			while(tmp->proximo != NULL && tmp->numero_conta != aux->numero_conta){
				tmp = tmp->proximo;
			}
			//Caso seja inserido algum número de conta igual a outro já existem, será informado que este elemento já existe, encerrando a aplicação
			if(tmp->numero_conta == aux->numero_conta){
				printf("\nEstá conta já existe, tente novamente com números diferentes.");
			}
			//Caso não haja duplicidade, o elemento informado será inserido ao final da lista
			else{
				tmp->proximo = aux;
			}
		}
	}
}

//Funcao responsavel por remover elementos dentro da lista
void remover(node* CABECA_LISTA)
{
	//Declaração dos atributos que serão utilizados nas operações, sendo elas o valor a ser removido e as variáveis auxiliares
	int conta;
	node *aux, *tmp = NULL;
	//Solicitação do valor a ser removido		
	printf("\nDigite o numero da conta do cliente que deseja remover: ");
	scanf("%d", &conta);
	//Verificação se a lista está vazia ou não, caso esteja será exibida uma mensagem
	if(CABECA_LISTA->proximo == NULL){
		printf("\nLista vazia!");
	}
	//Caso não esteja, serão realizas as operações para remover o objeto mencionado
	else {
		//Atribuição às variáveis auxiliares da referência da lista, para que consigam percorrer até encontrar o objeto ou não
		aux = CABECA_LISTA->proximo;
		tmp = CABECA_LISTA;
		//Loop de repetição responsável por percorrer a lista, encerrando quando encotrar o elemento mencionado ou se a lista chegar ao fim
		while(aux->proximo != NULL && aux->numero_conta != conta){
			tmp = tmp->proximo;
			aux = aux->proximo;
		}
		//Caso a lista chegue ao fim e não encontre o elemento mencionado, irá finalizar a aplicação com uma mensagem
		if(aux->proximo == NULL && aux->numero_conta != conta){
			printf("\nItem não encontrado, tente novamente");
		}
		//Caso o seja encontrado será retornada uma mensagem com o nome do cliente que foi removido e a operação de remover o objeto será concluida
		else {
			printf("\nItem removido com sucesso, cliente excluido: %s", aux->nome_cliente);
			aux = aux->proximo;
			tmp->proximo = aux;
		}
	}		
}

//Funcao responsavel por listar os elementos contidos dentro da lista
void imprime(node* CABECA_LISTA)
{
	//Verificando se a lista está vazia, caso esteja irá retornar uma mensagem
    if(CABECA_LISTA->proximo == NULL)
    {
        printf("\nLista vazia...\n");
    }
	//Caso não esteja vazia, irá percorrer a lista e imprimir os atributos contidos em cada nó
	else {
		//Declaração e atribuição de aux para receber o primeiro elemento da lista
        node* aux = CABECA_LISTA->proximo;
        //Loop responsável por percorre a lista até o fim, imprimindo os resultados e encerrando sua aplicação quando chegar ao fim
        while(aux != NULL)
        {
        	printf("\n===========================================");
            printf("\nEnd node: %d\n", aux);
            printf("Numero da conta: %d\n", aux->numero_conta);
            printf("Saldo da conta: %.2f\n", aux->saldo);
            printf("Nome cliente: %s\n", aux->nome_cliente);
            printf("End do prox: %d\n", aux->proximo);
            printf("===========================================\n");
            aux = aux->proximo;
        }
    }
}

//Funcao principal responsavel por chamar as funcoes dentro da lista e realizar as suas operacoes e resultados previstos
int main()
{
	//Declaração e atribuição de um espaço na memória para a variável CABECA_LISTA, que servirá de referência para as operações, começando sempre com um ponteiro direcionado para um espaço vazio "NULL"
	setlocale(LC_ALL, "");
    node* CABECA_LISTA = (node *) malloc(sizeof(node));
    CABECA_LISTA->proximo = NULL;

    int opt;
    //Inicialização do programa com um painel de opções, solicitando ao usuário uma opção para realizar uma ação dentro do programa
    do
    {
    	printf("\n|----Sistema-Bancário----|\n");
    	printf("|                        |");
        printf("\n|Digite: 1 para Listar   |\n");
        printf("|Digite: 2 para Inserir  |\n");
        printf("|Digite: 3 para Remover  |\n");
        printf("|Digite: 0 para Sair     |\n-->");
        scanf("%d", &opt);
        
        switch(opt)
        {
        	//Caso seja digitado 1, será realizada a impressão da lista, chamando a função "imprime", com os atributos contidos em cada nó
            case 1:
                printf("\nListando...\n");
                imprime(CABECA_LISTA);
                break;
            //Caso seja digitado 2, será chamada a função de inserir "inserir_fim", responsável por realizar a atribuição de um novo nó no fim da lista
            case 2:
                printf("\nInserindo...\n");
                inserir_fim(CABECA_LISTA);
                break;
            //Caso seja digitado 3, será chamada a função de remoção "remover", responsável por realizar a remoção de um nó na lista
            case 3:
                printf("\nRemovendo...\n");
                remover(CABECA_LISTA);
                break;
            //Caso seja digitado 0, será finalizado o loop e o programa irá encerrar sua aplicação
            case 0:
                printf("\nSaindo...\n");
                break;
            //Caso o valor não seja uma das opções acima, será retornada uma mensagem e o painel de opções irá solicitar novamente uma opção válida
            default:
                printf("\nOpcao invalida...\n");
        }
    //Condição para o loop encerrar sua aplicação
    }while(opt > 0);
    return 0;
}
