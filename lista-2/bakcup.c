int main(){
    int soma = 0, numero = 0, parcelas = 0;
    char op;
    scanf("%d %s", &parcelas, &op);
    if(op == '+'){
        for(int i = 0; i < parcelas; i++){
            scanf("%d", &numero);
            soma+= numero;
        }
    } else{
        for(int i = 0; i < parcelas; i++){
            scanf("%d", &numero);
            if(i == 0){
                soma = numero;
            } else{
                soma-= numero;
            }
        }
    }
    printf("%d\n", soma);
    return 0;
}