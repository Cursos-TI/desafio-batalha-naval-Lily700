#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ============================
    // NAVIO 1 - HORIZONTAL
    // ============================
    int l1 = 1, c1 = 2;
    int pode1 = c1 + TAM_NAVIO <= TAM;
    int sobrepoe1 = 0;

    if (pode1) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[l1][c1 + i] != AGUA) {
                sobrepoe1 = 1;
                break;
            }
        }
    }

    if (pode1 && !sobrepoe1) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[l1][c1 + i] = NAVIO;
        }
    }

    // ============================
    // NAVIO 2 - VERTICAL
    // ============================
    int l2 = 4, c2 = 5;
    int pode2 = l2 + TAM_NAVIO <= TAM;
    int sobrepoe2 = 0;

    if (pode2) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[l2 + i][c2] != AGUA) {
                sobrepoe2 = 1;
                break;
            }
        }
    }

    if (pode2 && !sobrepoe2) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[l2 + i][c2] = NAVIO;
        }
    }

    // ============================
    // NAVIO 3 - DIAGONAL PRINCIPAL (↘)
    // ============================
    int l3 = 6, c3 = 6;
    int pode3 = (l3 + TAM_NAVIO <= TAM) && (c3 + TAM_NAVIO <= TAM);
    int sobrepoe3 = 0;

    if (pode3) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[l3 + i][c3 + i] != AGUA) {
                sobrepoe3 = 1;
                break;
            }
        }
    }

    if (pode3 && !sobrepoe3) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[l3 + i][c3 + i] = NAVIO;
        }
    }

    // ============================
    // NAVIO 4 - DIAGONAL SECUNDÁRIA (↙)
    // ============================
    int l4 = 2, c4 = 7;
    int pode4 = (l4 + TAM_NAVIO <= TAM) && (c4 - TAM_NAVIO + 1 >= 0);
    int sobrepoe4 = 0;

    if (pode4) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[l4 + i][c4 - i] != AGUA) {
                sobrepoe4 = 1;
                break;
            }
        }
    }

    if (pode4 && !sobrepoe4) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[l4 + i][c4 - i] = NAVIO;
        }
    }

    // ============================
    // EXIBIR TABULEIRO
    // ============================
    printf("Tabuleiro Batalha Naval (0 = Água, 3 = Navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}