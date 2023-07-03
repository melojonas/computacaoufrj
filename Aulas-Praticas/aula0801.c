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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aula0801.h"

tipoErros CodificarBase16(byte *dados, unsigned long long numBytes, char *stringCodificada) {

    if (dados == NULL || stringCodificada == NULL) {
        return argumentoInvalido; // código de erro para argumentos inválidos
    }

    static const char tabelaBase16[] = "0123456789ABCDEF";
    unsigned long long i, j;

    for (i = 0, j = 0; i < numBytes; i++) {
        unsigned char byteAtual = dados[i];

        // Obter os dois caracteres correspondentes ao byte atual
        unsigned char nibbleAlto = (byteAtual >> 4) & 0x0F;
        unsigned char nibbleBaixo = byteAtual & 0x0F;

        stringCodificada[j++] = tabelaBase16[nibbleAlto];
        stringCodificada[j++] = tabelaBase16[nibbleBaixo];
    }

    stringCodificada[j] = '\0'; // Adicionar o terminador de string

    return 0; // retornar código de sucesso
}


/* $RCSfile$ */