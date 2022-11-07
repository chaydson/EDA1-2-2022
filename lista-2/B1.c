#include <stdio.h>

int main(){
    printf("%d", faz_conta_direito(4, '-'));
}

int faz_conta_direito(int parcelas, char op){
    int soma = 0, numero = 0;
    scanf("%d %s", &parcelas, &op);
    if(op == '+'){
        for(int i = 0; i < parcelas; i++){
            scanf("%d", &numero);
            soma+= numero;
        }
    } else{
        for(int i = 0; i < parcelas; i++){
            scanf("%d", &numero);
            if(i == 0){
                soma = numero;
            } else{
                soma-= numero;
            }
        }
    }
    return soma;
}