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

#define NUMERO_ARGUMENTOS							1

#define OK														0
#define NUMERO_ARGUMENTOS_INVALIDO		1

void
TrocarValores (int, int);

void
TrocarValores (int primeiroNumero, int segundoNumero)
{
  int auxiliar;

  #ifdef DEBUG
	printf ("\n\nComeco da funcao\n");
	printf ("&primeiroNumero: %p\n", &primeiroNumero);
	printf ("primeiroNumero: %i\n", primeiroNumero);
	printf ("&segundoNumero: %p\n", &segundoNumero);
	printf ("segundoNumero: %i\n", segundoNumero);
	printf ("&auxiliar: %p\n", &auxiliar);
	printf ("auxiliar: %i\n", auxiliar);
  #endif

  auxiliar = primeiroNumero;
  primeiroNumero = segundoNumero;
  segundoNumero = auxiliar;

  #ifdef DEBUG
  printf ("\n\nDepois da troca\n");
	printf ("&primeiroNumero: %p\n", &primeiroNumero);
	printf ("primeiroNumero: %i\n", primeiroNumero);
	printf ("&segundoNumero: %p\n", &segundoNumero);
	printf ("segundoNumero: %i\n", segundoNumero);
	printf ("&auxiliar: %p\n", &auxiliar);
	printf ("auxiliar: %i\n", auxiliar);
  #endif

}

int
main (int argc, char **argv)
{
	
  int numeroA, numeroB;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  #ifdef DEBUG
	printf ("\n\nComeco da main\n");
	printf ("&numeroA: %p\n", &numeroA);
	printf ("numeroA: %i\n", numeroA);
	printf ("&numeroB: %p\n", &numeroB);
	printf ("numeroB: %i\n", numeroB);
  #endif

  numeroA = 100;
  numeroB = 200;

  #ifdef DEBUG
	printf ("\n\nAntes da funcao\n");
	printf ("&numeroA: %p\n", &numeroA);
	printf ("&numeroB: %p\n", &numeroB);
  #endif

	printf ("numeroA: %i\n", numeroA);
	printf ("numeroB: %i\n", numeroB);

  TrocarValores (numeroA, numeroB);

  #ifdef DEBUG
	printf ("\n\nDepois da funcao\n");
	printf ("&numeroA: %p\n", &numeroA);
	printf ("&numeroB: %p\n", &numeroB);
  #endif

	printf ("numeroA: %i\n", numeroA);
	printf ("numeroB: %i\n", numeroB);

	return OK;
}

/* $RCSfile$ */

