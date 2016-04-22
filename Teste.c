#include <stdio.h>
#include <stdlib.h>

void ShellSort (int*vet, int size, int *c){
  int i , j , value;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
                *c=(*c)+1;
            }
            vet [j + gap] = value;
        }
    }
}


void Preenche(int* v, int n){
 int i;
 for(i=0; i<n; i++){
  scanf("%d", &v[i]);
  }
 }

int main(int argc, char *argv[])
{
int n,cont;
int* vet;

scanf("%d", &n);
while (n!=0){
 cont=0;
 vet= malloc(sizeof(int)*n);
 Preenche (vet,n);
 ShellSort(vet, n, &cont);
 if(cont%2==0){
  printf("Carlos\n");
 }else
 printf("Marcelo\n");


free(vet);
scanf("%d", &n);
}

 system("pause");
 return 0;
}
