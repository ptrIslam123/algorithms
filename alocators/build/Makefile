main.o:
	gcc -g ../main.c

compil:
	gcc -g -Wall -c ../*.c

link:
	gcc *.o -o main


build:
	make compil
	make link
	

run:
	./main

debug:
	kdbg ./main

clear:
	rm *.o
	rm ./main