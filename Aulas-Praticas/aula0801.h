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

#ifndef AULA0801
#define AULA0801 "@(#)aula0801.h $Revision$"

typedef unsigned char byte;
typedef enum {
    ok,
    argumentoInvalido
    } tipoErros;

tipoErros
CodificarBase16 (byte * /* (E) */,
                unsigned long long /* (E) */,
                char * /* (S) */);

#endif

/* $RCSfile$ */