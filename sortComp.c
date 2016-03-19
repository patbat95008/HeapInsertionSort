/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: sortComp.c
 *
 * PURPOSE: Test the sorting algorithms for time.
 *          Gets a file, reads the first line as
 *          the number of numbers to follow.
 *          It then sorts the array 2 different ways,
 *          through heapSort and insertionSort.
 *
 * USAGE: sortComp FILENAME
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"heap.h"
#include"insertionSort.h"

int main(int argc, char **argv){
   /* Determine if the correct filenames were used*/
   if(argc < 2){
      printf("SortComp usage: sortComp FILENAME\n");
      return 0;
   }
   /*open the file*/
   FILE *input;
   input = fopen(argv[1], "r");
   time_t start, end;
   int index = 0;
   int size = 0;
   int data = 0;
   int tmp = 0;
   double result = 0;
   double result2 = 0;

   /*build the array based on first line of file*/
   if(fscanf(input, "%d", &tmp) != NULL){
      size = tmp;
   }else{
      printf("ERROR: first line of file wasn't a number\n");
      return 0;
   }
   /*build 2 arrays: one for heapSort, one for insertionSort*/
   int array1[size];
   int array2[size];

   /*fill arrays*/
   while(!feof(input) && fscanf(input, "%d", &data) && index+1 <= size){
      array1[index] = data;
      array2[index] = data;
      index++;
   }

   /*heapSort the first array*/
   time(&start);
   heapHndl heap = newHeap(size+1);
   for(tmp = 0; tmp < size; tmp++){
      insert(heap, array1[tmp]);
   }
   /*inserting zero to sort one final time*/
   insert(heap, 0);
   time(&end);
   result = difftime(end, start);
   /*print data*/
   printf("heapSort:\n");
   printHeap(heap);
   freeHeap(heap);  

   /*insertionSort the second array*/
   printf("insertionSort:\n");
   time(&start);
   insertionSort(array2, size);
   time(&end);
   /*print data*/
   result2 = difftime(end, start);
   printf("%.2lf seconds elapsed for insertionSort.\n", result2);
   printf("%.2lf seconds elapsed for heapSort.\n", result);
   fclose(input);

   return 0;
}
