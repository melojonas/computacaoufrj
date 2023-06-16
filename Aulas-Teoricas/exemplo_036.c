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
#include <time.h>

#define OK										0

#define CARACTERES_VALIDOS "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!?@#$%"
int
main (int argc, char **argv) 
{
	unsigned indice;
  unsigned semente;

  semente = (unsigned) time (NULL);
	srand (semente);

	printf ("\nSenha: \"");
	for (indice = 0; indice < 16; indice++)
		printf ("%c", CARACTERES_VALIDOS [rand () % strlen (CARACTERES_VALIDOS)]);
	printf ("\"\n");
	return OK;
}

/* $RCSfile$ */
