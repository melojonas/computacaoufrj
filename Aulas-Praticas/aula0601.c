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
#include "aula0601.h"

/* Implementação da função GerarDigitosVerificadoresRG */
tipoErros GerarDigitosVerificadoresRg(byte rg [] /* entrada/saída */)
{
    unsigned char indice, resto, diferenca, digito;
    unsigned short soma = 0;

    if (rg == NULL)
        return argumentoInvalido;

    /* Verificar se rg tem comprimento igual COMPRIMENTO_RG */
    if (sizeof(rg) / sizeof(rg[0]) != COMPRIMENTO_RG)
        return comprimentoRgInvalido;

    for (indice = 0; indice < 8; indice++){
        soma += (rg[indice] * (indice + 2));
    }

    resto = soma % 11;

    diferenca = 11 - resto;

    if (diferenca == 10)
        digito = 88;
    else if (diferenca == 11)
        digito = 0;
    else
        digito = diferenca;

    rg[8] = digito;

    return ok;
}

/* $RCSfile$ */