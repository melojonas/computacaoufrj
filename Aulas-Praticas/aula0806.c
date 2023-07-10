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
#include <stdbool.h>

#include "aula0801.h"
#include "aula01.h"

#define EOS '\0'
#define NUMERO_ARGUMENTOS_MINIMO 4

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
    if (argc < NUMERO_ARGUMENTOS_MINIMO) {
        exibirErro("Número insuficiente de argumentos.");
        return comprimentoInvalido;
    }

    char *validacao, *stringCodificada;
    tipoAlfabeto64 alfabeto;
    tipoFinalLinha finalLinha;
    tipoErros retornoCodificacao;
    byte *dados;
    unsigned opcaoAlfabeto;
    unsigned opcaoFinalLinha;
    unsigned char valorByte;
    unsigned long long numBytes, i;

    opcaoFinalLinha = strtoul(argv[1], &validacao, 10);
    if (*validacao != '\0') {
        exibirErro("Argumento inválido para final de linha.");
        return argumentoInvalido;
    }
    if (opcaoFinalLinha == 0)
        finalLinha = desabilitado;
    else if (opcaoFinalLinha == 1)
        finalLinha = habilitado;
    else {
        exibirErro("Opção inválida para final de linha.");
        return finalLinhaInvalido;
    }

    opcaoAlfabeto = strtoul(argv[2], &validacao, 10);
    if (*validacao != '\0') {
        exibirErro("Argumento inválido para o alfabeto.");
        return argumentoInvalido;
    }
    if (opcaoAlfabeto == 0)
        alfabeto = basico;
    else if (opcaoAlfabeto == 1)
        alfabeto = estendido;
    else {
        exibirErro("Opção inválida para o alfabeto.");
        return alfabetoInvalido;
    }

    numBytes = strtoull(argv[3], &validacao, 10);
    if (*validacao != '\0') {
        exibirErro("Argumento inválido para número de bytes.");
        return argumentoInvalido;
    }
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
        valorByte = (unsigned char)strtol(argv[i + 4], &validacao, 16);
        if (*validacao != EOS) {
            exibirErro("Argumento inválido para byte. Esperado valor hexadecimal.");
            free(dados);
            return argumentoInvalido;
        }
        dados[i] = valorByte;
    }

    stringCodificada = (char *)malloc((numBytes * 4 / 3 + 4) * sizeof(char));
    if (stringCodificada == NULL) {
        exibirErro("Falha ao alocar memória.");
        free(dados);
        return memoriaInsuficiente;
    }
    
    retornoCodificacao = CodificarBase64(dados, numBytes, finalLinha, alfabeto, stringCodificada);
    if (retornoCodificacao != ok) {
        exibirErro("Erro ao codificar em Base32.");
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