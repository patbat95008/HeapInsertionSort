/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: heap.c
 *
 * PURPOSE: Implements the heap ADT. Has insertion, 
 *          printing, and deleting functions. Implements
 *          heapSort to sort heaps.
 *
 */

#include<stdio.h>
#include<stdlib.h>

#include"heapSort.h"

typedef struct heapStruct * heapHndl;

typedef struct heapStruct{
   int maxSize;
   int currentSize;
   int *data;
}heapStruct;


/* make an empty heap */
heapHndl newHeap(int maxSize){
   /*allocate memory*/
   heapStruct *new = malloc(sizeof(heapStruct));
   int *newArray = malloc(sizeof(int) * maxSize);
   /*set parameters*/
   new->maxSize = maxSize;
   new->currentSize = 0;
   new->data = newArray;

   return new;
}

/* build a heap with the given data
 * PRE: maxSize = maximum size of array
 *      numData = number of elements in array
 */
heapHndl buildHeap(int maxSize, int **data, int numData){
   heapStruct *new = malloc(sizeof(heapStruct));
   int *newArray = malloc(sizeof(int) * maxSize);
   int i = 0;
   int tmp = 0;

   /*check the preconditions*/
   if(maxSize == 0){
      printf("ERROR: Maxsize == 0\n");
      return NULL;
   }else if(numData == 0){
      printf("ERROR: numData == 0\n");
      return NULL;
   }

   /*build a new heap*/   
   new->currentSize = 0;
   new->maxSize = maxSize;
   new->data = newArray;
   /*fill heap with data*/
   while(i < numData){
     tmp = data[i];
     insert(new, tmp);
     i++;
   }
   heapSort(new->data, numData);

   return new;
}

/* Returns 1 if full, 0 otherwise */
int isFull(heapHndl H){
   if(H->currentSize == H->maxSize){
      return 1;
   }
   return 0;
}

/* Returns 1 if empty, 0 otherwise */
int isEmpty(heapHndl H){
   if(H->currentSize == 0){
      return 1;
   }

   return 0;
}

/* Returns the highest priority in heap
 * PRE: Heap must not be empty
 */
int maxValue(heapHndl H){
   if(isEmpty(H) == 1){
      return NULL;
   }
   return H->data[H->currentSize - 1];
}

/* deletes the hightest priority node 
 * PRE: Heap must not be empty
 */
void deleteMax(heapHndl H){
   /*check precondition*/
   if(isEmpty(H) == 1){
      return;
   }

   int i = 0;
   int tmp = 0;
   /*swap the next largest node with the smallest*/
   H->data[H->currentSize-1] = H->data[0];
   H->currentSize--;
   /*then heapSort*/
   heapSort(H->data, H->currentSize);
}

/* creates a new node for a new priority */
void insert(heapHndl H, int priority){
   /*sort through the list*/
   heapSort(H->data, H->currentSize);

   /*if heap is full, make a new heap and free old one*/
   if(isFull(H) == 1){
     heapHndl tmp;
     tmp = buildHeap(H->maxSize++, H->data, H->currentSize++);
     free(H);
     H = tmp;     
   }
   /*set the new node at the top of the tree*/
   int tmp = H->currentSize;
   H->data[tmp] = priority;
   /*sort the heap*/
   heapSort(H->data, H->currentSize);
   H->currentSize++;
}

/*frees the heap from memory*/
void freeHeap(heapHndl H){
   free(H->data);
   free(H);
}

/* Print the heap
 * PRE: heap is not empty
 */
void printHeap(heapHndl H){
   /*check precondition*/
   if(H->currentSize == 0) return;
   int index = 0;
   /*print the size, then the contents of the heap*/
   printf("%d\n", H->maxSize - 1);
   for(index = 0; index < H->currentSize - 1; index++){
      printf("%d\n", H->data[index]);
   }
   printf("\n");
}
