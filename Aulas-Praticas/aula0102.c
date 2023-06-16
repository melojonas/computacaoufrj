/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2023/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Jonas da Silva Melo
 * 
 * Descricao: tamanho dos tipos basicos e modificadores de sinal e largura
 * 
 * $Author: jonas.melo $
 * $Date: 2023/05/04 15:05:49 $
 * $Log: aula0102.c,v $
 * Revision 1.2  2023/05/04 15:05:49  jonas.melo
 * bug fixed
 *
 * Revision 1.1  2023/04/27 09:44:53  jonas.melo
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include "aula01.h"

#define OK 0
#define SCREEN_WIDTH 100

int main() {

    DashedLine();
    printf(TEXT_UNDERLINE "Tamanhos dos Tipos Basicos" RESET "\n\n");

    TypeSize("void:", sizeof(void));
    TypeSize("char:", sizeof(char));
    TypeSize("int:", sizeof(int));
    TypeSize("float:", sizeof(float));
    TypeSize("double:", sizeof(double));

    DashedLine();
    printf(TEXT_UNDERLINE "Tamanhos dos Modificadores de Sinal" RESET "\n\n");

    TypeSize("signed:", sizeof(signed));
    TypeSize("unsigned:", sizeof(unsigned));

    DashedLine();
    printf(TEXT_UNDERLINE "Tamanhos dos Modificadores de Largura" RESET "\n\n");

    TypeSize("short:", sizeof(short));
    TypeSize("long:", sizeof(long));
    TypeSize("long long:", sizeof(long long));

    DashedLine();

    return 0;

}

void TypeSize(const char* type_name, size_t size) {
    printf("%s%-15s%s %*s%s%lu %s%s\n", 
           TEXT_BLUE, type_name, RESET, 76, "", 
           TEXT_YELLOW, size, size==1?"byte":"bytes", RESET);
}

void DashedLine() {
    int i;
    putchar('\n');
    for (i = 0; i < SCREEN_WIDTH; i++) {
        putchar('-');
    }
    putchar('\n');
    putchar('\n');
}

/* $RCSfile: aula0102.c,v $ */
