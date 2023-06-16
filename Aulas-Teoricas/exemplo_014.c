/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2023/1
 *
 * Descricao:
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#define OK															0
#define NUMERO_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_NEGATIVO							2
#define ARGUMENTO_INVALIDO							3
#define DIGITO_INVALIDO									4
#define LIMITE_SUPERIOR_ULONG_EXCEDIDO	5
#define LIMITE_SUPERIOR_USHRT_EXCEDIDO	6

#define NUMERO_ARGUMENTOS						2
#define END_OF_STRING								'\0'

unsigned long long
CalcularFatorial (unsigned short);

unsigned long long
CalcularFatorial (unsigned short numero)
{
	unsigned long long resultado = 1;

	if (numero <= 1)
		return resultado;

  do
  {
		resultado *= numero; /* resultado = resultado * numero; */
    numero--;
  }
  while (numero > 1);
  return resultado;

}

int
main (int argc, char *argv[]) 
/* main (int argc, char **argv) */ 
{
  unsigned short numero;
	unsigned long auxiliar;
  char *validacao;

  #ifdef _MY_DEBUG_
  printf ("\nValidacao: %p\n", validacao);
  #endif

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("\nNumero de argumentos incorreto.\n");
		printf ("Uso: %s <inteiro>\n\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
  }
  
  if (argv [1][0] == '-')
  {
		printf ("\nArgumento negativo\n");
		exit (ARGUMENTO_NEGATIVO);
  }

  auxiliar = strtoul (argv [1], &validacao, 10);

	if (*validacao != END_OF_STRING)
  {
		printf ("\nArgumento contem caractere invalido: %c.\n", 
            *validacao);
		exit (ARGUMENTO_INVALIDO);
  }

  #ifdef _MY_DEBUG_
	printf ("\nargv: %p", argv [1]);
  printf ("Validacao: %p\n\n", validacao);
  #endif

	if (errno == EINVAL)
  {
		printf ("\nDigito invalido\n");
		exit (DIGITO_INVALIDO);
  }
				
	if (errno == ERANGE)
  {
		printf ("\nValor eh maior do que o limite permitido para unsigned long: %lu\n",
            ULONG_MAX);
		exit (LIMITE_SUPERIOR_ULONG_EXCEDIDO);
  }

	if (auxiliar > USHRT_MAX)
  {
		printf ("\nValor eh maior do que o limite permitido para unsigned short: %hu\n",
            USHRT_MAX);
		exit (LIMITE_SUPERIOR_USHRT_EXCEDIDO);
  }

  numero = (unsigned short) auxiliar;

  printf ("%s!: %llu\n", argv [1], CalcularFatorial (numero));
	return OK;
}

/* $RCSfile$ */
