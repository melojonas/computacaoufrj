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

#if defined __linux__ || defined __FreeBSD__
#define _XOPEN_SOURCE 600
#endif

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
    int option_index = 0;
    char *subopts = NULL;
    char *value = NULL;
    int option = -1;
    tipoErros resultado;
    static struct option long_options[] = {
        {"dos", required_argument, 0, 'D'},
        {"help", no_argument, 0, 'H'},
        {"show", required_argument, 0, 'S'},
        {"unix", required_argument, 0, 'U'},
        {0, 0, 0, 0}
    };

    char *inputFile = NULL;
    char *outputFile = NULL;

    while ((opt = getopt_long(argc, argv, "dDhHsSuU:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'd':
            case 'D':
            case 'u':
            case 'U':
                subopts = optarg;
                option = -1;

                while ((option = getsubopt(&subopts, (char * const []){"input", "output", NULL}, &value)) != -1) {
                    if (option == 0) {
                        inputFile = value;
                    } else if (option == 1) {
                        outputFile = value;
                    }
                }

                if (!inputFile) {
                    printf("Erro: É necessário fornecer o nome do arquivo de entrada (input).\n");
                    return argumentoInvalido;
                }

                if (opt == 'd' || opt == 'D') {
                    resultado = ConverterArquivoFormatoUnixParaFormatoDos(inputFile, outputFile);
                } else {
                    resultado = ConverterArquivoFormatoDosParaFormatoUnix(inputFile, outputFile);
                }

                if (resultado == ok) {
                    printf(TEXT_GREEN "Conversão concluída com sucesso.%s\n", RESET);
                    return ok;
                } else {
                    ExibirMensagemErro(resultado);
                    exit(resultado);
                }

                break; /* Esse break nao eh necessario mas por padrao decidi manter */
            case 'h':
            case 'H':
                printf("Uso: %s -d|--dos|-u|--unix <arquivo_original> [arquivo_convertido]\n", argv[0]);
                return 0;
            case 's':
            case 'S':
                subopts = optarg;
                option = -1;

                while ((option = getsubopt(&subopts, (char * const []){"input", NULL}, &value)) != -1) {
                    if (option == 0) {
                        inputFile = value;
                        break;
                    }
                }

                if (!inputFile) {
                    printf("Erro: É necessário fornecer o nome do arquivo de entrada (input) para a opção -s|--show.\n");
                    return argumentoInvalido;
                }
                
                tipoErros resultado = ExibirConteudoArquivo(inputFile);
                if (resultado == ok) {
                    printf(TEXT_GREEN "Conteúdo do arquivo exibido com sucesso.%s\n", RESET);
                    return ok;
                } else {
                    ExibirMensagemErro(resultado);
                    exit(resultado);
                }
            
                break; /* Esse break nao eh necessario mas por padrao decidi manter */
            case '?':
                printf("Erro: Opção inválida.\n");
                return erroOpcaoInvalida;
            default:
                break;
        }
    }
    
    if (optind < argc) {
        printf("Erro: Opção não reconhecida: %s\n", argv[optind]);
        return erroOpcaoInvalida;
    }

    printf("Erro: Nenhuma opção válida foi fornecida.\n");
    return erroOpcaoInvalida;
}

/* $RCSfile$ */
