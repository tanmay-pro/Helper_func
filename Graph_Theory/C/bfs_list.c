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

typedef long long elementtype;
typedef struct node node;
typedef struct node *ptrnode;

struct node
{
    elementtype data;
    ptrnode next;
    ptrnode rear;
    ptrnode prev;
};

void push_front(ptrnode p, elementtype data); // Insert at front
ptrnode createnode(elementtype data);
void pop(ptrnode p);                         // Remove from front
void push_back(ptrnode p, elementtype data); // Insert at Rear
void eject(ptrnode p);                       // Remove item from rear
bool empty(ptrnode p);                       // Return whether the Queue is empty or not
int size(ptrnode p);                         // Return The size of Queue
elementtype front(ptrnode p);                // Return the first element of the queue
elementtype back(ptrnode p);                 // Return the last element of the queue

ElementType minimum_c(ElementType *a, ElementType *b)
{
    if (*b > *a)
    {
        return *a;
    }
    else
    {
        return *b;
    }
}

elementtype back(ptrnode p)
{
    return p->rear->data;
}

elementtype front(ptrnode p)
{
    return p->next->data;
}

int size(ptrnode p)
{
    int c = 0;
    while (p->next != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

bool empty(ptrnode p)
{
    if (p->next == NULL)
    {
        return true;
    }
    else
        return false;
}

void push_front(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    if (p->next == NULL)
    {
        p->rear = pnew;
    }
    else
    {
        p->next->prev = pnew;
    }
    pnew->next = p->next;
    p->next = pnew;
    pnew->prev = p;
}

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->data = e;
    p->next = NULL;
    p->prev = NULL;
    p->rear = NULL;
    return p;
}

void pop(ptrnode p)
{
    if (p->next != NULL)
    {
        if (p->next->next == NULL)
        {
            p->rear = p;
        }
        ptrnode temp = p;
        temp->next = p->next;
        temp = temp->next;
        p->next = temp->next;
        free(temp);
    }
}

void push_back(ptrnode p, elementtype e)
{

    ptrnode pnew = createnode(e);
    if (p->rear == NULL)
    {
        pnew->prev = p;
        p->next = pnew;
    }
    else
    {
        pnew->prev = p->rear;
        p->rear->next = pnew;
    }
    p->rear = pnew;
}

void eject(ptrnode p)
{
    if (p->rear != NULL)
    {
        ptrnode temp = p->rear;
        temp->prev->next = NULL;
        if (temp->prev != p)
            p->rear = temp->prev;
        else
        {
            p->rear = NULL;
        }
        free(temp);
    }
}

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

void bfs(ptrgraph g, ElementType source_vertex, bool visited[], ElementType mindis[])
{
    fo(i, g->number_of_vertices)
    {
        mindis[i] = 0;
    }
    ptrnode q;
    q = createnode(0);
    push_front(q, source_vertex);
    visited[source_vertex] = true;
    while (!empty(q))
    {
        ElementType v = back(q);
        eject(q);
        while (g->prev_vertex_arr[v] != NULL)
        {
            if (!visited[g->prev_vertex_arr[v]->element])
            {
                push_front(q, g->prev_vertex_arr[v]->element);
                visited[g->prev_vertex_arr[v]->element] = true;
                mindis[g->prev_vertex_arr[v]->element] = mindis[v] + 1;
            }
            g->prev_vertex_arr[v] = g->prev_vertex_arr[v]->next;
        }
    }
}

int main()
{
    ElementType n, m;
    scanf("%lld %lld", &n, &m);
    ptrgraph g;
    g = CreateGraph(n);
    fo(i, m)
    {
        ElementType a, b;
        scanf("%lld %lld", &a, &b);
        InsertEdge(g, a - 1, b - 1);
        InsertEdge(g, b - 1, a - 1);
    }
    ElementType source_vertex;
    scanf("%lld", &source_vertex);
    bool visited[n];
    fo(i, n)
    {
        visited[i] = false;
    }
    ElementType mindis[n];
    bfs(g, source_vertex - 1, visited, mindis);
    return 0;
}
