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

#ifdef __FreeBSD__
#include <pwd.h>
#endif
#include <unistd.h>

#define OK													0
#define NUMERO_ARGUMENTOS_INVALIDO	1

#define NUMERO_ARGUMENTOS						2
#define COMPRIMENTO_MAXIMO_SENHA		128

int
main (int argc, char **argv) 
{
	char senha [COMPRIMENTO_MAXIMO_SENHA + 1];
	char confirmacao [COMPRIMENTO_MAXIMO_SENHA + 1];
  char *auxiliar;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <salt>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  auxiliar = getpass ("Senha: ");
  strcpy (senha, auxiliar);
  memset (auxiliar, 0x00, COMPRIMENTO_MAXIMO_SENHA + 1);
  auxiliar = getpass ("Confirmacao: ");
  strcpy (confirmacao, auxiliar);
  memset (auxiliar, 0x00, COMPRIMENTO_MAXIMO_SENHA + 1);

  if (strcmp (senha, confirmacao) != 0)
	{
		printf ("Senhas sao diferentes\n"); 
		exit (OK);
	}

  printf ("Senha plana: \"%s\"\n", senha);
  printf ("Salt: \"%s\"\n", argv [1]);
	printf ("Senha codificada: \"%s\"\n", crypt (senha, argv [1]));

	return OK;
}

/* $RCSfile$ */
