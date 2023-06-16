/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2023/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Jonas da Silva Melo
 * 
 * Descricao: <descrição sucinta dos objetivos do programa>
 * 
 * $Author: jonas.melo $
 * $Date: 2023/05/11 01:04:59 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2023/05/11 01:04:59  jonas.melo
 * Initial revision
 *
 *
 */

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "aula0301.h"
#include "aula01.h"

#define OK                                  0
#define NUMERO_ARGUMENTOS_INVALIDO          1
#define ARGUMENTO_NEGATIVO                  2
#define ARGUMENTO_INVALIDO                  3
#define DIGITO_INVALIDO                     4
#define LIMITE_SUPERIOR_ULLONG_EXCEDIDO     5

#define NUMERO_ARGUMENTOS                   3
#define EOS                                 '\0'

int main(int argc, char* argv[])
{
  ull x, y, mdc;
  char* validacao;

  /* Testes iniciais de validação de argumentos */
  if (argc != 3)
  {
    printf(TEXT_RED "Erro: Quantidade de argumentos inválida. O programa requer dois números inteiros não negativos.%s\n", RESET);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  if (argv [1][0] == '-' || argv [2][0] == '-')
  {
    printf (TEXT_RED "Erro: Primeiro argumento negativo.%s\n", RESET);
    exit (ARGUMENTO_NEGATIVO);
  }

  x = strtoull(argv[1], &validacao, 10);

  /* Teste de verificação da primeira conversão*/
  if (*validacao != EOS)
  {
    printf (TEXT_RED "Erro: Primeiro argumento contém caractere inválido: %c.%s\n", 
            *validacao, RESET);
    exit (ARGUMENTO_INVALIDO);
  }

  if (errno == EINVAL)
  {
    printf (TEXT_RED "Erro: Dígito inválido no primeiro argumento.%s\n", RESET);
    exit (DIGITO_INVALIDO);
  }
      
  if (errno == ERANGE)
  {
    printf (TEXT_RED "Erro: Primeiro argumento é maior do que o limite permitido para unsigned long long: %llu.%s\n",
          ULLONG_MAX, RESET);
    exit (LIMITE_SUPERIOR_ULLONG_EXCEDIDO);
  }

  y = strtoull(argv[2], &validacao, 10);

  /* Teste de verificação da segunda conversão*/
  if (*validacao != EOS)
  {
    printf (TEXT_RED "Erro: Segundo argumento contém caractere inválido: %c.%s\n", 
          *validacao, RESET);
    exit (ARGUMENTO_INVALIDO);
  }

  if (errno == EINVAL)
  {
    printf (TEXT_RED "Erro: Digito inválido no segundo argumento.%s\n", RESET);
    exit (DIGITO_INVALIDO);
  }
      
  if (errno == ERANGE)
  {
    printf (TEXT_RED "Erro: Segundo argumento é maior do que o limite permitido para unsigned long long: %llu.%s\n",
          ULLONG_MAX, RESET);
    exit (LIMITE_SUPERIOR_ULLONG_EXCEDIDO);
  }

  mdc = CalcularMaximoDivisorComum(x, y);

  printf(TEXT_GREEN "MDC (%llu, %llu) = %llu\n" RESET, x, y, mdc);

  return OK;
}

/* $RCSfile: aula0302.c,v $ */
