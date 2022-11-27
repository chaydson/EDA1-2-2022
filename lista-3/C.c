int soma(int n){
    if(n <= 0) return 0;
    return n%10 + soma(n/10);;
}

int resultado(int n){
    int soma_resultado = soma(n);
    int aux = soma_resultado;
    int grau = 0;
    while(aux > 0){
        aux = soma_resultado/10;
        grau++;
    }

    if(soma_resultado%9 == 0){
        printf("%d is a multiple of and has a 9-degree %d.\n", n, grau);
    } else{
        printf("%d is not a multiple of 9.\n", n);
    } 
}

int main(){

}