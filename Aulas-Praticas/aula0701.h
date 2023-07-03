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

#ifndef AULA0701
#define AULA0701 "@(#)aula0701.h $Revision$"

#include <sys/types.h>

#define APAGADO ' '
#define ACESO ' '
#define DEFEITUOSO '.'
#define NUMERO_MAXIMO_LINHAS 250
#define NUMERO_MAXIMO_COLUNAS 800

typedef enum {
    apagado = 0,
    aceso = 1,
    defeituoso = -1
} tipoPixel;

typedef enum {
    sucesso = 0
} tipoErros;

tipoErros MostrarMonitor(useconds_t tempoEspera, /* E */
                         tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E */
                         unsigned numeroMaximoLinhas, /* E */
                         unsigned numeroMaximoColunas, /* E */
                         char *corPixelApagado, /* E */
                         char *corPixelAceso /* E */);

#endif

/* $RCSfile$ */