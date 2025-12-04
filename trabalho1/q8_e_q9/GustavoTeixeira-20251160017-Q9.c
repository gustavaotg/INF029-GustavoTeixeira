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
    int jogador;
} Tabuleiro;


// Cria a string do tabuleiro inicial
void iniciarTabuleiro(Tabuleiro*, int);

// imprime o tabuleiro na tela
void mostrarTabuleiro(Tabuleiro);

// limpa a tela para não haver trapaças
void limparTela();

// faz um menu para o jogador atual, as ações possíveis serão:
//      1.Ver próprio tabuleiro
//      2.Fazer uma jogada (isso irá, consequentemente, imprimir o tabuleiro do oponente com as jogadas já feitas)
void menuJogador(Tabuleiro*, int, int);

// Pergunta ao jogador onde ele quer colocar os navios
void colocarNavios(Tabuleiro*);

// Verifica se existe somente 1 jogador que ainda tem navios
int gameOver(Tabuleiro*, int);


int main() {
    // tabuleiros dos jogadores
    Tabuleiro tabuleiros[QTDJOGADORES];
    for (int i = 0; i < QTDJOGADORES; i++) {
        iniciarTabuleiro(&(tabuleiros[i]), i + 1); // inicia tabuleiro do jogador i
        colocarNavios(&(tabuleiros[i]));
    }
    
    for (int rodada = 0; gameOver(tabuleiros, QTDJOGADORES) == 0; rodada++, limparTela()) {
        menuJogador(tabuleiros, QTDJOGADORES, rodada);
    }
    
    return 0;
}


void iniciarTabuleiro(Tabuleiro* tabuleiro, int nJog) {
    tabuleiro->lado = LADO_TABULEIRO;
    tabuleiro->tamanho = QTDCELULAS;
    tabuleiro->valores[0] = 'X';
    tabuleiro->valores[1] = 'O';
    tabuleiro->valores[2] = 'N';
    tabuleiro->vazio = VAZIO;
    tabuleiro->jogador = nJog;
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
                    printf("%4i", j + 1);
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
    
    
    return;
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

void colocarNavios(Tabuleiro* tabuleiro) {
    mostrarTabuleiro(*tabuleiro);
    // TAM: 4; QTD: 1 
    // TAM: 3; QTD: 1 
    // TAM: 1; QTD: 3 
    
    colocarNavioTamQtd(tabuleiro, 4, 1);
    colocarNavioTamQtd(tabuleiro, 3, 1);
    colocarNavioTamQtd(tabuleiro, 1, 3);


    return;
}
