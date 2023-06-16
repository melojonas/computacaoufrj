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

#include <stdio.h>
#include "exemplo_025.h"

boolean
ValidarDre (byte dre [COMPRIMENTO_DRE])
{
  unsigned short soma = 0;
  byte indice;

  if (dre == NULL)
		return falso;

  for (indice = 0; indice < (COMPRIMENTO_DRE - 1); indice++)
  {
    if (dre [indice] > 9)
      return falso;

    soma += dre [indice] * (indice + 1);
  }

  if (dre [indice] != (soma % 10))
    return falso;

  return verdadeiro;
}

/* $RCSfile$ */
