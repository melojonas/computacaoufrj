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
 * $Author$
 * $Date$
 * $Log$
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

#include "aula0601.h"
#include "aula01.h"

#define NUMERO_ARGUMENTOS   2
#define EOS                 '\0'

int main (int argc, char *argv[])
{
    byte rg[COMPRIMENTO_RG + 2];
    unsigned indice;
    tipoErros codigoRetorno;

    if (argc != NUMERO_ARGUMENTOS)
    {
        printf ("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
        exit (numeroArgumentosInvalido);
    }

    if (strlen(argv[1]) != (COMPRIMENTO_RG + 2))
    {
        printf ("Comprimento do argumento deve ser %u\n", COMPRIMENTO_RG + 2);
        exit (comprimentoRgInvalido);
    }

    for (indice = 0; indice < strlen(argv[1]); indice++)
    {
        if (indice == 2 || indice == 6)
        {
            if (argv[1][indice] != '.')
            {
                printf ("Argumento #%u inválido\n", indice);
                exit (digitoInvalido);
            }
            continue;
        }

        if (argv[1][indice] < '0' || argv[1][indice] > '9')
        {
            printf ("Argumento #%u invalido\n", indice);
            exit (digitoInvalido);
        }

        rg[indice] = (argv[1][indice] - '0');
    }

    codigoRetorno = GerarDigitosVerificadoresRg (rg);

    if (codigoRetorno == ok)
    {
        printf ("RG: %u%u.%u%u%u.%u%u%u-", 
                rg[0], rg[1], rg[2], rg[3], rg[4], rg[5], rg[6], rg[7]);
        if (rg[8] == 88)
            printf("X\n");
        else
            printf("%u\n", rg[8]);
    }

    return ok;
}

/* $RCSfile: aula0502.c,v $ */