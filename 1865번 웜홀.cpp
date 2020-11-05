#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#define SIZE 500
#define INF 987654321
using namespace std;

int dist[SIZE + 1];

struct Edge {
    int dir;
    int weight;
};

bool BF(int n, int m, int w);

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int tc;
    cin >> tc;
    int n, m, w;
    for (int i = 0; i < tc; i++)
    {
        cin >> n >> m >> w;
        if(BF(n, m, w))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

}
bool BF(int n, int m, int w)
{
    int v1, v2, weight;
    list <Edge>* graph;
    graph = new list<Edge>[n+1];
    for (int i = 1; i < n + 1; i++)
        dist[i] = INF;

    for (int i = 0; i < m; i++)     // 도로 입력
    {
        cin >> v1 >> v2 >> weight;
        graph[v1].push_front({ v2,weight });
        graph[v2].push_front({ v1,weight });
    }

    for (int i = 0; i < w; i++)     // 웜홀 입력
    {
        cin >> v1 >> v2 >> weight;
        graph[v1].push_front({ v2,-weight });
    }

    // 벨만 포드 알고리즘 수행
    dist[1] = 0;
    list <Edge>::iterator it;
    for (int cnt = 0; cnt < n-1; cnt++)
        for (int i = 1; i < n + 1; i++)
              for (it = graph[i].begin(); it != graph[i].end(); it++)
                 dist[it->dir] = min(dist[it->dir], dist[i] + it->weight);

    // negative cycle test
    for (int i = 1; i < n + 1; i++)
        for (it = graph[i].begin(); it != graph[i].end(); it++)
            if (dist[it->dir] > dist[i] + it->weight)
                return true;

    return false;
}