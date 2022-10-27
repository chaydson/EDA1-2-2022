#include <stdio.h>

int main(){
    int n, zezinho = 0, joaozinho = 0, cont = 1, minhaLista[100], totalJ = 0, totalZ = 0;
    scanf("%d", &n);
    while (n>0)
    {
        for(int i = 0; i < n; i++){
            scanf("%d%d", &joaozinho, &zezinho);
            totalJ += joaozinho;
            totalZ += zezinho;
            minhaLista[i] = totalJ-totalZ;
        }
        printf("\n");
        printf("Teste %d \n", cont);
        cont++;
        for(int i = 0; i < n; i++){
            printf("%d \n", minhaLista[i]);
        }
        printf("\n");
        zezinho = 0;
        joaozinho = 0;
        totalJ = 0;
        totalZ = 0;
        
        scanf("%d", &n);
    }
    return 0;
}