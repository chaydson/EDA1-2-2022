#include <stdio.h>

int iterator = 0;

void selection_sort(int v[1000]){
    int min = 0;
    int aux = 0;
    for(int i = 0; i < iterator-1; i++){
        min = i;
        for(int j = i+1; j < iterator; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}  

int main(){
    int v_main[1000];
    while(scanf("%d", &v_main[iterator]) != EOF){
        ++iterator;
    }
    selection_sort(v_main);
    for(int i = 0; i < iterator; i++){
        printf("%d ", v_main[i]);
    }
    printf("\n");
    return 0;
}