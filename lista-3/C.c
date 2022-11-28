#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prof = 1;
int soma(char numero[1001]){
    char aux[1001];
    int s = 0;
    for(int i = 0; i < strlen(numero); i++){
        s += (int)numero[i] - 48;
    }

    if(s == 9) {
        return 1;
    }

    if(s%9 != 0) {
        return 0;
    }

    if(s > 9) {
        prof++;
        sprintf(aux, "%d", s);
        soma(aux);
    }
}

int main(){
    char numero_main[1001];
    int resultado = 0;
    scanf("%s", &numero_main);
    while(numero_main[0] != '0'){
        resultado = soma(numero_main);
        if(resultado == 0) printf("%s is not a multiple of 9.\n", numero_main);
        else printf("%s is a multiple of 9 and has 9-degree %d.\n", numero_main, prof);
        prof = 1;
        scanf("%s", &numero_main);
    }
    return 0;
}