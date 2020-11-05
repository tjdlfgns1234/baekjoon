#include <iostream>
#include <algorithm>
#include <list>
#define SIZE 500
#define INF 987654321000
using namespace std;

long long dist[SIZE + 1];
int parent[SIZE + 1];

bool check = false;

struct Edge {
    long long dir;
    long long weight;
};

void init();
int find(int v);
void _union(int v, int u);
void BF(long long n, long long m);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    init();
    BF(n, m);
    
    for (int i = 2; i < n + 1; i++)
        if (!check)
            if (dist[i] != INF)
                cout << dist[i] << "\n";
            else
                cout << -1 << "\n";
        else {
            cout << -1 << "\n";
            break;
        }
    return 0;
}
void BF(long long n, long long m)
{
    long long v1, v2, weight;
    list <Edge>* graph;
    graph = new list<Edge>[n + 1];
    for (int i = 0; i < n + 1; i++)
        dist[i] = INF;

    for (int i = 0; i < m; i++)     // 버스 입력
    {
        cin >> v1 >> v2 >> weight;
        _union(v1, v2);
        graph[v1].push_front({ v2,weight });
        //graph[v2].push_front({ v1,weight });
    }

    // 벨만 포드 알고리즘 수행
    dist[1] = 0;
    list <Edge>::iterator it;
    for (int cnt = 0; cnt < n - 1; cnt++)
        for (int i = 1; i < n + 1; i++)
            if (find(i) != 1)
                continue;
            else
                 for (it = graph[i].begin(); it != graph[i].end(); it++)
                     dist[it->dir] = min(dist[it->dir], dist[i] + it->weight);

    // negative cycle test
    for (int i = 1; i < n + 1; i++)
        if (find(i) != 1)
            continue;
        else
              for (it = graph[i].begin(); it != graph[i].end(); it++)
                   if (dist[it->dir] > (dist[i] + it->weight))
                       check = true;

    return;
}
void init()
{
    for (int i = 0; i < SIZE + 1; i++)
    {
        parent[i] = i;
    }
}
int find(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find(parent[v]);
}
void _union(int v, int u)
{
    v = find(v), u = find(u);

    if (v == u)
        return;
    else if(v > u)
        parent[v] = u;
    else
        parent[u] = v;
}