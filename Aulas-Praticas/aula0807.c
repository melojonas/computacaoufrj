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
#include "aula01.h"

void imprimirMensagemErro(tipoErros erro) {
    printf(TEXT_RED);
    switch (erro) {
        case argumentoInvalido:
            printf("Argumento inválido.");
            break;
        case comprimentoInvalido:
            printf("Comprimento inválido.");
            break;
        case numBytesInvalido:
            printf("Número de bytes inválido.");
            break;
        case memoriaInsuficiente:
            printf("Memória insuficiente.");
            break;
        case valorByteInvalido:
            printf("Valor de byte inválido.");
            break;
        case falhaCodificacao:
            printf("Falha na codificação.");
            break;
        case hexadecimalInvalido:
            printf("Hexadecimal inválido.");
            break;
        case falhaDecodificacao:
            printf("Falha na decodificação.");
            break;
        case alfabetoInvalido:
            printf("Alfabeto inválido.");
            break;
        case entradaInvalida:
            printf("Entrada inválida.");
            break;
        case finalLinhaInvalido:
            printf("Indicador de final de linha inválido.");
            break;
        default:
            printf("Erro desconhecido.");
            break;
    }
    printf(RESET "\n");
}

void imprimirBytesHex(byte *bytes, ull numBytes) {
    ull i;
    
    printf(TEXT_BOLD TEXT_BLACK ">>>> %s", RESET);
    for (i = 0; i < numBytes; i++) {
        printf(TEXT_GREEN "%02X ", bytes[i]);
    }
    printf(RESET "\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        imprimirMensagemErro(argumentoInvalido);
        return 0;
    }

    tipoFinalLinha finalLinha = atoi(argv[1]);
    tipoAlfabeto64 alfabeto = atoi(argv[2]);
    char *entrada = argv[3];

    byte *saida = (byte *) malloc(strlen(entrada) * 3 / 4);
    if (saida == NULL) {
        imprimirMensagemErro(memoriaInsuficiente);
        return 0;
    }

    ull numBytes;
    tipoErros resultado = DecodificarBase64(entrada, finalLinha, alfabeto, saida, &numBytes);
    if (resultado != ok) {
        imprimirMensagemErro(resultado);
        free(saida);
        return 0;
    }

    imprimirBytesHex(saida, numBytes);

    free(saida);

    return 0;
}

/* $RCSfile$ */