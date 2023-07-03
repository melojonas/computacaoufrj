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

#define OK													0
#define NUMERO_ARGUMENTOS_INVALIDO	1

#define NUMERO_ARGUMENTOS						1
#define COMPRIMENTO_MAXIMO_NOME			6

int
main (int argc, char **argv) 
{
	char nome [COMPRIMENTO_MAXIMO_NOME + 1 + 1]; /* \n \0 */

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  do
  {
		printf ("Entre com um nome: ");
    fgets (nome, COMPRIMENTO_MAXIMO_NOME + 2, stdin);
    if (nome [strlen (nome) - 1] == '\n')
			nome [strlen (nome) - 1] = '\0';
		else
		{
			printf ("Comprimento do nome eh invalido\n");
			fpurge (stdin);			
		}
    if (strcmp (nome, "FIM"))
			printf ("Nome lido: \"%s\"\n", nome);
  }
  while (strcmp (nome, "FIM") != 0);

	return OK;
}

/* $RCSfile$ */
