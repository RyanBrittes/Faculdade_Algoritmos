#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");

    char entrada [100] = "BBBEAAAAFFHHHHHCBMMALLLCDDBBBBBBBCC", saida [100];
    char caracter;
    int i = 0, c = 0, cont = 1;
    
    while(entrada[i] != NULL){
        if(entrada[i] == entrada[i + 1]){
            cont++;
        }
        else{
            if(cont == 1){
                saida[c] = entrada[i];
                c++;
            } else {
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
    printf("\nTexto Original: %s", entrada);
    printf("\nQuantidade de caracteres: %d", i);
    printf("\n\nTexto compactado: %s", saida);
    printf("\nQuantidade de caracteres: %d", c);
    printf("\n\nApós a compactação foi possível obter um redução de: %d%%\n", (100 - ((c*100)/i)));
    return 0;
}