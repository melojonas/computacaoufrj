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

tipoErros decodificarArquivo(const char *nomeArquivoCodificado, const char *nomeArquivoSaida, tipoAlfabeto64 alfabeto) {
    FILE *arquivoCodificado = fopen(nomeArquivoCodificado, "r");
    if (arquivoCodificado == NULL) {
        return entradaInvalida;
    }

    fseek(arquivoCodificado, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivoCodificado);
    fseek(arquivoCodificado, 0, SEEK_SET);

    if (tamanhoArquivo <= 0) {
        fclose(arquivoCodificado);
        return entradaInvalida;
    }

    char *buffer = (char *) malloc(tamanhoArquivo + 1);
    if (buffer == NULL) {
        fclose(arquivoCodificado);
        return memoriaInsuficiente;
    }

    size_t bytesLidos = fread(buffer, sizeof(char), tamanhoArquivo, arquivoCodificado);
    fclose(arquivoCodificado);

    if (bytesLidos != (size_t) tamanhoArquivo) {
        free(buffer);
        return entradaInvalida;
    }

    buffer[tamanhoArquivo] = '\0';

    tipoFinalLinha finalLinha = desabilitado;

    byte *saida = (byte *) malloc(tamanhoArquivo);
    if (saida == NULL) {
        free(buffer);
        return memoriaInsuficiente;
    }

    ull numBytes;
    tipoErros resultado = DecodificarBase64(buffer, finalLinha, alfabeto, saida, &numBytes);
    free(buffer);

    if (resultado != ok) {
        free(saida);
        return resultado;
    }

    FILE *arquivoSaida = fopen(nomeArquivoSaida, "wb");
    if (arquivoSaida == NULL) {
        free(saida);
        return saidaInvalida;
    }

    size_t bytesEscritos = fwrite(saida, sizeof(byte), numBytes, arquivoSaida);
    fclose(arquivoSaida);
    free(saida);

    if (bytesEscritos != numBytes) {
        return saidaInvalida;
    }

    return ok;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        imprimirMensagemErro(argumentoInvalido);
        return argumentoInvalido;
    }

    tipoAlfabeto64 alfabeto = atoi(argv[1]);
    const char *nomeArquivoCodificado = argv[2];
    const char *nomeArquivoSaida = argv[3];

    tipoErros resultado = decodificarArquivo(nomeArquivoCodificado, nomeArquivoSaida, alfabeto);
    if (resultado != ok) {
        imprimirMensagemErro(resultado);
        return resultado;
    }

    printf("Arquivo decodificado com sucesso!\n");

    return ok;
}

/* $RCSfile$ */