/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2022/2
 *
 * Descricao:
 *
 * $Author: marcelo.lanza $
 * $Date: 2022/10/10 12:38:56 $
 * $Log: exemplo_023.c,v $
 * Revision 1.1  2022/10/10 12:38:56  marcelo.lanza
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define NUMERO_ARGUMENTOS							1

#define OK														0
#define NUMERO_ARGUMENTOS_INVALIDO		1

typedef unsigned char byte;

int
main (int argc, char **argv)
{
	
  byte indice;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  for (indice = 0; indice < 255; indice++)
		if ((indice >= 32) && (indice <= 126))
		  printf ("%02X %03d %c\n", indice, indice, indice);
	  else
      printf ("%02X %03d\n", indice, indice);
	printf ("%02X %03d\n", indice, indice);

	return OK;
}

/* $RCSfile: exemplo_023.c,v $ */

