
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
#include <errno.h>
#include <limits.h>

#include "exemplo_025.h"

#define SUCESSO											0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO					2
#define CARACTERE_INVALIDO_BASE			3	
#define LIMITE_ULONG_ULTRAPASSADO		4
#define LIMITE_BYTE_ULTRAPASSADO		5


#define NUMERO_ARGUMENTOS						COMPRIMENTO_DRE + 1

#define EOS													'\0'

int 
main (int argc, char *argv [])
{
  byte dre [COMPRIMENTO_DRE];
  byte indice;
  unsigned long auxiliar;
  char *validacao;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <dv>\n\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (indice = 1; indice < argc; ++indice)
  {
    auxiliar = strtoul (argv [indice], &validacao, 10);
    if (*validacao != EOS)
    {
			printf ("\nArgumento contem caractere invalido: \'%c\'\n\n", *validacao);
			exit (ARGUMENTO_INVALIDO);
    }

    if (errno == EINVAL)
    {
			printf ("\nArgumento contem caractere invalido para a base: \'%c\'\n\n", *validacao);
			exit (CARACTERE_INVALIDO_BASE);
    }

    if (errno == ERANGE)
    {
			printf ("\nArgumento ultrapassa o maximo permitido para unsigned long (%lu)\n\n", ULONG_MAX);
			exit (LIMITE_ULONG_ULTRAPASSADO);
    }

    if (auxiliar > 255)
    {
			printf ("\nArgumento ultrapassa o maximo permitido para byte.\n\n");
			exit (LIMITE_BYTE_ULTRAPASSADO);
    }

    dre [indice - 1] = (byte) auxiliar;
  } /* for */

  /* if (ValidarDre (&(dre [0]) == falso) */
  if (ValidarDre (dre) == falso)
    printf ("\nDRE invalido.\n\n");
  else
    printf ("\nDRE valido.\n\n");

  if (ValidarDre (NULL) == falso)
    printf ("\nDRE invalido.\n\n");
  else
    printf ("\nDRE valido.\n\n");

  return SUCESSO;
  
}

/* $RCSfile: exemplo_019.c,v $ */
