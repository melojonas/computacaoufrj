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
typedef enum { basico, estendido } tipoAlfabetoBase32;
typedef enum { padrao, seguro } tipoAlfabeto64;
typedef enum { desabilitado, habilitado } tipoFinalLinha;
typedef enum {
    ok,
    argumentoInvalido,
    comprimentoInvalido,
    numBytesInvalido,
    memoriaInsuficiente,
    valorByteInvalido,
    falhaCodificacao,
    hexadecimalInvalido,
    falhaDecodificacao,
    alfabetoInvalido
    } tipoErros;

tipoErros
CodificarBase16 (   byte * /* (E) */,
                    unsigned long long /* (E) */,
                    char * /* (S) */);

tipoErros
DecodificarBase16 ( char * /* (E) */,
                    byte * /* (S) */, 
                    unsigned long long * /* (S) */);

tipoErros
CodificarBase32 (   byte * /* (E) */,
                    unsigned long long /* (E) */,
                    tipoAlfabetoBase32 /* (E) */,
                    char * /* (S) */);

tipoErros
DecodificarBase32 ( char * /* (E) */,
                    tipoAlfabetoBase32 /* (E) */,
                    byte * /* (S) */,
                    unsigned long long * /* (S) */);

tipoErros
CodificarBase64 (   byte * /* (E) */,
                    unsigned long long /* (E) */,
                    tipoFinalLinha /* (E) */,
                    tipoAlfabeto64 /* (E) */,
                    char * /* (S) */);

#endif

/* $RCSfile$ */