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

CC = gcc # clang
LD = $(CC)

CFLAGS = -Wall -ansi
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
	@echo "Makefile"

exemplo_002: $(EXE002OBJS)
	$(LD) $(LFLAGS) -o $@ $(EXE002OBJS)

clean-objs:
	rm -f *.o

clean:
	rm -f *.o $(EXECS)

# $RCSfile$
