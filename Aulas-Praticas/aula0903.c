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

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aula0901.h"
#include "aula01.h"

void ExibirMensagemErro(tipoErros erro);

void ExibirMensagemErro(tipoErros erro) {
    switch (erro) {
        case argumentoInvalido:
            printf(TEXT_RED "Erro: Argumento inválido.");
            break;
        case erroArquivoOriginal:
            printf(TEXT_RED "Erro: Não foi possível abrir o arquivo original.");
            break;
        case erroArquivoConvertido:
            printf(TEXT_RED "Erro: Não foi possível criar ou escrever no arquivo convertido.");
            break;
        case erroCriarArquivoTemporario:
            printf(TEXT_RED "Erro: Não foi possível criar o arquivo temporário.");
            break;
        case erroRenomearOriginal:
            printf(TEXT_RED "Erro: Não foi possível renomear o arquivo original.");
            break;
        case erroRenomearConvertido:
            printf(TEXT_RED "Erro: Não foi possível renomear o arquivo convertido.");
            break;
        default:
            printf(TEXT_RED "Erro desconhecido.");
            break;
    }
    printf(RESET "\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Uso: %s <arquivo_original> [arquivo_convertido]\n", argv[0]);
        return comprimentoInvalido;
    }

    char *arquivoOriginal = argv[1];
    char *arquivoConvertido = (argc == 3) ? argv[2] : NULL;

    tipoErros resultado = ConverterArquivoFormatoUnixParaFormatoDos(arquivoOriginal, arquivoConvertido);

    if (resultado == ok) {
        printf(TEXT_GREEN "Conversão concluída com sucesso.%s\n", RESET);
    } else {
        ExibirMensagemErro(resultado);
    }

    return ok;
}


/* $RCSfile$ */
