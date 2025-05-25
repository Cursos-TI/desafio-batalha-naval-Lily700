#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração do tabuleiro e inicialização com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializando o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Definindo navios com 3 posições
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 3;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação simples: verificar se estão dentro dos limites e não se sobrepõem
    int pode_posicionar_horizontal = (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
    int pode_posicionar_vertical = (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);

    int sobreposicao = 0;

    if (pode_posicionar_horizontal) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
    }

    if (pode_posicionar_vertical && !sobreposicao) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }
    }

    if (pode_posicionar_horizontal && pode_posicionar_vertical && !sobreposicao) {
        // Posicionando navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }

        // Posicionando navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        }

        // Exibindo o tabuleiro
        printf("Tabuleiro Batalha Naval (0 = Agua, 3 = Navio):\n\n");
        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Erro: Não é possível posicionar os navios sem sobreposição ou fora dos limites do tabuleiro.\n");
    }

    return 0;
}