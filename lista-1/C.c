#include <stdio.h>

int main(){
    int n, alice = 0, beto = 0, aux;
    scanf("%d", &n);
    while (n>0)
    {
        for(int i = 0; i < n; i++){
            scanf("%d", &aux);
            if(aux == 0){
                alice++;
            }
            if(aux == 1){
                beto++;
            }
        }
        printf("Alice ganhou %d e Beto ganhou %d \n", alice, beto);
        beto = 0;
        alice = 0;
        scanf("%d", &n);
    }
    return 0;
}