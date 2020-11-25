#include<iostream>
#include<list>
#include<queue>

using namespace std;
#define MAX_VERTEX 5000
#define INF 987654321

struct Edge
{
    int dir;
    int weight;
};


int cost[MAX_VERTEX + 1] = { 0 };
int totalcost[MAX_VERTEX + 1] = { 0 };
bool visit[MAX_VERTEX + 1] = { false };
void Dijstra(list <Edge>* graph,int start, int vsize);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int v, e;
    int v1, v2, w;
    int fri;
    cin >> t;

    while (t--)
    {
        cin >> v >> e;
        list <Edge>* graph = new list<Edge>[v + 1];
        for (int i = 0; i < e; i++)
        {
            cin >> v1 >> v2 >> w;
            graph[v1].push_front({ v2,w });
            graph[v2].push_front({ v1,w });
        }

        for (int i = 1; i < v + 1; i++)
            totalcost[i] = 0,cost[i] = INF, visit[i] = false;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> fri;
            for (int j = 1; j < v + 1; j++)
                cost[j] = INF, visit[j] = false;
            Dijstra(graph, fri, v);
            for (int j = 1; j < v + 1; j++)
                if (cost[j] != INF)
                    totalcost[j] += cost[j];;
        }
        int Min = INF;
        int ans = 0;
        for (int i = 1; i < v + 1; i++)
            if (totalcost[i] != INF)
                if (Min > totalcost[i])
                    ans = i, Min = totalcost[i];
        cout << ans << "\n";
        graph->clear();
    }

}
void Dijstra(list <Edge>* graph,int start,int vsize)
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