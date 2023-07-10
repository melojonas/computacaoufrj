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
#include <ctype.h>
#include "aula0801.h"
#include "aula01.h"

tipoErros CodificarBase16(byte *dados, ull numBytes, char *stringCodificada) {

    if (dados == NULL || stringCodificada == NULL) {
        return argumentoInvalido; /* código de erro para argumentos inválidos */
    }

    static const char tabelaBase16[] = "0123456789ABCDEF";
    ull i, j;

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

tipoErros DecodificarBase16(char *stringCodificada, byte *dados, ull *numBytes) {

    if (stringCodificada == NULL || dados == NULL || numBytes == NULL) {
        return argumentoInvalido; /* código de erro para argumentos inválidos */
    }

    static const char tabelaBase16[] = "0123456789ABCDEF";
    ull i, j;

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

tipoErros CodificarBase32(byte *dados, ull numBytes, tipoAlfabetoBase32 alfabeto, char *stringCodificada) {
    if (dados == NULL || stringCodificada == NULL) {
        return argumentoInvalido; /* código de erro para argumentos inválidos */
    }

    const char *alfabetoBase32 = (alfabeto == basico) ? alfabetoBase32Basico : alfabetoBase32Estendido;
    ull i, j;

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

/* Implementação do código-fonte da função DecodificarBase32 */
tipoErros DecodificarBase32(char *stringCodificada, tipoAlfabetoBase32 alfabeto, byte *dadosDecodificados, ull *numBytes) {
    if (stringCodificada == NULL || dadosDecodificados == NULL || numBytes == NULL) {
        exit(argumentoInvalido); /* código de erro para argumentos inválidos */
    }
    if (alfabeto != basico && alfabeto != estendido) {
        exit(argumentoInvalido); /* código de erro para argumentos inválidos */
    }

    const char *alfabetoBase32;
    ull numCaracteresEntrada = strlen(stringCodificada);
    ull numCaracteresSaida = (numCaracteresEntrada * 5) / 8;
    byte *dados = (byte *)malloc((numCaracteresSaida + 1) * sizeof(byte));

    if (alfabeto == basico) {
        alfabetoBase32 = alfabetoBase32Basico;
    } else {
        alfabetoBase32 = alfabetoBase32Estendido;
    }

    if (numCaracteresSaida == 0) {
        free(dados);
        exit(entradaInvalida); /* código de erro para entrada inválida */
    }

    ull i;
    for (i = 0; i < (numCaracteresEntrada / 8); i++) {

        ull j = i * 5;
        ull k = i * 8;

        dados[0]= strchr(alfabetoBase32, stringCodificada[k]) - alfabetoBase32;
        dados[1] = strchr(alfabetoBase32, stringCodificada[k + 1]) - alfabetoBase32;
        dados[2] = strchr(alfabetoBase32, stringCodificada[k + 2]) - alfabetoBase32;
        dados[3] = strchr(alfabetoBase32, stringCodificada[k + 3]) - alfabetoBase32;
        dados[4] = strchr(alfabetoBase32, stringCodificada[k + 4]) - alfabetoBase32;
        dados[5] = strchr(alfabetoBase32, stringCodificada[k + 5]) - alfabetoBase32;
        dados[6] = strchr(alfabetoBase32, stringCodificada[k + 6]) - alfabetoBase32;
        dados[7] = strchr(alfabetoBase32, stringCodificada[k + 7]) - alfabetoBase32;

        dadosDecodificados[j] = dados[0] << 3 | (dados[1] >> 2 & 0x07);
        dadosDecodificados[j+1] = (dados[1] & 0x03) << 6 | (dados[2] << 1) | (dados[3] >> 4 & 0x01);
        dadosDecodificados[j+2] = (dados[3] & 0x0F) << 4 | (dados[4] >> 1 & 0x0F);
        dadosDecodificados[j+3] = ((dados[4] & 0x01) << 7) | (dados[5] << 2) | (dados[6] >> 3 & 0x03);
        dadosDecodificados[j+4] = ((dados[6] & 0x07) << 5) | dados[7];  
    }

    *numBytes = numCaracteresSaida;

    free(dados);
    return ok; /* retornar código de sucesso */
}

static const char alfabetoBase64Padrao[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char alfabetoBase64Seguro[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
static const int MAX_CARACTERES_LINHA = 76;

/* Implementação do código-fonte da função CodificarBase64 */
tipoErros CodificarBase64(byte *dados, ull numBytes, tipoFinalLinha tipoFinal, tipoAlfabeto64 alfabeto, char *stringCodificada) {
    if (dados == NULL || stringCodificada == NULL) {
        printf(TEXT_RED "Variáveis nulas\n");
        exit(argumentoInvalido);
    }
    if (alfabeto != padrao && alfabeto != seguro) {
        printf(TEXT_RED "Alfabeto inválido\n");
        exit(argumentoInvalido);
    }
    if (tipoFinal != desabilitado && tipoFinal != habilitado) {
        printf(TEXT_RED "Tipo de final de linha inválido\n");
        exit(argumentoInvalido);
    }

    const char *alfabetoBase64 = (alfabeto == padrao) ? alfabetoBase64Padrao : alfabetoBase64Seguro;

    ull numTriplas = (numBytes + 2) / 3;
    ull tamanhoSaida = numTriplas * 4;
    ull i, j;

    if (tipoFinal == habilitado) {
        ull numLinhas = (tamanhoSaida + MAX_CARACTERES_LINHA - 1) / MAX_CARACTERES_LINHA;
        tamanhoSaida += numLinhas * 2; /* Dois caracteres de final de linha ('\r\n') por linha */
    }

    char *temp = (char *) malloc(tamanhoSaida + 1); /* +1 para o caractere nulo de término de string */
    if (temp == NULL) {
        printf(TEXT_RED "Erro ao alocar memória em temp\n");
        exit(memoriaInsuficiente);
    }

    for (i = 0, j = 0; i < numBytes; i += 3, j += 4) {
        byte byteAtual = dados[i];
        byte byteProximo = (i + 1 < numBytes) ? dados[i + 1] : 0;
        byte bytePosterior = (i + 2 < numBytes) ? dados[i + 2] : 0;

        /* Obter os caracteres correspondentes ao primeiro sexteto */
        temp[j] = alfabetoBase64[byteAtual >> 2];

        /* Obter os caracteres correspondentes ao segundo sexteto */
        temp[j + 1] = alfabetoBase64[((byteAtual & 0x03) << 4) | (byteProximo >> 4)];

        /* Obter os caracteres correspondentes ao terceiro sexteto */
        temp[j + 2] = (byteProximo != 0) ? alfabetoBase64[((byteProximo & 0x0F) << 2) | (bytePosterior >> 6)] : '=';

        /* Obter os caracteres correspondentes ao quarto sexteto */
        temp[j + 3] = (bytePosterior != 0) ? alfabetoBase64[bytePosterior & 0x3F] : '=';
    }

    if (tipoFinal == habilitado) {
        size_t tamanhoTemp = strlen(temp);
        size_t numLinhas = (tamanhoTemp + MAX_CARACTERES_LINHA - 1) / MAX_CARACTERES_LINHA;
        size_t tamanhoSaidaComLinhas = tamanhoTemp + numLinhas * 2; /* Dois caracteres de final de linha ('\r\n') por linha */

        strcpy(stringCodificada, temp);

        size_t posicao = MAX_CARACTERES_LINHA;
        while (posicao < tamanhoSaidaComLinhas) {
            memmove(&stringCodificada[posicao + 2], &stringCodificada[posicao], tamanhoSaida - posicao);
            stringCodificada[posicao] = '\r';
            stringCodificada[posicao + 1] = '\n';
            posicao += MAX_CARACTERES_LINHA + 2;
        }
    } else {
        strcpy(stringCodificada, temp);
    }

    return ok; /* retornar código de sucesso */
}

/* Implementação do código-fonte da função DecodificarBase64 */
tipoErros DecodificarBase64(char *stringCodificada, tipoFinalLinha tipoLinha, tipoAlfabeto64 alfabeto, byte *dadosDecodificados, ull *numBytes) {
    if (stringCodificada == NULL || dadosDecodificados == NULL || numBytes == NULL) {
        printf(TEXT_RED "Variáveis nulas\n");
        exit(argumentoInvalido);
    }
    if (alfabeto != padrao && alfabeto != seguro) {
        printf(TEXT_RED "Alfabeto inválido\n");
        exit(argumentoInvalido);
    }
    if (tipoLinha != desabilitado && tipoLinha != habilitado) {
        printf(TEXT_RED "Tipo de final de linha inválido\n");
        exit(argumentoInvalido);
    }

    const char *alfabetoBase64 = (alfabeto == padrao) ? alfabetoBase64Padrao : alfabetoBase64Seguro;

    ull tamanhoEntrada = strlen(stringCodificada);
    ull tamanhoSaida = tamanhoEntrada * 3 / 4;
    ull i, j;

    if (tipoLinha == habilitado) {
        ull numLinhas = tamanhoEntrada / 78;
        tamanhoSaida -= numLinhas * 2; /* Dois caracteres de final de linha ('\r\n') por linha */
    }

    byte *dados = (byte *) malloc(tamanhoSaida);
    if (dados == NULL) {
        printf(TEXT_RED "Erro ao alocar memória em dados\n");
        exit(memoriaInsuficiente);
    }

    for (i = 0, j = 0; i < tamanhoEntrada; i += 4, j += 3) {
        char caractereAtual = stringCodificada[i];
        char caractereProximo = stringCodificada[i + 1];
        char caracterePosterior = stringCodificada[i + 2];
        char caractereSeguinte = stringCodificada[i + 3];

        /* Obter o primeiro sexteto */
        byte byteAtual = strchr(alfabetoBase64, caractereAtual) - alfabetoBase64;
        byte byteProximo = strchr(alfabetoBase64, caractereProximo) - alfabetoBase64;

        /* Obter o segundo sexteto */
        byte bytePosterior = (caracterePosterior != '=') ? strchr(alfabetoBase64, caracterePosterior) - alfabetoBase64 : 0;
        byte byteSeguinte = (caractereSeguinte != '=') ? strchr(alfabetoBase64, caractereSeguinte) - alfabetoBase64 : 0;

        /* Obter o primeiro byte */
        dados[j] = (byteAtual << 2) | (byteProximo >> 4);

        /* Obter o segundo byte */
        dados[j + 1] = (bytePosterior != 0) ? ((byteProximo & 0x0F) << 4) | (bytePosterior >> 2) : 0;

        /* Obter o terceiro byte */
        dados[j + 2] = (byteSeguinte != 0) ? ((bytePosterior & 0x03) << 6) | byteSeguinte : 0;
    }

    if (tipoLinha == habilitado) {
        ull tamanhoSaidaSemLinhas = tamanhoSaida;
        ull posicao = MAX_CARACTERES_LINHA;
        while (posicao < tamanhoSaidaSemLinhas) {
            memmove(&dados[posicao - 2], &dados[posicao], tamanhoSaida - posicao);
            posicao += MAX_CARACTERES_LINHA + 2;
        }
        tamanhoSaida = tamanhoSaidaSemLinhas;
    }

    *numBytes = tamanhoSaida;
    memcpy(dadosDecodificados, dados, tamanhoSaida);

    free(dados);
    return ok; /* retornar código de sucesso */
}

/* $RCSfile$ */