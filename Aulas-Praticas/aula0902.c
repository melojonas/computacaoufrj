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
#include "aula0901.h"
#include "aula01.h"

void ExibirMensagemErro(tipoErros erro) {
    switch (erro) {
        case argumentoInvalido:
            printf(TEXT_RED "Erro: Argumento inválido.");
            break;
        case comprimentoInvalido:
            printf(TEXT_RED "Erro: Comprimento inválido.");
            break;
        case memoriaInsuficiente:
            printf(TEXT_RED "Erro: Memória insuficiente.");
            break;
        default:
            printf(TEXT_RED "Erro desconhecido.");
            break;
    }
    printf(RESET "\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_arquivo>\n", argv[0]);
        exit(argumentoInvalido);
    }

    tipoErros resultado = ExibirConteudoArquivo(argv[1]);

    if (resultado == ok) {
        printf(TEXT_GREEN "Arquivo exibido com sucesso.%s\n", RESET);
    } else {
        ExibirMensagemErro(resultado);
    }

    return ok;
}

/* $RCSfile$ */
