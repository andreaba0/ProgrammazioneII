mergesort: main.o functions.o
	gcc -o mergesort.out main.o functions.o
	echo "compiling code..."

main.o: main.c header.h
	gcc -c main.c

functions.o: functions.c header.h
	gcc -c functions.c