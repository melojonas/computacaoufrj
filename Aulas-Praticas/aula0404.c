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
 * $Log: aula0404.c,v $
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
#include <errno.h>
#include <math.h>
#include "aula0401.h"
#include "aula01.h"

#define OK                                  0
#define NUMERO_ARGUMENTOS_INVALIDO          1
#define ARGUMENTO_INVALIDO                  2
#define DIGITO_INVALIDO                     4
#define ARGUMENTO_FORA_INTERVALO            5

#define NUMERO_ARGUMENTOS                   2
#define EOS                                 '\0'

int main(int argc, char *argv[])
{
    float percentual;
    float resultado_anterior = -1;
    unsigned short int n = 0;
    char *validacao;

    if (argc != 2)
    {
        printf(TEXT_RED "Formato esperado: %s <percentual>%s\n", argv[0], RESET);
        return NUMERO_ARGUMENTOS_INVALIDO;
    }

    percentual = strtof(argv[1], &validacao);

    if (*validacao != EOS)
    {
        printf(TEXT_RED "Primeiro argumento inválido: %c%s\n", *validacao, RESET);
        return ARGUMENTO_INVALIDO;
    }

    if (EINVAL == errno)
    {
        printf(TEXT_RED "Digito inválido: %c%s\n", *validacao, RESET);
        return DIGITO_INVALIDO;
    }

    if (percentual <= 0 || percentual >= 1)
    {
        printf(TEXT_RED "O percentual deve um valor ser entre 0 e 1.%s\n", RESET);
        return ARGUMENTO_FORA_INTERVALO;
    }

    while (1)
    {
        float resultado_atual = CalcularSerieHarmonicaAlternada(n);
        float diferenca = fabsf(resultado_atual - resultado_anterior);

        if (n % 2 == 0)
            printf(BG_WHITE TEXT_BLACK);
        else
            printf(BG_BLACK TEXT_WHITE);

        printf("S(%d): %.10f%s\n", n, resultado_atual, RESET);

        if (diferenca <= (percentual * resultado_anterior))
            break;

        resultado_anterior = resultado_atual;
        n++;
    }

    return OK;
}

/* $RCSfile: aula0404.c,v $ */