// Fazer Batalha Naval

#include <stdio.h>
#include <stdlib.h>

#define LADO_TABULEIRO 10
#define QTDCELULAS LADO_TABULEIRO*LADO_TABULEIRO
#define QTDNAVIOS 5
#define QTDJOGADORES 2

#define VAZIO ' '

typedef struct {
    char tabuleiro[LADO_TABULEIRO][LADO_TABULEIRO];
    int lado;
    int tamanho;
    char valores[3]; // X = tiro invalido; O = acertou alvo; N = navio posicionado;
    char vazio;
} Tabuleiro;


// Cria a string do tabuleiro inicial
void iniciarTabuleiro(Tabuleiro*);

// imprime o tabuleiro na tela
void mostrarTabuleiro(Tabuleiro);

// limpa a tela para não haver trapaças
void limparTela();

// faz um menu para o jogador atual, as ações possíveis serão:
//      2.Ver próprio tabuleiro
//      3.Fazer uma jogada (isso irá, consequentemente, imprimir o tabuleiro do oponente com as jogadas já feitas)
void menuJogador(Tabuleiro*, int, int);

// Pergunta ao jogador onde quer colocar os navios
void colocarNavios(Tabuleiro*);

// Verifica se existe somente 1 jogador que ainda tem navios
int gameOver(Tabuleiro*, int);


int main() {
    // tabuleiros dos jogadores
    Tabuleiro tabuleiros[QTDJOGADORES];
    for (int i = 0; i < QTDJOGADORES; i++) {
        iniciarTabuleiro(&(tabuleiros[i])); // inicia tabuleiro do jogador i
        colocarNavios(&(tabuleiros[i]));
    }
    
    for (int rodada = 0; gameOver(tabuleiros, QTDJOGADORES) == 0; rodada++, limparTela()) {
        menuJogador(tabuleiros, QTDJOGADORES, rodada);
    }
    
    return 0;
}


void iniciarTabuleiro(Tabuleiro* tabuleiro) {
    tabuleiro->lado = LADO_TABULEIRO;
    tabuleiro->tamanho = QTDCELULAS;
    tabuleiro->valores[0] = 'X';
    tabuleiro->valores[1] = 'O';
    tabuleiro->valores[2] = 'N';
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
        printf("\n  ├");
        for (int k = 0; k < tabuleiro.lado; k++) {
            printf("───");
            if (k != tabuleiro.lado - 1) {
                printf("┼");
            }
        }
        printf("┤\n");
    }
}    


void menuJogador(Tabuleiro*, int, int) {
    
}


void limparTela() {
    system("clear");
    return;

    //int tam = 3000;
    //char buffer[tam];
    
    //for (int i = 0; i < tam - 1; i++) {
    //    buffer[i] = '\n';
    //}
    
    //printf("%s", buffer);
    
    //return;   
}


