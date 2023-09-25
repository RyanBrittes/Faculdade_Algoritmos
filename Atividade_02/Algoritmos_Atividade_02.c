#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Estrutura Banco, respons�vel por conter as informa��es do cliente contida em cada no da estrutura
struct Banco { 
    int numero_conta;  
    char nome_cliente[30]; 
    float saldo; 
    struct Banco *proximo; 
}; 
//Redefini��o do nome da estrutura Banco para node, podendo ser chamada pelo novo nome agora
typedef struct Banco node;  

//Funcao responsavel por inserir elementos na lista pelo fim
void inserir_fim(node* CABECA_LISTA)
{
	//Declara��o e aloca��o de mem�ria para aux
    node* aux = (node*) malloc(sizeof(node));
    //Verifica��o se existe espa�o dispon�vel para aux ser utilizada, caso n�o exista a fun��o ser� encerrada com uma mensagem
    if(!aux){
    	printf("Sem memoria suficiente!");
    	exit(1);
	}
	//Caso haja o espa�o em mem�ria dispon�vel, ser�o requisitas as informa��es do novo n� e realizas algumas opera��es para que este elemento seja adicionado ao fim da lista
	else {
		//Solicita��o do n�mero da conta do cliente
		printf("Informe o numero da conta do cliente: ");
		scanf("%d", &aux->numero_conta);
		//Solicita��o do saldo dispon�vel do cliente
		printf("Informe o saldo do cliente: ");
		scanf("%f", &aux->saldo);
		//Solicita��o do nome do cliente
		printf("Informe o nome do cliente: ");
		scanf("%s", &aux->nome_cliente);
		//An�lise se o elemento � o primeiro da lista, caso seja, ele ser� adicionado
		if(CABECA_LISTA->proximo == NULL){
			CABECA_LISTA->proximo = aux; 
		}
		//Caso j� exista algum elemento na lista, ela ser� percorrida at� que o �ltimo elemento seja encontrado e o novo seja adicionado ao final da lista
		else {
			//Declara��o da vari�vel tmp, respons�vel por auxiliar no processo de percorre a lista e realizar a fun��o de adicionar o elemento no final da lista
			node* tmp = CABECA_LISTA->proximo;
			//Loop que ir� percorrer a lista, encerrando quando encontrar o �ltimo elemento da lista e caso seja inserido algum numero de conta j� existente
			while(tmp->proximo != NULL && tmp->numero_conta != aux->numero_conta){
				tmp = tmp->proximo;
			}
			//Caso seja inserido algum n�mero de conta igual a outro j� existem, ser� informado que este elemento j� existe, encerrando a aplica��o
			if(tmp->numero_conta == aux->numero_conta){
				printf("\nEst� conta j� existe, tente novamente com n�meros diferentes.");
			}
			//Caso n�o haja duplicidade, o elemento informado ser� inserido ao final da lista
			else{
				tmp->proximo = aux;
			}
		}
	}
}

//Funcao responsavel por remover elementos dentro da lista
void remover(node* CABECA_LISTA)
{
	//Declara��o dos atributos que ser�o utilizados nas opera��es, sendo elas o valor a ser removido e as vari�veis auxiliares
	int conta;
	node *aux, *tmp = NULL;
	//Solicita��o do valor a ser removido		
	printf("\nDigite o numero da conta do cliente que deseja remover: ");
	scanf("%d", &conta);
	//Verifica��o se a lista est� vazia ou n�o, caso esteja ser� exibida uma mensagem
	if(CABECA_LISTA->proximo == NULL){
		printf("\nLista vazia!");
	}
	//Caso n�o esteja, ser�o realizas as opera��es para remover o objeto mencionado
	else {
		//Atribui��o �s vari�veis auxiliares da refer�ncia da lista, para que consigam percorrer at� encontrar o objeto ou n�o
		aux = CABECA_LISTA->proximo;
		tmp = CABECA_LISTA;
		//Loop de repeti��o respons�vel por percorrer a lista, encerrando quando encotrar o elemento mencionado ou se a lista chegar ao fim
		while(aux->proximo != NULL && aux->numero_conta != conta){
			tmp = tmp->proximo;
			aux = aux->proximo;
		}
		//Caso a lista chegue ao fim e n�o encontre o elemento mencionado, ir� finalizar a aplica��o com uma mensagem
		if(aux->proximo == NULL && aux->numero_conta != conta){
			printf("\nItem n�o encontrado, tente novamente");
		}
		//Caso o seja encontrado ser� retornada uma mensagem com o nome do cliente que foi removido e a opera��o de remover o objeto ser� concluida
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
	//Verificando se a lista est� vazia, caso esteja ir� retornar uma mensagem
    if(CABECA_LISTA->proximo == NULL)
    {
        printf("\nLista vazia...\n");
    }
	//Caso n�o esteja vazia, ir� percorrer a lista e imprimir os atributos contidos em cada n�
	else {
		//Declara��o e atribui��o de aux para receber o primeiro elemento da lista
        node* aux = CABECA_LISTA->proximo;
        //Loop respons�vel por percorre a lista at� o fim, imprimindo os resultados e encerrando sua aplica��o quando chegar ao fim
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
	//Declara��o e atribui��o de um espa�o na mem�ria para a vari�vel CABECA_LISTA, que servir� de refer�ncia para as opera��es, come�ando sempre com um ponteiro direcionado para um espa�o vazio "NULL"
	setlocale(LC_ALL, "");
    node* CABECA_LISTA = (node *) malloc(sizeof(node));
    CABECA_LISTA->proximo = NULL;

    int opt;
    //Inicializa��o do programa com um painel de op��es, solicitando ao usu�rio uma op��o para realizar uma a��o dentro do programa
    do
    {
    	printf("\n|----Sistema-Banc�rio----|\n");
    	printf("|                        |");
        printf("\n|Digite: 1 para Listar   |\n");
        printf("|Digite: 2 para Inserir  |\n");
        printf("|Digite: 3 para Remover  |\n");
        printf("|Digite: 0 para Sair     |\n-->");
        scanf("%d", &opt);
        
        switch(opt)
        {
        	//Caso seja digitado 1, ser� realizada a impress�o da lista, chamando a fun��o "imprime", com os atributos contidos em cada n�
            case 1:
                printf("\nListando...\n");
                imprime(CABECA_LISTA);
                break;
            //Caso seja digitado 2, ser� chamada a fun��o de inserir "inserir_fim", respons�vel por realizar a atribui��o de um novo n� no fim da lista
            case 2:
                printf("\nInserindo...\n");
                inserir_fim(CABECA_LISTA);
                break;
            //Caso seja digitado 3, ser� chamada a fun��o de remo��o "remover", respons�vel por realizar a remo��o de um n� na lista
            case 3:
                printf("\nRemovendo...\n");
                remover(CABECA_LISTA);
                break;
            //Caso seja digitado 0, ser� finalizado o loop e o programa ir� encerrar sua aplica��o
            case 0:
                printf("\nSaindo...\n");
                break;
            //Caso o valor n�o seja uma das op��es acima, ser� retornada uma mensagem e o painel de op��es ir� solicitar novamente uma op��o v�lida
            default:
                printf("\nOpcao invalida...\n");
        }
    //Condi��o para o loop encerrar sua aplica��o
    }while(opt > 0);
    return 0;
}
