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
#include "aula01.h"

void ExibirMensagemErro(tipoErros erro)
{
    switch (erro) {
        case ok:
            printf(TEXT_RED "Nenhum erro ocorreu.");
            break;
        case argumentoInvalido:
            printf(TEXT_RED "Argumento inválido.");
            break;
        case comprimentoInvalido:
            printf(TEXT_RED "Comprimento inválido.");
            break;
        case memoriaInsuficiente:
            printf(TEXT_RED "Memória insuficiente.");
            break;
        case erroArquivoOriginal:
            printf(TEXT_RED "Erro ao abrir o arquivo original.");
            break;
        case erroArquivoConvertido:
            printf(TEXT_RED "Erro ao abrir o arquivo convertido.");
            break;
        case erroCriarArquivoTemporario:
            printf(TEXT_RED "Erro ao criar o arquivo temporário.");
            break;
        case erroRenomearOriginal:
            printf(TEXT_RED "Erro ao renomear o arquivo original.");
            break;
        case erroRenomearConvertido:
            printf(TEXT_RED "Erro ao renomear o arquivo convertido.");
            break;
        case arquivoJaEstaNoFormato:
            printf(TEXT_RED "Erro: O arquivo já está no formato solicitado.");
            break;
        default:
            printf("Erro desconhecido.");
            break;
    }
    printf(RESET "\n");
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
        printf(TEXT_GREEN "Conversão concluída com sucesso.%s\n", RESET);
    } else {
        ExibirMensagemErro(resultado);
    }

    return ok;
}

/* $RCSfile$ */
