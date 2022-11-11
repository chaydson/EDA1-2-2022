#include <stdio.h>

int main(){
    char operacoes[1];
    int quantLinhas = 0, linha = 0, coluna = 0, tamanhoLinha = 0;
    
    scanf("%d", &quantLinhas);
    char matriz[quantLinhas][10000];

    for(int i = 0; i < quantLinhas; i++){
        scanf(" %[^\n]s", matriz[i]);
    }


    scanf("%d %d", &linha, &coluna);
    linha--;
    coluna--;

    while (scanf(" %s", &operacoes) != EOF){
        if(operacoes[0] == 'j' && linha + 1 < quantLinhas){
            linha++;
        } else if (operacoes[0] == 'k' && linha > 0){
            linha--;
        }

        tamanhoLinha = (int)strlen(matriz[linha]) - 1;

        if(coluna >= tamanhoLinha){
            printf("%d %d %c \n", linha+1, tamanhoLinha+1, matriz[linha][tamanhoLinha]);
        } else {
                printf("%d %d %c \n", linha+1, coluna+1, matriz[linha][coluna]);
            }
    }  
    return 0;
}