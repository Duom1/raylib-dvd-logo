all:
	gcc main.c -o program -Wall -lraylib

run: all
	./program
