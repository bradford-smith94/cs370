# Bradford Smith, Justin Tsang and Keyur Ved
# CS 370 Assignment 8 HackerRank Find Median
# 04/03/2016
# "We pledge our honor that we have abided by the Stevens Honor System."

PRG=findmedian
PROJECT=findmedian
SRC=median.c
OBJ=$(SRC:.c=.o)
CC=gcc
RM=rm -f
LDLIBS+= -lm
LDFLAGS+=
CFLAGS+=
CPPFLAGS+= -pedantic-errors -Wall
DBFLGS= -g -DDEBUG

# objects are implicitly compiled with `$(CC) -c $(CPPFLAGS) $(CFLAGS)`
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
