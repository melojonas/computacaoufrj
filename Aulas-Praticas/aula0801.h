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
typedef unsigned long long ull;
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
    alfabetoInvalido,
    entradaInvalida,
    finalLinhaInvalido
    } tipoErros;

tipoErros
CodificarBase16 (   byte * /* (E) */,
                    ull /* (E) */,
                    char * /* (S) */);

tipoErros
DecodificarBase16 ( char * /* (E) */,
                    byte * /* (S) */, 
                    ull * /* (S) */);

tipoErros
CodificarBase32 (   byte * /* (E) */,
                    ull /* (E) */,
                    tipoAlfabetoBase32 /* (E) */,
                    char * /* (S) */);

tipoErros
DecodificarBase32 ( char * /* (E) */,
                    tipoAlfabetoBase32 /* (E) */,
                    byte * /* (S) */,
                    ull * /* (S) */);

tipoErros
CodificarBase64 (   byte * /* (E) */,
                    ull /* (E) */,
                    tipoFinalLinha /* (E) */,
                    tipoAlfabeto64 /* (E) */,
                    char * /* (S) */);

tipoErros
DecodificarBase64 ( char * /* (E) */,
                    tipoFinalLinha /* (E) */,
                    tipoAlfabeto64 /* (E) */,
                    byte * /* (S) */,
                    ull * /* (S) */);

#endif

/* $RCSfile$ */