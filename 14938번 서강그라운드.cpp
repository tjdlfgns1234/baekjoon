#include<iostream>
#include<list>
#include<queue>

using namespace std;
#define MAX_VERTEX 20000
#define INF 987654321

struct Edge
{
    int dir;
    int weight;
};

list <Edge>* graph;
int result = 0;
int Max = 0;
int value[MAX_VERTEX + 1] = { 0 };
int cost[MAX_VERTEX + 1] = { 0 };
bool visit[MAX_VERTEX + 1] = { false };
void Dijstra(int start, int vsize);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int v, range,e;
    int v1, v2, w;

    cin >> v >> range>> e;

    for (int i = 1; i < v+1; i++)
        cin >> value[i];

    graph = new list<Edge>[v + 1];

    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_front({ v2,w });
        graph[v2].push_front({ v1,w });
    }

    for (int i = 1; i < v + 1; i++)
    {
        for (int j = 1; j < v + 1; j++)
            cost[j] = INF, visit[j] = false;
        Dijstra(i, v);
        for (int j = 1; j < v + 1; j++)
            if (cost[j] < range + 1)
                Max += value[j];
        result = max(result, Max);
        Max = 0;
    }

    cout << result;
    return 0;
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