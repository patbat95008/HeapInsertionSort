/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: heapSort.c
 *
 * PURPOSE: sort a given heap by priority
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct heapStruct * heapHndl;

/* sorts a given heap.
 * PRE: numKeys > 1
 * POST: returns nothing.
 */
void heapSort(int keys[], int numKeys){
   printf("heapSort called\n");
   heapify(keys, numKeys);
   int end = numKeys;
   while(end > 1){
      swap(keys, end, 1);
      end--;
      maxHeapify(keys, 1, end);
   }
}

/* Fixes from the top of a heap going down.
 * PRE: start is not a root.
 */
void maxHeapify(int keys[], int start, int end){
   printf("maxHeapify called\n");
   int root = start;
   int child = 0;
   int tmp = 0;
   /* While the root has at least one child,
    * keep looping through list
    */
   while(root * 2 + 1 <= end){
      child = root * 2 + 1; /* left child */
      tmp = root; /*tracks child to swap with*/
      printf("While loop: child = %d\n", child);
      printf("while loop: tmp = %d\n", tmp);
      if (keys[tmp] < keys[child]){
         tmp = child;
      }
      if (child + 1 <= end && 
          keys[tmp] < keys[child + 1]){
         tmp = child + 1;
      }
      if(tmp != root){
         swap(keys, root, tmp);
         root = tmp; /*sift down with the child*/
      }else{
         return;
      }
   } 
}

/* Put elements of keys in heap order, in place */
void heapify(int keys[], int index){
   printf("heapify called\n");
   int start = (index - 2)/2;/*start is the last parent node*/

   /* Sift down node at start to the index so that 
    * all nodes are ordered
    */
   while(start >= 0){
      maxHeapify(keys, start, index-1);
      start--;
   }
}

/* Fixes the order of a root.
 * PRE: start must not be the root.
 */
void fixProblemChild(int keys[], int start){
   printf("fixProblemChild start = %d\n", start);
   if(start == 1) return; /*at root*/
   int parent = start/2;
   if(keys[start] > keys[parent]){
      swap(keys, start, parent);
      fixProblemChild(keys, parent);
   }else{
      return;
   }
}


/* Finds the maximum of the three keys
 * PRE: left, right, and start must be in the array
 * POST: returns the largest location, not the data
 *       in said location
 */
int maximum(int keys[], int left, int right, int start){
   if(keys[start] > keys[right] 
      && keys[start] > keys[left]){
      return start;
   }

   if(keys[left] > keys[start] 
      && keys[left] > keys[right]){
      return left;
   }

   if(keys[right] > keys[start]
      && keys[right] > keys[left]){
      return right;
   }
   
   return start;
}

/* Swaps the data from 2 locations
 * PRE: first and second must be in the array
 * POST: returns nothing
 */
void swap(int keys[], int first, int second){
   printf("swap called\n");
   int tmp = keys[first];
   int swap = keys[second];
   keys[first] = swap;
   keys[second] = tmp;
}
