
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

#define SUCESSO											0
#define NUMERO_ARGUMENTOS_INVALIDO	1

#define NUMERO_ARGUMENTOS						1

#define EOS													'\0'

int 
main (int argc, char *argv [])
{
  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  printf ("Tamanho do char: %lu byte\n", (long unsigned) sizeof (char));

  return SUCESSO;
  
}

/* $RCSfile: exemplo_019.c,v $ */
