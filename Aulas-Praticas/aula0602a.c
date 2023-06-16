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

#include "aula0601.h"
#include "aula01.h"

#define NUMERO_ARGUMENTOS   COMPRIMENTO_RG + 1
#define EOS                 '\0'

int main (int argc, char *argv[])
{
    byte *rg[COMPRIMENTO_RG + 1];
    unsigned indice;
    tipoErros codigoRetorno;

    if (argc != NUMERO_ARGUMENTOS)
    {
        printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8>\n", argv[0]);
        exit (numeroArgumentosInvalido);
    }

    for (indice = 1; indice < argc; indice++)
    {
        if (argv[indice][0] < '0' || argv[indice][0] > '9')
        {
            printf ("Argumento #%u invalido\n", indice);
            exit (digitoInvalido);
        }

        rg[indice - 1] = (byte) (argv[indice][0] - '0');
    }

    codigoRetorno = GerarDigitosVerificadoresRg (&rg);

    if (codigoRetorno == ok)
    {
        printf ("RG: %u%u.%u%u%u.%u%u%u-%c\n", 
                rg[0], rg[1], rg[2], rg[3], rg[4], rg[5], rg[6], rg[7],
                rg[8] == 88 ? 'X' : rg[8]);
    }

    return ok;
}

/* $RCSfile: aula0502.c,v $ */