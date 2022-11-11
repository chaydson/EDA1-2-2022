#include <stdio.h>
#include <string.h>

void screenBuilder(void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF){
    }
    return;
}

int main(){
    int height, i, j, k, width = 12;
    scanf("%d", &height);
    height += 2;
    char screen[height][width];
    int galhos[height][width];
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            screen[i][j] = ' ';
            if (i == (height - 1) || i == 0){
                screen[i][j] = '~';
            }
            if ((i <= (height - 2) && i != 0) && (j >= 4 && j <= 6)){
                screen[i][j] = '|';
            }
            if (j == (width - 1)){
                screen[i][j] = '\n';
            }
        }
    }
    int sticks, heightSticks;
    char side;
    scanf("%d", &sticks);
    screenBuilder();
    for (int k = 0; k < sticks; k++){
        scanf("%c %d", &side, &heightSticks);
        screenBuilder();
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                if (side == 'D'){
                    if (j >= 7 && j <= 9){
                        if (i == (height - (heightSticks + 1))){
                            screen[i][j] = '-';
                        }
                    }
                }
                if (side == 'E'){
                    if (j >= 1 && j <= 3){
                        if (i == (height - (heightSticks + 1))){
                            screen[i][j] = '-';
                        }
                    }
                }
            }
        }
    }
    char player;
    scanf("%c", &player);
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            if (player == 'E'){
                if (i == (height - 2) || i == (height - 3)){
                    if (j == 2){
                        screen[i][j] = 'L';
                    }
                }
            }
            if (player == 'D'){
                if (i == (height - 2) || i == (height - 3)){
                    if (j == 8){
                        screen[i][j] = 'L';
                    }
                }
            }
        }
    }
    int change = 0, iterator = 1, l, p, dead = 0, haveSticks = 0;
    char actions[2000];
    screenBuilder();
    fgets(actions, 2000, stdin);
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            if (i == (height - 7) && j <= 10){
                printf("~");
                if (j == 10){
                    printf("\n");
                }
            }
            if (i > (height - 7)){
                printf("%c", screen[i][j]);
            }
        }
    }
    for (k = 0; k < (strlen(actions) - 1); k++){
        change = 0;
        dead = 0;
        haveSticks = 0;
        for (l = 0; l < height; l++){
            for (p = 0; p < width; p++){
                galhos[l][p] = 0;
            }
        }
        for (i = 0; i < height; i++){
            for (j = 0; j < width; j++){
                if (actions[k] == 'T'){
                    if (i == (height - 2)){
                        if (j == 2){
                            if (screen[i][j] == 'L'){
                                if (screen[i][j + 6] == '-' || screen[i - 1][j + 6] == '-'){
                                    haveSticks = 1;
                                } else{
                                    screen[i][j] = ' ';
                                    screen[i - 1][j] = ' ';
                                    screen[i][j + 6] = 'L';
                                    screen[i - 1][j + 6] = 'L';
                                    change = 1;
                                }
                            }
                        }
                        if (j == 8 && change == 0){
                            if (screen[i][j] == 'L'){
                                if (screen[i][j - 6] == '-' || screen[i - 1][j - 6] == '-'){
                                    haveSticks = 1;
                                } else{
                                    screen[i][j] = ' ';
                                    screen[i - 1][j] = ' ';
                                    screen[i][j - 6] = 'L';
                                    screen[i - 1][j - 6] = 'L';
                                }
                            }
                        }
                    }
                }
                if (actions[k] == 'B'){
                    if (i == (height - 2)){
                        if (j == 2){
                            if (screen[i][j] == 'L'){
                                if (screen[i][j + 2] == '>'){
                                    screen[i - ((height - 2) - iterator)][j + 2] = ' ';
                                    screen[i - ((height - 2) - iterator)][j + 3] = ' ';
                                    screen[i - ((height - 2) - iterator)][j + 4] = ' ';
                                    screen[i][j + 2] = '|';
                                    screen[i][j + 3] = '|';
                                    screen[i][j + 4] = '|';
                                    iterator++;
                                    for (l = 0; l < height; l++){
                                        for (p = 0; p < width; p++){
                                            if (screen[l][p] == '-'){
                                                screen[l][p] = ' ';
                                                galhos[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (l = 0; l < height; l++){
                                        for (p = 0; p < width; p++){
                                            if (galhos[l][p] == 1){
                                                if (screen[l][p] == 'L'){
                                                    dead = 1;
                                                } else {
                                                    screen[l][p] = '-';
                                                }
                                            }
                                            if (l == (height - 1)){
                                                screen[l][p] = '~';
                                                if(p == width-1){
                                                    screen[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (screen[i - 1][j + 2] == '|'){
                                    screen[i][j + 2] = '>';
                                    break;
                                }
                            }
                        }
                        if (j == 8){
                            if (screen[i][j] == 'L'){
                                if (screen[i][j - 2] == '<'){
                                    screen[i - ((height - 2) - iterator)][j - 2] = ' ';
                                    screen[i - ((height - 2) - iterator)][j - 3] = ' ';
                                    screen[i - ((height - 2) - iterator)][j - 4] = ' ';
                                    screen[i][j - 2] = '|';
                                    screen[i][j - 3] = '|';
                                    screen[i][j - 4] = '|';
                                    iterator++;
                                    for (l = 0; l < height; l++){
                                        for (p = 0; p < width; p++){
                                            if (screen[l][p] == '-'){
                                                screen[l][p] = ' ';
                                                galhos[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (l = 0; l < height; l++){
                                        for (p = 0; p < width; p++){
                                            if (galhos[l][p] == 1){
                                                if (screen[l][p] == 'L'){
                                                    dead = 1;
                                                } else {
                                                    screen[l][p] = '-';
                                                }
                                            } if (l == (height - 1)){
                                                screen[l][p] = '~';
                                                if(p == width-1){
                                                    screen[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (screen[i - 1][j - 2] == '|'){
                                    screen[i][j - 2] = '<';
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (dead != 1 && haveSticks != 1){
            for (i = 0; i < height; i++){
                for (j = 0; j < width; j++){
                    if (i == (height - 7) && j <= 10){
                        printf("~");
                        if (j == 10){
                            printf("\n");
                        }
                    }
                    if (i > (height - 7)){
                        printf("%c", screen[i][j]);
                    }
                }
            }
        }
        else if (haveSticks == 1){
            printf("**beep**\n");
            continue;
        } else{
            printf("**dead**\n");
            break;
        }
    }
    return 0;
}