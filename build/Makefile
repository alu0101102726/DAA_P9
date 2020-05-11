IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

LIBS=-lm

_OBJ = main.o file.o solution.o vectors.o exec.o greedy-algorithm-2.o grasp-algorithm.o greedy-algorithm.o algorithm.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/solution.hpp $(IDIR)/file.hpp $(IDIR)/vectors.hpp $(IDIR)/exec.hpp $(IDIR)/grasp-algorithm.hpp $(IDIR)/greedy-algorithm-2.hpp $(IDIR)/greedy-algorithm.hpp $(IDIR)/algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/file.o: $(ODIR)/file.cpp $(IDIR)/file.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/exec.o: $(ODIR)/exec.cpp $(IDIR)/exec.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/vectors.o: $(ODIR)/vectors.cpp $(IDIR)/vectors.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/solution.o: $(ODIR)/solution.cpp $(IDIR)/solution.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algorithm.o: $(ODIR)/algorithm.cpp $(IDIR)/algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/greedy-algorithm.o: $(ODIR)/greedy-algorithm.cpp $(IDIR)/greedy-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/greedy-algorithm-2.o: $(ODIR)/greedy-algorithm-2.cpp $(IDIR)/greedy-algorithm-2.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grasp-algorithm.o: $(ODIR)/grasp-algorithm.cpp $(IDIR)/grasp-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ $(INCDIR)/*~