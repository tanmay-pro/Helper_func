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

void dijkstra(ptrgraph g, int source_vertex, int n, ll d[], ll p[], ll weight_matrix[][n])
{
    fo(i, n)
    {
        d[i] = m;
        p[i] = -1;
    }
    bool visited[n];
    fo(i, n)
    {
        visited[i] = false;
    }
    d[source_vertex] = 0;
    fo(i, n)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if (d[v] == m)
            break;
        visited[v] = true;
        while (g->prev_vertex_arr[v] != NULL)
        {
            ll dest = g->prev_vertex_arr[v]->element;
            ll len = weight_matrix[v][g->prev_vertex_arr[v]->element];
            if (d[v] + len < d[dest])
            {
                d[dest] = d[v] + len;
                p[dest] = v;
            }
            g->prev_vertex_arr[v] = g->prev_vertex_arr[v]->next;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, lol;
        scanf("%d %d", &n, &lol);
        ptrgraph g;
        g = CreateGraph(n);
        ll matrix[n][n];
        fo(i, lol)
        {
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            InsertEdge(g, a - 1, b - 1);
            matrix[a - 1][b - 1] = c;
        }
        ll d[n];
        ll p[n];
        dijkstra(g, source - 1, n, d, p, matrix);
    }
    return 0;
}