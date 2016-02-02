# Bradford Smith (bsmith8)
# Makefile for spoj Challenge1
# 02/01/2016
################################################################################

PRG=fortytwo
AUTHOR=bsmith8
PROJECT=spoj_challenge1
SRC=fortytwo.cpp
OBJ=$(SRC:.cpp=.o)
CXX=g++
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

debug: fclean
debug: CPPFLAGS+= $(DBFLGS)
debug: all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(PRG)

re: fclean all

tar: fclean
	tar -cvzf $(AUTHOR)_$(PROJECT).tar.gz ./*

