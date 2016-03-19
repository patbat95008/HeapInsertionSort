/* By Patrick Russell
 *    pcrussel@ucsc.edu
 *
 * NAME: insertionSort.c
 *
 * PURPOSE: Sort a series of keys from
 *          largest to smallest in an array
 */

void insertionSort(int keys[], int numKeys){
   int index = 1;
   int j_index = 0;
   int tmp = 0;
   /*loop through the array, checking each number*/
   for(index = 1; index <= numKeys; index++){
      j_index = index;
      /*check to see if the number is sorted correctly*/
      while(j_index > 0 && keys[j_index-1] > keys[j_index]){
         tmp = keys[j_index];
         keys[j_index] = keys[j_index - 1];
         keys[j_index - 1] = tmp;
	 j_index--;
      }
   }
   printSort(keys, numKeys);
}

/*print the array*/
void printSort(int keys[], int numKeys){
   int index = 0;
   printf("%d\n", numKeys);
   for(index = 0; index < numKeys; index++){
      printf("%d\n", keys[index]);
   }
}
