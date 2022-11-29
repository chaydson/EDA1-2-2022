#include <stdio.h>

int empates(int T, int N, int vetor[])
{

    int max = 3 * N;
    int sum = 0;
    for (int i = 0; i < T; i++)
    {
        sum += vetor[i];
    }
    return max - sum;
}

int main(void)
{
    int T, N, pontosTime[1000];
    char time[11];
    scanf("%d %d", &T, &N);
    while (T != 0)
    {
        for (int i = 0; i < T; i++)
        {
            scanf("%s %d", time, &pontosTime[i]);
        }
        printf("%d\n", empates(T, N, pontosTime));

        T, N, pontosTime[1000];
        time[11];
        scanf("%d %d", &T, &N);
    }

    return 0;
}