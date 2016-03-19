/* by Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: heapSort.c
 *
 * PURPOSE: take an array and sort it, then return sorted array.
 *
 */



#include<stdio.h>
#include<stdlib.h>

   /* Iterate down, extract max child, swap max with root
    * PRE: root = place to start, bottom = place to stop
    */
void iterateDownHeap(int numbers[], int root, int bottom){
   /* index = node that has already been checked for heap property*/
   /* left child = 2i, right child=2i + 1 for parent at i*/
   int index = 0;
   int maxChild = 0;
   int tmp = 0;

   /* Loop iterates by swapping maxchild with root and then iterating 
    * over the subtree of maxchild in the same manner
    */
   while ((root*2 <= bottom) && (!index)){
      if (root*2 == bottom){
         maxChild = root * 2;
      }else if (numbers[root * 2] > numbers[root * 2 + 1]){
         maxChild = root * 2;
      }else{
         maxChild = root * 2 + 1;
      }
      /*max child = largest child that needs to be swapped with root*/
      if (numbers[root] < numbers[maxChild]){
       
         tmp = numbers[root];
         numbers[root] = numbers[maxChild];
         numbers[maxChild] = tmp;
         /* Swapped root element, or new maxchild,
          * is checked for satisfying the heap property
          */
         root = maxChild;
      }else{
         index = 1;
      }
   }
}

/* Sort a given array.
 * PRE: array_size = size of the array
 */
void heapSort(int keys[], int numKeys){
   int index = 0;
   int tmp = 0;

   /*build heap*/
   for (index = (numKeys / 2)-1; index >= 0; index--){
      iterateDownHeap(keys, index, numKeys);
   }
   /*sort heap by exchanging root(max) element of heap with first element of heap*/
   for (index = numKeys - 1; index >= 1; index--){
      tmp = keys[0];
      keys[0] = keys[index];
      keys[index] = tmp;
      iterateDownHeap(keys, 0, index-1);
   }
}
