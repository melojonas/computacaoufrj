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

#define OK													0
#define NUMERO_ARGUMENTOS_INVALIDO	1
#define ERRO_ABRINDO_ARQUIVO				2

#define NUMERO_ARGUMENTOS						2
#define COMPRIMENTO_MAXIMO_NOME			50

int
main (int argc, char **argv) 
{
  FILE *arquivo;
	char nome [COMPRIMENTO_MAXIMO_NOME + 1 + 1]; /* \n \0 */
	unsigned linhas = 0;

  if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <arquivo>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

  arquivo = fopen (argv [1], "w");
  if (arquivo == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv [1]);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		exit (ERRO_ABRINDO_ARQUIVO);
	}

  do
  {
		printf ("Entre com um nome: ");
    fgets (nome, COMPRIMENTO_MAXIMO_NOME + 2, stdin);
    if (nome [strlen (nome) - 1] != '\n')
		{
			printf ("Comprimento do nome eh invalido\n");
			fpurge (stdin);			
		}
		else
		{
			nome [strlen (nome) - 1] = '\0';
			if (strcmp (nome, "FIM"))
			{
				if (linhas == 0)
					fprintf (arquivo, "%s", nome);
				else
					fprintf (arquivo, "\n%s", nome);
				linhas++;
			}
		}
  }
  while (strcmp (nome, "FIM") != 0);

	fclose (arquivo);
	printf ("Arquivo criado com sucesso contendo %u linhas\n", linhas);
	return OK;
}

/* $RCSfile$ */
