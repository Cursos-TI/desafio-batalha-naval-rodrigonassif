#include <stdio.h>

int main() {
    // Inicializa todas as posições do tabuleiro com 0 (água)
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define valor dos navios
    int navio1 = 3;
    int navio2 = 3;
    int navio3 = 3;
    int navio4 = 3;

    // Posiciona navio1 na linha 6, colunas 3, 4, 5 (índices: linha 6 = i=6, colunas j=3,4,5)
    tabuleiro[6][3] = navio1;
    tabuleiro[6][4] = navio1;
    tabuleiro[6][5] = navio1;

    // Posiciona navio2 na coluna 6, linhas 1, 2, 3 (índices: coluna 6 = j=6, linhas i=0,1,2)
    tabuleiro[0][6] = navio2;
    tabuleiro[1][6] = navio2;
    tabuleiro[2][6] = navio2;

    // Posicionamento dos navios 3 e 4 em diagonais 
    tabuleiro[1][1] = navio3;
    tabuleiro[2][2] = navio3;
    tabuleiro[3][3] = navio3;

    tabuleiro[0][9] = navio4;
    tabuleiro[1][8] = navio4;
    tabuleiro[2][7] = navio4;


    // Exibe o tabuleiro com cabeçalho formatado (A-J para colunas, 1-10 para linhas)
    printf("Tabuleiro de Batalha Naval\n");
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        if (i < 9) {
            printf("%d  ", i + 1);
        } else {
            printf("%d ", i + 1);  // Alinhamento para 10
        }
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}