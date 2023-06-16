/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2023/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Jonas da Silva Melo
 * 
 * Descricao: <descrição sucinta dos objetivos do programa>
 * 
 * $Author: jonas.melo $
 * $Date: 2023/06/14 00:37:42 $
 * $Log: aula0502.c,v $
 * Revision 1.1  2023/06/14 00:37:42  jonas.melo
 * Initial revision
 *
 *
 */

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>

#include "aula0501.h"
#include "aula01.h"

#define NUMERO_ARGUMENTOS   3
#define EOS                 '\0'

int main (int argc, char *argv[])
{
    unsigned short linhas, colunas, linha, coluna;
    char *validacao;

    linhas = (unsigned short) strtol (argv[1], &validacao, 10);

    /*testar <linhas> */
    if (*argv[1] == EOS)
    {
        printf (TEXT_RED "Argumento <linhas> invalido.\n");
        exit (digitoInvalido);
    }

    if (linhas == 0 || linhas > NUMERO_MAXIMO_LINHAS)
    {
        printf (TEXT_RED "Número de <linhas> inválido.\n");
        exit (argumentoInvalido);
    }

    colunas = (unsigned short) strtol (argv[2], &validacao, 10);

    /*testar <colunas> */
    if (*argv[2] == EOS)
    {
        printf (TEXT_RED "Argumento <colunas> invalido.\n");
        exit (digitoInvalido);
    }

    if (colunas == 0 || colunas > NUMERO_MAXIMO_COLUNAS)
    {
        printf (TEXT_RED "Número de <colunas> inválido.\n");
        exit (argumentoInvalido);
    }

    if (argc != (NUMERO_ARGUMENTOS + linhas * colunas))
    {
        printf (TEXT_RED "Número de argumentos inválido: %d.\n", argc);
        exit (numeroArgumentosInvalido);
    }

    long double matriz [linhas] [colunas];

    for (linha = 0; linha < linhas; linha++){
        for (coluna = 0; coluna < colunas; coluna++){
            matriz [linha] [coluna] = strtold (argv [linha * colunas + coluna + NUMERO_ARGUMENTOS], &validacao);

            if (*validacao != EOS)
            {
                printf (TEXT_RED "Argumento '%s' inválido.\n", argv [linha * colunas + coluna + NUMERO_ARGUMENTOS]);
                exit (digitoInvalido);
            }
        }
    }

    ExibirMatriz (linhas, colunas, matriz);

    return ok;
}

/* $RCSfile: aula0502.c,v $ */