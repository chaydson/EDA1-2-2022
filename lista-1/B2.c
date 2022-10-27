#include <stdio.h>

int main(){
    int N, soma, aux;
    soma = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &aux);
        soma+=aux;
    }
    printf("%d \n", soma);
    return 0;
}