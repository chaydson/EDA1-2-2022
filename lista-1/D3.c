#include <stdio.h>

int main(){
    long long int quantRest = 0, 
    codigo = 0, 
    nota = 0, 
    dias = 0, 
    maiorNota = 0,
    menorCodigo = 100000000000,
    melhores[300]; 
    while (scanf("%lld", &quantRest) != EOF){
        for(int i = 0; i < quantRest; i++){
            if(scanf("%lld %lld", &codigo, &nota) != EOF){
                if(nota >= maiorNota){
                    if(codigo < menorCodigo){
                        menorCodigo = codigo;
                        maiorNota = nota;
                        melhores[dias] = codigo;   
                    } else {
                        maiorNota = nota;
                        melhores[dias] = codigo;  
                    }
                }
            } else{
                break;
            }
        }
        maiorNota = 0;
        dias++;
    }

    for(int i = 0; i < dias; i++){
        printf("Dia %lld \n%lld \n\n", i+1, melhores[i]);
    }

    return 0;
}