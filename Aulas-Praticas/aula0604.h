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

#ifndef AULA0604
#define AULA0604 "@(#)aula0604.h $Revision$"

#define COMPRIMENTO_RG  8

typedef enum {
    ok,
    numeroArgumentosInvalido,
    digitoInvalido,
    argumentoInvalido,
    comprimentoRgInvalido,
    digitoVerificadorInvalido
    } tipoErros;

tipoErros
GerarDigitosVerificadoresRg (char * /* entrada */, char * /* saida */);

tipoErros
ValidarRg (char * /* entrada */);

#endif

/* $RCSfile$ */