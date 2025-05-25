#include <stdio.h>

// Tamanho do tabuleiro e das habilidades
#define TAM 10
#define HAB 5
#define HAB_ORIGEM 2  // Centro de uma matriz 5x5

// Função para sobrepor habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HAB][HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (habilidade[i][j] == 1) {
                int lin = origemLinha + (i - HAB_ORIGEM);
                int col = origemColuna + (j - HAB_ORIGEM);

                // Verifica se está dentro dos limites do tabuleiro
                if (lin >= 0 && lin < TAM && col >= 0 && col < TAM) {
                    if (tabuleiro[lin][col] == 0) {
                        tabuleiro[lin][col] = 5; // Marca área afetada pela habilidade
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define navios
    int navio = 3;

    // Posicionamento dos navios
    tabuleiro[6][3] = navio; tabuleiro[6][4] = navio; tabuleiro[6][5] = navio;
    tabuleiro[0][6] = navio; tabuleiro[1][6] = navio; tabuleiro[2][6] = navio;
    tabuleiro[1][1] = navio; tabuleiro[2][2] = navio; tabuleiro[3][3] = navio;
    tabuleiro[0][9] = navio; tabuleiro[1][8] = navio; tabuleiro[2][7] = navio;

    // Matrizes das habilidades
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // Construir Cone (formato triangular com base embaixo)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= HAB_ORIGEM - i && j <= HAB_ORIGEM + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Construir Cruz (linha central e coluna central)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == HAB_ORIGEM || j == HAB_ORIGEM) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Construir Octaedro (losango)
for (int i = 0; i < HAB; i++) {
    for (int j = 0; j < HAB; j++) {
        int dist_i = (i > HAB_ORIGEM) ? (i - HAB_ORIGEM) : (HAB_ORIGEM - i);
        int dist_j = (j > HAB_ORIGEM) ? (j - HAB_ORIGEM) : (HAB_ORIGEM - j);

        if (dist_i + dist_j <= 2) {
            octaedro[i][j] = 1;
        } else {
            octaedro[i][j] = 0;
        }
    }
}

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone centrado em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 7, 7);       // Cruz centrada em (7,7)
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);   // Octaedro centrado em (5,5)

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval\n");
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(". ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");
        }
        printf("\n");
    }

    return 0;
}