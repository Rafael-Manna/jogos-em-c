//Objetivo: Criar um programa em C que permita que dois jogadores humanos joguem uma partida de Jogo da Velha em um tabuleiro 3x3 exibido no console.

#include <stdio.h>
#include <stdlib.h>

// funcao para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[3][3]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tabuleiro[i][j] = '.';
}

// funcao para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[3][3]) {
	printf("  0 1 2\n");
	for (int i = 0; i < 3; i++) {
		printf("%d ", i);
		for (int j = 0; j < 3; j++) {
			printf("%c", tabuleiro[i][j]);
			if (j < 2) printf("|");
		}
		printf("\n");
		if (i < 2) printf("  -----\n");
	}
}

// funcao para validar jogadas
int jogadaValida(int linha, int coluna, char tabuleiro[3][3]) {
	if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
		if (tabuleiro[linha][coluna] == '.')
			return 1;
	}
	return 0;
}

// funcao para verificar se tem vencedor
char verificarVencedor(char tabuleiro[3][3]) {
	// Verifica linhas e colunas
	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != '.')
			return tabuleiro[i][0];
		if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != '.')
			return tabuleiro[0][i];
	}
	// Verifica diagonais
	if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != '.')
		return tabuleiro[0][0];
	if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != '.')
		return tabuleiro[0][2];

	return '.';
}

// funcao para verificar empate
int verificarEmpate(char tabuleiro[3][3]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tabuleiro[i][j] == '.')
				return 0;
	return 1; // Tabuleiro cheio
}

// Funcao principal
int main() {
	char tabuleiro[3][3];
	char jogadorAtual = 'X';
	int linha, coluna;
	char vencedor = '.';

	inicializarTabuleiro(tabuleiro);

	while (1) {
		system("clear"); //funcao pra limpar a cada acao
		exibirTabuleiro(tabuleiro);
		printf("\nJogador %c, digite linha e coluna (ex: 1 2): ", jogadorAtual);
		scanf("%d %d", &linha, &coluna);

		if (!jogadaValida(linha, coluna, tabuleiro)) {
			printf("Jogada invalida... pressione Enter para tentar novamente.\n");
			getchar(); // limpa o \n do buffer
			getchar(); // espera o enter para coninuar
			continue;
		}

		tabuleiro[linha][coluna] = jogadorAtual;
		vencedor = verificarVencedor(tabuleiro);

		if (vencedor != '.') {
			system("clear");
			exibirTabuleiro(tabuleiro);
			printf("\nParabens! Jogador %c venceu!\n", vencedor);
			break;
		} else if (verificarEmpate(tabuleiro)) {
			system("clear");
			exibirTabuleiro(tabuleiro);
			printf("\nEmpate! Ninguemm venceu.\n");
			break;
		}

		// Troca o jogador
	if (jogadorAtual == 'X') {
    jogadorAtual = 'O';
} else {
    jogadorAtual = 'X';
}
	}

	return 0;
}
