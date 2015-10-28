all: ex1

clean:
	rm -f main.o ex1

ex1: main.o
	gcc -std=c99 -Wall -Werror -pedantic-errors  main.o -o ex1

main.o: main.c
	gcc -std=c99 -Wall -Werror -pedantic-errors -c main.c 
