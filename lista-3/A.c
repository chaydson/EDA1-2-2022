#include <stdio.h>

int f91(int n){
    if(n >= 101) return n-10;
    if(n <= 100) {
        f91(f91(n+11));
    }
}

int main(){
    int n_main = 1;
    while (scanf("%d", &n_main)){
        if(n_main == 0) return 0;
        printf("f91(%d) = %d\n", n_main ,f91(n_main));
    }
    return 0;
}