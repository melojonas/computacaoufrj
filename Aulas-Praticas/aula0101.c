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
 * $Date: 2023/05/04 15:04:24 $
 * $Log: aula0101.c,v $
 * Revision 1.2  2023/05/04 15:04:24  jonas.melo
 * bug fixed
 *
 * Revision 1.1  2023/04/27 06:45:51  jonas.melo
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aula01.h"

#define OK 0
#define MAX_NAME_LENGTH 64
#define SCREEN_WIDTH 100

int main(int argc, char *argv[]) {
    char name[MAX_NAME_LENGTH + 1] = {'\0'};
    int name_len, padding, start_col;

    /* Check if an argument was provided */
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    /* Copy the argument into the name variable */
    strncpy(name, argv[1], MAX_NAME_LENGTH);
    name[MAX_NAME_LENGTH] = '\0';
    name_len = strlen(name);

    /* Calculate the padding and starting column for centering the name */
    padding = (SCREEN_WIDTH - name_len - 2) / 2;
    start_col = padding;

    /* Print a blank line before the output */
    printf("\n");

    /* Print the column headers */
    int i, j;
    for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf(BG_WHITE TEXT_BLACK "%d", i);
		}
    }
    printf(RESET "\n");

    int k, l;
    for (k = 0; k < 10; k++) {
		for (l = 0; l < 10; l++) {
			printf(BG_WHITE TEXT_BLACK "%d", l);
		}
    }
    printf(RESET "\n");

	/* Print a blank line */
    printf("\n");

    /* Print the name centered in bold red */
    int m, n;
    for (m = 0; m < start_col; m++) {
        printf(" ");
    }
    printf(TEXT_RED TEXT_UNDERLINE "\"%s\"" RESET "\n", name);
    for (n = 0; n < SCREEN_WIDTH - start_col - name_len - 2; n++) {
        printf(" ");
    }

	/* Print a blank line */
    printf("\n");

	/* Print the straight line */
    int o;
	for (o = 0; o < SCREEN_WIDTH; o++) {
		printf("-");
	}

	/* Print a blank line */
    printf("\n\n");

	return OK;
}

/* $RCSfile: aula0101.c,v $ */
