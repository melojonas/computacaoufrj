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
#include <unistd.h>
#include <getopt.h>
#include "aula0901.h"
#include "aula01.h"

void ExibirMensagemErro(tipoErros erro) {
    switch (erro) {
        case erroAbrindoArquivo:
            printf(TEXT_RED "Erro: Não foi possível abrir o arquivo.");
            break;
        case erroLendoArquivo:
            printf(TEXT_RED "Erro: Não foi possível ler o arquivo.");
            break;
        case erroEscrevendoArquivo:
            printf(TEXT_RED "Erro: Não foi possível escrever no arquivo.");
            break;
        case erroFechandoArquivo:
            printf(TEXT_RED "Erro: Não foi possível fechar o arquivo.");
            break;
        case erroOpcaoInvalida:
            printf(TEXT_RED "Erro: Opção inválida.");
            break;
        case erroConverterUnixParaDos:
            printf(TEXT_RED "Erro: Falha ao converter o arquivo do formato Unix para o formato DOS.");
            break;
        case erroConverterDosParaUnix:
            printf(TEXT_RED "Erro: Falha ao converter o arquivo do formato DOS para o formato Unix.");
            break;
        case argumentoInvalido:
            printf(TEXT_RED "Erro: Argumento inválido.");
            break;
        case comprimentoInvalido:
            printf(TEXT_RED "Erro: Falta argumento para a opção.");
            break;
        case arquivoJaEstaNoFormato:
            printf(TEXT_RED "Erro: O arquivo já está no formato solicitado.");
            break;
        default:
            printf(TEXT_RED "Erro: Erro desconhecido.");
            break;
    }
    printf(RESET "\n");
}

int main(int argc, char *argv[]) {
    int opt;
    char opcao;
    int option_index = 0;
    static struct option long_options[] = {
        {"dos", required_argument, 0, 'D'},
        {"help", no_argument, 0, 'H'},
        {"show", required_argument, 0, 'S'},
        {"unix", required_argument, 0, 'U'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "dDhHsSuU:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'd':
            case 'D':
            case 'u':
            case 'U':
                opcao = opt;
                break;
            case 'h':
            case 'H':
                printf("Uso: %s -d|--dos|-u|--unix <arquivo_original> [arquivo_convertido]\n", argv[0]);
                return ok;
            case 's':
            case 'S':
                if ((optind > argc)) {
                    ExibirMensagemErro(comprimentoInvalido);
                    exit(comprimentoInvalido);
                }
                opcao = opt;
                break;
            case '?':
                ExibirMensagemErro(erroOpcaoInvalida);
                exit(erroOpcaoInvalida);
            default:
                break;
        }
    }

    if (opcao == 'd' || opcao == 'D' || opcao == 'u' || opcao == 'U') {
        if (optind > argc) {
            ExibirMensagemErro(comprimentoInvalido);
            exit(comprimentoInvalido);
        }
        char *arquivoOriginal = argv[optind == argc ? optind - 1 : optind];
        char *arquivoConvertido = (optind + 2 < argc) ? argv[optind + 2] : NULL;
        tipoErros resultado;

        if (opcao == 'd' || opcao == 'D')
            resultado = ConverterArquivoFormatoUnixParaFormatoDos(arquivoOriginal, arquivoConvertido);
        else
            resultado = ConverterArquivoFormatoDosParaFormatoUnix(arquivoOriginal, arquivoConvertido);

        if (resultado == ok) {
            printf(TEXT_GREEN "Conversão concluída com sucesso.%s\n", RESET);
            return ok;
        } else {
            ExibirMensagemErro(resultado);
            exit(resultado);
        }
    }

    if (opcao == 's' || opcao == 'S') {
        char *arquivo = argv[optind == argc ? optind - 1 : optind];
        tipoErros resultado = ExibirConteudoArquivo(arquivo);
        if (resultado == ok) {
            printf(TEXT_GREEN "Conteúdo do arquivo exibido com sucesso.%s\n", RESET);
            return ok;
        } else {
            ExibirMensagemErro(resultado);
            return resultado;
        }
    }

    printf(TEXT_RED "Erro: Nenhuma opção válida foi fornecida.%s\n", RESET);
    return erroOpcaoInvalida;
}

/* $RCSfile$ */
