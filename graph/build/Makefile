main.o:
	gcc -g ../main.c

compil:
	gcc -g -c ../*.c

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