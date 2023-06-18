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
#include "aula0604.h"

/* Implementação da função GerarDigitosVerificadoresRG */
tipoErros GerarDigitosVerificadoresRg(char *rg_entrada /* entrada */, char *rg_saida /* saída */)
{
    unsigned char indice, resto, diferenca, digito, contador = 0;
    unsigned short soma = 0;

    if (rg_entrada == NULL){
        printf("Entrada nula\n");
        exit(argumentoInvalido);}

    for (indice = 0; indice < 8; indice++){
        if (indice == 2 || indice == 6)
        {
            if (rg_entrada[indice] != '.'){
                printf("Dígito '%c' inválido\n", rg_entrada[indice]);
                exit(digitoInvalido);}
            continue;
        }

        soma += (rg_entrada[indice] * (contador + 2));
        contador++;
    }

    resto = soma % 11;

    diferenca = 11 - resto;

    if (diferenca == 11)
        digito = 0;
    else
        digito = diferenca;

    for (indice = 0; indice < 11; indice++)
        rg_saida[indice] = (char) rg_entrada[indice];

    rg_saida[10] = '-';
    rg_saida[11] = digito;

    return ok;
}

/* Implementação da função ValidarRG usando a função GerarDigitosVerificadoresRg */
tipoErros ValidarRg(char *rg_entrada /* entrada */) {
    char rg_saida[12];

    if (rg_entrada == NULL){
        printf("Entrada nula\n");
        return argumentoInvalido;}

    GerarDigitosVerificadoresRg(rg_entrada, rg_saida);

    if (rg_entrada[11] != rg_saida[11])
        return digitoVerificadorInvalido;

    return ok;
}

/* $RCSfile$ */