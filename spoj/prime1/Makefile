# Aidan Racaniello and Bradford Smith
# Makefile for CS 370 Assignment 3 SPOJ Prime1
# 02/21/2016
# "We pledge our honor that We have abided by the Stevens Honor System."
################################################################################

PRG=prime1
PROJECT=cs370-assignment3
SRC=prime1.cpp
OBJ=$(SRC:.cpp=.o)
CXX=g++
TEX=pdflatex
TEXSRC=report.tex
RM=rm -f
INCLPATH=
LIBPATH=
LDLIBS=
LDFLAGS+=
# implicit compiling rules:
# C++ compiled with: `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS)`
CFLAGS+=
CPPFLAGS+= -pedantic-errors -Wall
CXXFLAGS+=
DBFLGS= -g -DDEBUG

all: $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(PRG)

tex:
	$(TEX) $(TEXSRC)

debug: fclean
debug: CPPFLAGS+= $(DBFLGS)
debug: all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(PRG)

texclean:
	$(RM) *.aux
	$(RM) *.log

texfclean: texclean
	$(RM) $(TEXSRC:.tex=.pdf)

re: fclean all

test: debug
	./$(PRG) < testcases.txt

submit: fclean tex texclean
	zip $(PROJECT).zip ./*

