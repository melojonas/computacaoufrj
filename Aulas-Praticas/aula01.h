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
 * $Date: 2023/05/04 14:54:51 $
 * $Log: aula01.h,v $
 * Revision 1.2  2023/05/04 14:54:51  jonas.melo
 * update macros
 *
 * Revision 1.1  2023/04/27 06:39:05  jonas.melo
 * Initial revision
 *
 *
 */

#ifndef _AULA_01_
#define _AULA_01_  "@(#)aula01.h $Revision: 1.2 $"

/* Text color macros */
#define TEXT_BLACK           "\033[30m"
#define TEXT_RED             "\033[31m"
#define TEXT_GREEN           "\033[32m"
#define TEXT_YELLOW          "\033[33m"
#define TEXT_BLUE            "\033[34m"
#define TEXT_MAGENTA         "\033[35m"
#define TEXT_CYAN            "\033[36m"
#define TEXT_WHITE           "\033[37m"

/* Text color variant macros */
#define TEXT_BOLD                  "\033[1m"
#define TEXT_UNDERLINE             "\033[4m"
#define TEXT_HIGH_INTENSITY        "\033[2m"
#define TEXT_BOLD_HIGH_INTENSITY   "\033[1;2m"

/* Background color macros */
#define BG_BLACK             "\033[40m"
#define BG_RED               "\033[41m"
#define BG_GREEN             "\033[42m"
#define BG_YELLOW            "\033[43m"
#define BG_BLUE              "\033[44m"
#define BG_MAGENTA           "\033[45m"
#define BG_CYAN              "\033[46m"
#define BG_WHITE             "\033[47m"

/* Background color variant macros */
#define BG_HIGH_INTENSITY          "\033[0;100m"

/* Reset color macro */
#define RESET                      "\033[0m"

void TypeSize(const char* type_name, size_t size);
void DashedLine();

#endif /* _AULA_01_ */

/*	$RCSfile: aula01.h,v $ */
