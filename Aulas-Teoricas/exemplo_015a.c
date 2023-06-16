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

#include "exemplo_015.h"

unsigned long long
CalcularFatorial (unsigned short numero)
{

	if (numero <= 1)
		return 1;

  return numero * CalcularFatorial (numero - 1);

}

/* $RCSfile$ */
