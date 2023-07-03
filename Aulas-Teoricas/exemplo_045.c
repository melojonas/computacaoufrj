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

#define NUMERO_ARGUMENTOS										3
#define COMPRIMENTO_MAXIMO_NOME							50
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO			1024

int
main (int argc, char **argv) 
{
  FILE *leitura, *escrita;
	char nomeArquivoTemporario [COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1];
	char nomeArquivoBackup [COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1];
	char nome [COMPRIMENTO_MAXIMO_NOME + 1 + 1]; /* \n \0 */
	unsigned linhas = 0;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <arquivo> <nome>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  leitura = fopen (argv [1], "r");
  if (leitura == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv [1]);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		exit (ERRO_ABRINDO_ARQUIVO);
	}

	strcpy (nomeArquivoTemporario, argv [1]);
	strcat (nomeArquivoTemporario, ".XXXXXX");
	strcpy (nomeArquivoBackup, argv [1]);
	strcat (nomeArquivoBackup, ".backup");

	#ifdef DEPURACAO
	printf ("Nome temporario: %s\n", nomeArquivoTemporario);
	#endif 	

  mktemp (nomeArquivoTemporario);
	
	#ifdef DEPURACAO
	printf ("Nome temporario: %s\n", nomeArquivoTemporario);
	#endif 	

	escrita = fopen (nomeArquivoTemporario, "w");
	if (escrita == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", nomeArquivoTemporario);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		fclose (leitura);
		exit (ERRO_ABRINDO_ARQUIVO);
	}

  while ((fgets (nome, COMPRIMENTO_MAXIMO_NOME + 2, leitura)) != NULL)
  {
		if (nome [strlen (nome) - 1] == '\n')
			nome [strlen (nome) - 1] = '\0';

		if (strcmp (nome, argv [2]))
    {
			if (linhas == 0)
				fprintf (escrita, "%s", nome);
			else
				fprintf (escrita, "\n%s", nome);
			linhas++;
		}
  }

  if (ferror (leitura))
  {
		printf ("Erro lendo o arquivo \"%s\"\n", argv [1]);
	  fclose (leitura);
	  fclose (escrita);
		remove (nomeArquivoTemporario);
		exit (ERRO_LENDO_ARQUIVO);
  }

	fclose (leitura);
	fclose (escrita);
	printf ("Arquivo criado com sucesso contendo %u linhas\n", linhas);
	rename (argv [1], nomeArquivoBackup);
	rename (nomeArquivoTemporario, argv [1]);
	return OK;
}

/* $RCSfile$ */
