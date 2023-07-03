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
#define COMPRIMENTO_MAXIMO_SENHA		128

int
main (int argc, char **argv) 
{
	char senha [COMPRIMENTO_MAXIMO_SENHA + 1];
	char confirmacao [COMPRIMENTO_MAXIMO_SENHA + 1];
  char *auxiliar;

  auxiliar = getpass ("Senha: ");
  strcpy (senha, auxiliar);
  memset (auxiliar, 0x00, COMPRIMENTO_MAXIMO_SENHA + 1);
  printf ("Senha: \"%s\"\n", senha);
  auxiliar = getpass ("Senha: ");
  strcpy (confirmacao, auxiliar);
  memset (auxiliar, 0x00, COMPRIMENTO_MAXIMO_SENHA + 1);
  printf ("Senha: \"%s\"\n", senha);
  printf ("Confirmacao: \"%s\"\n", confirmacao);

	return OK;
}

/* $RCSfile$ */
