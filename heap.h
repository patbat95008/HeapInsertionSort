/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: heap.h
 *
 * PURPOSE: Header file for heap.c
 *
 */

typedef struct heapStruct * heapHndl;

/* make an empty heap */
heapHndl newHeap(int maxSize);

/* build a heap with the data array */
heapHndl buildHeap(int maxSize, int **data, int numData);

/* returns 1 if full, 0 otherwise */
int isFull(heapHndl H);

/* returns 1 if empty, 0 otherwise */
int isEmpty(heapHndl H);

/* returns the highest priority in heap */
int maxValue(heapHndl H);

/* deletes the hightest priority node */
void deleteMax(heapHndl H);

/* creates a new node for a new priority */
void insert(heapHndl H, int priority);

/* print the contents of the heap*/
void printHeap(heapHndl H);

/* free heap from memory*/
void freeHeap(heapHndl H);
