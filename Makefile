
FLAGS= -ansi -pedantic -Wall -g

# target
pce: main.o salesrank.o
	gcc -o pce main.o salesrank.o


main.o: main.c salesrank.h
	gcc $(FLAGS) -c main.c


salesrank.o: salesrank.c salesrank.h
	gcc $(FLAGS) -c salesrank.c

zip:
	zip proj_aed_fase1.zip Makefile main.c salesrank.h salesrank.c

clean:
	rm -f *.o pce