# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2023/1
# Prof. Marcelo Luiz Drumond Lanza
# Autor: Jonas da Silva Melo
# 
# Descricao: 
# 
# $Author$
# $Date$
# $Log$
#

OS = $(shell uname -s)

CC = gcc

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

DIALECT = ansi
STANDARD = -ansi

ifeq ($(dialeto), C90)
DIALECT = c90
STANDARD = -std=c90
endif
ifeq ($(dialeto), C89)
DIALECT = c89
STANDARD = -std=c89
endif
ifeq ($(dialeto), C99)
DIALECT = c99
STANDARD = -std=c99
endif
ifeq ($(dialeto), C11)
DIALECT = c11
STANDARD = -std=c11
endif

ifeq ($(debug), DEBUG)
DEBUG = -g
endif

CFLAGS = -Wall $(STANDARD) $(DEBUG)
LFLAGS = -Wall

AULA01 = 	aula0101\
			aula0102\
			aula0103

AULA02 =	aula0202a\
			aula0202b\
			aula0202c\
			aula0202d

AULA03 =	aula0302a\
			aula0302b\
			aula0302c\
			aula0302d

AULA04 =	aula0402a\
			aula0402b\
			aula0402c\
			aula0402d\
			aula0404a\
			aula0404b\
			aula0404c\
			aula0404d\
			aula0404e

AULA05 =	aula0502\
			aula0503

AULA06 =	aula0602a\
			aula0602b\
			aula0603a\
			aula0603b\
			aula0605a\
			aula0605b\
			aula0606a\
			aula0606b

AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o

AULA0202AOBJS = aula0201a.o aula0202.o
AULA0202BOBJS = aula0201b.o aula0202.o
AULA0202COBJS = aula0201c.o aula0202.o
AULA0202DOBJS = aula0201d.o aula0202.o

AULA0302AOBJS = aula0301a.o aula0302.o
AULA0302BOBJS = aula0301b.o aula0302.o
AULA0302COBJS = aula0301c.o aula0302.o
AULA0302DOBJS = aula0301d.o aula0302.o

AULA0402AOBJS = aula0401a.o aula0402.o
AULA0402BOBJS = aula0401b.o aula0402.o
AULA0402COBJS = aula0401c.o aula0402.o
AULA0402DOBJS = aula0401d.o aula0402.o
AULA0404AOBJS = aula0403a.o aula0404.o
AULA0404BOBJS = aula0403b.o aula0404.o
AULA0404COBJS = aula0403c.o aula0404.o
AULA0404DOBJS = aula0403d.o aula0404.o
AULA0404EOBJS = aula0403e.o aula0404.o

AULA0502OBJS = aula0501.o aula0502.o
AULA0503OBJS = aula0501.o aula0503.o

AULA0602AOBJS = aula0601.o aula0602a.o
AULA0602BOBJS = aula0601.o aula0602b.o
AULA0603AOBJS = aula0601.o aula0603a.o
AULA0603BOBJS = aula0601.o aula0603b.o
AULA0605AOBJS = aula0604.o aula0605a.o
AULA0605BOBJS = aula0604.o aula0605b.o
AULA0606AOBJS = aula0604.o aula0606a.o
AULA0606BOBJS = aula0604.o aula0606b.o

LIBMATEMATICARECURSAOOBJS = aula0201a.o aula0301a.o aula0401a.o aula0403a.o
LIBMATEMATICADOWHILEOBJS = aula0201b.o aula0301b.o aula0401b.o aula0403b.o
LIBMATEMATICAFOROBJS = aula0201c.o aula0301c.o aula0401c.o aula0403c.o
LIBMATEMATICAWHILEOBJS = aula0201d.o aula0301d.o aula0401d.o aula0403d.o
LIBMATEMATICAOBJS = aula0501.o

LIBMATEMATICARECURSAO = libmatematicarecursao.a
LIBMATEMATICADOWHILE = libmatematicadowhile.a
LIBMATEMATICAFOR = libmatematicafor.a
LIBMATEMATICAWHILE = libmatematicawhile.a
LIBMATEMATICA = libmatematica.a

LIBS = $(LIBMATEMATICARECURSAO) $(LIBMATEMATICADOWHILE) $(LIBMATEMATICAFOR) $(LIBMATEMATICAWHILE) $(LIBMATEMATICA)
EXECS = $(AULA01) $(AULA02) $(AULA03) $(AULA04) $(AULA05) $(AULA06)

ALL = $(EXECS) $(LIBS)

# Regras implícitas
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

aula01: $(AULA01)

aula02: $(AULA02)

aula03: $(AULA03)

aula04: $(AULA04)

aula05: $(AULA05)

aula06: $(AULA06)

aula01-all:
	@for standard in c90 c89 c99 c11 ansi; do \
		for compiler in gcc clang ; do \
			for file in $(AULA01); do \
				$$compiler $(CFLAGS) -Werror -D$$standard -o $$(basename $$file .c)-$(OS)-$$compiler-$$standard $$file.c; \
			done \
		done \
	done

aula02-all:
	@for standard in c90 c89 c99 c11 ansi; do \
		for compiler in gcc clang ; do \
			for file in aula0201?.c ; do \
				output_file=$$(echo aula0202$$(basename $$file .c | cut -c9)) ; \
				$$compiler $(CFLAGS) -Werror -D$$standard -o $$output_file-$(OS)-$$compiler-$$standard $$file aula0202.c ; \
			done \
		done \
	done

aula03-all:
	@for standard in c90 c89 c99 c11 ansi; do \
		for compiler in gcc clang ; do \
			for file in aula0301?.c ; do \
				output_file=$$(echo aula0302$$(basename $$file .c | cut -c9)) ; \
				$$compiler $(CFLAGS) -Werror -D$$standard -o $$output_file-$(OS)-$$compiler-$$standard $$file aula0302.c ; \
			done \
		done \
	done

aula04-all:
	@for standard in c90 c89 c99 c11 ansi; do \
		for compiler in gcc clang ; do \
			for file in aula0401?.c ; do \
				output_file=$$(echo aula0402$$(basename $$file .c | cut -c9)) ; \
				$$compiler $(CFLAGS) -Werror -D$$standard -o $$output_file-$(OS)-$$compiler-$$standard $$file aula0402.c -lm ; \
			done \
		done \
	done
	@for standard in c90 c89 c99 c11 ansi; do \
		for compiler in gcc clang ; do \
			for file in aula0403?.c ; do \
				output_file=$$(echo aula0404$$(basename $$file .c | cut -c9)) ; \
				$$compiler $(CFLAGS) -Werror -D$$standard -o $$output_file-$(OS)-$$compiler-$$standard $$file aula0404.c -lm ; \
			done \
		done \
	done

aula05-all:
	@for standard in c90 c89 c99 c11 ansi; do \
		for compiler in gcc clang ; do \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0502-$(OS)-$$compiler-$$standard aula0501.c aula0502.c; \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0503-$(OS)-$$compiler-$$standard aula0501.c aula0503.c; \
		done \
	done

aula06-all:
	@for standard in c90 c89 c99 c11 ansi; do \
		for compiler in gcc clang ; do \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0602a-$(OS)-$$compiler-$$standard aula0601.c aula0602a.c; \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0602b-$(OS)-$$compiler-$$standard aula0601.c aula0602b.c; \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0603a-$(OS)-$$compiler-$$standard aula0601.c aula0603a.c; \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0605a-$(OS)-$$compiler-$$standard aula0604.c aula0605a.c; \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0605b-$(OS)-$$compiler-$$standard aula0604.c aula0605b.c; \
			$$compiler $(CFLAGS) -Werror -D$$standard -o aula0606a-$(OS)-$$compiler-$$standard aula0604.c aula0606a.c; \
		done \
	done

aula0101: $(AULA0101OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0101OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302a: $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402a: $(AULA0402AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402b: $(AULA0402BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402c: $(AULA0402COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402d: $(AULA0402DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404a: $(AULA0404AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404AOBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404b: $(AULA0404BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404BOBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404c: $(AULA0404COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404COBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404d: $(AULA0404DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404DOBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404e: $(AULA0404EOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0404EOBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0502: $(AULA0502OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0503: $(AULA0503OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0503OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0602a: $(AULA0602AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0602b: $(AULA0602BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0603a: $(AULA0603AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0603b: $(AULA0603BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0605a: $(AULA0605AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0605b: $(AULA0605BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0606a: $(AULA0606AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0606AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

libmatematicarecursao.a: $(LIBMATEMATICARECURSAOOBJS)
	$(AR) $(ARFLAGS) $@ $(LIBMATEMATICARECURSAOOBJS)

libmatematicadowhile.a: $(LIBMATEMATICADOWHILEOBJS)
	$(AR) $(ARFLAGS) $@ $(LIBMATEMATICADOWHILEOBJS)

libmatematicafor.a: $(LIBMATEMATICAFOROBJS)
	$(AR) $(ARFLAGS) $@ $(LIBMATEMATICAFOROBJS)

libmatematicawhile.a: $(LIBMATEMATICAWHILEOBJS)
	$(AR) $(ARFLAGS) $@ $(LIBMATEMATICAWHILEOBJS)

.PHONY: clean-all clean clean-gcc clean-clang clean-bsd clean-linux clean-ansi clean-c89 clean-90 clean-c99 clean-c11

clean-all:
	rm -f *.o $(EXECS) $(LIBS) *-FreeBSD-* *-Linux-*

clean:
	rm -f *.o $(EXECS) $(LIBS)

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
