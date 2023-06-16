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
 * $Date: 2023/05/04 13:19:03 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2023/05/04 13:19:03  jonas.melo
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "aula01.h"
#include "aula0201.h"

#define OK								0
#define NUMERO_ARGUMENTOS_INVALIDO		1
#define ARGUMENTO_INVALIDO				2

#define NUMERO_ARGUMENTOS				2
#define END_OF_STRING					'\0'

int main(int argc, char *argv[]) {
    unsigned short limite;
    char *validacao;

    #ifdef _MY_DEBUG_
        printf ("\nValidacao: %p\n", validacao);
    #endif

    /* validação da entrada do CLI */
    if (argc != NUMERO_ARGUMENTOS) {
        printf(BG_WHITE TEXT_RED "Erro: uso incorreto. Use: %s <inteiro>\n" RESET, argv[0]);
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    limite = strtoul(argv[1], &validacao, 10);

    #ifdef _MY_DEBUG_
        printf ("\nargv: %p", argv [1]);
        printf ("Validacao: %p\n\n", validacao);
    #endif

    if (*validacao != END_OF_STRING) {
        printf(BG_WHITE TEXT_RED "Erro: o argumento \"%s\" não é um número inteiro válido.\n" RESET, argv[1]);
        exit (ARGUMENTO_INVALIDO);
    }

    /* impressão dos termos da série de Fibonacci até o limite definido */
    int i;
    for (i = 0; i <= limite; i++) {
        unsigned long long fibonacci = CalcularTermoSerieFibonacci(i);
        if (fibonacci == 4) {
            printf(BG_WHITE TEXT_RED "F (%d) ultrapassa o limite superior permitido para o tipo \033[1;3munsigned long long.%s\n", i, RESET);
            break;
        }

        printf(BG_WHITE TEXT_BLACK "F (%d) = %llu" RESET, i, fibonacci);
        printf("\n");
    }

    return OK;
}

/* $RCSfile: aula0202.c,v $ */