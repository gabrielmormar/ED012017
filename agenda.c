/* 	ESTRUTURAS DE DADOS - 2017/01
	Univesidade de Brasília - UNB
	Aluno: Gabriel Morais Marreiros
	Matricula: 16/0121256
	Github: @Gabrielmormar
	Descrição: Agenda Eletrônica usando lista encadeada em C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//estrutura da agenda
struct agenda{
	char nome[50];
	char email[100];
	char telefone[12];
	struct agenda *prox;
};
typedef struct agenda Agenda;
//Inicia a lista
Agenda* inicializa(void) {
	return NULL;
}
//Insere alfabeticamente na lista
Agenda* InsereAgenda(Agenda *a) {
	Agenda *novo = (Agenda*)malloc(sizeof(Agenda));

	printf("\n1- Inserindo novo contato\n\n");
	printf("Digite o nome: ");
	scanf("%[^\n]s", novo->nome);
	getchar();
	printf("Digite o email: ");
	scanf("%[^\n]s", novo->email);
	getchar();
	printf("Digite o telefone: ");
	scanf("%[^\n]s", novo->telefone);
	getchar();

	Agenda *ant = NULL;
	Agenda *p = a;

	while(p != NULL && strcmp(p->nome, novo->nome) < 0) { //procura posição correta
		ant = p;
		p = p->prox;
	}

	if(ant == NULL) {
		novo->prox = a;
		a = novo;
	} else {
		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return a;
}
//Retira elementos da agenda
Agenda* RetiraAgenda(Agenda *a) {
	Agenda *ant = NULL;
	Agenda *p = a;

	char nome[50];

	printf("\n3- Removendo contato\n\n");
	printf("Digite o nome para retirar: ");
	scanf("%[^\n]s", nome);
	getchar();

	while(p != NULL && strstr(p->nome, nome) == NULL) {//verifica se nome eh o mesmo a ser procurado
		ant = p;
		p = p->prox;
	}

	if(p == NULL)
		return a;

	if(ant == NULL)
		a = p->prox;
	else
		ant->prox = p->prox;

	free(p);//libera ponteiro

	return a;
}
//Edita email e/ou telefone do contato
void EditaAgenda(Agenda *a) {
	Agenda *p;
	int opc = 0;
	char nome[50];

	printf("\n2- Editando Contato\n\n");
	printf("Digite o nome para Editar: ");
	scanf("%[^\n]s", nome);
	getchar();

	for(p = a; p != NULL; p = p->prox) {
		if(strstr(p->nome, nome) != NULL) {	//verifica se o nome a ser procurado esta na lista		
			while(opc <= 0 || opc > 3) {//apresenta opções
				printf("1- Editar Email\n");
				printf("2- Editar Telefone\n");
				printf("3- Editar Email e Telefone\n");
				printf("Opção: ");
				scanf("%d", &opc);
				getchar();
			}
			//faz as alterações desejadas
			if(opc == 1) {//verifica opçoes
				printf("Altere o email: ");
				scanf("%[^\n]s", p->email);
				getchar();//getchar();
			} else if(opc == 2) {
				printf("Altere o numero: ");
				scanf("%[^\n]s", p->telefone);
				getchar();
			} else {
				printf("Altere o email: ");
				scanf("%[^\n]s", p->email);
				getchar();
				printf("Altere o numero: ");
				scanf("%[^\n]s", p->telefone);
				getchar();
			}
			printf("\nAlterado com sucesso!\n");
		}
	}
}
//busca contato na agenda
void Busca(Agenda *a) {
	Agenda *p;
	char nome[50];

	printf("\n4- Buscando Contato\n\n");
	printf("Digite o nome para buscar: ");
	scanf("%[^\n]s", nome);//pede nome a ser buscado
	getchar();

	for(p = a; p != NULL; p = p->prox) {//procura pelo nome a ser procurado
		if(strstr(p->nome, nome) != NULL) {//se o nome a ser procurado fizer parte do contato imprime. ex:aniel, imprime o contato completo de daniel
			printf("Nome: %s \n", p->nome);
			printf("Email: %s \n", p->email);
			printf("Telefone: %s \n\n", p->telefone);
		}
	}
}
//Imprime toda a agenda
void Mostra(Agenda *a) {
	Agenda *p;
	printf("\n5- Contatos\n\n");
	for(p = a; p != NULL; p = p->prox) {//loop percorre toda a lista ate o final, ate encontrar NULL
		printf("Nome: %s \n", p->nome);	
		printf("Email: %s \n", p->email);
		printf("Telefone: %s \n\n", p->telefone);
	}
	printf("\n");
}
//funcao principal
int main(void) {
	Agenda *a;
	int continua = 1, opc = 0;//indicadores de inicio

	a = inicializa();//inicializa a lista

	printf("\n\t Bem-Vindo a Agenda Eletronica\n");
	
	while(continua) {
		printf("\nOpções da Agenda:\n");
		printf("1- Inserir Contato\n");
		printf("2- Editar Contato\n");
		printf("3- Remover Contato\n");
		printf("4- Buscar Contato\n");
		printf("5- Listar todos os contatos\n");
		printf("6- Sair\n\n");

		while(opc <= 0 || opc > 6) {//verifica a opção digitada
			printf("Digite sua opção: ");
			scanf("%d", &opc);
			getchar();
		}

		switch(opc) {//verifica quais das opções foi digita e executa o comando desejado 
			case 1:
				a = InsereAgenda(a);
				break;

			case 2:
				EditaAgenda(a);
				break;

			case 3:
				a = RetiraAgenda(a);
				break;

			case 4:
				Busca(a);
				break;

			case 5:
				Mostra(a);
				break;

			case 6:
				continua = 0;

		}
		opc = 0;//zera a opção para poder continuar
	}

	printf("\tAte Logo!\n");//mensagem de despedida do programa

	return 0;
}