#include <stdio.h>
#include <string.h>

int main(){
    char resposta[4];
    int triagem = 0, ret = 0, cont = 0, i = 0;

    while (scanf("%s", &resposta) != EOF)
    {
        i++;
        ret = strcmp(resposta, "nao");
        if(ret > 0){
            cont++;
        }

        if(cont >= 2 && i % 10 == 0){
            triagem++;
            cont = 0;
        }

        if(i % 10 == 0){
            cont = 0;
        }
    }
    printf("%d", triagem);
    return 0;
}