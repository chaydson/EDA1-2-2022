#include <stdio.h>

int main(){
    int n = 0, soma = 0, valorConta = 0, valorChutado = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &valorConta);
        soma += valorConta;
    }
    scanf("%d", &valorChutado);
    if(soma == valorChutado){
        printf("Acertou \n");
    } else{
        printf("Errou \n");
    }
    return 0;
}