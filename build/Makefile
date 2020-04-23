IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

LIBS=-lm

_OBJ = main.o graph.o file.o exec.o algorithm.o greedy-algorithm.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/exec.hpp $(IDIR)/graph.hpp $(IDIR)/file.hpp $(IDIR)/algorithm.hpp $(IDIR)/greedy-algorithm.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/graph.o: $(ODIR)/graph.cpp $(IDIR)/graph.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algorithm.o: $(ODIR)/algorithm.cpp $(IDIR)/algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/file.o: $(ODIR)/file.cpp $(IDIR)/file.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/greedy-algorithm.o: $(ODIR)/greedy-algorithm.cpp $(IDIR)/greedy-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/exec.o: $(ODIR)/exec.cpp $(IDIR)/exec.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)


main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ $(INCDIR)/*~