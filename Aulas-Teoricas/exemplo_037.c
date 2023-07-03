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

#ifdef __FreeBSD__
#include <pwd.h>
#endif
#include <unistd.h>

#define OK										0

int
main (int argc, char **argv) 
{
	char *senha, *confirmacao;

  senha = getpass ("Senha: ");
  printf ("Senha: \"%s\"\n", senha);
  confirmacao = getpass ("Confirmacao: ");
  printf ("Senha: \"%s\"\n", senha);
  printf ("Confirmacao: \"%s\"\n", confirmacao);

	return OK;
}

/* $RCSfile$ */
