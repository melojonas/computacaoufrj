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

#ifndef AULA0901
#define AULA0901 "@(#)aula0901.h $Revision$"

typedef enum {
    ok,
    argumentoInvalido,
    comprimentoInvalido,
    memoriaInsuficiente,
    erroArquivoOriginal,
    erroArquivoConvertido,
    erroCriarArquivoTemporario,
    erroRenomearOriginal,
    erroRenomearConvertido
    } tipoErros;

tipoErros
ExibirConteudoArquivo (char * /* (E) */);

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos ( char *, /* original */
                                            char * /* convertido */);


#endif

/* $RCSfile$ */