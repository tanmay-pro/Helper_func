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
int MOD = 1e9 + 7;

typedef struct edge
{
    ll source;
    ll des;
    ll weight;
} edge;

int cmpfunc(const void *a, const void *b)
{
    const edge *x = a;
    const edge *y = b;
    return x->weight - y->weight;
}

ll find(ll x, ll king[])
{
    if (king[x] != x)
    {
        king[x] = find(king[x], king);
        return king[x];
    }
    else
    {
        return king[x];
    }
}

void unionfn(ll rank[], ll king[], ll a, ll b)
{
    if (rank[a] > rank[b])
    {
        rank[a] += rank[b];
        king[b] = king[a];
    }
    else
    {
        rank[b] += rank[a];
        king[a] = king[b];
    }
}

// void unionfn(ll a, ll b, ll king[])
// {
//     king[a] = b;
// }

ll mstsum(ll king[], ll m, edge array[], ll rank[])
{
    ll sum = 0;
    fo(i, m)
    {
        ll king1 = find(array[i].source, king);
        ll king2 = find(array[i].des, king);
        if (king1 != king2)
        {
            unionfn(rank, king, king1, king2);
            sum += array[i].weight;
        }
    }
    return sum;
}

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll rank[n + 1];
    fo(i, n + 1)
    {
        rank[i] = 0;
    }
    edge array[m];
    fo(i, m)
    {
        edge e;
        scanf("%lld %lld %lld", &e.source, &e.des, &e.weight); // Inputting all the edges 
        array[i] = e;
    }
    qsort(array, m, sizeof(edge), cmpfunc);
    ll king[n + 1];
    fo(i, n + 1)
    {
        king[i] = i;
    }
    ll ans = mstsum(king, m, array, rank);
    printf("%lld", ans);
    br;
    return 0;
}
