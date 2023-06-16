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
 * $Date: 2023/05/11 01:01:17 $
 * $Log: aula0301b.c,v $
 * Revision 1.1  2023/05/11 01:01:17  jonas.melo
 * Initial revision
 *
 *
 */

#include "aula0301.h"

ull CalcularMaximoDivisorComum(ull x, ull y)
{
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0)
        return y;
    else if (y == 0)
        return x;
    else
    {
        ull z;
        do
        {
            z = x % y;
            x = y;
            y = z;
        } while (z != 0);
        
        return x;
    }
}

/* $RCSfile: aula0301b.c,v $ */