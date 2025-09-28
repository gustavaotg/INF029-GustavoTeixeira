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


void esperarUsuario() {
	printf("Pressione enter para continuar...");
	getchar();
	getchar(); // 2 getchar() sao necessarios por causa do \n no buffer apos o scanf
}

void separador() {
	for (int i = 0; i < 50; i++)
		printf("-");
	printf("\n");
	return;
}

int imprimirLista(carros* lista) {

	if (lista->qtdCarros == 0) {
		printf("Sem carros cadastrados!\n");
		return 1;
	}

	for (int i = 0; i < lista->qtdCarros; i++) {
		printf("Carro [%i]|| Chassi: %i | Ano: %i\n", i + 1, lista->Lista[i].chassi, lista->Lista[i].ano);
	}
	return 0;
}

void cadastrarCarro(carros* lista) {
	if (lista->qtdCarros >= TAM) {
		printf("Quantidade maxima de carros!\n");
		return;
	}
	printf("Digite o chassi: ");
	scanf("%i", &(lista->Lista[lista->qtdCarros].chassi));
	printf("Digite o ano: ");
	scanf("%i", &(lista->Lista[lista->qtdCarros].ano));
	lista->qtdCarros++;
}

void modificarCarro(carros* lista) {
	int escolha = -1;
	imprimirLista(lista);
	while (escolha < 1 || escolha > lista->qtdCarros) {
		printf("Digite o numero do carro que deseja modificar: ");
		scanf("%i", &escolha);
	}
	printf("Digite o ano: ");
	scanf("%i", &(lista->Lista[escolha-1].ano));
	return;
}

void excluirCarro(carros* lista) {


	return;
}

int main() {
	
	carros lstCarros;
	lstCarros.qtdCarros = 0;

	int escolha = -1;
	while(escolha) {
		separador();
		printf("Cadastramento de Carros\n");
		printf("[1] Cadastrar\n");
		printf("[2] Listar\n");
		printf("[3] Modificar\n");
		printf("[4] Excluir\n");
		printf("[0] Sair\n");
		printf("Digite a escolha:\n");
		scanf("%i", &escolha);
		separador();

		switch (escolha) {
			case 0:
				printf("Volte Sempre!\n");
				break;
			case 1: // Cadastrar
				cadastrarCarro(&lstCarros);
				printf("Cadastrando...[%i]\n", lstCarros.qtdCarros);
				break;
			case 2: // Listar
				imprimirLista(&lstCarros);
				esperarUsuario();
				break;
			case 3: // Modificar
				modificarCarro(&lstCarros);
				printf("Modificando...\n");
				break;
			case 4: // Excluir
				excluirCarro(&lstCarros);
				printf("Excluindo...\n");
				break;
		}
    
  }
  
  return 0;
}
