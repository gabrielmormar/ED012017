#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int n;//numero de elementos
	int vet[MAX];//vetor de 10 elementos
} Pilha;

Pilha p;

/*Pilha* cria(void) {
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->n = 0;
	return p;
}*/

void push(Pilha *p, int x) {
	if(p->n == 10) {
		printf("PIlha estorou!");
		exit(1);
	} else {
		p->vet[p->n] = x;
		p->n++;
	}
}

int pop(Pilha *p) {
	int x;
	if(vazia(p)) {
		printf("pilha vazia.");
		exit(1);
	} else {
		x = p->vet[p->n-1];
		p->n--;
		return x;
	}
}

int vazia(Pilha *p) {
	return (p->n == 0);
}

void libera (Pilha *p) {
	free(p);
}



int main(void) {	
	//cria();
	push(&p,10);
	push(&p,5);
	push(&p,7);
	push(&p,23);
	push(&p,3);
	push(&p,43);
	printf("%d\n",pop(&p));
	printf("%d\n",pop(&p));
	printf("%d\n",pop(&p));



	return 0;
}