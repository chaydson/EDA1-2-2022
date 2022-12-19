#include <stdio.h>

int iterator = 0;

void bublle_sort(int v[1000]){
    int aux = 0;
    for(int i = 0; i < iterator; i++){
        for(int i = 0; i < iterator-1; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
            }
        }
    }
}  

int main(){
    int v_main[1000];
    while(scanf("%d", &v_main[iterator]) != EOF){
        ++iterator;
    }
    bublle_sort(v_main);
    for(int i = 0; i < iterator; i++){
        printf("%d ", v_main[i]);
    }
    printf("\n");
    return 0;
}