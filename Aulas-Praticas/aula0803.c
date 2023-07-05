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

#define NUMERO_ARGUMENTOS   2
#define EOS                 '\0'

/* Função para exibir a string decodificada no formato especificado */
void exibirBytesDecodificados(byte *bytes, unsigned long long numBytes) {
    unsigned long long i;
    
    printf(TEXT_BOLD TEXT_BLACK ">>>> %s", RESET);
    for (i = 0; i < numBytes; i++) {
        printf(TEXT_GREEN "%03u ", bytes[i]);
    }
    printf(RESET "\n");
}

/* Função para exibir mensagem de erro em vermelho */
void exibirErro(char *mensagemErro) {
    printf(TEXT_RED "%s%s\n", mensagemErro, RESET);
}

int main(int argc, char *argv[]) {
               
        if (argc != NUMERO_ARGUMENTOS) {
            exibirErro("Número de argumentos inválido.");
            return comprimentoInvalido;
        }

        unsigned long long numBytes, tamanhoString;
        char *stringCodificada;
        tipoErros retornoDecodificacao;
        byte *bytesDecodificados;
        
        
        stringCodificada = argv[1];
        tamanhoString = strlen(stringCodificada);

        /* Verificar se a string possui um número par de caracteres */
        if (tamanhoString % 2 != 0) {
            exibirErro("String inválida. Deve conter um número par de caracteres.");
            return hexadecimalInvalido;
        }

        numBytes = tamanhoString / 2;
        bytesDecodificados = (byte *)malloc(numBytes * sizeof(byte));
        
        if (bytesDecodificados == NULL) {
            exibirErro("Falha ao alocar memória.");
            return memoriaInsuficiente;
        }
    
        retornoDecodificacao = DecodificarBase16(stringCodificada, bytesDecodificados, &numBytes);
        if (retornoDecodificacao != ok) {
            exibirErro("Erro ao decodificar a string em Base16.");
            free(bytesDecodificados);
            return falhaDecodificacao;
        }
    
        exibirBytesDecodificados(bytesDecodificados, numBytes);
    
        free(bytesDecodificados);
    
        return ok;
}

/* $RCSfile$ */