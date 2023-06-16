
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

#include "exemplo_030.h"

#define SUCESSO													0
#define NUMERO_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_INVALIDO							2
#define COMPRIMENTO_ARGUMENTO_INVALIDO	3


#define NUMERO_ARGUMENTOS						COMPRIMENTO_DRE + 1

#define EOS													'\0'

int 
main (int argc, char *argv [])
{
  char dre [COMPRIMENTO_DRE + 1];
  unsigned short indice;
  tipoCodigosRetorno codigoRetorno;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <dv>\n\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (indice = 1; indice < argc; ++indice)
  {
    if (strlen (argv [indice]) > 1)
		{
			printf ("\nComprimento do argumento #%u eh invalido.\n\n", indice);
			exit (COMPRIMENTO_ARGUMENTO_INVALIDO);
		}

		dre [indice - 1] = argv [indice][0];

  } /* for */

  /* if (ValidarDre (&(dre [0]) == falso) */
  codigoRetorno = ValidarDre (dre);

	switch (codigoRetorno)
  {
		case dreValido:
			printf ("\nDRE valido.\n\n");
		break;

		case argumentoInvalido:
			printf ("\nArgumento passado por referencia nao pode ser igual a NULL.\n\n");
		break;

		case digitoInvalido:
			printf ("\nArgumento contem caractere invalido.\n\n");
		break;

		case dreInvalido:
			printf ("\nDRE invalido.\n\n");
		break;

		default:
			printf ("\nCodigo de retorno invalido.\n\n");
  }

  codigoRetorno = ValidarDre (NULL);

	switch (codigoRetorno)
  {
		case dreValido:
			printf ("\nDRE invalido.\n\n");
		break;

		case argumentoInvalido:
			printf ("\nArgumento passado por referencia nao pode ser igual a NULL.\n\n");
		break;

		case digitoInvalido:
			printf ("\nArgumento contem caractere invalido.\n\n");
		break;

		case dreInvalido:
			printf ("\nDRE invalido.\n\n");
		break;

		default:
			printf ("\nCodigo de retorno invalido.\n\n");
	}

  return SUCESSO;
  
}

/* $RCSfile: exemplo_019.c,v $ */
