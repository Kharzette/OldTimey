CC=gcc
CFLAGS=-std=c17
SOURCES=$(wildcard *.c) $(wildcard Instructions/*.c)

all: Timey

Timey: $(SOURCES)
	$(CC) -o Timey $(SOURCES) $(CFLAGS)