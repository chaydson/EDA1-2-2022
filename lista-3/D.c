long soma(long n){
    if(n <= 0) return 0;
    return n%10 + soma(n/10);
}

int main(){
    long n_main = 0;
    scanf("%ld", &n_main);
    printf("%ld\n", soma(n_main));
    return 0;
}