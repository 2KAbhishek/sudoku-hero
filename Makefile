CC = g++
CFLAGS = -std=c++11
SRC = src/sudoku-hero.cpp

# Default target : dependencies
all: sudoku-hero

# @ macro evaluates to current target
sudoku-hero: bin
	$(CC) $(CFLAGS) $(SRC) -o ./bin/$@

bin:
	mkdir -p $@

