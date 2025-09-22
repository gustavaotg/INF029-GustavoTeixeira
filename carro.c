#include <stdio.h>

/* Cria uma struct para carros */
typedef struct carro {
	int chassi;
	int ano;
} carro;

#define TAM 3

typedef struct carros {
	carro Lista[TAM];
	int qtdCarros;
} carros;

int main() {
	
	int escolha = -1;
	while(escolha) {
		printf("Cadastramento de Carros\n");
		printf("[1] Cadastrar\n");
		printf("[2] Listar\n");
		printf("[3] Modificar\n");
		printf("[4] Excluir\n");
		printf("[0] Sair\n");
		printf("Digite a escolha:\n");
		scanf("%i", &escolha);
		
		switch (escolha) {
			case 0:
				printf("Volte Sempre!\n");
				break;
			case 1:
				printf("Cadastrando...\n")
				break;
			case 2:
				break;
			case 3:
				printf("Modificando...\n")
				break;
			case 4:
				printf("Excluindo...\n")
				break;
			
		
		
		}
    
  }
  
  return 0;
}
