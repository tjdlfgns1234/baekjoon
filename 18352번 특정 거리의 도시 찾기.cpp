﻿#include<iostream>
#include<list>
#include<queue>

using namespace std;
#define MAX_VERTEX 300000
#define INF 987654321

struct Edge
{
    int dir;
    int weight;
};

list <Edge>* graph;
int cost[MAX_VERTEX + 1] = { 0 };
bool visit[MAX_VERTEX + 1] = { false };
void Dijstra(int start, int vsize);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int v, e, k;
    int start;
    int v1, v2;

    cin >> v >> e >> k;
    cin >> start;

    graph = new list<Edge>[v + 1];

    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2;
        graph[v1].push_front({ v2,1 });
    }

    for (int i = 1; i < v + 1; i++)
        cost[i] = INF;

    Dijstra(start, v);
    bool ans = false;
    for (int i = 1; i < v + 1; i++)
        if (cost[i] == k)
            cout << i << "\n",ans = true;
     
    if(!ans)
        cout << -1<< "\n";

}
void Dijstra(int start, int vsize)
{
    cost[start] = 0;
    visit[start] = true;
    int size = vsize - 1;

    int now = start;
    list <Edge>::iterator it;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < vsize; i++)
    {
        for (it = graph[now].begin(); it != graph[now].end(); it++)
            if (!visit[it->dir] && (cost[it->dir] > (cost[now] + it->weight)))
                cost[it->dir] = cost[now] + it->weight, pq.push({ -cost[it->dir],it->dir });

        now = -1;
        while (!pq.empty())
        {
            if (!visit[pq.top().second])
            {
                now = pq.top().second;
                pq.pop();
                break;
            }
            pq.pop();
        }

        if (now == -1)
            break;
        visit[now] = true;
    }
}