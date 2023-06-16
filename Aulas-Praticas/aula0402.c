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
 * $Date: 2023/05/26 02:26:10 $
 * $Log: aula0402.c,v $
 * Revision 1.1  2023/05/26 02:26:10  jonas.melo
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
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include "aula0401.h"
#include "aula01.h"

#define OK                                  0
#define NUMERO_ARGUMENTOS_INVALIDO          1
#define ARGUMENTO_INVALIDO                  2
#define DIGITO_INVALIDO                     4
#define LIMITE_DOUBLE_EXCEDIDO              5
#define LIMITE_INT_EXCEDIDO                 6

#define NUMERO_ARGUMENTOS                   3
#define EOS                                 '\0'

int main(int argc, char *argv[])
{
    double base;
    int expoente;
    long double resultado;
    char *validacao;

    if (argc != 3)
    {
        printf(TEXT_RED "Formato esperado: <real> <inteiro>%s\n", RESET);
        return NUMERO_ARGUMENTOS_INVALIDO;
    }

    base = strtod(argv[1], &validacao);

    if (*validacao != EOS)
    {
        printf(TEXT_RED "Primeiro argumento inválido: %c%s\n", *validacao, RESET);
        return ARGUMENTO_INVALIDO;
    }

    if (EINVAL == errno)
    {
        printf(TEXT_RED "Digito inválido no primeiro argumento: %c%s\n", *validacao, RESET);
        return DIGITO_INVALIDO;
    }

    if (ERANGE == errno)
    {
        printf(TEXT_RED "A base excede o limite permitido para double: %f e %f.%s\n", DBL_MAX, DBL_MIN, RESET);
        return LIMITE_DOUBLE_EXCEDIDO;
    }

    expoente = strtol(argv[2], &validacao, 10);

    if (*validacao != EOS)
    {
        printf(TEXT_RED "Segundo argumento inválido: %c%s\n", *validacao, RESET);
        return ARGUMENTO_INVALIDO;
    }

    if (EINVAL == errno)
    {
        printf(TEXT_RED "Digito inválido no segundo argumento: %c%s\n", *validacao, RESET);
        return DIGITO_INVALIDO;
    }

    if (ERANGE == errno)
    {
        printf(TEXT_RED "O expoente excede o limite permitido para int: +-%d%s\n", INT_MAX, RESET);
        return LIMITE_INT_EXCEDIDO;
    }

    resultado = CalcularExponencial(base, expoente);

    printf(BG_BLUE TEXT_YELLOW "%.1f ^ %d: %s", base, expoente, RESET);
    printf(TEXT_RED "%Lf%s\n", resultado, RESET);

    return 0;
}

/* $RCSfile: aula0402.c,v $ */