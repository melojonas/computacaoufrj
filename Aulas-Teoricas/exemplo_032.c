
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
  tipoCodigosRetorno codigoRetorno;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\nUso: %s <d1d2d3d4d5d6d7d8dv>\n\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  codigoRetorno = ValidarDre (argv [1]);

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

  return SUCESSO;
  
}

/* $RCSfile$ */
