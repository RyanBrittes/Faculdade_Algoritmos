#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Arquivo { 
    int contador;
    char caracter;
    struct Arquivo *proximo; 
}; 
typedef struct Arquivo node;

char entrada[100] = "BBBEAAAAFFHHHHHCBMMALLLCDDBBBBBBBCC";

void inserir(node* List, node* aux){
    if(List->proximo == NULL){
        List->proximo = aux; 
    } else {
        node* tmp = List->proximo;

        while(tmp->proximo != NULL){
            tmp = tmp->proximo;
        }
        tmp->proximo = aux;
    }
}

void percorrer(node* List){
    
    node* aux = (node*) malloc(sizeof(node));

    if(!aux){
        printf("Sem memoria suficiente!");
    	exit(1);
    } else {
        int cont = 1, i = 0, aux_contador;
        char aux_caracter;

        while(entrada[i] != NULL){
            if(entrada[i] == entrada[i + 1]){
                cont++;
            }
            else{
                while(entrada[i] != entrada[i + 1]){
                    if(cont == 1){
                        aux->caracter = entrada[i];
                        inserir(List, aux);
                    } 
                    else {
                        aux->contador = cont;
                        aux->caracter = entrada[i];
                        inserir(List, aux);
                    }
                }
                cont = 1;
            }
            i++;
        }
    }
}

void listar(node* List){
    if(List->proximo == NULL){
        printf("\nLista vazia...\n");
    }
	//Caso n�o esteja vazia, ir� percorrer a lista e imprimir os atributos contidos em cada n�
	else {
		//Declara��o e atribui��o de aux para receber o primeiro elemento da lista
        node* aux = List->proximo;
        //Loop respons�vel por percorre a lista at� o fim, imprimindo os resultados e encerrando sua aplica��o quando chegar ao fim
        while(aux != NULL)
        {
        	printf("\n===========================================");
            printf("Node: %d%c\n", aux->contador, aux->caracter);
            printf("===========================================\n");
            aux = aux->proximo;
        }
    }
}

int main(){
    setlocale(LC_ALL, "");
    node* List = (node *) malloc(sizeof(node));
    List->proximo = NULL;
    
    int opt;
    do{
    	printf("\n|----Sistema-Banc�rio----|\n");
    	printf("|                        |");
        printf("\n|Digite: 1 para Listar   |\n");
        printf("|Digite: 2 para Inserir  |\n");
        printf("|Digite: 0 para Sair     |\n-->");
        scanf("%d", &opt);
        
        switch(opt)
        {
            case 1:
                printf("\nListando...\n");
                listar(List);
                break;
            case 2:
                printf("\nInserindo...\n");
                percorrer(List);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida...\n");
        }
    }while(opt > 0);
    return 0;
}