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
 * $Author: jonas.melo $
 * $Date: 2023/06/14 00:37:42 $
 * $Log: aula0501.c,v $
 * Revision 1.1  2023/06/14 00:37:42  jonas.melo
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include "aula0501.h"

/* Implementação da função ExibirMatriz */
tipoErros ExibirMatriz ( unsigned short linhas, unsigned short colunas, long double matriz [linhas][colunas])
{
    unsigned int linha, coluna;
    
    if (linhas == 0 || colunas == 0)
        return argumentoInvalido;

    for (linha = 0; linha < linhas; linha++)
    {
        printf ("| ");
        for (coluna = 0; coluna < colunas; coluna++)
            printf ("%.10Lf ", matriz[linha][coluna] );
        printf (" |\n");
    }
    
    return ok;
}

/* Implementação da função MultiplicarMatrizes */
tipoErros MultiplicarMatrizes ( unsigned short linhas1, unsigned short colunas1, unsigned short linhas2, unsigned short colunas2, long double matriz1 [linhas1][colunas1], long double matriz2 [linhas2][colunas2], long double matrizProduto [linhas1][colunas2])
{
    unsigned short linha, coluna, i;
    long double soma;
    
    if (linhas1 == 0 || colunas1 == 0 || linhas2 == 0 || colunas2 == 0)
        return argumentoInvalido;
    
    if (colunas1 != linhas2)
        return dimensaoMatrizesInvalido;
    
    for (linha = 0; linha < linhas1; linha++)
    {
        for (coluna = 0; coluna < colunas2; coluna++)
        {
            soma = 0;
            for (i = 0; i < colunas1; i++)
                soma += matriz1[linha][i] * matriz2[i][coluna];
            matrizProduto[linha][coluna] = soma;
        }
    }
    
    return ok;
}

/* $RCSfile: aula0501.c,v $ */