#include <stdio.h>

int N = 0;

void insert_sort(int v[10000000000]){
    int aux = 0;
    int j = 0;
    for(int i = 0; i < N; i++){
        aux = v[i];
        j = i;
        while(j > 0 && aux < v[j-1]){
            v[j] = v[j-1];
            j--; 
        }
        v[j] = aux;
    }
}  

int binary_search(int v[10000000000], int low, int high, int key){
    while(low <= high){
        int mid = (high + low)/2;
        if(v[mid] < key){
            low = mid+1;
        }
        else if(v[mid] > key){
            high = mid-1;
        } else{
            return v[mid];
        }
    }
    return -1;
}

int main(){
    int M = 0;
    scanf("%d %d", &N, &M);
    int v_lista[N], v_lista_aux[N], v_procurados[M];
    for(int i = 0; i < N; i++){
       scanf("%d", &v_lista[i]);
    }
    for(int i = 0; i < N; i++){
       v_lista_aux[i] = v_lista[i];
    }
    for(int i = 0; i < M; i++){
       scanf("%d", &v_procurados[i]);
    }
    insert_sort(v_lista);
    printf("\n");
    for(int i = 0; i < M; i++){
        int resultado = binary_search(v_lista, 0, N-1, v_procurados[i]);
        if(resultado == -1){
            printf("%d \n", -1);
        } else{
            for(int j = 0; j < N; j++){
                if(v_lista_aux[j] == resultado){
                    printf("%d \n", j);
                }
            }
        }
        
    }
    return 0;
}