#include <stdio.h>

int main(){
    int leitor;
    while(scanf("%x",&leitor) != EOF){
        char *string = &leitor;
        for(int i = 0; i<4; i++){
            if(string[i] == 0){
                return 0;
            }
            printf("%c", string[i]);
        }
    }
}