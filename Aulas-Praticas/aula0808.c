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
tipoErros codificarArquivo(const char *nomeArquivoEntrada, const char *nomeArquivoSaida, tipoAlfabeto64 alfabeto) {
    FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "rb");
    if (arquivoEntrada == NULL) {
        return entradaInvalida;
    }

    fseek(arquivoEntrada, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivoEntrada);
    fseek(arquivoEntrada, 0, SEEK_SET);

    if (tamanhoArquivo <= 0) {
        fclose(arquivoEntrada);
        return entradaInvalida;
    }

    byte *buffer = (byte *) malloc(tamanhoArquivo);
    if (buffer == NULL) {
        fclose(arquivoEntrada);
        return memoriaInsuficiente;
    }

    size_t bytesLidos = fread(buffer, sizeof(byte), tamanhoArquivo, arquivoEntrada);
    fclose(arquivoEntrada);

    if (bytesLidos != (size_t) tamanhoArquivo) {
        free(buffer);
        return entradaInvalida;
    }

    tipoFinalLinha finalLinha = habilitado; // Habilita caracteres de final de linha para arquivos codificados

    char *saida = (char *) malloc(tamanhoArquivo * 4 / 3 + 4); // Tamanho máximo de saída em Base64
    if (saida == NULL) {
        free(buffer);
        return memoriaInsuficiente;
    }

    tipoErros resultado = CodificarBase64(buffer, tamanhoArquivo, finalLinha, alfabeto, saida);
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

    size_t bytesEscritos = fwrite(saida, sizeof(char), strlen(saida), arquivoSaida);
    fclose(arquivoSaida);
    free(saida);

    if (bytesEscritos != strlen(saida)) {
        return saidaInvalida;
    }

    return ok;
}

/* Função para exibir mensagem de erro em vermelho */
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

int main(int argc, char *argv[]) {
    if (argc != 4) {
        imprimirMensagemErro(argumentoInvalido);
        return argumentoInvalido;
    }

    tipoAlfabeto64 alfabeto = atoi(argv[1]);
    const char *nomeArquivoEntrada = argv[2];
    const char *nomeArquivoSaida = argv[3];

    tipoErros resultado = codificarArquivo(nomeArquivoEntrada, nomeArquivoSaida, alfabeto);
    if (resultado != ok) {
        imprimirMensagemErro(resultado);
        return resultado;
    }

    printf("Arquivo codificado com sucesso!\n");

    return ok;
}

/* $RCSfile$ */