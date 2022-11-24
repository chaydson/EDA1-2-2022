#include <stdio.h>
#include <string.h>
void armazenaValor(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    return;
}
int main()
{
    int altura, i, j, k, largura = 12;
    scanf("%d", &altura);
    altura += 2;
    char tela[altura][largura];
    int galhos[altura][largura];
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            tela[i][j] = ' ';
            if (i == (altura - 1) || i == 0)
            {
                tela[i][j] = '~';
            }
            if ((i <= (altura - 2) && i != 0) && (j >= 4 && j <= 6))
            {
                tela[i][j] = '|';
            }
            if (j == (largura - 1))
            {
                tela[i][j] = '\n';
            }
        }
    }
    int quantidadeDeGalhos, alturaDoGalho;
    char posicaoGalho;
    scanf("%d", &quantidadeDeGalhos);
    armazenaValor();
    for (int k = 0; k < quantidadeDeGalhos; k++)
    {
        scanf("%c %d", &posicaoGalho, &alturaDoGalho);
        armazenaValor();
        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                if (posicaoGalho == 'D')
                {
                    if (j >= 7 && j <= 9)
                    {
                        if (i == (altura - (alturaDoGalho + 1)))
                        {
                            tela[i][j] = '-';
                        }
                    }
                }
                if (posicaoGalho == 'E')
                {
                    if (j >= 1 && j <= 3)
                    {
                        if (i == (altura - (alturaDoGalho + 1)))
                        {
                            tela[i][j] = '-';
                        }
                    }
                }
            }
        }
    }
    char posicaoJogador;
    scanf("%c", &posicaoJogador);
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (posicaoJogador == 'E')
            {
                if (i == (altura - 2) || i == (altura - 3))
                {
                    if (j == 2)
                    {
                        tela[i][j] = 'L';
                    }
                }
            }
            if (posicaoJogador == 'D')
            {
                if (i == (altura - 2) || i == (altura - 3))
                {
                    if (j == 8)
                    {
                        tela[i][j] = 'L';
                    }
                }
            }
        }
    }
    int trocou = 0, contador = 1, l, p, morreu = 0, temGalho = 0;
    char acoes[2000];
    armazenaValor();
    fgets(acoes, 2000, stdin);

    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < largura; j++)
        {
            if (i == (altura - 7) && j <= 10)
            {
                printf("~");
                if (j == 10)
                {
                    printf("\n");
                }
            }
            if (i > (altura - 7))
            {
                printf("%c", tela[i][j]);
            }
        }
    }
    for (k = 0; k < (strlen(acoes) - 1); k++)
    {
        trocou = 0;
        morreu = 0;
        temGalho = 0;
        for (l = 0; l < altura; l++)
        {
            for (p = 0; p < largura; p++)
            {
                galhos[l][p] = 0;
            }
        }
        for (i = 0; i < altura; i++)
        {
            for (j = 0; j < largura; j++)
            {
                if (acoes[k] == 'T')
                {
                    if (i == (altura - 2))
                    {
                        if (j == 2)
                        {
                            if (tela[i][j] == 'L')
                            {
                                if (tela[i][j + 6] == '-' || tela[i - 1][j + 6] == '-')
                                {
                                    temGalho = 1;
                                }
                                else
                                {
                                    tela[i][j] = ' ';
                                    tela[i - 1][j] = ' ';
                                    tela[i][j + 6] = 'L';
                                    tela[i - 1][j + 6] = 'L';
                                    trocou = 1;
                                }
                            }
                        }
                        if (j == 8 && trocou == 0)
                        {
                            if (tela[i][j] == 'L')
                            {
                                if (tela[i][j - 6] == '-' || tela[i - 1][j - 6] == '-')
                                {
                                    temGalho = 1;
                                }
                                else
                                {
                                    tela[i][j] = ' ';
                                    tela[i - 1][j] = ' ';
                                    tela[i][j - 6] = 'L';
                                    tela[i - 1][j - 6] = 'L';
                                }
                            }
                        }
                    }
                }
                if (acoes[k] == 'B')
                {
                    if (i == (altura - 2))
                    {
                        if (j == 2)
                        {
                            if (tela[i][j] == 'L')
                            {
                                if (tela[i][j + 2] == '>')
                                {
                                    tela[i - ((altura - 2) - contador)][j + 2] = ' ';
                                    tela[i - ((altura - 2) - contador)][j + 3] = ' ';
                                    tela[i - ((altura - 2) - contador)][j + 4] = ' ';
                                    tela[i][j + 2] = '|';
                                    tela[i][j + 3] = '|';
                                    tela[i][j + 4] = '|';
                                    contador++;
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (tela[l][p] == '-')
                                            {
                                                tela[l][p] = ' ';
                                                galhos[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (galhos[l][p] == 1)
                                            {
                                                if (tela[l][p] == 'L')
                                                {
                                                    morreu = 1;
                                                }
                                                else
                                                {
                                                    tela[l][p] = '-';
                                                }
                                            }
                                            if (l == (altura - 1))
                                            {
                                                tela[l][p] = '~';
                                                if(p == largura-1){
                                                    tela[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (tela[i - 1][j + 2] == '|')
                                {
                                    tela[i][j + 2] = '>';
                                    break;
                                }
                            }
                        }
                        if (j == 8)
                        {
                            if (tela[i][j] == 'L')
                            {
                                if (tela[i][j - 2] == '<')
                                {
                                    tela[i - ((altura - 2) - contador)][j - 2] = ' ';
                                    tela[i - ((altura - 2) - contador)][j - 3] = ' ';
                                    tela[i - ((altura - 2) - contador)][j - 4] = ' ';
                                    tela[i][j - 2] = '|';
                                    tela[i][j - 3] = '|';
                                    tela[i][j - 4] = '|';
                                    contador++;
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (tela[l][p] == '-')
                                            {
                                                tela[l][p] = ' ';
                                                galhos[l + 1][p] = 1;
                                            }
                                        }
                                    }
                                    for (l = 0; l < altura; l++)
                                    {
                                        for (p = 0; p < largura; p++)
                                        {
                                            if (galhos[l][p] == 1)
                                            {
                                                if (tela[l][p] == 'L')
                                                {
                                                    morreu = 1;
                                                }
                                                else
                                                {
                                                    tela[l][p] = '-';
                                                }
                                            }
                                            if (l == (altura - 1))
                                            {
                                                tela[l][p] = '~';
                                                if(p == largura-1){
                                                    tela[l][p] = '\n';
                                                }
                                            }
                                        }
                                    }
                                    break;
                                }
                                if (tela[i - 1][j - 2] == '|')
                                {
                                    tela[i][j - 2] = '<';
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (morreu != 1 && temGalho != 1)
        {
            for (i = 0; i < altura; i++)
            {
                for (j = 0; j < largura; j++)
                {
                    if (i == (altura - 7) && j <= 10)
                    {
                        printf("~");
                        if (j == 10)
                        {
                            printf("\n");
                        }
                    }
                    if (i > (altura - 7))
                    {
                        printf("%c", tela[i][j]);
                    }
                }
            }
        }
        else if (temGalho == 1)
        {
            printf("**beep**\n");
            continue;
        }
        else
        {
            printf("**morreu**\n");
            break;
        }
    }
    return 0;
}