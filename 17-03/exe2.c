#include<stdio.h>

int main(void){
    int m[3][4];
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            printf("Valor da posicao[%i][%i]: ",i+1,j+1);
            scanf("%i", &m[i][j]);
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 4; j++){
            printf("%i ",m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
