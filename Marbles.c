#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>


int bb(int *vet, int chave, int Tam){
 int inf = 0;     //Limite inferior  (o primeiro elemento do vetor em C é zero          )
 int sup = Tam - 1; //Limite superior  (termina em um número a menos 0 a 9 são 10 numeros )
 int meio;
 while (inf <= sup)
 {
  meio = (inf + sup) / 2;
  if (chave == vet[meio])
   return meio;
  if (chave < vet[meio])
   sup = meio - 1;
  else
   inf = meio + 1;
 }
 return -1;   // não encontr


}
void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
 int i, j, k, metadeTamanho, *vetorTemp;

 if (posicaoInicio == posicaoFim) return;

 // ordenacao recursiva das duas metades
 metadeTamanho = (posicaoInicio + posicaoFim) / 2;
 mergeSort(vetor, posicaoInicio, metadeTamanho);
 mergeSort(vetor, metadeTamanho + 1, posicaoFim);

 // intercalacao no vetor temporario t
 i = posicaoInicio;
 j = metadeTamanho + 1;
 k = 0;
 vetorTemp = (int)malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

 while (i < metadeTamanho + 1 || j  < posicaoFim + 1) {
  if (i == metadeTamanho + 1) { // i passou do final da primeira metade, pegar v[j]
   vetorTemp[k] = vetor[j];
   j++;
   k++;
  }
  else {
   if (j == posicaoFim + 1) { // j passou do final da segunda metade, pegar v[i]
    vetorTemp[k] = vetor[i];
    i++;
    k++;
   }
   else {
    if (vetor[i] < vetor[j]) {
     vetorTemp[k] = vetor[i];
     i++;
     k++;
    }
    else {
     vetorTemp[k] = vetor[j];
     j++;
     k++;
    }
   }
  }

 }
 // copia vetor intercalado para o vetor original
 for (i = posicaoInicio; i <= posicaoFim; i++) {
  vetor[i] = vetorTemp[i - posicaoInicio];
 }
 free(vetorTemp);
}


int main(int argc, char* argv[]){
 int q, n, i,j,k=1,aux=0,l=1, *res, *c, *vet; 
 while (1){
  scanf_s("%d", &n);
  scanf_s("%d", &q);
  if (n == 0 && q == 0 )
   break;
  *res = calloc(q, sizeof(int));//respostas depois de ordenado
  *c = calloc(q, sizeof(int));// chaves de busca
  *vet = calloc(n, sizeof(int));//marmores
  for (i = 0; i < n; i++){
   scanf_s("%d", &vet[i]);
  }
  for (i = 0; i <q; i++){
   
   scanf_s("%d", &c[i]);
  }
  mergeSort(vet, 0, n-1);//ordena
  
  
  for (j = 0; j < q; j++){   
   res[j]=bb(vet, c[j],n);
   aux = res[j];
   if (vet[aux - 1] == vet[aux])
    res[j]--;
   }
  }
  for (j = 0; j < q; j++){
   if (j == 0)
    printf("CASE# %d\n", k);
   
   if (res[j] == -1){
    printf("%d not found\n", c[j]);
   }
   else 
   
   printf("%d found at %d\n", c[j], res[j]+1 );
   
  }


  free(vet);
  free(c);
  free(res);
  k++;
  
  
  system("pause");
  return 0;
}
