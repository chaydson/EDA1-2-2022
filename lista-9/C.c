#include <stdio.h>

int iterator = 0;

void insert_sort(int v[50000]){
    int aux = 0;
    int j = 0;
    for(int i = 0; i < iterator; i++){
        aux = v[i];
        j = i;
        while(j > 0 && aux < v[j-1]){
            v[j] = v[j-1];
            j--; 
        }
        v[j] = aux;
    }
}  

int main(){
    int v_main[50000];
    while(scanf("%d", &v_main[iterator]) != EOF){
        ++iterator;
    }
    insert_sort(v_main);
    for(int i = 0; i < iterator; i++){
        printf("%d ", v_main[i]);
    }
    printf("\n");
    return 0;
}