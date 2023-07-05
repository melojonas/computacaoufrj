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
        return argumentoInvalido; /* código de erro para argumentos inválidos */
    }

    static const char tabelaBase16[] = "0123456789ABCDEF";
    unsigned long long i, j;

    for (i = 0, j = 0; i < numBytes; i++) {
        unsigned char byteAtual = dados[i];

        /* Obter os dois caracteres correspondentes ao byte atual */
        unsigned char nibbleAlto = (byteAtual >> 4) & 0x0F;
        unsigned char nibbleBaixo = byteAtual & 0x0F;

        stringCodificada[j++] = tabelaBase16[nibbleAlto];
        stringCodificada[j++] = tabelaBase16[nibbleBaixo];
    }

    stringCodificada[j] = '\0'; /* Adicionar o terminador de string */

    return ok; /* retornar código de sucesso */
}

tipoErros DecodificarBase16(char *stringCodificada, byte *dados, unsigned long long *numBytes) {

    if (stringCodificada == NULL || dados == NULL || numBytes == NULL) {
        return argumentoInvalido; /* código de erro para argumentos inválidos */
    }

    static const char tabelaBase16[] = "0123456789ABCDEF";
    unsigned long long i, j;

    for (i = 0, j = 0; stringCodificada[i] != '\0'; i += 2) {
        unsigned char caractereAlto = stringCodificada[i];
        unsigned char caractereBaixo = stringCodificada[i + 1];

        /* Obter os nibbles correspondentes aos caracteres atuais */
        unsigned char nibbleAlto = strchr(tabelaBase16, caractereAlto) - tabelaBase16;
        unsigned char nibbleBaixo = strchr(tabelaBase16, caractereBaixo) - tabelaBase16;

        dados[j++] = (nibbleAlto << 4) | nibbleBaixo;
    }

    *numBytes = j; /* Armazenar o número de bytes decodificados */

    return ok; /* retornar código de sucesso */
}

static const char alfabetoBase32Basico[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
static const char alfabetoBase32Estendido[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";


tipoErros CodificarBase32(byte *dados, unsigned long long numBytes, tipoAlfabetoBase32 alfabeto, char *stringCodificada) {
    if (dados == NULL || stringCodificada == NULL) {
        return argumentoInvalido; /* código de erro para argumentos inválidos */
    }

    const char *alfabetoBase32 = (alfabeto == basico) ? alfabetoBase32Basico : alfabetoBase32Estendido;
    unsigned long long i, j;

    for (i = 0, j = 0; i < numBytes; i += 5) {
        unsigned char byteAtual = dados[i];
        unsigned char byteProximo = (i + 1 < numBytes) ? dados[i + 1] : 0;

        /* Obter os caracteres correspondentes ao primeiro e segundo quinteto */
        unsigned char caractere1 = (byteAtual >> 3) & 0x1F;
        unsigned char caractere2 = ((byteAtual << 2) & 0x1c) | ((byteProximo >> 6) & 0x03);

        stringCodificada[j++] = alfabetoBase32[caractere1];
        stringCodificada[j++] = alfabetoBase32[caractere2];

        if (i + 1 < numBytes) {
            byteAtual = dados[i + 1];
            byteProximo = (i + 2 < numBytes) ? dados[i + 2] : 0;

            /* Obter os caracteres correspondentes ao terceiro e quarto quinteto */
            caractere1 = (byteAtual >> 1) & 0x1F;
            caractere2 = ((byteAtual << 4) & 0x1F) | ((byteProximo >> 4) & 0x0f);

            stringCodificada[j++] = alfabetoBase32[caractere1];
            stringCodificada[j++] = alfabetoBase32[caractere2];

            if (i + 2 < numBytes) {
                byteAtual = dados[i + 2];
                byteProximo = (i + 3 < numBytes) ? dados[i + 3] : 0;

                /* Obter os caracteres correspondentes ao quinto e sexto quinteto */
                caractere1 = ((byteAtual << 1) & 0x1F) | (byteProximo >> 7);
                caractere2 = (byteProximo >> 2) & 0x1F;

                stringCodificada[j++] = alfabetoBase32[caractere1];
                stringCodificada[j++] = alfabetoBase32[caractere2];

                if (i + 3 < numBytes) {
                    byteAtual = dados[i + 3];
                    byteProximo = (i + 4 < numBytes) ? dados[i + 4] : 0;

                    /* Obter os caracteres correspondentes sétimo e oitavo */
                    caractere1 = ((byteAtual << 3) & 0x1F) | ((byteProximo >> 5) & 0x07);
                    caractere2 = byteProximo & 0x1F;

                    stringCodificada[j++] = alfabetoBase32[caractere1];
                    stringCodificada[j++] = alfabetoBase32[caractere2];
                }
            }
        }
    }

    stringCodificada[j] = '\0'; /* Adicionar o caractere nulo de terminação */

    return ok; /* retornar código de sucesso */
}



/* $RCSfile$ */