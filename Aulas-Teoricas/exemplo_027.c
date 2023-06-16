
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
#include <string.h>
#include <errno.h>
#include <limits.h>

#include "exemplo_025.h"

#define SUCESSO													0
#define NUMERO_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_INVALIDO							2
#define COMPRIMENTO_ARGUMENTO_INVALIDO	3
/*
#define CARACTERE_INVALIDO_BASE			3	
#define LIMITE_ULONG_ULTRAPASSADO		4
#define LIMITE_BYTE_ULTRAPASSADO		5
*/

#define NUMERO_ARGUMENTOS						2	

#define EOS													'\0'

int 
main (int argc, char *argv [])
{
  byte dre [COMPRIMENTO_DRE];
  byte indice;
  /*
	char auxiliar [2];
  char *validacao;
   */

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1d2d3d4d5d6d7d8dv>\n\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  if (strlen (argv [1]) != COMPRIMENTO_DRE)
  {
		printf ("\nComprimento do argumento deve ser %u\n\n", COMPRIMENTO_DRE);
		exit (COMPRIMENTO_ARGUMENTO_INVALIDO);
  }

  /*  
  auxiliar [1] = EOS;
  */

  for (indice = 0; indice < strlen (argv [1]); ++indice)
  {
    
		if (argv [1][indice] < '0' || argv [1][indice] > '9')
		{
			printf ("\nArgumento contem caractere invalido.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}
    
    dre [indice] = argv [1][indice] - '0';

		/* 
			122052969 
			indice = 0 -> argv [1][0] = '1' -> 49 -> '1' - '0' -> 49 - 48 -> 1
			indice = 1 -> argv [1][1] = '2' -> 50 -> '2' - '0' -> 50 - 48 -> 2 
		*/

		/*
    auxiliar [0] = argv [1][indice];
    dre [indice] = (byte) strtoul (auxiliar, &validacao, 10);

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
		*/

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

/* $RCSfile$ */
