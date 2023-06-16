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
#include <string.h>
#include "exemplo_030.h"

tipoCodigosRetorno
ValidarDre (char dre [COMPRIMENTO_DRE + 1])
{
  unsigned short soma = 0;
  unsigned short indice;

  if (dre == NULL)
		return argumentoInvalido;

  if (strlen (dre) != COMPRIMENTO_DRE)
    return comprimentoDreInvalido;

  #ifdef _DEBUG_
	printf ("\n\"%s\"\n", dre);
	#endif

  for (indice = 0; indice < (COMPRIMENTO_DRE - 1); indice++)
  {
    if (dre [indice] < '0' || dre [indice] > '9')
      return digitoInvalido;

    soma += (dre [indice] - '0') * (indice + 1);
  }

  #ifdef _DEBUG_
	printf ("\n\"%s\"\n", dre);
	printf ("Soma: %hu - Resto: %hu\n", soma, soma % 10);
	printf ("Indice: %hu\n", indice);
	printf ("DV: %c\n", dre [indice]);
	#endif

  if ((dre [indice] - '0') != (soma % 10))
    return dreInvalido;

  return dreValido;
}

/* $RCSfile$ */
