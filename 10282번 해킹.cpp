#include<iostream>
#include<list>
#include<queue>

using namespace std;
#define MAX_VERTEX 10000
#define INF 987654321

struct Edge
{
    int dir;
    int weight;
};


int cost[MAX_VERTEX + 1] = { 0 };
bool visit[MAX_VERTEX + 1] = { false };
void Dijstra(list <Edge>* graph,int start, int vsize);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;
    int start;
    int v1, v2, w;

    int t;
    cin >> t;
  

    

    for (int j = 0; j < t; j++)
    {
        cin >> v >> e;
        cin >> start;
        list <Edge>* graph = new list<Edge>[v + 1];
        for (int i = 0; i < e; i++)
        {
            cin >> v1 >> v2 >> w;
            graph[v2].push_front({ v1,w });
        }

        for (int i = 1; i < v + 1; i++)
            cost[i] = INF,visit[i] = false;

        Dijstra(graph,start, v);
        int Max = -INF;
        int cnt = 0;
        for (int i = 1; i < v + 1; i++)
            if (cost[i] != INF)
                Max = max(cost[i], Max);
        for (int i = 1; i < v + 1; i++)
            if (visit[i])
                cnt++;
        cout << cnt << " " << Max << "\n";
    }

}
void Dijstra(list <Edge>* graph,int start, int vsize)
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