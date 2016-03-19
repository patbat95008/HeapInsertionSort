# By Patrick Russell
#    pcrussel@ucsc.edu
#
# Makefile for programing assignment 3
# compiles sortPrint, sortComp, and heapDriver executables

heapDriver : heapdriver.o heap.o
	gcc -ansi -Wall -Wextra -pedantic -o heapDriver heapDriver.o heap.o

sortComp : sortComp.o heapSort.o insertionSort.o heap.o list.o
	gcc -ansi -Wall -Wextra -pedantic -o sortComp sortComp.o heapSort.o insertionSort.o heap.o list.o

sortPrint : sortPrint.o heapSort.o insertionSort.o heap.o list.o
	gcc -ansi -Wall -Wextra -pedantic -o sortPrint sortPrint.o heapSort.o insertionSort.o heap.o list.o

heapDriver.o : heapdriver.c heap.c
	gcc -c -ansi -Wall -Wextra -pedantic heapdriver.c heap.c

sortComp.o : sortComp.c heap.c insertionSort.c
	gcc -c -ansi -Wall -Wextra -pedantic sortComp.c heap.c insertionSort.c

sortPrint.o : sortPrint.c heap.c insertionSort.c
	gcc -c -ansi -Wal -Wextra -pedantic sortPrint.c heap.c insertionSort.c

list.o : list.h list.c
	gcc -c -ansi -Wall -Wextra -pedantic list.c

heap.o : heap.h heap.c
	gcc -c -ansi -Wall -Wextra -pedantic heap.c

insertionSort.o : insertionSort.h insertionSort.c
	gcc -c -ansi -Wall -Wextra -pedantic insertionSort.c

heapSort.o : heapSort.h heapSort.c
	gcc -c -ansi -Wall -Wextra -pedantic heapSort.c

clean :
	rm heapDriver sortComp sortPrint heapDriver.o sortComp.o sortPrint.o list.o heap.o insertionSort.o heapSort.o
