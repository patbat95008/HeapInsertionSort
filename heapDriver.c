/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: heapDriver.c
 *
 * PURPOSE: test the functions of heap.c
 *
 */

#include<stdio.h>
#include<stdlib.h>

#include"heap.h"
#include"insertionSort.h"

int main(){
   heapHndl *test1 = newHeap(10);
   printf("Test1 = %p\n", test1);
   int **data[] = {5,3,2,1,10};
   
   heapHndl *test2 = buildHeap(10, data, 5);
   printf("Test2 = %p\n", test2);
   insert(test1, 1);
   insert(test1, 2);
   insert(test1, 4);
   insert(test1, 20);
   insert(test1, 3);
   printf("Test1 isEmpty = %d\n", isEmpty(test1));
   printf("Test2 isFull = %d\n\n", isFull(test2));
   printHeap(test1);

   printf("now testing insertionSort...\n");
   int data2[] = {1,3,56,33,2};
   insertionSort(data2, 5);
   
   return 1;
}
