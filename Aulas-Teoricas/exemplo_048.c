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
#include <errno.h>

#define OK																	0
#define NUMERO_ARGUMENTOS_INVALIDO					1
#define ERRO_ABRINDO_ARQUIVO								2
#define ERRO_LENDO_ARQUIVO									3
#define ERRO_ESCREVENDO_ARQUIVO							4

#define NUMERO_ARGUMENTOS										3
#define COMPRIMENTO_BUFFER									256

typedef unsigned char byte;

int
main (int argc, char **argv) 
{
  FILE *leitura, *escrita;
	byte buffer [COMPRIMENTO_BUFFER];
	size_t lidos;
	size_t escritos = 0;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <arquivo-origem> <arquivo-destino>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  leitura = fopen (argv [1], "r");
  if (leitura == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv [1]);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		exit (ERRO_ABRINDO_ARQUIVO);
	}

	escrita = fopen (argv [2], "w");
	if (escrita == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv [2]);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		fclose (leitura);
		exit (ERRO_ABRINDO_ARQUIVO);
	}

  while ((lidos = fread (buffer, 1, COMPRIMENTO_BUFFER, leitura)) > 0)
	{
		escritos += fwrite (buffer, 1, lidos, escrita);
    if (ferror (escrita))
    {
			printf ("Erro escrevendo o arquivo \"%s\"\n", argv [1]);
			fclose (leitura);
			fclose (escrita);
			exit (ERRO_ESCREVENDO_ARQUIVO);
		}
  }

  if (ferror (leitura))
  {
		printf ("Erro lendo o arquivo \"%s\"\n", argv [1]);
	  fclose (leitura);
	  fclose (escrita);
		exit (ERRO_LENDO_ARQUIVO);
  }

	fclose (leitura);
	fclose (escrita);
	printf ("Foram copiados %li bytes\n", escritos);
	return OK;
}

/* $RCSfile$ */
