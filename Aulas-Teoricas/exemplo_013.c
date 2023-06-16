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

#define OK													0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO					2

#define NUMERO_ARGUMENTOS						2
#define END_OF_STRING								'\0'

int
main (int argc, char *argv[]) 
/* main (int argc, char **argv) */ 
{
  long  numero;
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
  
  numero = strtol (argv [1], &validacao, 10);

  #ifdef _MY_DEBUG_
	printf ("\nargv: %p", argv [1]);
  printf ("Validacao: %p\n\n", validacao);
  #endif

	if (*validacao != END_OF_STRING)
  {
		printf ("\nArgumento contem caractere invalido: %c.\n", 
            *validacao);
		exit (ARGUMENTO_INVALIDO);
  }
				
  if ((numero % 2) == 0)
	  printf ("\nNumero eh par\n");
  else
	  printf ("\nNumero eh impar\n");

	return OK;
}

/* $RCSfile$ */
