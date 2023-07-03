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
#define COMPRIMENTO_MAXIMO_NOME_EXCEDIDO		5
#define ERRO_LENDO_DRE											6
#define ARQUIVO_CORROMPIDO									7

#define NUMERO_ARGUMENTOS										3
#define COMPRIMENTO_MAXIMO_NOME							50
#define COMPRIMENTO_DRE											9

typedef enum {falso, verdadeiro} boolean;

int
main (int argc, char **argv) 
{
  FILE *leitura, *escrita;
  char nome [COMPRIMENTO_MAXIMO_NOME + 2];
  char dre [COMPRIMENTO_DRE + 2];
	boolean ultimaLinhaContemEnter;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <arquivo-texto> <arquivo-binario>\n", argv [0]);
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

	ultimaLinhaContemEnter = verdadeiro;
  while ((fgets (nome, COMPRIMENTO_MAXIMO_NOME + 2, leitura)) != NULL)
	{
		if (nome [strlen (nome) - 1] != '\n')
    {
			printf ("Arquivo corrompido.\n");
			fclose (leitura);
			fclose (escrita);
			remove (argv [2]);
			exit (COMPRIMENTO_MAXIMO_NOME_EXCEDIDO);
    }

		nome [strlen (nome) - 1] = '\0';

		if ((fgets (dre, COMPRIMENTO_DRE + 2, leitura)) == NULL)
    {
			printf ("Arquivo corrompido.\n");
			fclose (leitura);
			fclose (escrita);
			remove (argv [2]);
			exit (ERRO_LENDO_DRE);
    }

		if (dre [strlen (dre) - 1] == '\n')
			dre [strlen (dre) - 1] = '\0';
		else
			ultimaLinhaContemEnter = falso;

		fwrite (nome, strlen (nome) + 1, 1, escrita);
    if (ferror (escrita))
    {
			printf ("Erro escrevendo o arquivo \"%s\"\n", argv [1]);
			fclose (leitura);
			fclose (escrita);
			remove (argv [2]);
			exit (ERRO_ESCREVENDO_ARQUIVO);
		}

		fwrite (dre, strlen (dre), 1, escrita);
    if (ferror (escrita))
    {
			printf ("Erro escrevendo o arquivo \"%s\"\n", argv [1]);
			fclose (leitura);
			fclose (escrita);
			remove (argv [2]);
			exit (ERRO_ESCREVENDO_ARQUIVO);
		}
  }

	if (ultimaLinhaContemEnter == verdadeiro)
	{
		printf ("Erro escrevendo o arquivo \"%s\"\n", argv [1]);
		fclose (leitura);
		fclose (escrita);
		remove (argv [2]);
		exit (ARQUIVO_CORROMPIDO);
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
	return OK;
}

/* $RCSfile$ */
