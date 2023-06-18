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

#define NUMERO_ARGUMENTOS   2
#define EOS                 '\0'

int main (int argc, char *argv[])
{
    char rg[13];
    unsigned indice;
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

    for (indice = 0; indice < 12; indice++)
    {
        if (indice == 2 || indice == 6)
        {
            if (argv[1][indice] != '.')
            {
                printf ("Argumento #%u inválido\n", indice);
                exit (digitoInvalido);
            }
            
            rg[indice] = (char) argv[1][indice];
            continue;
        }

        if (indice == 10)
        {
            if (argv[1][indice] != '-')
            {
                printf ("Argumento #%u inválido\n", indice);
                exit (digitoInvalido);
            }

            rg[indice] = (char) argv[1][indice];
            continue;
        }

        if (indice == 11)
        {
            if (argv[1][indice] == 'X' || argv[1][indice] == 'x')
            {
                rg[indice] = 10;
                continue;
            }
        }

        if (argv[1][indice] < '0' || argv[1][indice] > '9')
        {
            printf ("Argumento #%u invalido\n", indice);
            exit (digitoInvalido);
        }

        rg[indice] = (char) (argv[1][indice] - '0');
    }

    codigoRetorno = ValidarRg (rg);

    if (codigoRetorno == ok)
    {
        printf ("RG: ");

        for (indice = 0; indice < 12; indice++)
        {
            if (indice == 2 || indice == 6 || indice == 10)
            {
                printf ("%c", rg[indice]);
                continue;
            }

            if (indice == 11)
            {
                if (rg[indice] == 10)
                {
                    printf ("X");
                    continue;
                }
            }
    
            printf ("%d", rg[indice]);
        }
        
        printf (" - valido\n");
    }

    if (codigoRetorno == digitoVerificadorInvalido)
    {
        printf ("RG: ");

        for (indice = 0; indice < 12; indice++)
        {
            if (indice == 2 || indice == 6 || indice == 10)
            {
                printf ("%c", rg[indice]);
                continue;
            }

            if (indice == 11)
            {
                if (rg[indice] == 10)
                {
                    printf ("X");
                    continue;
                }
            }
    
            printf ("%d", rg[indice]);
        }
        
        printf (" - invalido\n");
    }

    return ok;
}

/* $RCSfile: aula0502.c,v $ */