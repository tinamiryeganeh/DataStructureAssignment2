#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include <math.h>
#include <limits.h> 
#include"Heap.c"
#include"PriorityQueue.h"

/* TODO: implement get_max
returns largest element in heap/highest priority
*/
int get_max(Heap* h){
     return (h->arrayPtr[0]);
}

//------------------------------------------------------------------------

/* TODO: implement extract_max
extracts and returns max element in heap
note that heap property must be maintained after extraction
also check for valid input (cannot extract from empty heap)
*/
int extract_max(Heap* h){
    if(h->size<1){
        printf("PriorityQueue Error: Heap underflow!\n");
        exit(EXIT_FAILURE);
    }
    int max = get_max(h);
    //check this line
    h->arrayPtr[0] = h->arrayPtr[h->size-1];
    h->size = h->size -1;
    heapify(h, 0);
    return max;
}



//------------------------------------------------------------------------

/* TODO: implement increase_priority
This function increases priority/value of element at index i to 'new_value'
*/
void increase_priority(Heap* h, int i, int new_value){
    if(new_value < h->arrayPtr[i]){
        printf("PriorityQueue Error: New value is smaller than current key!\n");
        exit(EXIT_FAILURE);
    }
    h->arrayPtr[i] = new_value;
    while(i>0 && h->arrayPtr[parent(i)] < h->arrayPtr[i]){

        swap(h->arrayPtr, i, parent(i));
        i = parent(i);
    }
}


//------------------------------------------------------------------------

/* TODO: implement insert functionality
This function inserts priority 'value' into heap
You will need to have implemented the increase_priority and use it here
*/
void insert(Heap* h, int value){
    h->size = h->size+1;
    h->arrayPtr[h->size-1] = INT_MIN;
    increase_priority(h, h->size-1, value);
}