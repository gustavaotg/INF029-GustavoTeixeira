#include <stdio.h>

#define LADO_TABULEIRO 3
#define QTDCELULAS LADO_TABULEIRO*LADO_TABULEIRO
#define JOG1 'X'
#define JOG2 'O'
#define VAZIO '.'
// Pensando bem acho que seria melhor ter feito uma struct...

typedef struct {
    char tabuleiro[LADO_TABULEIRO][LADO_TABULEIRO];
    int lado;
    int tamanho;
    char jogador[2];
    char vazio;
} Tabuleiro;

// Cria a string do tabuleiro inicial
void iniciarTabuleiro(Tabuleiro*);

//imprime o tabuleiro na tela
void mostrarTabuleiro(Tabuleiro);

void fazerJogada(Tabuleiro*);

// retorna 0 se não tiver acabado o jogo, 1 se 'X' ganhar e 2 se 'O' ganhar
int gameOver(Tabuleiro*);

// retorna 0 se for a vez de 'X' e 1 se for de 'O'
// A verificação é feita a partir da quantidade de espaços vazios
int jogadorAtual(Tabuleiro); 


int main()
{   
    Tabuleiro tabuleiro;
    iniciarTabuleiro(&tabuleiro);

    for(int nJogada = 0; (gameOver(&tabuleiro)) == 0 && nJogada < tabuleiro.tamanho; nJogada++) {
        fazerJogada(&tabuleiro);
    }
    mostrarTabuleiro(tabuleiro);
    int vencedor = gameOver(&tabuleiro);

    if (vencedor) {
        printf("O jogador %c venceu!\n", tabuleiro.jogador[vencedor-1]);
    } else {
        printf("Empate!\n");
    }
    return 0;
}

void iniciarTabuleiro(Tabuleiro* tabuleiro) {
    tabuleiro->lado = LADO_TABULEIRO;
    tabuleiro->tamanho = QTDCELULAS;
    tabuleiro->jogador[0] = JOG1;
    tabuleiro->jogador[1] = JOG2;
    tabuleiro->vazio = VAZIO;
    for (int i = 0; i < tabuleiro->lado; i++) {
        for (int j = 0; j < tabuleiro->lado; j++) {
            tabuleiro->tabuleiro[i][j] = tabuleiro->vazio;
        }
    }
    return;
}

void mostrarTabuleiro(Tabuleiro tabuleiro) {
    for (int i = -1; i < tabuleiro.lado; i++) {
        for (int j = -1; j < tabuleiro.lado; j++) {
            if (i == -1) {
                if (j == -1) {
                    printf("    ");
                } else {
                    printf("%i   ", j + 1);
                }
                continue;
            } else if (j == -1) {
                printf("%c", 'A' + i);
            } else {
                printf("%c", tabuleiro.tabuleiro[i][j]);
            }
            printf(" │ ");
        }
        printf("\n  ├───┼───┼───┤\n");
    }
    
    return;
}


void fazerJogada(Tabuleiro* tabuleiro) {
    int jogadaValida = 0;
    char jogada[3];
    int jogAtual = jogadorAtual(*tabuleiro);
    int posLinha;
    int posColuna;


    while (!jogadaValida) {
        mostrarTabuleiro(*tabuleiro);

        printf("Vez do Jogador '%c':", tabuleiro->jogador[jogAtual]);
        fgets(jogada, sizeof(jogada), stdin);
        getchar();
        jogada[2] = '\0';

        posLinha = (jogada[0] & 0xdf) - 'A';
        posColuna = jogada[1] - '1';
        
        // Ambas as posições devem estar no intervalo [0; tamLado)
        jogadaValida = (0 <= posLinha && posLinha < tabuleiro->lado) && 
                       (0 <= posColuna && posColuna < tabuleiro->lado) &&
                       (tabuleiro->tabuleiro[posLinha][posColuna] == tabuleiro->vazio);
        if (jogadaValida == 0) {
            printf("Posição inválida!\n");
        }
    }
    // Exemplo de jogada: A1

    tabuleiro->tabuleiro[posLinha][posColuna] = tabuleiro->jogador[jogAtual];
    return;
}

int jogadorAtual(Tabuleiro tabuleiro) {
    // Conta quantas celulas estão ocupadas
    int qtdNVazio = 0;
    for (int i = 0; i < tabuleiro.lado; i++) {
        for (int j = 0; j < tabuleiro.lado; j++) {
            if (tabuleiro.tabuleiro[i][j] != tabuleiro.vazio) {
                qtdNVazio++;
            }
        }
    }
    return (qtdNVazio % 2);
}

int gameOver(Tabuleiro* tabuleiro) {
    char* verde = "\033[32m";
    return 0;
}