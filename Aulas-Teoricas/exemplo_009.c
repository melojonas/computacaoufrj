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

#define OK													0

int
main (int argc, char *argv[]) 
/* main (int argc, char **argv) */ 
{
  int numero;

  numero = atoi (argv [1]);

  if ((numero % 2) == 0)
		printf ("\nNumero eh par\n");
  else
		printf ("\nNumero eh impar\n");

	return OK;
}

/* $RCSfile$ */
