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

#ifndef AULA0601
#define AULA0601 "@(#)aula0601.h $Revision$"

#define COMPRIMENTO_RG  8

typedef unsigned char byte;

typedef enum {
    ok,
    numeroArgumentosInvalido,
    digitoInvalido,
    argumentoInvalido,
    comprimentoRgInvalido
    } tipoErros;

tipoErros
GerarDigitosVerificadoresRg (byte [ ]);

#endif

/* $RCSfile$ */