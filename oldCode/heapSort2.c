#include <stdio.h>
#include <stdlib.h>
 
#define ValType double
#define IS_LESS(v1, v2)  (v1 < v2) 
#define SWAP(r,s)  do{ValType t=r; r=s; s=t; } while(0)
 
void heapSort(int a[], int count){
    int start, end;
 
    /* heapify */
    for (start = (count-2)/2; start >=0; start--) {
        siftDown( a, start, count);
    }
 
    for (end=count-1; end > 0; end--) {
	printf("in heapSort, swapping a[%d] and a[0]\n", end);
        SWAP(a[end],a[0]);
        siftDown(a, 0, end);
    }
}
 
void siftDown( ValType *a, int start, int end){
    int root = start;
    printf("start = %d\n end = %d\n", start, end); 
    int child = 0;
    while ( root*2+1 < end ) {
        child = 2*root + 1;
        printf("child = %d\n", child);
        if ((child + 1 < end) && IS_LESS(a[child],a[child+1])) {
            child += 1;
            printf("child++ = %d\n", child);
        }
        if (IS_LESS(a[root], a[child])) {
            printf("swapping a[%d] = %d and a[%d] = %d\n", child, a[child], root, a[root]);
            SWAP( a[child], a[root] );
            root = child;
        }
        else
            return;
    }
}

