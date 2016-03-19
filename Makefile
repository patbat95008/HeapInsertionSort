# By Patrick Russell
#    pcrussel@ucsc.edu
#
# Makefile for programing assignment 3
# compiles sortPrint, sortComp, and heapDriver executables

GCC = gcc -ansi -Wall -Wextra -pedantic

all: heapDriver sortPrint sortComp

sortComp : sortComp.o heap.o insertionSort.o heapSort.o
	${GCC} -o sortComp sortComp.o heap.o insertionSort.o heapSort.o

sortPrint : sortPrint.o heap.o insertionSort.o heapSort.o
	${GCC} -o sortPrint sortPrint.o heap.o insertionSort.o heapSort.o

heapDriver : heapDriver.o heap.o heapSort.o insertionSort.o
	${GCC} -o heapDriver heapDriver.o heap.o heapSort.o insertionSort.o

sortComp.o : sortComp.c heap.h insertionSort.h
	${GCC} -c sortComp.c

sortPrint.o : sortPrint.c heap.h insertionSort.h
	${GCC} -c sortPrint.c

heapDriver.o : heapDriver.c heap.h insertionSort.h
	${GCC} -c heapDriver.c

heap.o : heap.h heap.c heapSort.h
	${GCC} -c heap.c heap.h

heapSort.o : heapSort.h heapSort.c
	${GCC} -c heapSort.c heapSort.h

insertionSort.o : insertionSort.h insertionSort.c
	${GCC} -c insertionSort.h insertionSort.c

clean :
	rm heapDriver.o heap.o heapSort.o heap.h.gch heapSort.h.gch insertionSort.o insertionSort.h.gch sortPrint.o sortComp.o
