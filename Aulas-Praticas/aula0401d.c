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
 * $Log: aula0401d.c,v $
 * Revision 1.1  2023/05/26 02:26:10  jonas.melo
 * Initial revision
 *
 *
 */

#include "aula0401.h"

/* Implementação da função CalcularExponencial usando a estrutura while */
long double CalcularExponencial(double base, int expoente)
{
    long double resultado = 1;

    if (expoente == 0)
        return 1;
    else if (expoente < 0)
        return 1 / CalcularExponencial(base, -expoente);
    
    while (expoente > 0)
    {
        resultado *= base;
        expoente--;
    }
    
    return resultado;
}

/* $RCSfile: aula0401d.c,v $ */