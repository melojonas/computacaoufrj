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

#define OK													0

int
main (int argc, char *argv[]) 
/* main (int argc, char **argv) */ 
{
  unsigned indice;

  printf ("\nNumero de argumentos: %i\n", argc);
	for (indice = 0; indice < argc; indice++)  
    printf ("ARG(#%03u): \"%s\"\n", indice, argv [indice]);

	printf ("\n\n");

	return OK;
}

/* $RCSfile$ */
