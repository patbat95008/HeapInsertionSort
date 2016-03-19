/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: heap.c
 *
 * PURPOSE: Implements the heap ADT
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
   heapStruct *new = malloc(sizeof(heapStruct));
   int *newArray = malloc(sizeof(int) * maxSize);
   new->maxSize = maxSize;
   new->currentSize = 0;
   new->data = newArray;
   return new;
}

/* build a heap with the given data */
heapHndl buildHeap(int maxSize, int data[], int numData){
   heapStruct *new = malloc(sizeof(heapStruct));
   int *newArray = malloc(sizeof(int) * maxSize);
   int i = 0;
   int tmp = 0;

   if(maxSize == 0){
      printf("ERROR: Maxsize == 0\n");
      return NULL;
   }else if(numData == 0){
      printf("ERROR: numData == 0\n");
      return NULL;
   }
   
   new->currentSize = 0;
   new->maxSize = maxSize;
   new->data = newArray;
   /*while(i < numData){
     tmp = data[i];
     insert(new, tmp);
     i++;
   }*/
   while(i < numData){
      tmp = data[i];
      newArray[i] = tmp;
      i++;
   }
   heapSort(newArray, numData);
   new->data = newArray;
   new->currentSize = numData;
   /*heapSort(new->data, new->currentSize);*/
   printHeap(new);
   return new;
}

/* returns 1 if full, 0 otherwise */
int isFull(heapHndl H){
   if(H->currentSize == H->maxSize){
      return 1;
   }
   return 0;
}

/* returns 1 if empty, 0 otherwise */
int isEmpty(heapHndl H){
   if(H->currentSize == 0){
      return 1;
   }

   return 0;
}

/* returns the highest priority in heap */
int maxValue(heapHndl H){
   if(isEmpty(H) == 1){
      return NULL;
   }
   return H->data[0];
}

/* deletes the hightest priority node */
void deleteMax(heapHndl H){

   if(isEmpty(H) == 1){
      return;
   }

   int i = 0;
   int tmp = 0;
   /*loop through the list, 
    *advancing it over the data
    *by 1*/
   while(i < H->currentSize - 1){
      tmp = H->data[i+1];
      H->data[i] = tmp;
      i++;
   }
   H->currentSize--;
   
   heapSort(H->data, H->currentSize);
   printHeap(H);
}

/* creates a new node for a new priority */
void insert(heapHndl H, int priority){
   heapSort(H->data, H->currentSize);
   if(isFull(H) == 1){
     H = buildHeap(H->maxSize++, H->data, H->currentSize++);
   }
   int tmp = H->currentSize;
   H->data[tmp] = priority;
   heapSort(H->data, H->currentSize);
   H->currentSize++;
   printHeap(H);
}

/* Print the heap*/
void printHeap(heapHndl H){
   if(H->currentSize == 0) return;
   int index = 0;
   for(index = 0; index < H->currentSize; index++){
      printf("H->data[%d] = %d\n", index, H->data[index]);
   }
   printf("\n");
}
