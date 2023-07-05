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
 * 
 */

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "aula0801.h"
#include "aula01.h"

#define NUMERO_ARGUMENTOS   3
#define EOS                 '\0'

/* Função para exibir a string codificada no formato especificado */
void exibirStringCodificada(char *stringCodificada) {
    printf(TEXT_BOLD TEXT_BLACK ">>>>> %s", RESET);
    printf(TEXT_GREEN "%s%s\n", stringCodificada, RESET);
}

/* Função para exibir mensagem de erro em vermelho */
void exibirErro(char *mensagemErro) {
    printf(TEXT_RED "%s%s\n", mensagemErro, RESET);
}

int main(int argc, char *argv[]) {
    
    unsigned i;
    char *validacao, *stringCodificada;
    tipoErros retornoCodificacao;
    byte *dados;
    
    if (argc < NUMERO_ARGUMENTOS) {
        exibirErro("Número insuficiente de argumentos.");
        return comprimentoInvalido;
    }

    unsigned long long numBytes = strtoull(argv[1], NULL, 10);
    if (numBytes == 0) {
        exibirErro("Número inválido de bytes.");
        return numBytesInvalido;
    }

    dados = (byte *)malloc(numBytes * sizeof(byte));
    if (dados == NULL) {
        exibirErro("Falha ao alocar memória.");
        return memoriaInsuficiente;
    }

    for (i = 0; i < numBytes; i++) {
        unsigned long valorByte = strtoul(argv[i + 2], &validacao, 10);
        if (*validacao != EOS || valorByte > 255) {
            exibirErro("Valor inválido de byte.");
            free(dados);
            return valorByteInvalido;
        }
        dados[i] = (byte)valorByte;
    }

    stringCodificada = (char *)malloc((2 * numBytes + 1) * sizeof(char));
    if (stringCodificada == NULL) {
        exibirErro("Falha ao alocar memória.");
        free(dados);
        return 1;
    }

    retornoCodificacao = CodificarBase16(dados, numBytes, stringCodificada);
    
    if (retornoCodificacao != ok) {
        exibirErro("Erro ao codificar em Base16.");
        free(dados);
        free(stringCodificada);
        return falhaCodificacao;
    }

    exibirStringCodificada(stringCodificada);

    free(dados);
    free(stringCodificada);
    return ok;
}

/* $RCSfile$ */