#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define ll long long
#define PI 3.14159265
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
int m = 1e9 + 7;

typedef struct MinHeap *ptrheap;

typedef struct MinHeap
{
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
} min_heap;

typedef ll ElementType;

void swap(ElementType *x, ElementType *y);           // Swap Elements
int parent(int i);                                   // Return parent of Node
int left_child(int i);                               // Return left Child
int right_child(int i);                              // return right Child
int getMinimum(ptrheap h);                           // Get Minimum Element from Min_Heap
void insertElement(ElementType k, ptrheap h);        // Insert Element k in Min Heap
void decreaseElement(int i, int new_val, ptrheap h); // Change Value of some element to a new reduced vaue
ElementType extractMin(ptrheap h);                   // Remove Min Element and return it
void deleteElement(int i, ptrheap h);                // Deletes Element at index 'i'
void MinHeapify(int i, ptrheap h);                   // Heapify Function

void swap(ElementType *x, ElementType *y)
{
    ElementType temp = *x;
    *x = *y;
    *y = temp;
}

int parent(int i)
{
    return (i - 1) / 2;
}

int left_child(int i)
{
    return (2 * i + 1);
}

int right_child(int i)
{
    return (2 * i + 2);
}

int getMinimum(ptrheap h)
{
    return h->harr[0];
}

void insertElement(ElementType k, ptrheap h)
{
    if (h->heap_size == h->capacity)
    {
        printf("Heap full");
        br;
        return;
    }
    h->heap_size++;
    int i = h->heap_size - 1;
    h->harr[i] = k;
    while (i != 0 && h->harr[parent(i)] > h->harr[i])
    {
        swap(&h->harr[i], &h->harr[parent(i)]);
        i = parent(i);
    }
}

void decreaseElement(int i, int new_val, ptrheap h)
{
    h->harr[i] = new_val;
    while (i != 0 && h->harr[parent(i)] > h->harr[i])
    {
        swap(&h->harr[i], &h->harr[parent(i)]);
        i = parent(i);
    }
}

ElementType extractMin(ptrheap h)
{
    if (h->heap_size <= 0)
        return m;
    if (h->heap_size == 1)
    {
        h->heap_size--;
        return h->harr[0];
    }
    ElementType root = h->harr[0];
    h->harr[0] = h->harr[h->heap_size - 1];
    h->heap_size--;
    MinHeapify(0, h);
    return root;
}

void deleteElement(int i, ptrheap h)
{
    decreaseElement(i, m, h);
    extractMin(h);
}

void MinHeapify(int i, ptrheap h)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < h->heap_size && h->harr[l] < h->harr[i])
        smallest = l;
    if (r < h->heap_size && h->harr[r] < h->harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&h->harr[i], &h->harr[smallest]);
        MinHeapify(smallest, h);
    }
}
