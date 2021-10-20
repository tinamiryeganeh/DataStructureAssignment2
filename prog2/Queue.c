#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Queue.h"
// Implemeting Queue

/* 
TODO: define the Queue structure using 'typedef struct Queue' - this queue holds integer values
the Queue struct has the following fields:
- head: corresponding to the head of the queue
- tail: indicating the tail of the queue
- length: length of the array used for implementing the queue
- count: number of elements in the queue
- array: (pointer to) the array used for implementing the queue
*/

// Implementation file for Queue ADT

// private QueueObj type
typedef struct Queue
{
    int head;
    int tail;
    int length;
    int count;
    int *arrayPtr;
} Queue;

//------------------------------------------------------------------------

/*
TODO: implement the initializeQueue - this function instantiates the Queue struct using malloc and sets the values for the fields.
Arguments to this function are:
- int* arr: (pointer to) array 'arr' that is used for implementing the queue
- int n: length of array 'arr'
It returns a pointer to the instantiated Queue
*/

Queue *initializeQueue(int n, int *arr)
{
    Queue *Q;
    Q = malloc(sizeof(Queue));
    Q->head = 0;
    Q->tail = 0;
    Q->length = n;
    Q->arrayPtr = arr;
    return (Q);
}

//------------------------------------------------------------------------

/*
TODO: implement Queue destructor - this function frees memory allocated to Queue
Argument to this function is a queue pointer
*/
void destructQueue(Queue *q)
{
    if (q != NULL)
    {
        while (q->length != 0)
        {
            dequeue(q);
        }
        free(q);
        q = NULL;
    }
}

//------------------------------------------------------------------------

/* TODO: implement the 'enqueue' functionality
This function takes in a queue pointer and int value 'x' and adds 'x' to queue
Need to check for overflow

*/
// Enqueue()
// Places new data at the back of Q.
void enqueue(Queue *q, int x)
{
    if (q == NULL)
    {
        printf("Queue Error: calling Enqueue() on NULL Queue reference\n");
        exit(EXIT_FAILURE);
    }
    if (q->count == q->length - 1)
    {
        printf("Overflow \n");
    }
    q->arrayPtr[q->tail] = x;
    q->tail = q->tail+1;
    if (q->tail == q->length)
    {
       q->tail =0;
    } 
    q->count++;  
}

//------------------------------------------------------------------------

/* TODO: implement the 'dequeue' functionality
This function takes in a queue pointer and removes element from head of the queue
Need to check for underrflow
*/

int dequeue(Queue *q)
{
    if (q == NULL)
    {
        printf("Queue Error: calling Dequeue() on NULL Queue reference\n");
        exit(EXIT_FAILURE);
    }
    if ( q->count == 0 )
    {
        exit(EXIT_FAILURE);
    }
    int x = q->arrayPtr[q->head];
    q->head = q->head +1;
    if(q->head == q->length)
    {
        q->head = 0;
    }
    q->count--;
    return x;
}

//------------------------------------------------------------------------

/* TODO: implement the printQueue
This function takes in a queue pointer and prints the contents of the queue in order (head to tail)
Note: this is a non-trivial function
*/
// printQueue()
void printQueue(Queue *q)
{

    if (q == NULL)
    {
        printf("Queue Error: calling printQueue() on NULL Queue reference\n");
        exit(EXIT_FAILURE);
    }
    //printf("Queue: ");
    for (int i = 0; i <= count(q)-1; i++)
    {
        printf("%d ", q->arrayPtr[i]);
    }
    printf("\n");
}
//------------------------------------------------------------------------

/* TODO: implement the count
This function takes in a queue pointer and returns the 'count' field of the queue
Implementing this is necessarity for the simulator to run properly
*/

int count(Queue *q)
{
    return (q->count);
}

//-----------------------------------------------------------------------------