# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# Prof. Marcelo Luiz Drumond Lanza
# EEL270 - Computacao II - Turma 2023/1
#
# Descricao:
#
# $Author$
# $Date$
# $Log$

OS = $(shell uname -s)

CC = gcc

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

DIALECT = ansi
STANDARD = -ansi

ifeq ($(dialect), C90)
DIALECT = c90
STANDARD = -std=c90
endif

ifeq ($(dialect), C89)
DIALECT = c89
STANDARD = -std=c89
endif

ifeq ($(dialect), C99)
DIALECT = c99
STANDARD = -std=c99
endif

ifeq ($(dialect), C11)
DIALECT = c11
STANDARD = -std=c11
endif

DEBUG =

ifeq ($(debug), DEBUG)
DEBUG = -D_EEL270_DEBUG_
endif

CFLAGS = -Wall $(STANDARD) $(DEBUG)
LFLAGS = -Wall

EXE001OBJS = exemplo_001.o
EXE002OBJS = exemplo_002.o

EXECS = exemplo_001\
        exemplo_002

# Regra Implicita
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(EXECS)

exemplo_001: $(EXE001OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE001OBJS)
	@echo "GNUmakefile"

exemplo_002: $(EXE002OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE002OBJS)

.PHONY: clean-all clean clean-gcc clean-clang clean-bsd clean-linux clean-ansi clean-c89 clean-90 clean-c99 clean-c11

clean-all:
	rm -f *.o $(EXECS) *-FreeBSD-* *-Linux-*

clean:
	rm -f *.o $(EXECS)

clean-bsd:
	rm -f *.o $(EXECS) *-FreeBSD-* 

clean-linux:
	rm -f *.o $(EXECS) *-Linux-* 

clean-gcc:
	rm -f *.o $(EXECS) *-gcc-* 

clean-clang:
	rm -f *.o $(EXECS) *-clang-* 

clean-ansi:
	rm -f *.o $(EXECS) *-ansi* 

clean-c89:
	rm -f *.o $(EXECS) *-c89* 

clean-c90:
	rm -f *.o $(EXECS) *-c90* 

clean-c99:
	rm -f *.o $(EXECS) *-c99* 

clean-c11:
	rm -f *.o $(EXECS) *-c11* 

clean-objs:
	rm -f *.o

# $RCSfile$
