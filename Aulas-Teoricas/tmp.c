
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

#include "exemplo_028.h"

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
  tipoCodigosRetorno codigoRetorno;

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
	dre [0] = 240;
  codigoRetorno = ValidarDre (dre);

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

  /*
  if (codigoRetorno == dreValido)
    printf ("\nDRE invalido.\n\n");
	else
		if (codigoRetorno == argumentoInvalido)
			printf ("\nArgumento passado por referencia nao pode ser igual a NULL.\n\n");
		else
			if (codigoRetorno == digitoInvalido)
			  printf ("\nArgumento contem caractere invalido.\n\n");
			else
			  printf ("\nDRE invalido.\n\n");
	*/
	
  /*
  if (codigoRetorno == dreValido)
    printf ("\nDRE invalido.\n\n");
  else if (codigoRetorno == argumentoInvalido)
		printf ("\nArgumento passado por referencia nao pode ser igual a NULL.\n\n");
  else if (codigoRetorno == digitoInvalido)
	  printf ("\nArgumento contem caractere invalido.\n\n");
	else
	  printf ("\nDRE invalido.\n\n");
  */

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
