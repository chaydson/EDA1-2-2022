#include <stdio.h>

int main(){
    int c1 = 0, c2 = 0, c3 = 0, doutorado = 0, resposta = 0;
    scanf("%d %d %d", &c1, &c2, &c3);
    scanf("%d", &doutorado);
    resposta = c1 + c2 + c3;
    if(resposta == doutorado){
        printf("Acertou \n");
    } else{
        printf("Errou \n");
    }
    return 0;
}