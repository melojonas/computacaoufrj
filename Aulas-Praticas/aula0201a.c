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
 * $Date: 2023/05/04 13:17:08 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2023/05/04 13:17:08  jonas.melo
 * Initial revision
 *
 *
 */

#include "aula0201.h"

/* Função recursiva para calcular o termo da série de Fibonacci */
unsigned long long
CalcularTermoSerieFibonacci (unsigned short termo) {
    unsigned long long f1, f2, f3;
    
    if (termo == 0)
        return 0;
    if (termo == 1)
        return 1;
    
    f1 = CalcularTermoSerieFibonacci (termo - 2);
    f2 = CalcularTermoSerieFibonacci (termo - 1);
    f3 = f1 + f2;

    if (f3 < f1 || f3 < f2){
        return 4;
    }
    
    return f3;
}

/* $RCSfile: aula0201a.c,v $ */