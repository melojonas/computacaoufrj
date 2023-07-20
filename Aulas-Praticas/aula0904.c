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
#include <time.h>
#include <unistd.h>
#include "aula0901.h"

void ExibirMensagemErro(tipoErros erro)
{
    switch (erro) {
        case ok:
            printf("Nenhum erro ocorreu.\n");
            break;
        case argumentoInvalido:
            printf("Argumento inválido.\n");
            break;
        case comprimentoInvalido:
            printf("Comprimento inválido.\n");
            break;
        case memoriaInsuficiente:
            printf("Memória insuficiente.\n");
            break;
        case erroArquivoOriginal:
            printf("Erro ao abrir o arquivo original.\n");
            break;
        case erroArquivoConvertido:
            printf("Erro ao abrir o arquivo convertido.\n");
            break;
        case erroCriarArquivoTemporario:
            printf("Erro ao criar o arquivo temporário.\n");
            break;
        case erroRenomearOriginal:
            printf("Erro ao renomear o arquivo original.\n");
            break;
        case erroRenomearConvertido:
            printf("Erro ao renomear o arquivo convertido.\n");
            break;
        default:
            printf("Erro desconhecido.\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Uso: %s <arquivo_original> [arquivo_convertido]\n", argv[0]);
        return 1;
    }

    char *arquivoOriginal = argv[1];
    char *arquivoConvertido = (argc == 3) ? argv[2] : NULL;

    tipoErros resultado = ConverterArquivoFormatoDosParaFormatoUnix(arquivoOriginal, arquivoConvertido);

    if (resultado == ok) {
        printf("Conversão concluída com sucesso.\n");
    } else {
        ExibirMensagemErro(resultado);
    }

    return ok;
}

/* $RCSfile$ */
