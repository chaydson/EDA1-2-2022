#include <stdio.h>

int quant = 0;

struct Instrucao{
    int codigo;
    char palavra[20];
};

void insert_sort(struct Instrucao v[quant]){
    struct Instrucao aux;
    int j = 0;
    for(int i = 0; i < quant; i++){
        aux = v[i];
        j = i;
        while(j > 0 && aux.codigo < v[j-1].codigo){
            v[j] = v[j-1];
            j--;
        }
        v[j] = aux;
    }
}

int binary_search(struct Instrucao v[quant], int low, int high, int key){
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid].codigo < key){
            low = mid + 1;
        } else if(v[mid].codigo > key){
            high = mid - 1;
        } else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int entrada_usuario = 0;
    scanf("%d", &quant);
    struct Instrucao instrucoes[quant];
    for(int i = 0; i < quant; i++){
        scanf("%d %s", &instrucoes[i].codigo, &instrucoes[i].palavra);
    }
    insert_sort(instrucoes);
    while(scanf("%d", &entrada_usuario) != EOF){
        int resultado = binary_search(instrucoes, 0, quant, entrada_usuario);
        if(resultado == -1){
            printf("undefined\n");
        } else{
            printf("%s\n", instrucoes[resultado].palavra);
        }
    }
    return 0;
}