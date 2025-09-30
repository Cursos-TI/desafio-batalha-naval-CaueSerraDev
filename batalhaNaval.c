#include <stdio.h>

#define TAMANHO 10     // tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3    // tamanho fixo de cada navio (3 posições)

//----------------------------------------------------------
// Função para imprimir o tabuleiro no console
//----------------------------------------------------------
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("=== Tabuleiro Batalha Naval ===\n\n");

    // Cabeçalho com números das colunas
    printf("   ");
    for (int c = 0; c < TAMANHO; c++)
        printf("%d ", c);
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d: ", i); // Mostra o número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//----------------------------------------------------------
// Função que verifica se o navio pode ser colocado no local
// tabuleiro    -> matriz 10x10
// linha, coluna -> coordenada inicial
// orientacao    -> 'H' (horizontal), 'V' (vertical)
//                   'D' (diagonal principal), 'S' (diagonal secundária)
//----------------------------------------------------------
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO],
                   int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + TAM_NAVIO > TAMANHO) return 0;
        for (int j = 0; j < TAM_NAVIO; j++)
            if (tabuleiro[linha][coluna + j] != 0) return 0;
    } 
    else if (orientacao == 'V') {
        if (linha + TAM_NAVIO > TAMANHO) return 0;
        for (int i = 0; i < TAM_NAVIO; i++)
            if (tabuleiro[linha + i][coluna] != 0) return 0;
    } 
    else if (orientacao == 'D') { // Diagonal principal (\)
        if (linha + TAM_NAVIO > TAMANHO || coluna + TAM_NAVIO > TAMANHO) return 0;
        for (int k = 0; k < TAM_NAVIO; k++)
            if (tabuleiro[linha + k][coluna + k] != 0) return 0;
    } 
    else if (orientacao == 'S') { // Diagonal secundária (/)
        if (linha + TAM_NAVIO > TAMANHO || coluna - (TAM_NAVIO - 1) < 0) return 0;
        for (int k = 0; k < TAM_NAVIO; k++)
            if (tabuleiro[linha + k][coluna - k] != 0) return 0;
    }
    return 1;
}

//----------------------------------------------------------
// Função para posicionar o navio (marca com 3 na matriz)
//----------------------------------------------------------
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO],
                     int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int j = 0; j < TAM_NAVIO; j++)
            tabuleiro[linha][coluna + j] = 3;
    } 
    else if (orientacao == 'V') {
        for (int i = 0; i < TAM_NAVIO; i++)
            tabuleiro[linha + i][coluna] = 3;
    } 
    else if (orientacao == 'D') { // Diagonal principal
        for (int k = 0; k < TAM_NAVIO; k++)
            tabuleiro[linha + k][coluna + k] = 3;
    } 
    else if (orientacao == 'S') { // Diagonal secundária
        for (int k = 0; k < TAM_NAVIO; k++)
            tabuleiro[linha + k][coluna - k] = 3;
    }
}

//----------------------------------------------------------
// Programa principal
//----------------------------------------------------------
int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa tudo com 0 (água)

    // ------------------------------
    // Coordenadas pré-definidas para os 4 navios
    // ------------------------------
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical
    int linhaD = 0, colunaD = 0; // Navio diagonal principal
    int linhaS = 0, colunaS = 9; // Navio diagonal secundária

    // Navio horizontal
    if (podePosicionar(tabuleiro, linhaH, colunaH, 'H'))
        posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    else
        printf("ERRO: Não foi possível posicionar o navio horizontal!\n");

    // Navio vertical
    if (podePosicionar(tabuleiro, linhaV, colunaV, 'V'))
        posicionarNavio(tabuleiro, linhaV, colunaV, 'V');
    else
        printf("ERRO: Não foi possível posicionar o navio vertical!\n");

    // Navio diagonal principal
    if (podePosicionar(tabuleiro, linhaD, colunaD, 'D'))
        posicionarNavio(tabuleiro, linhaD, colunaD, 'D');
    else
        printf("ERRO: Não foi possível posicionar o navio diagonal principal!\n");

    // Navio diagonal secundária
    if (podePosicionar(tabuleiro, linhaS, colunaS, 'S'))
        posicionarNavio(tabuleiro, linhaS, colunaS, 'S');
    else
        printf("ERRO: Não foi possível posicionar o navio diagonal secundária!\n");

    // Exibe o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}

