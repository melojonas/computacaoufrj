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
#include <time.h>

#define OK										0

int
main (int argc, char **argv) 
{
	unsigned indice;
  unsigned semente;

  semente = (unsigned) time (NULL);
	srand (semente);

	for (indice = 0; indice < 23; indice++)
		printf ("%u - %i\n", indice + 1, rand () % 11);

	return OK;
}

/* $RCSfile$ */
