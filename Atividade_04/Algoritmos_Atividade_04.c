#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
    
    //Declaração dos atributos que seram utilizados na função
    char entrada[100], saida [100];
    char caracter;
    int i = 0, c = 0, cont = 1, reducao;

    //Solicitação do valor que será compactado
    printf("\nDigite o texto que será compactado: ");
    scanf("%s", &entrada);
    
    //Loop de repetição responsável por percorrer o vetor até chegar em um valor 
    while(entrada[i] != NULL){

        //Condição responsável por realizar a contagem de elementos repetidos
        if(entrada[i] == entrada[i + 1]){
            cont++;
        }

        //Condição responsável por atribuir os elementos compactados a vetor saida
        else{

            //Condição que garante que elementos com apenas um elemento não tenham sua quantidade representada na compactação, adicionando apenas o elemento sem repetição
            if(cont == 1){
                saida[c] = entrada[i];
                c++;
            } 
            
            //Condição que adiciona no vetor saida os elementos sem repetição com a quantidade de elementos repetidos do elemento adicionado
            else {
                //Variável resposável por converter o valor int para char 
                caracter = cont+'0';
                saida[c] = caracter;
                c++;
                saida[c] = entrada[i];
                c++;
            }
        cont = 1;
        }
        i++;
    }

    //Variável responsável por calcular a porcentagem de redução com a compactação
    reducao = (100 - ((c*100)/i));

    //Impressão dos resultados
    printf("\nTexto Original: %s", entrada);
    printf("\nQuantidade de caracteres: %d", i);
    printf("\n\nTexto compactado: %s", saida);
    printf("\nQuantidade de caracteres: %d", c);
    printf("\n\nApós a compactação foi possível obter um redução de: %d%%\n", reducao);

    return 0;
}