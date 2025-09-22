#include <stdio.h>

/* Cria uma struct para carros */
typedef struct carro {
  int chassi;
  int ano;
} carro;

#define TAM 3

typedef struct carros {
	carro Lista[TAM];
	int qtdCarros = 0;
} carros

int main() {
  
  int escolha = -1;
  while(escolha) {
    printf("")
    printf("[1] Cadastrar");
    printf("[2] Listar");
    printf("[3] Modificar");
    printf("[4] Excluir");
    printf("[0] Sair");
    printf("Digite a escolha");
	  scanf("%i", &escolha);
    
  }
  
  return 0;
}
