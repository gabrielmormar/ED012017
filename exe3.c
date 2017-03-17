#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n,i;
    float media,total = 0;

    printf("Numero de elementos: ");
    scanf("%d", &n);
    int *vetor = (int*)malloc(n*sizeof(int));

    for(i = 0; i < n; i++){
        printf("Valor da posiçao vetor[i]: ");
        scanf("%d", &vetor[i]);
        total += vetor[i];
    }
    media = total/(float)n;
    printf("Media = %.2f", media);

    free(vetor);

    return 0;
}
