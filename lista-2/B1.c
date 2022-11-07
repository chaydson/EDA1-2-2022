int faz_conta_direito(int parcelas, char op){
    int soma = 0, numero = 0;
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
    return soma;
}