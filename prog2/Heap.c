// Implementation of (Max) Heap
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Heap.h"

// TODO: Implement funcs for fetching parent and left/right child
int parent(int i)
{
    return ((i-1)/2);
}

int left(int i)
{
    return ((2*i)+1);
}

int right(int i)
{
    return ((2*i) + 2);
}

//------------------------------------------------------------------------

// TODO: Helper function for swapping A[i] and A[j] elements in an array
void swap(int *A, int i, int j)
{
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//------------------------------------------------------------------------

/* TODO: declare the Heap struct as in the header file
This Heap struc has the following fields:
- len: length of the array used for implementing the heap
- size: number of elements in the backbone array that are 'heapified' or ordered as heap
- array: (pointer to) array used for implementing the heap
*/
typedef struct Heap
{
    int len;
    int size;
    int *arrayPtr;
} Heap;

//------------------------------------------------------------------------

/* TODO: implement initializeHeap function which instantiates a heap using malloc.
This function takes in the following arguments:
- length of the array used for implementation
- size of the heap; i.e. number of elements in array that we want to be ordered as heap
- pointer to array used for implementing the heap
It returns a pointer to the instantiated heap
*/
Heap *initializeHeap(int len, int h_size, int *arr)
{
    Heap *H;
    H = malloc(sizeof(Heap));
    H->len = len;
    H->size = h_size;
    H->arrayPtr = arr;
    return (H);
}

//------------------------------------------------------------------------

/*  TODO: implement heap destructor that frees memory allocated to heap */

void destructHeap(Heap *h)
{
    if (h != NULL)
    {
        free(h);
        h = NULL;
    }
}

//------------------------------------------------------------------------

/* TODO: implement 'heapify' function, given a heap pointer and an index i
This function maintain (max) Heap property given an index i for heap h
*/

void heapify(Heap *h, int i)
{
    int l, r;
    int largest;
    l = left(i);
    r = right(i);
    if (l <= h->size && h->arrayPtr[l] > h->arrayPtr[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= h->size && h->arrayPtr[r] > h->arrayPtr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(h->arrayPtr, i, largest);
        heapify(h, largest);
    }
}

//------------------------------------------------------------------------

/* TODO: implement array_to_heap function
You may use initializeHeap function for implementing this function
*/
Heap *array_to_Heap(int *A, int len, int size)
{
    return initializeHeap(len, size, A);
}

//------------------------------------------------------------------------

/* TODO: implement utility functions:
- size(): returns the size field of a heap
- len(): returns the length field of a heap
*/
int size(Heap *h)
{
    return h->size;
}

int len(Heap *h)
{
    return h->len;
}