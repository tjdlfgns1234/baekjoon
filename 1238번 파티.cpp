#include<iostream>
#include<list>
#include<queue>

using namespace std;
#define MAX_VERTEX 1000
#define INF 987654321

struct Edge
{
    int dir;
    int weight;
};

list <Edge>* graph;
int cost[MAX_VERTEX + 1] = { 0 };
int cost2[MAX_VERTEX + 1] = { 0 };
bool visit[MAX_VERTEX + 1] = { false };
void Dijkstra(int start, int vsize);
void Dijkstra(int start, int end,int vsize);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    int start;
    int v1, v2, w;
    int result = -INF;

    cin >> n >> m;
    cin >> start;

    graph = new list<Edge>[m + 1];

    for (int i = 0; i < m; i++)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_front({ v2,w });
    }

    for (int i = 1; i < n + 1; i++)
        cost[i] = INF;

    Dijkstra(start, n);
    for (int i = 1; i < n + 1; i++)
        result = max(result,cost[i]);


    for (int i = 1; i < n + 1; i++)
    {
        for (int i = 1; i < n + 1; i++)
            cost2[i] = INF,visit[i]=false;
        Dijkstra(i, start, n);
        if(cost2[start]!=INF)
            cost[i] += cost2[start];
    }

    for (int i = 1; i < n + 1; i++)
        result = max(result, cost[i]);

    cout << result;

}
void Dijkstra(int start, int vsize)
{
    cost[start] = 0;
    visit[start] = true;

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
void Dijkstra(int start, int end, int vsize)
{
    cost2[start] = 0;
    visit[start] = true;

    int now = start;
    list <Edge>::iterator it;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < vsize; i++)
    {
        for (it = graph[now].begin(); it != graph[now].end(); it++)
            if (!visit[it->dir] && (cost2[it->dir] > (cost2[now] + it->weight)))
                cost2[it->dir] = cost2[now] + it->weight, pq.push({ -cost2[it->dir],it->dir });

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
        if (visit[end])
            return;
    }
}
