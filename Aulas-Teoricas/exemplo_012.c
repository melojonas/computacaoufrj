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
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ARGUMENTO_INVALIDO					2

#define NUMERO_ARGUMENTOS						2
#define END_OF_STRING								'\0'

int
main (int argc, char *argv[]) 
/* main (int argc, char **argv) */ 
{
  int numero;
  unsigned indice;

  if (argc != NUMERO_ARGUMENTOS)
  {
    printf ("\nNumero de argumentos incorreto.\n");
		printf ("Uso: %s <inteiro>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

  for (indice = 0; 
       argv [1][indice] != END_OF_STRING; 
       indice++)
    if ((argv [1][indice] < '0') ||   /* if ((argv [1][indice] < 48) || */
        (argv [1][indice] > '9'))     /*     (argv [1][indice] > 57))   */
    {
			printf ("\nArgumento contem caractere invalido: %c.\n", 
              argv [1][indice]);
			exit (ARGUMENTO_INVALIDO);
    }
				
  numero = atoi (argv [1]);

  if ((numero % 2) == 0)
	  printf ("\nNumero eh par\n");
  else
	  printf ("\nNumero eh impar\n");

	return OK;
}

/* $RCSfile$ */
