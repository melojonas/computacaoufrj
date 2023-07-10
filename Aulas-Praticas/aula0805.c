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

void exibirBytesDecodificados(byte *dadosDecodificados, ull numBytes) {
    ull i;
    
    printf(TEXT_BOLD TEXT_BLACK ">>>> %s", RESET);
    for (i = 0; i < numBytes; i++) {
        printf(TEXT_GREEN "%02X ", dadosDecodificados[i]);
    }
    printf(RESET "\n");
}

void exibirErro(char *mensagemErro) {
    printf(TEXT_RED "%s%s\n", mensagemErro, RESET);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        exibirErro("Número incorreto de argumentos!\n");
        exit(comprimentoInvalido);
    }

    tipoAlfabetoBase32 alfabeto;
    if (strcmp(argv[1], "0") == 0) {
        alfabeto = basico;
    } else if (strcmp(argv[1], "1") == 0) {
        alfabeto = estendido;
    } else {
        exibirErro("Argumento de alfabeto inválido!\n");
        exit(argumentoInvalido);
    }

    char *stringCodificada = argv[2];
    ull tamanhoStringCodificada = strlen(stringCodificada);
    ull numBytesDecodificados = (tamanhoStringCodificada * 5) / 8;
    byte *dadosDecodificados = (byte *)malloc((tamanhoStringCodificada + 1) * sizeof(byte));

    if (dadosDecodificados == NULL) {
        exibirErro("Erro ao alocar memória!\n");
        exit(memoriaInsuficiente);
    }

    tipoErros resultadoDecodificacao = DecodificarBase32(stringCodificada, alfabeto, dadosDecodificados, &numBytesDecodificados);

    if (resultadoDecodificacao != ok) {
        if (resultadoDecodificacao == entradaInvalida) {
            exibirErro("String codificada inválida!\n");
        } else {
            exibirErro("Erro ao decodificar Base32!\n");
        }
        free(dadosDecodificados);
        exit(falhaDecodificacao);
    }

    exibirBytesDecodificados(dadosDecodificados, numBytesDecodificados);

    free(dadosDecodificados);

    return ok;
}


/* $RCSfile$ */