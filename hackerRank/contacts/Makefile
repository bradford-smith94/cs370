# Aidan Racaniello, Bradford Smith and Nicholas Zubrycki
# Makefile for CS 370 Assignment 7
# 03/28/2016
# "We pledge our honor that we have abided by the Stevens Honor System."
################################################################################

PRG=contacts
PROJECT=contacts
SRC=contacts.c
OBJ=$(SRC:.c=.o)
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

all: $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PRG)

debug: fclean
debug: CPPFLAGS+= $(DBFLGS)
debug: all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(PRG)

re: fclean all

submit: fclean
	zip $(PROJECT).zip ./*

