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


typedef struct graph *ptrgraph;
typedef struct vertex *ptrvertex;
typedef ll ElementType;

typedef struct graph
{
    int number_of_vertices;
    ptrvertex *prev_vertex_arr;
} graph;

typedef struct vertex
{
    ElementType element;
    ptrvertex next;
} vertex;


ptrgraph CreateGraph(int n)
{
    ptrgraph G;
    G = (ptrgraph)malloc(sizeof(struct graph));
    G->number_of_vertices = n;
    G->prev_vertex_arr = (ptrvertex *)malloc(n * sizeof(struct vertex));
    fo(i, n)
    {
        G->prev_vertex_arr[i] = NULL;
    }
    return G;
}

void InsertEdge(ptrgraph G, ElementType u, ElementType v)
{
    bool found = false;
    ptrvertex temp;
    ElementType w;
    temp = G->prev_vertex_arr[u];
    if (temp == NULL)
    {
        G->prev_vertex_arr[u] = (ptrvertex)malloc(sizeof(struct vertex));
        G->prev_vertex_arr[u]->element = v;
        G->prev_vertex_arr[u]->next = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        w = temp->next->element;
        if (w == v)
            found = true;
        temp = temp->next;
    }
    if (!found)
    {
        temp = (ptrvertex)malloc(sizeof(struct vertex));
        temp->element = v;
        temp->next = G->prev_vertex_arr[u]->next;
        G->prev_vertex_arr[u]->next = temp;
    }
    return;
}
