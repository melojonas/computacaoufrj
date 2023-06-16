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
 * $Date: 2023/06/14 00:37:42 $
 * $Log: aula0501.h,v $
 * Revision 1.1  2023/06/14 00:37:42  jonas.melo
 * Initial revision
 *
 *
 */

#ifndef AULA0501
#define AULA0501 "@(#)aula0501.h $Revision: 1.1 $"

typedef enum {
    ok,
    numeroArgumentosInvalido,
    digitoInvalido,
    argumentoInvalido,
    dimensaoMatrizesInvalido
    } tipoErros;

#define NUMERO_MAXIMO_LINHAS    100
#define NUMERO_MAXIMO_COLUNAS   100

tipoErros
ExibirMatriz (  unsigned short, /* numero de linhas da matriz (E) */
                unsigned short, /* numero de colunas da matriz 1 (E) */
                long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]); /* matriz (E) */

tipoErros
MultiplicarMatrizes (   unsigned short, /* numero de linhas da matriz 1 (E) */
                        unsigned short, /* numero de colunas da matriz 1 (E) */ 
                        unsigned short, /* numero de linhas da matriz 2 (E) */ 
                        unsigned short, /* numero de colunas da matriz 2 (E) */
                        long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz 1 (E) */
                        long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz 2 (E) */
                        long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]); /* matriz produto (S) */


tipoErros
CalcularMenorComplementar ( unsigned short, /* ordem da matriz (E) */ 
                            unsigned short, /* linha do elemento (E) */
                            unsigned short, /* coluna do elemento (E) */
                            long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz (E) */
                            long double *); /* menor complementar (S) */

tipoErros
CalcularComplementoAlgebrico (  unsigned short, /* ordem da matriz (E) */
                                unsigned short, /* linha do elemento (E) */
                                unsigned short, /* coluna do elemento (E) */
                                long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],/* matriz (E) */
                                long double *); /* complemento algebrico (S) */

tipoErros
CalcularDeterminanteMatriz (unsigned short, /* ordem da matriz (E) */
                            long double [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* matriz (E) */
                            long double *); /* determinante (S) */

#endif

/* $RCSfile: aula0501.h,v $ */