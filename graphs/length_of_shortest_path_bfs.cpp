#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
int m = 1e9 + 7;
int p = 31;

bfs_length_of_shortest_path(vvl &adj, int num_of_nodes, int source_vertex)
{   
    queue<int> q;
    vector<bool> visited;
    vi distance(num_of_nodes, 0);
    q.push(source_vertex);
    visited[source_vertex] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (visited[adj[v][i]] == false)
            {
                q.push(adj[v][i]);
                visited[adj[v][i]] = true;
                distance[adj[v][i]] = distance[v] + 1;
            }
        }
    }
}
