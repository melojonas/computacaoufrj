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

#define NUMERO_MINIMO_ARGUMENTOS		2

size_t 
ObterComprimentoString (char *);

size_t 
ObterComprimentoString (char *string)
{
	size_t comprimento = 0;

  if (string == NULL)
		return -1;

	#ifdef INDEXACAO

  while (string [comprimento] != '\0')
    comprimento++;

  #else 

	char *auxiliar;

  auxiliar = string;
  while (*auxiliar != '\0')
    auxiliar++;

  comprimento = auxiliar - string; 

  #endif

  return comprimento;
}


int
main (int argc, char **argv) 
{
	unsigned indice;

	if (argc < NUMERO_MINIMO_ARGUMENTOS)
	{
		printf ("Uso: %s <string1> [... <stringN>]\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	for (indice = 1; indice < argc; indice++)
		printf ("\"%s\": %lu caracteres\n", 
            argv [indice],
						ObterComprimentoString (argv [indice]));

	return OK;
}
