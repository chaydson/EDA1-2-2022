#include <stdio.h>

int main(){
    int quantRest = 0, 
    codigo = 0, 
    nota = 0, 
    maiorNota = 0, 
    melhorRestaurante = 0, 
    dia = 0,
    menorCodigo = 100000000;
    while (scanf("%d", &quantRest) != EOF) {
        for(int i = 0; i < quantRest; i++){
            if(scanf("%d %d", &codigo, &nota) != EOF){
                if(nota > maiorNota){
                    maiorNota = nota;
                    melhorRestaurante = codigo;
                    menorCodigo = codigo;
                } else {
                    if(nota == maiorNota && codigo < menorCodigo){
                        maiorNota = nota;
                        melhorRestaurante = codigo;
                        menorCodigo = codigo;
                    }
                }
            } else {
                break;
            }
        }
        printf("Dia %d\n%d\n\n", dia+1, melhorRestaurante);
        dia++;
        maiorNota = 0;
        menorCodigo = 100000000;
    }

    return 0;
}