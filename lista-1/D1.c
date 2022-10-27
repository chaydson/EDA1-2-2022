#include <stdio.h>

int main(){
    _Bool stringsIguais(char s1[], char s2[]);
    int aux = 0;
    char name[1000];
    while(scanf("%s", &name) != EOF){
        if(stringsIguais(name, "marte")){
            aux++;
        }
    }
    if(aux>0){
        printf("Leonardo Cicero Marciano \n");
    } else {
        printf("none \n");
    }
}

_Bool stringsIguais(char s1[], char s2[]){
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
    {
        return 1;
    } else {
        return 0;
    }
}