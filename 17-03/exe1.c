#include<stdio.h>

int main(void){
    int v[10], i;

    for(i = 0; i < 10; i++){
        printf("Valor da posicao %i: ", i+1);
        scanf("%i", &v[i]);
    }

    printf("Vetor: ");
    for(i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }

    return 0;
}
