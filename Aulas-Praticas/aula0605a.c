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

#include "aula0604.h"

#define NUMERO_ARGUMENTOS   COMPRIMENTO_RG + 1
#define EOS                 '\0'

int main (int argc, char *argv[])
{
    char rg[10];
    char rg_saida[12];
    unsigned indice, contador = 0;
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

        if (contador == 2 || contador == 6)
        {
            rg[contador] = (char) '.';
            contador++;
            indice--;
            continue;
        }

        rg[contador] = (char) argv[indice][0] - '0';
        contador++;
    }

    codigoRetorno = GerarDigitosVerificadoresRg(rg, rg_saida);

    if (codigoRetorno == ok)
    {
        printf ("RG: ");

        for (indice = 0; indice < 12; indice++)
        {
            if (indice == 2 || indice == 6 || indice == 10)
            {
                printf ("%c", rg_saida[indice]);
                continue;
            }

            if (indice == 11)
            {
                if (rg_saida[indice] == 10)
                {
                    printf ("X");
                    continue;
                }
            }
    
            printf ("%d", rg_saida[indice]);
        }

        printf ("\n");
    }

    return ok;
}

/* $RCSfile: aula0502.c,v $ */