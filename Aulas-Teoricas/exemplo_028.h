/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2023/1
 *
 * Descricao:
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *******************************************************************************/

#ifndef EXEMPLO_028
#define EXEMPLO_028

#define COMPRIMENTO_DRE								9

typedef unsigned char byte;

typedef enum 
{
	dreValido, 
	argumentoInvalido,
	digitoInvalido,
	dreInvalido
} tipoCodigosRetorno;

tipoCodigosRetorno
ValidarDre (byte [COMPRIMENTO_DRE]);

#endif

/* $RCSfile$ */
