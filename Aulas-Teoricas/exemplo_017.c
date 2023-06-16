/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2022/2
 *
 * Descricao:
 *
 * $Author: marcelo.lanza $
 * $Date: 2022/10/10 12:38:56 $
 * $Log: exemplo_023.c,v $
 * Revision 1.1  2022/10/10 12:38:56  marcelo.lanza
 * Initial revision
 *
 *
 *******************************************************************************/

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define NUMERO_ARGUMENTOS							1

#define OK														0
#define NUMERO_ARGUMENTOS_INVALIDO		1

int
main (int argc, char **argv)
{
	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	printf ("CHAR_BIT: %i\n", CHAR_BIT);
	printf ("SCHAR_MIN: %i\n", SCHAR_MIN);
	printf ("SCHAR_MAX: %i\n", SCHAR_MAX);
	printf ("UCHAR_MAX: %i\n", UCHAR_MAX);
	printf ("CHAR_MIN: %i\n", CHAR_MIN);
	printf ("CHAR_MAX: %i\n", CHAR_MAX);
	printf ("MB_LEN_MAX: %i\n", MB_LEN_MAX);
	printf ("SHRT_MIN: %hi\n", SHRT_MIN);
	printf ("SHRT_MAX: %hi\n", SHRT_MAX);
	printf ("USHRT_MAX: %hu\n", USHRT_MAX);
	printf ("INT_MIN: %i\n", INT_MIN);
	printf ("INT_MAX: %i\n", INT_MAX);
	printf ("UINT_MAX: %u\n", UINT_MAX);
	printf ("LONG_MIN: %li\n", LONG_MIN);
	printf ("LONG_MAX: %li\n", LONG_MAX);
	printf ("ULONG_MAX: %lu\n", ULONG_MAX);
	printf ("LLONG_MIN: %lli\n", LLONG_MIN);
	printf ("LLONG_MAX: %lli\n", LLONG_MAX);
	printf ("ULLONG_MAX: %llu\n", ULLONG_MAX);
	printf ("FLT_RADIX: %u\n", FLT_RADIX);
	printf ("FLT_MANT_DIG: %u\n", FLT_MANT_DIG);
	printf ("DBL_MANT_DIG: %u\n", DBL_MANT_DIG);
	printf ("LDBL_MANT_DIG: %u\n", LDBL_MANT_DIG);
	printf ("FLT_DIG: %i\n", FLT_DIG);
	printf ("DBL_DIG: %i\n", DBL_DIG);
	printf ("LDBL_DIG: %i\n", LDBL_DIG);
	printf ("FLT_MIN_EXP: %i\n", FLT_MIN_EXP);
	printf ("DBL_MIN_EXP: %i\n", DBL_MIN_EXP);
	printf ("LDBL_MIN_EXP: %i\n", LDBL_MIN_EXP);
	printf ("FLT_MAX_EXP: %i\n", FLT_MAX_EXP);
	printf ("DBL_MAX_EXP: %i\n", DBL_MAX_EXP);
	printf ("LDBL_MAX_EXP: %i\n", LDBL_MAX_EXP);
	printf ("FLT_MIN_10_EXP: %i\n", FLT_MIN_10_EXP);
	printf ("DBL_MIN_10_EXP: %i\n", DBL_MIN_10_EXP);
	printf ("LDBL_MIN_10_EXP: %i\n", LDBL_MIN_10_EXP);
	printf ("FLT_MAX_10_EXP: %i\n", FLT_MAX_10_EXP);
	printf ("DBL_MAX_10_EXP: %i\n", DBL_MAX_10_EXP);
	printf ("LDBL_MAX_10_EXP: %i\n", LDBL_MAX_10_EXP);
	printf ("FLT_EPSILON: %f\n", FLT_EPSILON);
	printf ("DBL_EPSILON: %f\n", DBL_EPSILON);
	printf ("LDBL_EPSILON: %Lf\n", LDBL_EPSILON);
	printf ("FLT_MIN: %f\n", FLT_MIN);
	printf ("DBL_MIN: %f\n", DBL_MIN);
	printf ("LDBL_MIN: %Lf\n", LDBL_MIN);
	printf ("FLT_MAX: %f\n", FLT_MAX);
	printf ("DBL_MAX: %f\n", DBL_MAX);
	printf ("LDBL_MAX: %Lf\n", LDBL_MAX);
	printf ("FLT_ROUNDS: %i\n", FLT_ROUNDS);
	/*
	printf ("FLT_EVAL_METHOD: %u\n", FLT_EVAL_METHOD);
	printf ("DECIMAL_DIG: %u\n", DECIMAL_DIG);
	 */
	return OK;
}

/* $RCSfile: exemplo_023.c,v $ */

