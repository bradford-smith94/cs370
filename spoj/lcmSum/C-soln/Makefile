# Makefile for CS 370 Group Project 2
# 04/29/2016
# "We pledge our honor that we have abided by the Stevens Honor System."
################################################################################

PRG=lcmsum
SRC=main.c
OBJ=$(SRC:.c=.o)
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

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(PRG)

re: fclean all
