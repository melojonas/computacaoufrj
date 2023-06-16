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
 * $Log: aula0503.c,v $
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

#define NUMERO_ARGUMENTOS   5
#define EOS                 '\0'

int main(int argc, char *argv[]) {

    unsigned short linhas1, colunas1, linhas2, colunas2;
    unsigned short linha, coluna;
    char *validacao;

    linhas1 = strtol(argv[1], &validacao, 10);
    
    /* Teste de <linhas1> */
    if (*validacao != EOS) {
        printf("Argumento <linhas1> inválido.\n");
        exit(digitoInvalido);
    }

    if (linhas1 < 1 || linhas1 > NUMERO_MAXIMO_LINHAS) {
        printf("Número de <linhas1> inválido.\n");
        exit(argumentoInvalido);
    }

    colunas1 = strtol(argv[2], &validacao, 10);

    /* Teste de <colunas1> */
    if (*validacao != EOS) {
        printf("Argumento <colunas1> inválido.\n");
        exit(digitoInvalido);
    }

    if (colunas1 < 1 || colunas1 > NUMERO_MAXIMO_COLUNAS) {
        printf("Número de <colunas1> inválido.\n");
        exit(argumentoInvalido);
    }

    linhas2 = strtol(argv[3], &validacao, 10);

    /* Teste de <linhas2> */
    if (*validacao != EOS) {
        printf("Argumento <linhas2> inválido.\n");
        exit(digitoInvalido);
    }

    if (linhas2 < 1 || linhas2 > NUMERO_MAXIMO_LINHAS) {
        printf("Número de <linhas2> inválido.\n");
        exit(argumentoInvalido);
    }

    colunas2 = strtol(argv[4], &validacao, 10);

    /* Teste de <colunas2> */
    if (*validacao != EOS) {
        printf("Argumento <colunas2> inválido.\n");
        exit(digitoInvalido);
    }

    if (colunas2 < 1 || colunas2 > NUMERO_MAXIMO_COLUNAS) {
        printf("Número de <colunas2> inválido.\n");
        exit(argumentoInvalido);
    }

    if (argc != (NUMERO_ARGUMENTOS + linhas1 * colunas1 + linhas2 * colunas2)) {
        printf("Número de argumentos inválido: %d.\n", argc);
        exit(numeroArgumentosInvalido);
    }

    long double matriz1[linhas1][colunas1];
    long double matriz2[linhas2][colunas2];
    long double produto[linhas1][colunas2];

    for (linha = 0; linha < linhas1; linha++){
        for (coluna = 0; coluna < colunas1; coluna++){
            matriz1 [linha] [coluna] = strtold (argv [linha * colunas1 + coluna + NUMERO_ARGUMENTOS], &validacao);

            if (*validacao != EOS)
            {
                printf (TEXT_RED "Argumento '%s' inválido.\n", argv [linha * colunas1 + coluna + NUMERO_ARGUMENTOS]);
                exit (digitoInvalido);
            }
        }
    }
    
    for (linha = 0; linha < linhas2; linha++){
        for (coluna = 0; coluna < colunas2; coluna++){
            matriz2 [linha] [coluna] = strtold (argv [linha * colunas2 + coluna + NUMERO_ARGUMENTOS + linhas1 * colunas1], &validacao);

            if (*validacao != EOS)
            {
                printf (TEXT_RED "Argumento '%s' inválido.\n", argv [linha * colunas2 + coluna + NUMERO_ARGUMENTOS + linhas1 * colunas1]);
                exit (digitoInvalido);
            }
        }
    }

    MultiplicarMatrizes(linhas1, colunas1, linhas2, colunas2, matriz1, matriz2, produto);

    /* Exibir matrizes usando a função ExibirMatriz */
    printf("Matriz 1:\n");
    ExibirMatriz(linhas1, colunas1, matriz1);
    printf("\n");

    printf("Matriz 2:\n");
    ExibirMatriz(linhas2, colunas2, matriz2);
    printf("\n");

    printf("Produto:\n");
    ExibirMatriz(linhas1, colunas2, produto);
    printf("\n");

    return ok;
}

/* int main (int argc, char *argv[])
{
    unsigned short linhas, colunas, linha, coluna;
    char *validacao;

    linhas = (unsigned short) strtol (argv[1], &validacao, 10);

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
} */

/* $RCSfile: aula0503.c,v $ */