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
 * $Date: 2023/05/04 15:06:57 $
 * $Log: aula0103.c,v $
 * Revision 1.2  2023/05/04 15:06:57  jonas.melo
 * bug fixed
 *
 * Revision 1.1  2023/04/27 10:27:52  jonas.melo
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

    printf(TEXT_UNDERLINE "Tamanhos dos Modificadores de Sinal combinados com Modificadores de Largura" RESET "\n\n");

    TypeSize("signed short:", sizeof(signed short));
    TypeSize("signed int:", sizeof(signed int));
    TypeSize("signed long:", sizeof(signed long));
    TypeSize("signed long long:", sizeof(signed long long));
    TypeSize("unsigned short:", sizeof(unsigned short));
    TypeSize("unsigned int:", sizeof(unsigned int));
    TypeSize("unsigned long:", sizeof(unsigned long));
    TypeSize("unsigned long long:", sizeof(unsigned long long));

    DashedLine();
    printf(TEXT_UNDERLINE "Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal" RESET "\n\n");

    TypeSize("signed char:", sizeof(signed char));
    TypeSize("unsigned char:", sizeof(unsigned char));
    TypeSize("signed int:", sizeof(signed int));
    TypeSize("unsigned int:", sizeof(unsigned int));

    DashedLine();
    printf(TEXT_UNDERLINE "Tamanhos dos Tipos Basicos combinados com Modificadores de Largura" RESET "\n\n");

    TypeSize("short int:", sizeof(short int));
    TypeSize("long int:", sizeof(long int));
    TypeSize("long long int:", sizeof(long long int));
    TypeSize("long double:", sizeof(long double));

    DashedLine();
    printf(TEXT_UNDERLINE "Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal e com Modificadores de Largura" RESET "\n\n");

    TypeSize("signed short int:", sizeof(signed short int));
    TypeSize("signed long int:", sizeof(signed long int));
    TypeSize("signed long long int:", sizeof(signed long long int));
    TypeSize("unsigned short int:", sizeof(unsigned short int));
    TypeSize("unsigned long int:", sizeof(unsigned long int));
    TypeSize("unsigned long long int:", sizeof(unsigned long long int));

    DashedLine();

    return 0;

}

void TypeSize(const char* type_name, size_t size) {
    printf("%s%-23s%s %*s%s%lu %s%s\n", 
           TEXT_BLUE, type_name, RESET, 68, "", 
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

/* $RCSfile: aula0103.c,v $ */
