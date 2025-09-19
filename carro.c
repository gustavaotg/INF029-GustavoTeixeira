#include <stdio.h>

# Cria uma struct para carros
typedef struct carro {
  int chassi;
  int ano;
} carro;

int main() {
  
  carro pegeout_203;
  pegeout_203.chassi = 31415926535897932;
  pegeout_203.ano = 1984;

  return 0;
}
