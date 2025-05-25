#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5  // Tamanho das matrizes de habilidade (deve ser ímpar)
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Função para inicializar uma matriz com zeros
void inicializar_matriz(int m[TAM_TAB][TAM_TAB], int valor) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            m[i][j] = valor;
        }
    }
}

// Função para imprimir o tabuleiro com legendas
void imprimir_tabuleiro(int m[TAM_TAB][TAM_TAB]) {
    printf("\nLegenda: 0 = Água, 3 = Navio, 5 = Habilidade\n\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navios simples
void posicionar_navios(int m[TAM_TAB][TAM_TAB]) {
    // Horizontal
    m[1][2] = NAVIO; m[1][3] = NAVIO; m[1][4] = NAVIO;

    // Vertical
    m[4][6] = NAVIO; m[5][6] = NAVIO; m[6][6] = NAVIO;

    // Diagonal ↘
    m[6][6] = NAVIO; m[7][7] = NAVIO; m[8][8] = NAVIO;

    // Diagonal ↙
    m[2][7] = NAVIO; m[3][6] = NAVIO; m[4][5] = NAVIO;
}

// Gera matriz cone (ponta no meio da primeira linha)
void gerar_matriz_cone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Se j está dentro do "alargamento" da linha i
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Gera matriz cruz
void gerar_matriz_cruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Gera matriz octaedro (forma de losango)
void gerar_matriz_octaedro(int octa[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }
}

// Aplica uma matriz de habilidade sobre o tabuleiro, no ponto central (cx, cy)
void aplicar_habilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int cx, int cy) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Cálculo da posição no tabuleiro
            int linha = cx - TAM_HAB / 2 + i;
            int coluna = cy - TAM_HAB / 2 + j;

            // Verifica se está dentro dos limites
            if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    // Inicializa o tabuleiro com água
    inicializar_matriz(tabuleiro, AGUA);

    // Posiciona navios fixos
    posicionar_navios(tabuleiro);

    // Gera as matrizes de habilidade dinamicamente
    gerar_matriz_cone(cone);
    gerar_matriz_cruz(cruz);
    gerar_matriz_octaedro(octaedro);

    // Aplica as habilidades ao tabuleiro em pontos fixos
    aplicar_habilidade(tabuleiro, cone, 2, 2);         // Cone em (2,2)
    aplicar_habilidade(tabuleiro, cruz, 5, 5);         // Cruz em (5,5)
    aplicar_habilidade(tabuleiro, octaedro, 7, 3);     // Octaedro em (7,3)

    // Exibe o resultado final
    imprimir_tabuleiro(tabuleiro);

    return 0;
}