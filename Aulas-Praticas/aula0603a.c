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

#define NUMERO_ARGUMENTOS   2
#define EOS                 '\0'

int main (int argc, char *argv[])
{
    byte rg[COMPRIMENTO_RG + 2];
    unsigned indice_argv, indice_rg = 0;
    tipoErros codigoRetorno;

    if (argc != NUMERO_ARGUMENTOS)
    {
        printf ("Uso: %s <12.345.678-9>\n", argv[0]);
        exit (numeroArgumentosInvalido);
    }

    if (strlen(argv[1]) != (COMPRIMENTO_RG + 4))
    {
        printf ("Comprimento do argumento deve ser %u\n", COMPRIMENTO_RG + 2);
        exit (comprimentoRgInvalido);
    }

    for (indice_argv = 0; indice_argv < 12; indice_argv++)
    {
        if (indice_argv == 2 || indice_argv == 6)
        {
            if (argv[1][indice_argv] != '.')
            {
                printf ("Argumento #%u inválido\n", indice_argv);
                exit (digitoInvalido);
            }
            continue;
        }

        if (indice_argv == 10)
        {
            if (argv[1][indice_argv] != '-')
            {
                printf ("Argumento #%u inválido\n", indice_argv);
                exit (digitoInvalido);
            }
            continue;
        }

        if (argv[1][indice_argv] < '0' || argv[1][indice_argv] > '9')
        {
            printf ("Argumento #%u invalido\n", indice_argv);
            exit (digitoInvalido);
        }

        rg[indice_rg] = (byte) (argv[1][indice_argv] - '0');
        indice_rg++;
    }

    codigoRetorno = ValidarRg (rg);

    if (codigoRetorno == ok)
    {
        printf ("RG: %u%u.%u%u%u.%u%u%u-", 
                rg[0], rg[1], rg[2], rg[3], rg[4], rg[5], rg[6], rg[7]);
        if (rg[8] == 10)
            printf("X - valido\n");
        else
            printf("%u - valido\n", rg[8]);
    }

    if (codigoRetorno == digitoVerificadorInvalido)
    {
        printf ("RG: %u%u.%u%u%u.%u%u%u-", 
                rg[0], rg[1], rg[2], rg[3], rg[4], rg[5], rg[6], rg[7]);
        if (rg[8] == 10)
            printf("X - invalido\n");
        else
            printf("%u - invalido\n", rg[8]);
    }

    return ok;
}

/* $RCSfile: aula0502.c,v $ */