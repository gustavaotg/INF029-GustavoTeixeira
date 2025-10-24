// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: GUSTAVO TEIXEIRA GUIMARAES
//  email:  gustavaotg@gmail.com
//  Matrícula: 20251160017
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

int conversorData(char data[], int* dia, int* mes, int* ano) {
  
  if ((dia == NULL) || (mes == NULL) || (ano == NULL)) {
    return 0;
  }

  //quebrar a string data em strings sDia, sMes, sAno
  char sDia[3];
  char sMes[3];
  char sAno[5];
  char* ptrData[3] = {sDia, sMes, sAno};
  int indiceData = 0;

  // Sub-indice
  int subI = 0;
  for (int i = 0; (data[i] != '\0') && (indiceData < 3) && (subI < 4)  && !((subI > 2) && (indiceData < 2)); i++, subI++) {
    //printf(".");
    if (data[i] == '/') {
      // Verifica se separador não tem valores antes dele 
      // SubI é como se fizesse a pergunta: Quantos caracteres li antes da barra?
      if (subI == 0) {
        return 0;
      }

      *(ptrData[indiceData] + subI) = '\0';

      // Quando voltar pro loop ele vai se corrigir pra 0 
      subI = -1;

      indiceData++;

    } else {
      *(ptrData[indiceData] + subI) = data[i];
    }
  }
  //printf("(%i) -> SubI:%i | IndiceData:%i ||| ", ((subI >= 2) && (indiceData < 2)), subI, indiceData);
  if (indiceData != 2) {
    return 0;
  }

  // Colocando a sentinela do ano
  *(ptrData[indiceData] + subI) = '\0';
  
  //printf("(%s) (%s) (%s) ||| ", sDia, sMes, sAno);

  *dia = atoi(sDia);
  *mes = atoi(sMes);
  *ano = atoi(sAno);

  if (*ano < 0 || (*mes <= 0) || (*dia <= 0)) {
    return 0;
  }

  // Caso ano tenha 2 digitos ele será padronizado pra 4
  if (*ano < 50) {
    *ano += 2000;
  } else if (*ano < 100) {
    *ano += 1900;
  }

  return 1;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  //printf("Q1: ");
  
  //quebrar a string data em strings sDia, sMes, sAno
  char sDia[3];
  char sMes[3];
  char sAno[5];
  char* ptrData[3] = {sDia, sMes, sAno};
  int indiceData = 0;

  // Sub-indice
  int subI = 0;
  for (int i = 0; (data[i] != '\0') && (indiceData < 3) && (subI < 4)  && !((subI > 2) && (indiceData < 2)); i++, subI++) {
    //printf(".");
    if (data[i] == '/') {
      // Verifica se separador não tem valores antes dele 
      // SubI é como se fizesse a pergunta: Quantos caracteres li antes da barra?
      if (subI == 0) {
        datavalida = 0;
        return datavalida;
      }

      *(ptrData[indiceData] + subI) = '\0';

      // Quando voltar pro loop ele vai se corrigir pra 0 
      subI = -1;

      indiceData++;

    } else {
      *(ptrData[indiceData] + subI) = data[i];
    }
  }
  //printf("(%i) -> SubI:%i | IndiceData:%i ||| ", ((subI >= 2) && (indiceData < 2)), subI, indiceData);
  if (indiceData != 2) {
    datavalida = 0;
    return datavalida;
  }

  // Colocando a sentinela do ano
  *(ptrData[indiceData] + subI) = '\0';
  
  //printf("(%s) (%s) (%s) ||| ", sDia, sMes, sAno);

  int iDia, iMes, iAno;
  iDia = atoi(sDia);
  iMes = atoi(sMes);
  iAno = atoi(sAno);

  // Caso ano tenha 2 digitos ele será padronizado pra 4
  if (iAno < 50) {
    iAno += 2000;
  } else if (iAno < 100) {
    iAno += 1900;
  }

  // Garantindo que o mes está no intervalo [1; 12] (Coloquei  o "< 1" pois poderia receber -5 como um mês)
  if ((iMes < 1) || (iMes > 12)) {
    datavalida = 0;
    return datavalida;
  }

  // Meses de 31 dias
  if ((iMes == 1) || (iMes == 3) || (iMes == 5) || (iMes == 7) || (iMes == 8) || (iMes == 10) || (iMes == 12)) {
    if ((iDia < 1) || (iDia > 31)) {
      datavalida = 0;
    }

  // Fevereiro
  } else if (iMes == 2) {
    if ((iDia < 1) || (iDia > 28)) {
      datavalida = 0;
    }
    if (iDia == 29) {
      // Verificar ano bissexto (E a regra do centenario)
      if (((iAno % 400) == 0) || ((iAno % 100) != 0 && (iAno % 4) == 0)) {
        datavalida = 1;
      }
    }
  
  // Meses com 30 dias
  } else {
    if ((iDia < 1) || (iDia > 30)) {
      datavalida = 0;
    }
  }




  //printf("%s\n", data);

  return datavalida;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    //printf("Q2: "); 
    // TODO!!! Q2 PASSA NOS TESTES MAS NÃO ESTÁ 100% FUNCIONAL!
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      //Para verificar se a data final é maior que a inicial é so verificar se o resultado é negativo 
      //calcule a distancia entre as datas
      
      int dmaInicial[3];
      int dmaFinal[3];
      conversorData(datainicial, &dmaInicial[0], &dmaInicial[1], &dmaInicial[2]);
      conversorData(datafinal, &dmaFinal[0], &dmaFinal[1], &dmaFinal[2]);

      dma.qtdAnos = dmaFinal[2] - dmaInicial[2];
      dma.qtdMeses = dmaFinal[1] - dmaInicial[1];
      dma.qtdDias = dmaFinal[0] - dmaInicial[0];
      
      // Estou pensando em converter tudo para dias
      // Apos ter a diferenca em dias verificar se é negativo (inicio > fim)
      // Depois converter de dias para meses e anos, dependendo
      
      if (dma.qtdDias < 0) {
        dma.qtdMeses--;
        dma.qtdDias = dma.qtdDias + 30; // consertar depois (pois nem sempre são 30 dias)
      }
      
      if (dma.qtdMeses < 0) {
        dma.qtdAnos--;
        dma.qtdMeses = dma.qtdMeses + 12;
      }
      
      if (dma.qtdAnos < 0) {
        dma.retorno = 4;
        return dma;
      }

      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;
  
  //printf("Q3:");
  
    int isCLetter = ('A' <= (c & 0xdf) && (c & 0xdf) <= 'Z');

    // *(texto + i) é o caractere na i-ésima posição do texto
    if (isCaseSensitive == 1 || isCLetter == 0) {
      for (int i = 0; *(texto + i) != '\0'; i++) {
        if (*(texto + i) == c) {
          qtdOcorrencias++;
        }
      }
    } else {
      for (int i = 0; *(texto + i) != '\0'; i++) {
        if ((*(texto + i) & 0xdf) == (c & 0xdf)) {
          qtdOcorrencias++;
        }
      }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int qtdOcorrencias = 0;
    // Caracteres acentuados contam por 2, todos viram 'numeros negativos' 
    int qtdAcentos2 = 0;

    //printf("Q4: ");

    if (strBusca == NULL) {
      return qtdOcorrencias;
    }

    for (int i = 0; strTexto[i] != '\0'; i++) {
      if (strTexto[i] < 0) {
        qtdAcentos2++;
      }
      for (int j = 0; 1; j++) {
        if (strBusca[j] == '\0') {
          posicoes[qtdOcorrencias*2] = i + 1 - (qtdAcentos2 / 2);
          posicoes[(qtdOcorrencias*2)+1] = i + j - (qtdAcentos2 / 2);
          //printf("|%i|[%i]", posicoes[qtdOcorrencias*2], posicoes[(qtdOcorrencias*2)+1]);
          qtdOcorrencias += 1;
          break;
        } else if (strTexto[i + j] != strBusca[j]) {
          break;
        }
      }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
    //printf("Q5: ");
    int qtdDigitos = 1;
    for (int numcpy = num; numcpy > 0; qtdDigitos = qtdDigitos*10, numcpy = numcpy/10) {}
    
    int numInv = 0;
    for (int i = 1; i < qtdDigitos; i = i*10) {
        numInv += ((num/i) % 10) * (qtdDigitos / i/10);
    }
    
    return numInv;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
    int qtdOcorrencias = 0;

    // 10 elevado a quantidade de digitos no numero da busca
    int qtdDigitosBusca = 1;
    for (int numcpy = numerobusca; numcpy > 0; qtdDigitosBusca = qtdDigitosBusca*10, numcpy = numcpy/10) {}

    // 10 elevado a quantidade de digitos no numero base
    int qtdDigitosBase = 1;
    for (int numcpy = numerobase; numcpy > 0; qtdDigitosBase = qtdDigitosBase*10, numcpy = numcpy/10) {}
    
    // Caso a busca seja igual a 0
    if (qtdDigitosBusca == 1) {
        qtdDigitosBusca = 10;
    }
    
    //printf("qtdDigitosBase: %i \nqtdDigitosBusca: %i\n", qtdDigitosBase, qtdDigitosBusca);
    
    // Multipliquei por 10 o digitobase pois o loop estava repentindo um a menos que o necessário
    for (int i = 1; i < qtdDigitosBase*10/qtdDigitosBusca; i = i*10) {
        if (((numerobase/i) % qtdDigitosBusca) == numerobusca) {
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
    int achou = 0;
    // Meio estranho que palavra[] não tem a sentinela '\0'
    int qtdLinha = 8;
    int qtdColuna = 10;
    int tamPalavra = 5;

    // Verificar horizontal e vertical
    // Diagonal = combinacao de horizontal e vertical
    // Exemplo: Se eu não puder ir pra cima eu certamente não posso ir diagonalmente pra cima também.

    // i = linha ; j = coluna
    for (int i = 0; i < qtdLinha; i++) {
      for (int j = 0; j < qtdColuna; j++) {
        if (matriz[i][j] == palavra[0]) {
          // Coloquei -1 no tamanho da palavra pois estou comparando com um indice
          int praCima = (i >= tamPalavra - 1)? 1 : 0; 
          // Não coloquei o -1 aqui pois estou comparando com o proprio tamanho
          int praBaixo = (qtdLinha - i >= tamPalavra)? 1 : 0;
          int praEsq = (j >= tamPalavra - 1)? 1 : 0;
          int praDir = (qtdColuna - j >= tamPalavra)? 1 : 0;
          //printf("\n[%i;%i]{%i|%i|%i|%i} ", i, j, praCima, praBaixo, praEsq, praDir);
          for (int vertical = -praCima; vertical <= praBaixo; vertical++) {
            for (int horizontal = -praEsq; horizontal <= praDir; horizontal++) {
              if (vertical == 0 && horizontal == 0) {
                continue;
              }
              for (int k = 1; matriz[i + (k*vertical)][j + (k*horizontal)] == palavra[k]; k++) {
                if (k + 1 == tamPalavra) {
                  achou = 1;
                  goto pararProcura; // usar break não sairia dos loops aninhados
                }
              }
            } 
          }
        }
      }
    }
    pararProcura:

    return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
