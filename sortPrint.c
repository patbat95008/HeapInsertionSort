/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: sortPrint.c
 *
 * PURPOSE: Test the sorting algorithms in HeapSort and InsertionSort
 *
 * USAGE: sortPrint FILENAME
 *
 */

#include<stdio.h>
#include<stdlib.h>

#include"heap.h"
#include"insertionSort.h"

int main(int argc, char **argv){
   /* Determine if the correct filenames were used*/
   if(argc < 2){
      printf("SortPrint usage: sortPrint FILENAME\n");
      return 0;
   }
   FILE *input;
   input = fopen(argv[1], "r");

   int index = 0;
   int size = 0;
   int data = 0;
   int tmp = 0;

   /*build the array based on first line of file*/
   if(fscanf(input, "%d", &tmp) != NULL){
      size = tmp;
   }
   /*build 2 arrays: one for heapSort, one for insertionSort*/
   int array1[size];
   int array2[size];

   /*fill array*/
   while(!feof(input) && fscanf(input, "%d", &data) && index+1 <= size){
      array1[index] = data;
      array2[index] = data;
      index++;
   }

   /*heapSort the first array*/
   heapHndl heap = newHeap(size+1);
   for(tmp = 0; tmp < size; tmp++){
      insert(heap, array1[tmp]);
   }
   /*inserting zero to sort one final time*/
   insert(heap, 0);
   printf("heapSort:\n");
   printHeap(heap);
   freeHeap(heap);  

   /*insertionSort the second array*/
   printf("insertionSort:\n");
   insertionSort(array2, size);

   fclose(input);
   return 0;
}
