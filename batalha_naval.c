/* 	ESTRUTURAS DE DADOS - 2017/01
	Univesidade de Brasília - UNB
	Aluno: Gabriel Morais marreiros
	Matricula: 16/0121256
	Github: @Gabrielmormar
	Descrição: Jogo da batalha naval em linguagem C  */
#include <stdio.h>
#include <time.h>
#include <string.h>

char barcos1[10][10], barcos2[10][10], tab1[10][10], tab2[10][10], nome_j1[20], nome_j2[20];
int x, y, pontos_j1 = 0, pontos_j2 = 0;
//dá as boas vindas ao usuario
void boas_vindas(void) {
	printf("\n===============================================================================");	
	printf("\n\t\t\tBem vindo a Batalha Naval!!!\n");
	printf("\t\t\tJOGADOR 1 vs JOGADOR 2\n");
	printf("===============================================================================\n");
	printf("Nome do jogador 1: ");
	scanf(" %[^\n]s", nome_j1);
	printf("Nome do jogador 2: ");
	scanf(" %[^\n]s", nome_j2);
	printf("\n");
	getchar();
}
//mostra os tabuleiros na tela
void mostra_tab(void) {
	int i, j;
	printf("\tJOGADOR 1"); printf("\t\t\t\tJOGADOR 2\n\n"); 
	printf("\t");
	printf(" ");
	for(i = 0; i < 10; i++) { //imprime os indices de cada colunas
		printf(" %i ", i);
	} 
	printf("\t\t"); 
	printf(" ");
	for(i = 0; i < 10; i++) {//imprime o indice das colunas
		printf(" %i ", i);
	} printf("\n");
	for(i = 0; i < 10; i++) {
		printf("\t");
		printf("%i", i);//imprime o indice das linhas
		for(j = 0; j<10; j++) {
			printf(" %c ", tab1[i][j]);
		}
		printf("\t\t");
		printf("%i", i);//imprime o indice das linhas
		for(j = 0; j<10; j++) {
			printf(" %c ", tab2[i][j]);
		}
		printf("\n");
	}
	printf("\n\t%s: %i pontos",nome_j1, pontos_j1);
	printf("\t\t\t\t%s: %i pontos\n\n",nome_j2, pontos_j2);
}
//pede coordenadas ao usuario
void pede_coordenadas(void) {
	printf("Digite as coordenadas do alvo(x,y): ");
	scanf("%d %d", &x, &y);
	printf("\n\n===============================================================================\n");
}
//posiciona barcos no tabuleiro
void posiciona_barcos(char tab[][10]) {
	int i, j, l, c, b = 0;
	//gera os porta-avioes
	do {
		c = rand()%10; //gera uma coluna aleatoria
		if(c>5) {//verifica se cabera na horizontal
			l = rand()%6;//gera uma linha para caber n avertical
			//verifica se já existe alguma embarcação no local
			if(tab[l][c] != 'X' && tab[l+1][c] != 'X' && tab[l+2][c] != 'X' && tab[l+3][c] != 'X' && tab[l+4][c] != 'X') {
				for(j = l; j<(l+5);j++){
					tab[j][c] = 'X';
				} 
				b += 1;//indica que já foi criado uma embarcação
			}
		} else {
			if(c<6) {
				l = rand()%10;
				if(tab[l][c+1] != 'X' && tab[l][c+2] != 'X' && tab[l][c+3] != 'X' && tab[l][c+4] != 'X') {
					for(i = c; i<(c+5);i++){
						tab[l][i] = 'X';
					}
					b += 1;
				}
			}
		}
	} while(b < 3); //cria 3 embarcações do mesmo tipo
	 b = 0;
	//Gera submarinos
	do {
		c = rand()%10;
		if(c > 7) {
			l = rand()%8;
			if(tab[l][c] != 'X' && tab[l+1][c] != 'X' && tab[l+2][c] != 'X'){
				for(j = l; j<(l+2); j++) {
					tab[j][c] = 'X';
				} 
				b += 1;
			}
		} else {
			if(c < 8) {
				l = rand()%10;
				if(tab[l][c] != 'X' && tab[l][c+1] != 'X' && tab[l][c+2] != 'X') {
					for(i = c; i<(c+2); i++) {
						tab[l][i] = 'X';
					}
					b += 1;
				}
			}
		}
	} while(b < 4);
}
//verifica os tiros dado por cada jogador
void verifica(int v) {
	pede_coordenadas();
	//verifica de quem é a vez, se der 0, é a vez do jogador 1
	if(v%2 == 0) { 
		//verifica se o jogador já atacou a mesma coordenada mais de uma vez
		if(tab2[x][y] == '*' || tab2[x][y] == 'X') {
			printf("\tVOCE JA ACERTOU ESSA COORDENADA! ESCOLHA OUTRA!!\n");
			printf("===============================================================================\n");
			pede_coordenadas();
			verifica(v);
		} else {
			//verifica se o tiro foi na agua
			if(barcos2[x][y] == '~') {
				printf("\t\t\t\tTIRO NA AGUA!\n");
				printf("===============================================================================\n");
				tab2[x][y] = '*';
			} else {
				//verifica se o jogador acertou
				if(barcos2[x][y] == 'X') {
					printf("\t\t\t\t***ACERTOU!!!***\n");
					tab2[x][y] = 'X';
					pontos_j1 += 5;
				}
			}
		}
	} else if(v%2 == 1){
		if(tab1[x][y] == '*' || tab1[x][y] == 'X') {
			printf("\tVOCE JA ACERTOU ESSA COORDENADA! ESCOLHA OUTRA!!\n");
			printf("===============================================================================\n");
			pede_coordenadas();
			verifica(v);
		} else {
			if(barcos1[x][y] == '~') {
				printf("\t\t\t\tTIRO NA AGUA!\n");
				printf("===============================================================================\n");
				tab1[x][y] = '*';
			} else {
				if(barcos1[x][y] == 'X') {
					printf("\t\t\t\t***ACERTOU!!!***\n");
					tab1[x][y] = 'X';
					pontos_j2 += 5;
				}
			}
		}
	}
}
//funcao main
int main(void) {
	memset(tab1, '~', 100); 
	memset(tab2, '~', 100); 
	memset(barcos1, '~', 100);
	memset(barcos2, '~', 100);	
	srand(time(NULL));
	int v = 0;
	boas_vindas();
	posiciona_barcos(barcos1);
	posiciona_barcos(barcos2);
	//incia jogo para os jogadores, enquanto um dos jogadores não acerta os alvos com o menor numero de chances, o loop continua
	do {
		mostra_tab();
		printf("\t\t\t\tVez de %s!\n\n\n", nome_j1);
		//pede_coordenadas();
		verifica(v);
		v++;//troca a vez de cada jogador
		mostra_tab();
		printf("\t\t\t\tVez de %s!\n\n\n", nome_j2);
		verifica(v);
		v++;
	} while(pontos_j1 < 115 && pontos_j2 < 115);
	//verifica quem foi o ganhador do jogo
	if(pontos_j1 > pontos_j2)
		printf("O jogador 1 ganhou o jogo!!!\n");
	else if(pontos_j2 > pontos_j1)
		printf("O jogador 2 ganhou o jogo!!!\n");
	else
		printf("O jogo empatou!\n");

	return 0;
}