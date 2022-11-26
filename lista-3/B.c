void move(char *palavra){
    if(*palavra == '\0') return 0;
    if(palavra[0] == 'x'){
        move(palavra+1);
        printf("%c", palavra[0]);
    } else{
        printf("%c", palavra[0]);
        move(palavra+1);
    }
}

int main(){
    char main_palavra[101];
    scanf("%s", &main_palavra);
    move(main_palavra);
    printf("\n");
    return 0;
}