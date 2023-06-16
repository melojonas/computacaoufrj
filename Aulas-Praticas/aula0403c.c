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
 * $Log: aula0403c.c,v $
 * Revision 1.1  2023/05/26 02:26:10  jonas.melo
 * Initial revision
 *
 *
 */

#include "aula0401.h"

/* Implementação da função CalcularSerieHarmonicaAlternada usando a estrutura for */
float CalcularSerieHarmonicaAlternada(unsigned short int termo)
{
    float resultado = 0;
    int contador;
    
    if (termo == 0)
        return 0;
    else if (termo == 1)
        return 1;

    for (contador = 1; contador <= termo; contador++)
    {
        if (contador % 2 == 0)
            resultado -= 1.0 / contador;
        else
            resultado += 1.0 / contador;
    }
    
    return resultado;
}

/* $RCSfile: aula0403c.c,v $ */