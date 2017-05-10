#include <stdio.h>
#include <stdlib.h>

struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

Lista* inicializa(void) {
	return NULL;
}

Lista* insere(Lista *l, int i) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

Lista* cria(int v) {
	Lista *p = (Lista*)malloc(sizeof(Lista));
	p->info = v;
	return p;
}

Lista* insere_ordenado(Lista *l, int v) {
	Lista *novo = cria(v);
	Lista *ant = NULL;
	Lista *p = l;

	while(p != NULL && p->info < v) {
		ant = p;
		p = p->prox;
	}

	if(ant == NULL) {
		novo->prox = l;
		l = novo;
	} else {
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	return l;
}

void imprime(Lista *l) {
	Lista *p;
	for(p = l; p != NULL; p = p->prox)
		printf("%d ", p->info);
	printf("\n");
}

int vazia(Lista *l) {
	return(l == NULL);
}

Lista *retira(Lista *l, int v) {
	Lista *ant = NULL;
	Lista *p = l;

	while(p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}

	if(p == NULL)
		return l;

	if(ant == NULL)
		l = p->prox;
	else
		ant->prox = p->prox;

	free(p);
	return l;
}


int main(void) {
	Lista *l;
	int c = 0, i;
	l = inicializa();
	while(c < 5) {
		printf("Numero para lista(inicio): ");
		scanf("%d", &i);
		l = insere_ordenado(l,i);
		c++;
	}
	l = retira(l,10);
	imprime(l);

	return 0;
}