main: main.o struct.o
	gcc -o main main.o struct.o

run:
	./main

main.o: main.c struct.h
	gcc -c main.c

struct.o: struct.c struct.h
	gcc -c struct.c