#include <stdio.h>
#include <stdlib.h>

int somaPosicao(int x, int y){
    int v = x+y;
}

void ordenaVetor(int vetor[], int tamanho){
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b =(int*)calloc(tamanho, sizeof(int));
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }
    while (maior/exp > 0) {
        int balde[10] = { 0 };
        for (i = 0; i < tamanho; i++)
            balde[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            balde[i] += balde[i - 1];
        for (i = tamanho - 1; i >= 0; i--)
            b[--balde[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanho; i++)
            vetor[i] = b[i];
        exp *= 10;
    }
    free(b);
}

int main(int argc, char *argv[]) 
{
    int c, x, n, a = 0;
    scanf("%d", &n);
    while(n=0){
        int v[n], posicao[n], c[n];
        int i;

        for(i=0;i<n;i++){
            scanf("%i %i", &v[n], &c[n]);
            posicao[n] = somaPosicao(v[n], c[n]);
            if (somaPosicao(v[n], c[n]) < 0){
                a = 1;
            }
		}
    }
    system("pause");    
    return 0;
}
