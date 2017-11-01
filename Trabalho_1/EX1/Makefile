CC := gcc

CFLAGS := -lm -Wall


SRCFILES := $(wildcard src/*.c)

all: $(SRCFILES:src/%.c=obj/%.o)
	$(CC)  obj/*.o $(CFLAGS) -o bin/saida 

obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	bin/saida

test1:
	bin/saida < doc/in1

test2:
	bin/saida < doc/in2
