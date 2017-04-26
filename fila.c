#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	int ini, fim;
	int vet[MAX];
} Fila;

Fila f;

int incre(int i) {
	return (i+1)%MAX;
}

int vazia(Fila *f) {
	return (f->ini == f->fim);
}

void insere(Fila *f, int x) {
	if(f->fim + 1 >= MAX) {
		printf("A fila estorou\n");
		exit(1);
	} else 
		f->vet[f->fim++] = x;	
}

int retira(Fila *f) {
	int v;
	if(vazia(f)) {
		printf("A fila esta vazia!\n");
		exit(1);
	} else {
		v = f->vet[f->ini];
		f->ini = incre(f->ini);
	}
	return v;
}

int main(void) {
	f.ini = 0;
	f.fim = 0;

	insere(&f,4);
	insere(&f,2);
	insere(&f,3);
	printf("%d\n",retira(&f));



	return 0;
}