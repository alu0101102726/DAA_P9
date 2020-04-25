IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src

LIBS=-lm

_OBJ = main.o graph.o file.o exec.o algorithm.o solution.o greedy-algorithm.o second-greedy-algorithm.o grasp-algorithm.o multiboot-algorithm.o variable-neighborhood-search-algorithm.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/exec.hpp $(IDIR)/solution.hpp $(IDIR)/graph.hpp $(IDIR)/file.hpp $(IDIR)/algorithm.hpp $(IDIR)/greedy-algorithm.hpp $(IDIR)/second-greedy-algorithm.hpp $(IDIR)/grasp-algorithm.hpp $(IDIR)/multiboot-algorithm.hpp $(IDIR)/variable-neighborhood-search-algorithm.hpp
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/graph.o: $(ODIR)/graph.cpp $(IDIR)/graph.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algorithm.o: $(ODIR)/algorithm.cpp $(IDIR)/algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/file.o: $(ODIR)/file.cpp $(IDIR)/file.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/greedy-algorithm.o: $(ODIR)/greedy-algorithm.cpp $(IDIR)/greedy-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/second-greedy-algorithm.o: $(ODIR)/second-greedy-algorithm.cpp $(IDIR)/second-greedy-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grasp-algorithm.o: $(ODIR)/grasp-algorithm.cpp $(IDIR)/grasp-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/multiboot-algorithm.o: $(ODIR)/multiboot-algorithm.cpp $(IDIR)/multiboot-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/variable-neighborhood-search-algorithm.o: $(ODIR)/variable-neighborhood-search-algorithm.cpp $(IDIR)/variable-neighborhood-search-algorithm.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)
		
$(ODIR)/exec.o: $(ODIR)/exec.cpp $(IDIR)/exec.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/solution.o: $(ODIR)/solution.cpp $(IDIR)/solution.hpp 
		$(CC) -c -o $@ $< $(CFLAGS)


main: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ $(INCDIR)/*~