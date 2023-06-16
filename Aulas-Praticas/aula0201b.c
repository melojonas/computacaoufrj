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
 * $Log: aula0201b.c,v $
 * Revision 1.1  2023/05/04 13:17:08  jonas.melo
 * Initial revision
 *
 *
 */

#include "aula0201.h"

/* função para calcular o e-nésimo termo da série de Fibonacci usando do...while */
unsigned long long CalcularTermoSerieFibonacci(unsigned short numero) {
    unsigned long long f1 = 0, f2 = 1, f3;
    unsigned short i = 1;

    while (i < numero) {
        f3 = f1 + f2;

        if (f3 < f1 || f3 < f2) {
            return 4;
        }

        f1 = f2;
        f2 = f3;
        i++;
    }

    return f2;
}

/* $RCSfile: aula0201b.c,v $ */