# Bradford Smith (bsmith8)
# Makefile for spoj INTEST
# 02/01/2016
# "I pledge my honor that I have abided by the Stevens Honor System."
################################################################################

GENPRG=generator
READPRG=reader
AUTHOR=bsmith8
PROJECT=spoj_intest
GENSRC=generator.c
READSRC=reader.c
GENOBJ=$(GENSRC:.c=.o)
READOBJ=$(READSRC:.c=.o)
CC=gcc
RM=rm -f
INCLPATH=
LIBPATH=
LDLIBS=
LDFLAGS+=
# implicit compiling rules:
# C complied with: `$(CC) -c $(CPPFLAGS) $(CFLAGS)`
CFLAGS+=
CPPFLAGS+= -pedantic-errors -Wall
CXXFLAGS+=
DBFLGS= -g -DDEBUG

all: $(GENOBJ) $(READOBJ)
	$(CC) $(LDFLAGS) $(GENOBJ) $(LDLIBS) -o $(GENPRG)
	$(CC) $(LDFLAGS) $(READOBJ) $(LDLIBS) -o $(READPRG)

debug: fclean
debug: CPPFLAGS+= $(DBFLGS)
debug: all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(GENPRG)
	$(RM) $(READPRG)

re: fclean all

tar: fclean
	tar -cvzf $(AUTHOR)_$(PROJECT).tar.gz ./*

