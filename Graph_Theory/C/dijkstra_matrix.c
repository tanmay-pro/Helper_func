#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
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
int MOD = 1e9 + 7;

ll minimum(ll *a, ll *b)
{
    if (*a < *b)
        return *a;
    else
        return *b;
}

ll minDistance(ll dist[], bool sptSet[], ll V)
{
    ll min = MOD;
    ll min_index = 0;

    fo(v, V)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(ll V, ll graph[][V], ll src, ll dist[], ll parent[])
{
    bool sptSet[V];
    fo(i, V)
    {
        dist[i] = MOD;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        ll u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        fo(v, V)
        {
            if (!sptSet[v] && (graph[u][v] > 0) && dist[u] + graph[u][v] <= dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}
