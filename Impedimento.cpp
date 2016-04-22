#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
	int a, d, atacante_prox, dist_defesa, contador, temp;

    while (scanf("%d %d", &a, &d) && a && d){
        scanf("%d", atacante_prox);
		
		int i;
        for (i = 1; i < a; i++){
            scanf("%d", temp);
            if (temp < atacante_prox) atacante_prox = temp;
        }
        contador = 0;

		int j;
        for (j = 0; j < d; j++){
            scanf("%d", dist_defesa);
            if (dist_defesa <= atacante_prox) contador++;
        }

        if (contador >= 2) printf("N\n");
        else printf("Y\n");
    }
	
	system("pause");
    return 0;
}
